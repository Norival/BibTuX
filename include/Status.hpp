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

#ifndef STATUS_H
#define STATUS_H

#include<BibFile.h>
#include <Config.h>
#include<displayFunctions.hpp>

extern "C" {
#include <ncurses.h>
}

class Status
{
  public:
    Status();
    void refreshStatus(Config &config, BibFile &bibfile, const float version);

  protected:
    WINDOW *statusWin;
};

#endif
