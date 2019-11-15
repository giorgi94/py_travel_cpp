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

            struct stat file_stats;

            stat(item.fullpath.c_str(), &file_stats);

            item.ctime = (int)file_stats.st_ctime;
            item.mtime = (int)file_stats.st_mtime;

            if ((entry->d_type & DT_DIR) == DT_DIR && !((entry->d_type & DT_LNK) == DT_LNK))
            {

                item.isdir = true;
                item.size = 0;

                items.push_back(item);

                std::string dirname = fullpath + "/";
                _travel(dirname, items);
            }
            else if ((entry->d_type & DT_REG) == DT_REG)
            {
                item.isdir = false;
                item.size = file_stats.st_size;

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