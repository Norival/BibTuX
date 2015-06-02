#include "BibFile.h"
#include <BibArticle.h>
#include <Config.h>

using namespace std;


BibFile::BibFile(string bibpath):
  m_bibPath(bibpath)
{
  //Constructor
}

BibFile::readBib(const string &bibpath, vector<string> &file)
{
  ifstream bibfile(bibpath.c_str());
  
  if (bibfile)
  {
    //Création de variables temporaires pour stocker les données
    string line;

    string keyTmp = "";
    string authorTmp = "";
    string journalTmp = "";
    string pagesTmp = "";
    string monthTmp = "";
    int yearTmp = "";
    int titleTmp = "";
    int volumeTmp = "";
    int numberTmp = "";

    while (getline(bibfile, line))
    {
      if (line[0] != '@')
        continue;
      else if (line.substr(1, 7) == "Article")
      {
        keyTmp = line.substr(9, line.size()-1)
        while (getline(bibfile, line))
        {
          if (line[0] != '}')
          {
            for (int i = 0; i < line.size(), i++)
            {
              switch (line[i])
              {
                case 'a' : //Author
                  if (
              }
            }
          }
        }
      }
    }
  }
}
