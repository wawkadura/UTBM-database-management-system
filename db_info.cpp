#include "db_info.h"
#include <iostream>

#include <vector>
#include <dirent.h>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

using namespace std;

DbInfo::DbInfo(string path) : current_db_path(path) {}

void DbInfo::setDbPath(string path){
    this->current_db_path = path;
}

std::string DbInfo::getDbPath(){
    return this->current_db_path;
}

vector<string> DbInfo::getTables()
{
    DIR *dir;
    struct dirent *diread;
    vector<string> files;

    if ((dir = opendir("db/")) != nullptr)
    {
        while ((diread = readdir(dir)) != nullptr)
        {
            string name = diread->d_name;
            if (name != "." && name != "..")
            {
                files.push_back(name);
            }
        }
        closedir(dir);
    }
    else
    {
        return files;
    }
    
    return files;
}
