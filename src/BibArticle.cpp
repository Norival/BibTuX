#include "BibArticle.h"

using namespace std;


BibArticle::BibArticle() : BibItem()
{
  //Constructor
}

BibArticle::BibArticle(string key,
    string author,
    string journal,
    string pages,
    string month,
    string title,
    int year,
    int volume,
    int number
    )
{
  m_Char.Author= author;
  m_Char.Journal = journal;
  m_Char.Pages = pages;
  m_Char.Month = month;

  m_Char.Year = year;
  m_Char.Title = title;
  m_Char.Volume = volume;
  m_Char.Number = number;
}

characteristics BibArticle::getCharacteristics(void) const
{
  return m_Char;
}

