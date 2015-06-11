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

#ifndef BIBFILE_H
#define BIBFILE_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>

#include<BibItem.h>

class BibFile
{
  public:
    BibFile(std::string bibpath);
    void readBib(const std::string &bibpath);
    const void listItems(std::string type = "all");

  protected:
    std::string m_bibPath;
    std::map<std::string, BibItem*> listOfItems;
    std::vector<std::string> listOfKeys;
    std::map<std::string, BibItem*>::iterator itemsIterator;

};

#endif
