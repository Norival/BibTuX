#ifndef BIBITEM_H
#define BIBITEM_H

#include <iostream>
#include <string>
#include <vector>

class BibItem
{
  public:
    BibItem();
    BibItem(std::string type,
        std::string key,
        std::string author,
        std::string journal,
        std::string pages,
        std::string month,
        std::string title,
        int year,
        int volume,
        int number
        );

    //Accesseurs
    const std::string getType();
    const std::string getKey();
    const std::string getAuthor();
    const std::string getJournal();
    const std::string getPages();
    const std::string getMonth();
    const std::string getTitle();
    const int getYear();
    const int getVolume();
    const int getNumber();

  protected:
    std::string m_type;
    std::string m_key;
    std::string m_author;
    std::string m_journal;
    std::string m_pages;
    std::string m_month;
    std::string m_title;
    int m_year;
    int m_volume;
    int m_number;

};




#endif
