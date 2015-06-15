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

  int ch;
  int nline = 1;

  printw("Hello! Welcome in Bib Master!");

  Config currentConfig;
  currentConfig.loadConfig();

  mvprintw(nline, 1, "Reading database");
  nline++;
  BibFile myBib(currentConfig.getBibpath());
  myBib.readBib(currentConfig.getBibpath());

  mvprintw(nline, 1, "Press d for displaying items");
  nline++;
  refresh();

  ch = getch();
  if (ch == 'd')
  {
    mvprintw(nline, 1, "Which type of item ? [ALL, article, book, misc]");
    nline++;
    ch = getch();
    if (ch == 'a')
    {
      myBib.listItems();
    }
  }

  getch();
  endwin();
  return 0;
}
