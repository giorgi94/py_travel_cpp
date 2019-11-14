#include "travel.h"

void _travel(
    const std::string &dirname,
    std::list<filetype> &items)
{

    if (DIR *dir = opendir(dirname.c_str()))
    {
        while (struct dirent *entry = readdir(dir))
        {
            if (strcmp(entry->d_name, ".") == 0)
                continue;
            if (strcmp(entry->d_name, "..") == 0)
                continue;

            filetype item;

            std::string fullpath = dirname + entry->d_name;

            item.fullpath = fullpath;
            item.filename = entry->d_name;

            if ((entry->d_type & DT_DIR) == DT_DIR && !((entry->d_type & DT_LNK) == DT_LNK))
            {

                item.type = 'f';

                items.push_back(item);

                std::string dirname = fullpath + "/";
                _travel(dirname, items);
            }
            else if ((entry->d_type & DT_REG) == DT_REG)
            {
                item.type = 'd';
                items.push_back(item);
            }
        }

        closedir(dir);
    }
}

std::list<filetype> travel(std::string dirname)
{

    if (*(--dirname.end()) != '/')
    {
        dirname += '/';
    }

    std::list<filetype> items;

    _travel(dirname, items);

    return items;
}