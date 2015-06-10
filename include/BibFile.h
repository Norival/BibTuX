#ifndef BIBFILE_H
#define BIBFILE_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>

#include<BibItem.h>

class BibFile
{
  public:
    BibFile(std::string bibpath);
    void readBib(const std::string &bibpath);
    const void listItems(std::string type = "all");

  protected:
    std::string m_bibPath;
    std::map<std::string, BibItem*> listOfItems;
    std::vector<std::string> listOfKeys;
    std::map<std::string, BibItem*>::iterator itemsIterator;

};








#endif
