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
    //vector<string> items(0);
    //string itemTmp;
    string type;

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
      if (line.rfind('@') == line.npos) //Pas de @
        continue;
      else //Présence d'un @
      {
        keyTmp = line.substr(
            line.rfind('{') + 1,
            line.size() - 1);
        if (line.rfind("Article") != line.npos) //C'est un article
          type = "article";

        while (getline(bibfile, line))
        {
          //Lecture des composantes et sockage dans les strings Tmp
          if (line.rfind("author") != line.npos)
          {
            authorTmp = line.substr(
                line.rfind('{') + 1,
                line.rfind('}') - 1);
          }
          if (line.rfind("journal") != line.npos)
          {
            journalTmp = line.substr(
                line.rfind('{') + 1,
                line.rfind('}') - 1);
          }
          if (line.rfind("pages") != line.npos)
          {
            pagesTmp = line.substr(
                line.rfind('{') + 1,
                line.rfind('}') - 1);
          }
          if (line.rfind("month") != line.npos)
          {
            monthTmp = line.substr(
                line.rfind('{') + 1,
                line.rfind('}') - 1);
          }
          if (line.rfind("title") != line.npos)
          {
            titleTmp = line.substr(
                line.rfind('{') + 1,
                line.rfind('}') - 1);
          }
          
          if (line.rfind("year") != line.npos)
          {
            string str;
            str = line.substr(
                line.rfind('{') + 1,
                line.rfind('}') - 1);
            Config::fromString(str, yearTmp);
          }
          if (line.rfind("volume") != line.npos)
          {
            string str;
            str = line.substr(
                line.rfind('{') + 1,
                line.rfind('}') - 1);
            Config::fromString(str, volumeTmp);
          }
          if (line.rfind("number") != line.npos)
          {
            string str;
            str = line.substr(
                line.rfind('{') + 1,
                line.rfind('}') - 1);
            Config::fromString(str, numberTmp);
          }
        }
      }
    }

  }
  else
    cout << "Unable to read Bibtex file..." << endl;
}

//template<typename T>
