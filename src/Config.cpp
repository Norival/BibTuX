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
      << "@BibPath: " << path << endl;
  }
  else
  {
    cout << "Error: unable to write file..." << endl;
  }
}

vector<string> Config::loadConfig()
{
  vector<string> config(0);
  string line;

  if (!Config::isReadable(m_configPath.c_str()))
  {
    cout << "No configuration file found. Writing new one in "
      << m_configPath << endl;
    cout << "Where is the .bib database?" << endl;
    cin >> m_bibPath;
    Config::initConfig(m_configPath, m_bibPath);
  }
  else
  {
    cout << "Configuration file loaded!" << endl;
  }

  ifstream load(m_configPath.c_str());
  while (getline(load, line))
  {
    config.push_back(line);
  }

  return config;
}
