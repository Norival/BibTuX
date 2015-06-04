#ifndef CONFIG_H
#define CONFIG_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>


class Config
{

  public:
    Config();
    bool isReadable(const std::string &file);
    void initConfig(const std::string &file, const std::string &path);
    void loadConfig();
    const std::string getBibpath();

    static void removeCharacter(std::string &Str, char C);
    static bool fromString(const std::string &Str, int &Dest); 


  protected:
    std::string m_configPath;
    std::string m_bibPath;
    
};

#endif
