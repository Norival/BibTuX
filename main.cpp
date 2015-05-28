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

#include<Config.h>

using namespace std;

int main ()
{
  
  cout << "Hello! Welcome in Bib Master!" << endl;

  Config currentConfig;
  currentConfig.loadConfig();

  return 0;
}
