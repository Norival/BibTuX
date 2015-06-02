#ifndef BIBFILE_H
#define BIBFILE_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>


class BibFile
{
  public:
    BibFile(std::string bibpath);
    void readBib(const std::string &bibpath, std::vector<std::string> &file);


  protected:
    std::string m_bibPath;
    std::vector<std::string> m_File;


};








#endif
