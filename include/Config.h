#ifndef CONFIG_H
#define CONFIG_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

class Config
{
  public:
    Config();
    bool isReadable(const std::string &file);
    void initConfig(const std::string &file, const std::string &path);
    void loadConfig();

    static void removeCharacter(std::string &Str, char C);


  protected:
    std::string m_configPath;
    std::string m_bibPath;
    
};

#endif
