#include "Config.h"

using namespace std;

Config::Config():
  m_configPath("/home/xavier/.bibmasterrc"),
  m_bibPath()
{
  //Constructor
}

bool Config::isReadable(const string &file)
{
  ifstream fichier(file.c_str());  
  return !fichier.fail();
}

void Config::initConfig(const string &file, const string &path)
{
  ofstream initConfigFile(file.c_str());

  if (initConfigFile)
  {
    initConfigFile 
      << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
      << "%        BibMaster configuration file          %" << endl
      << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
      << "% Created on date" << endl << endl
      << "@BibPath:" << path << endl;
  }
  else
  {
    cout << "Error: unable to write file..." << endl;
  }
}

void Config::loadConfig()
{
  string line;

  if (!Config::isReadable(m_configPath.c_str()))
  {
    //Verifying presence of configuration file
    string bib;
    cout << "No configuration file found. Writing new one in "
      << m_configPath << endl;
    cout << "Where is the .bib database?" << endl;
    cin >> bib;

    Config::initConfig(m_configPath, bib);
  }
  else
    cout << "Configuration file loaded!" << endl;

  ifstream load(m_configPath.c_str());

  /* Reading file and initializing var */
  while (getline(load, line))
  {
    int nline = 1;
    if (line[0] == '%' || line[0] == ' ')
      continue;
    else if (line[0] == '@')
    {
      if (line.substr(1, 7) == "BibPath")
        m_bibPath = line.substr(9);
    }
    else
    {
      cout << "Bad configuration file..." << endl;
      cout << "Error in line " << nline;
    }
    nline++;
  }
}
