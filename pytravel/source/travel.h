#ifndef TRAVEL_H
#define TRAVEL_H

#include <string>
#include <list>

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

struct filetype
{
    bool isdir;
    std::string filename;
    std::string fullpath;
    int size;
    int ctime;
    int mtime;
};

void _travel(
    const std::string &dirname,
    std::list<filetype> &items);

std::list<filetype> travel(std::string dirname);

#endif