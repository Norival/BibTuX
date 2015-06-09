#include "BibItem.h"

using namespace std;

BibItem::BibItem()
{
  m_key = "";
  //Constructor
}

BibItem::BibItem(string type,
    string key,
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
  m_type = type;
  m_key = key;
  m_author = author;
  m_journal = journal;
  m_pages = pages;
  m_month = month;
  m_title = title;

  m_year = year;
  m_volume = volume;
  m_number = number;
}
//
//Accesseurs
const string BibItem::getType()
{
  return m_type;
}
const string BibItem::getKey()
{
  return m_key;
}

const string BibItem::getAuthor()
{
  return m_author;
}

const string BibItem::getJournal()
{
  return m_journal;
}

const string BibItem::getPages()
{
  return m_pages;
}

const string BibItem::getMonth()
{
  return m_month;
}

const string BibItem::getTitle()
{
  return m_title;
}

const int BibItem::getYear()
{
  return m_year;
}

const int BibItem::getVolume()
{
  return m_volume;
}

const int BibItem::getNumber()
{
  return m_number;
}
