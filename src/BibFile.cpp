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

#include "BibFile.h"
#include <Config.h>

using namespace std;


BibFile::BibFile(string bibpath):
  m_bibPath(bibpath)
{
  //Constructor
}

void BibFile::readBib(const string &bibpath)
{
  ifstream bibfile(bibpath.c_str());

  if (bibfile)
  {
    //Création de variables temporaires pour stocker les données
    string line;
    string typeTmp= "";

    string keyTmp = "";
    string authorTmp = "";
    string journalTmp = "";
    string pagesTmp = "";
    string monthTmp = "";
    string titleTmp = "";
    int yearTmp = 0;
    int volumeTmp = 0;
    int numberTmp = 0;

    while (getline(bibfile, line))
    {
      //Boucle générale, lecture du fichier
      if (line.rfind('@') != line.npos) //Présence d'un @
      {
        typeTmp = line.substr(
            line.find('@') + 1,
            line.find_first_of('{') - 1);
        keyTmp = line.substr(
            line.find_first_of('{') + 1,
            line.find_last_of(',') - line.find_first_of('{') - 1);
      }

      //Lecture des composantes et sockage dans les strings Tmp
      if (line.rfind("author") != line.npos)
      {
        authorTmp = line.substr(
            line.find_first_of('{') + 1,
            line.find_last_of('}') - line.find_first_of('{') - 1);
      }
      if (line.rfind("journal") != line.npos)
      {
        journalTmp = line.substr(
            line.find_first_of('{') + 1,
            line.find_last_of('}') - line.find_first_of('{') - 1);
      }
      if (line.rfind("pages") != line.npos)
      {
        pagesTmp = line.substr(
            line.find_first_of('{') + 1,
            line.find_last_of('}') - line.find_first_of('{') - 1);
      }
      if (line.rfind("month") != line.npos)
      {
        monthTmp = line.substr(
            line.find_first_of('{') + 1,
            line.find_last_of('}') - line.find_first_of('{') - 1);
      }
      if (line.rfind("title") != line.npos)
      {
        titleTmp = line.substr(
            line.find_first_of('{') + 1,
            line.find_last_of('}') - line.find_first_of('{') - 1);
      }

      if (line.rfind("year") != line.npos)
      {
        string str;
        str = line.substr(
            line.find_first_of('{') + 1,
            line.find_last_of('}') - line.find_first_of('{') - 1);
        Config::fromString(str, yearTmp);
      }
      if (line.rfind("volume") != line.npos)
      {
        string str;
        str = line.substr(
            line.find_first_of('{') + 1,
            line.find_last_of('}') - line.find_first_of('{') - 1);
        Config::fromString(str, volumeTmp);
      }
      if (line.rfind("number") != line.npos)
      {
        string str;
        str = line.substr(
            line.find_first_of('{') + 1,
            line.find_last_of('}') - line.find_first_of('{') - 1);
        Config::fromString(str, numberTmp);
      }
      Config::removeCharacter(line, ' ');
      if (line == "}")
      {
        listOfItems[keyTmp] = new BibItem(typeTmp,
            keyTmp,
            authorTmp,
            journalTmp,
            pagesTmp,
            monthTmp,
            titleTmp,
            yearTmp,
            volumeTmp,
            numberTmp);
      }
    }
    for(itemsIterator = listOfItems.begin();
        itemsIterator != listOfItems.end();
        ++itemsIterator)
    { 
      listOfKeys.push_back(itemsIterator->first);
      //cout << it->first << "\n";
    }
  }
  else
    cout << "Unable to read Bibtex file..." << endl;
}

const void BibFile::listItems(string type)
{
  /* Creating window */
  displayWin = createWindow(
      LINES / 2,
      COLS,
      LINES / 2,
      0,
      1
      );

  int i = 1;

  if (type == "all")
  {
    cout << "\n List of all items in Bibfile: \n\n";
  }
  if (type == "all" || type == "article")
  {
    cout << endl << "Articles:" << endl;
    for(itemsIterator = listOfItems.begin();
        itemsIterator != listOfItems.end();
        ++itemsIterator)
    {
      if (itemsIterator->second->getType() == "Article")
      {
        cout << i << " " << itemsIterator->first << ": " 
          << itemsIterator->second->getTitle() << endl;
        i++;
      }
    }
  }
  if (type == "all" || type == "book")
  {
    cout << endl << "Books:" << endl;
    //Continuer pour les autres types
    for(itemsIterator = listOfItems.begin();
        itemsIterator != listOfItems.end();
        ++itemsIterator)
    {
      if (itemsIterator->second->getType() == "Book")
      {
        cout << i << " " << itemsIterator->first << ": " 
          << itemsIterator->second->getTitle() << endl;
        i++;
      }
    }
  }
  if (type == "all" || type == "misc")
  {
    cout << endl << "Miscellaneaous:" << endl;
    for(itemsIterator = listOfItems.begin();
        itemsIterator != listOfItems.end();
        ++itemsIterator)
    {
      if (itemsIterator->second->getType() == "Misc")
      {
        cout << i << " " << itemsIterator->first << ": " 
          << itemsIterator->second->getTitle() << endl;
        i++;
      }
    }
  }
  destroyWindow(displayWin);
}
