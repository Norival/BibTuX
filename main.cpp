/******************************************************************************
 *                                   BibTuX
 *
 *  Author: Xavier Laviron
 *  Purpose: Managing BibTeX database
 *
 *  BibTuX is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  BibTuX is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with BibTuX.  If not, see <http://www.gnu.org/licenses/>.
 *
 *****************************************************************************/


#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<map>
#include <ncurses.h>

#include<BibItem.h>
#include<BibFile.h>
#include<Config.h>
#include<displayFunctions.hpp>
#include<Status.hpp>

#define VERSION 0.1

using namespace std;

int main ()
{
  /* ncurses initialization */
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
  int row, col;
  getmaxyx(stdscr, row, col);

  WINDOW *commandWin;
  commandWin = createWindow(
      3,
      COLS,
      LINES - 4,
      0,
      2);

  int ch;
  int nline = 1;

  Config currentConfig;
  currentConfig.loadConfig();

  BibFile myBib(currentConfig.getBibpath());
  myBib.readBib(currentConfig.getBibpath());

  Status status;
  status.refreshStatus(currentConfig, myBib, VERSION);

  while(1)
  {
    mvwprintw(commandWin, 1, 1, "Press 'd' to display items, 'q' to quit");
    wclrtoeol(commandWin);
    wborder(commandWin, '|', '|', '-', '-', '+', '+', '+', '+');
    ch = wgetch(commandWin);
    if (ch == 'd')
    {
      while (1)
      {
        wclrtoeol(commandWin);
        mvwprintw(commandWin, 1,
            1,
            "Which type of item ? [all(a), article(r), book(b), misc(m)]"
            );
        wclrtoeol(commandWin);
        wborder(commandWin, '|', '|', '-', '-', '+', '+', '+', '+');
        refresh();
        status.refreshStatus(currentConfig, myBib, VERSION);
        wrefresh(commandWin);
        ch = getch();
        switch (ch)
        {
          case 'a':
            myBib.listItems();
            break;
          case 'r':
            myBib.listItems("article");
            break;
          case 'b':
            myBib.listItems("book");
            break;
          case 'm':
            myBib.listItems("misc");
            break;
        }
        break;
      }
    }
    if (ch == 'q')
      break;
  }

  //getch();
  endwin();
  return 0;
}
