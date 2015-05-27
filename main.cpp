/******************************************************************************
 *                      Bib Master
 *
 *  Author: Xavier Laviron
 *  Programm: Managing BibTeX database
 *
 *
 *
 ******************************************************************************/


#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>

using namespace std;

const string configPath("bibconfig");
string bibPath;

bool isReadable(const string &file)
{
  ifstream fichier(file.c_str());  
  return !fichier.fail();
}

void initConfig()
{
  ofstream initConfigFile(configPath.c_str());

  initConfigFile << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
    << "% BibMaster configuration file" << endl
    << "% Created on date" << endl;
}

int main ()
{
  
  cout << "Hello! Welcome in Bib Master!" << endl;

  if (isReadable(configPath.c_str()))
  {
    ofstream oconfigFile(configPath.c_str());
    ifstream iconfigFile(configPath.c_str());
  }
  else
  {
    cout << "Le fichier n'existe pas! Création!" << endl;
    initConfig();
  }
  oconfigFile << "Hello!" << endl;


  //int i = 1;
  //string line;
  //while(getline(iconfigFile, line))
  //{
    //cout << "ligne " << i << " : " << line << endl;
    //i++;
  //} 







  return 0;
}
