#ifndef BIBITEM_H
#define BIBITEM_H

#include <iostream>
#include <string>
#include <vector>

class BibItem
{
  public:
    BibItem();
    const std::string getKey();


  protected:
    std::string m_key;

};




#endif
