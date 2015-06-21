/*
 * This file is part of BibTuX. BibTuX is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * BibTuX is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * BibTuX.  If not, see <http://www.gnu.org/licenses/>.
 */


/* Functions to control display with ncurses */

#include "displayFunctions.hpp" 

WINDOW *createWindow(int height, int width, int starty, int startx, int type)
{
  WINDOW *localWindow;

  localWindow = newwin(height, width, starty, startx);
  noecho();
  box(localWindow, 0 , 0);
  switch (type)
  {
    case 1:
      wborder(localWindow, ' ', ' ', '-', ' ', ' ', ' ', ' ', ' ');
      break;
    case 2:
      wborder(localWindow, '|', '|', '-', '-', '+', '+', '+', '+');
      break;
    case 3:
      wborder(localWindow, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
      break;
    default:
      break;
  }

  wrefresh(localWindow);

  return localWindow;
}

void destroyWindow(WINDOW *localWindow)
{
	wborder(localWindow, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(localWindow);
	delwin(localWindow);
}

void moveCursor(WINDOW *localWindow, int &direction)
{
  int y, x;
  getyx(localWindow, y, x);

  switch (direction)
  {
    case 'j':
      y++;
      break;
    case 'k':
      y--;
      break;
    case 'h':
      x--;
      break;
    case 'l':
      x++;
      break;
  }
  wmove(localWindow, y, x);
  wrefresh(localWindow);
}
