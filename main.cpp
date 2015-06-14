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

  string choice;
  string mesg;
  mesg = "Hello! Welcome in BibTuX!";
  mvprintw(row/2, (col-mesg.size())/2, "Hello world!");
  refresh();
  
  //cout << "Hello! Welcome in Bib Master!" << endl;


  Config currentConfig;
  currentConfig.loadConfig();

  cout << "Lecture de la base de données..." << endl;
  BibFile myBib(currentConfig.getBibpath());
  myBib.readBib(currentConfig.getBibpath());

  cout << "What do you want to do ?\n"
    << "1: Display items" << endl;
  cin >> choice;

  if (choice == "d")
  {
    cout << "Which type of item ? [ALL, article, book, misc]" << endl;
    cin >> choice;
    myBib.listItems(choice);
  }

  endwin();


  return 0;
}
