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

#include "Status.hpp"
#include <BibFile.h>

using namespace std;

Status::Status()
{
  statusWin = createWindow(
      6,
      COLS,
      0,
      0,
      0
      );
}

void Status::refreshStatus(Config &config, BibFile &bibfile)
{
  int y, x;
  getmaxyx(statusWin, y, x);

  mvwprintw(statusWin, 1, 1, "BibTuX v%g", 0.1);
  mvwprintw(statusWin, 3, 1, "BibTeX database: %s",
     config.getBibpath().c_str()); 
  mvwprintw(statusWin, 4, 1, "File size: %i ko", 2);

  wmove(statusWin, 1, x/2);
  wvline(statusWin, ACS_VLINE, 4);

  mvwprintw(statusWin, 1, x/2 + 1,
      "%i items", bibfile.countItems("all"));
  mvwprintw(statusWin, 2, x/2 + 1,
      "%i articles", bibfile.countItems("article"));
  mvwprintw(statusWin, 3, x/2 + 1,
      "%i books", bibfile.countItems("book"));
  mvwprintw(statusWin, 4, x/2 + 1,
      "%i misc", bibfile.countItems("misc"));


  wrefresh(statusWin);
} 
