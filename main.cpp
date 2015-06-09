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
#include<map>

#include<BibItem.h>
#include<BibFile.h>
#include<Config.h>

using namespace std;

int main ()
{
  
  vector<string> listOfKeys(0);
  cout << "Hello! Welcome in Bib Master!" << endl;

  Config currentConfig;
  currentConfig.loadConfig();

  cout << "Lecture de la base de données..." << endl;
  BibFile myBib(currentConfig.getBibpath());
  myBib.readBib(currentConfig.getBibpath());

  myBib.getKeys(listOfKeys); 

  cout << listOfKeys[1] << endl;

  
  return 0;
}
