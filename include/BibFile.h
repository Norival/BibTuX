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
    const void getKeys(std::vector<std::string> &keys);

  protected:
    std::string m_bibPath;
    std::map<std::string, BibItem*> listOfItems;


};








#endif
