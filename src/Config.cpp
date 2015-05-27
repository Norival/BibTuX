#include "Config.h"

using namespace std;

Config::Config():
  m_configPath("~/.bibmasterrc"),
  m_bibPath(0)
{
  //Constructor
}

bool Config::isReadable(const string &file)
{
  ifstream fichier(file.c_str());  
  return !fichier.fail();
}

void Config::initConfig(const string &file, string path)
{
  ofstream initConfigFile(file);

  initConfigFile 
    << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
    << "%        BibMaster configuration file          %" << endl
    << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
    << "% Created on date" << endl << endl
    << "@BibPath: " << path << endl;
}

vector<string> Config::loadConfig(const string &file, string &bibpath)
{
  vector<string> config(0);
  string line;
  string path;

  if (isReadable(file))
  {
    ifstream load(file.c_str());
    while (getline(load, line))
    {
      config.push_back(line);
    }
  }
  else
  {
    cout << "No configuration file found. Writing new one in " <<
      << configPath << endl;
    cout << "Where is the .bib database?" << endl;
    cin >> bibpath;
    initConfig(path);
  }
}
