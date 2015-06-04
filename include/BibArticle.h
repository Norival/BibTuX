#ifndef BIBARTICLE_H
#define BIBARTICLE_H 

#include <iostream>
#include <string>
#include <vector>

#include "BibItem.h"

struct characteristics
{
  std::string Author;
  std::string Journal;
  std::string Pages;
  std::string Month;
  std::string Title;
  int Year;
  int Volume;
  int Number;
};

class BibArticle : public BibItem
{
  public:
    BibArticle();
    BibArticle(std::string key,
        std::string author,
        std::string journal,
        std::string pages,
        std::string month,
        std::string title,
        int year,
        int volume,
        int number
        );
    characteristics getCharacteristics() const;

  protected:
    characteristics m_Char;

};

#endif
