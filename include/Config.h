#ifndef CONFIG_H
#define CONFIG_H

#include<fstream>
#include<string>
#include<vector>

class Config
{
  public:
    Config();
    void initConfig(const std::string &file, std::string path);
    bool isReadable(const std::string &file);
    std::vector<std::string> loadConfig(const std::string &file, std::string &bibpath);
    

  protected:
    std::string m_configPath;
    std::string m_bibPath;
    
    
};

#endif
