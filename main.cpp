#include <iostream>
#include "source/binomial.h"
#include "source/travel.h"

int main(int argc, char **argv)
{

    std::cout << binomial(5, 2) << std::endl;

    auto items = travel(argv[1]);

    for (int i = 0; i < items.size(); i++)
    {
        auto item = items[i];

        std::cout << item.first << " - " << item.second << std::endl;
    }

    return 0;
}