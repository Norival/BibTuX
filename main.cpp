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
  string choice;
  
  cout << "Hello! Welcome in Bib Master!" << endl;

  Config currentConfig;
  currentConfig.loadConfig();

  cout << "Lecture de la base de données..." << endl;
  BibFile myBib(currentConfig.getBibpath());
  myBib.readBib(currentConfig.getBibpath());

  cout << "What do you want to do ?\n"
    << "1: Display items" << endl;
  cin >> choice;

  if (choice == "d")
  {
    cout << "Which type of item ? [ALL, article, book, misc]" << endl;
    cin >> choice;
    myBib.listItems(choice);
  }


  return 0;
}
