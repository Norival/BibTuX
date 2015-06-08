#ifndef BIBFILE_H
#define BIBFILE_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>


class BibFile
{
  public:
    BibFile(std::string bibpath);
    void readBib(const std::string &bibpath);

  protected:
    std::string m_bibPath;
    std::vector<std::string> m_File;


};








#endif
