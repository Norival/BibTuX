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

#include "Config.h"

using namespace std;

string Config::HOME = getenv("HOME");

void Config::removeCharacter(string &Str, char C)
{
  Str.erase( 
      remove(Str.begin(), Str.end(), C), 
      Str.end());  
}

bool Config::fromString(const string &Str, int &Dest)
{ 
  // créer un flux à partir de la chaîne donnée 
  istringstream iss(Str); 
  // tenter la conversion vers Dest 
  return iss >> Dest != 0; 
}

Config::Config()
{
  m_configPath = HOME + "/.bibtuxrc";
  m_bibPath = "";
  //Constructor
}

const string Config::getBibpath()
{
  return m_bibPath;
}

bool Config::isReadable(const string &file)
{
  ifstream fichier(file.c_str());  
  return !fichier.fail();
}

void Config::initConfig(string file, const string &path)
{
  while (1)
  {
    ofstream initConfigFile(file.c_str());
    if (initConfigFile)
    {
      initConfigFile 
        << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
        << "%           BibTuX configuration file          %" << endl
        << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
        << "\n"
        << "@BibPath = " << path << endl;
      break;
    }
    else
    {
      string msg = "Error: unable to write file...";
      errorWin = createWindow(
          6,
          msg.size() + 4,
          LINES/2 - 3,
          COLS/2 - msg.size()/2,
          2
          );
      int y, x, cury, curx;
      getmaxyx(errorWin, y, x);
      mvwprintw(errorWin,
          1, 
          x/2 - msg.size()/2,
          "%s",
          msg.c_str()
          );
      /* Finir le message d'erreur */
      mvwprintw(errorWin,
          2,
          1,
          "Enter file path:"
          );
      char str[80];
      echo();
      getyx(errorWin, cury, curx);
      wmove(errorWin, cury+1, 1);
      wgetstr(errorWin, str);
      file = str;
      wrefresh(errorWin);
      endwin();
    }
  }
}

void Config::loadConfig()
{
  string line;
  if (!Config::isReadable(m_configPath.c_str()))
  {
    //Verifying presence of configuration file
    string bib;
    char str[80];
    string msg = "No configuration file found. Writing new one in";
    msgWin = createWindow(
        6,
        msg.size() + 4,
        LINES/2 - 3,
        COLS/2 - msg.size()/2,
        2
        ); 
    int y, x, cury, curx;
    getmaxyx(msgWin, y, x);
    while (!Config::isReadable(m_bibPath))
    {
      mvwprintw(msgWin,
          1,
          x/2 - msg.size()/2,
          msg.c_str()
          );
      mvwprintw(msgWin,
          2,
          x/2 - m_configPath.size()/2,
          m_configPath.c_str()
          );
      mvwprintw(msgWin,
          3,
          1,
          "Where is the .bib database?"
          );
      echo();
      getyx(msgWin, cury, curx);
      wmove(msgWin, cury+1, 1);
      wgetstr(msgWin, str);
      m_bibPath = str;
      getyx(msgWin, cury, curx);
      wmove(msgWin, cury-1, 1);
      wclrtoeol(msgWin);
      wborder(msgWin, '|', '|', '-', '-', '+', '+', '+', '+');
      wrefresh(msgWin);

      Config::initConfig(m_configPath, m_bibPath);
    }
  }
  //else
    //mvprintw(1, 1, "Config file loaded");

  ifstream load(m_configPath.c_str());

  /* Reading file and initializing var */
  while (getline(load, line))
  {
    if (line.find('%') != line.npos)
      continue;
    else if (line.find('@') != line.npos)
    {
      if (line.find("BibPath") != line.npos)
      {
        m_bibPath = line.substr(
            line.find('=') + line.find_first_not_of(' ', line.find('=') + 1) -
            line.find('='),
            line.find_last_not_of(' ')
            );
      }
    }
  }
}
