#include "BibItem.h"

using namespace std;

BibItem::BibItem()
{
  m_key = "";
  //Constructor
}

const string BibItem::getKey()
{
  return m_key;
}
