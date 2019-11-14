#ifndef TRAVEL_H
#define TRAVEL_H

#include <string>
#include <list>

#include <sys/types.h>
#include <dirent.h>
#include <string.h>

struct filetype
{
    char type;
    std::string filename;
    std::string fullpath;
};

void _travel(
    const std::string &dirname,
    std::list<filetype> &items);

std::list<filetype> travel(std::string dirname);

#endif