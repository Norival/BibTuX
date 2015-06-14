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

#ifndef DISPLAYFUNCTION_H
#define DISPLAYFUNCTION_H

extern "C" {
#include <ncurses.h>
}

WINDOW *createWindow(int height, int width, int starty, int startx, int type);
void destroyWindow(WINDOW *localWindow);

#endif
