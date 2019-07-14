#ifndef TRAVEL_H
#define TRAVEL_H

#include <vector>
#include <string>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

void _travel(
    const std::string &dirname,
    std::vector<std::pair<char, std::string>> &items);

std::vector<std::pair<char, std::string>> travel(std::string dirname);

#endif