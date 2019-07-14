#include "travel.h"

void _travel(
    const std::string &dirname,
    std::vector<std::pair<char, std::string>> &items)
{

    if (DIR *dir = opendir(dirname.c_str()))
    {
        while (struct dirent *entry = readdir(dir))
        {
            if (strcmp(entry->d_name, ".") == 0)
                continue;
            if (strcmp(entry->d_name, "..") == 0)
                continue;

            std::pair<char, std::string> item;

            std::string filename = dirname + entry->d_name;

            item.second = filename;

            if ((entry->d_type & DT_DIR) == DT_DIR && !((entry->d_type & DT_LNK) == DT_LNK))
            {
                item.first = 'd';
                items.push_back(item);

                std::string dirname = filename + "/";
                _travel(dirname, items);
            }
            else if ((entry->d_type & DT_REG) == DT_REG)
            {
                item.first = 'f';
                items.push_back(item);
            }
        }

        closedir(dir);
    }
}

std::vector<std::pair<char, std::string>> travel(std::string dirname)
{

    if (*(--dirname.end()) != '/')
    {
        dirname += '/';
    }

    std::vector<std::pair<char, std::string>> items;

    _travel(dirname, items);

    return items;
}