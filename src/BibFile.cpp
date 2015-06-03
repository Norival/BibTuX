#include "BibFile.h"
#include <BibArticle.h>
#include <Config.h>

using namespace std;


BibFile::BibFile(string bibpath):
  m_bibPath(bibpath)
{
  //Constructor
}

void BibFile::readBib(const string &bibpath)//, vector<string> &file)
{
  ifstream bibfile(bibpath.c_str());
  
  if (bibfile)
  {
    //Création de variables temporaires pour stocker les données
    string line;
    vector<string> items(0);
    string itemTmp;

    string keyTmp = "";
    string authorTmp = "";
    string journalTmp = "";
    string pagesTmp = "";
    string monthTmp = "";
    int yearTmp = 0;
    int titleTmp = 0;
    int volumeTmp = 0;
    int numberTmp = 0;

    while (getline(bibfile, line))
    {
      //Enregistrement des items dans des strings
      if (line[0] != '@')
        continue;
      else
      {
        itemTmp = "";
        while (line[0] != '}')
        {
          getline(bibfile, line);
          itemTmp += line;
        }
        items.push_back(itemTmp);
      }
    }

  }
  else
    cout << "Unable to read Bibtex file..." << endl;
}
