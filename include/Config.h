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

#ifndef CONFIG_H
#define CONFIG_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
#include<ncurses.h>


class Config
{

  public:
    Config();
    bool isReadable(const std::string &file);
    void initConfig(const std::string &file, const std::string &path);
    void loadConfig();
    const std::string getBibpath();

    static void removeCharacter(std::string &Str, char C);
    static bool fromString(const std::string &Str, int &Dest); 
    static std::string $HOME;


  protected:
    std::string m_configPath;
    std::string m_bibPath;
    
};

#endif
