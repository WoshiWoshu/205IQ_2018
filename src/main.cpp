/*
** EPITECH PROJECT, 2019
** 205IQ
** File description:
** Maths
*/

#include <cstring>
#include <iostream>
#include "IQ.hpp"

static void displayHelp(void)
{
        std::cout << "USAGE" << std::endl;
        std::cout << "\t./205IQ u s [IQ1] [IQ2]" << std::endl << std::endl;
        std::cout << "DESCRIPTION" << std::endl;
        std::cout << "\tu\tmean" << std::endl;
        std::cout << "\ts\tstandard deviation" << std::endl;
        std::cout << "\tIQ1\tminimum IQ" << std::endl;
        std::cout << "\tIQ2\tmaximum IQ" << std::endl;
}

static bool isNum(char *buff)
{
    for (int i = 0; buff[i] != '\0'; ++i)
        if ((buff[i] < '0' || buff[i] > '9') && buff[i] != '.')
            return FAILURE;
    if (strcmp(buff, ".") == 0)
        return FAILURE;
    return SUCCESS;
}

static bool iQ(int ac, char **av)
{
    if (ac == 3)
        if (densityProb(std::atof(av[1]), std::atof(av[2])) == FAILURE)
            return FAILURE;
    if (ac == 4)
        if (isNum(av[3]) == FAILURE
        or oneIQ(std::atof(av[1]), std::atof(av[2]),
        std::atof(av[3])) == FAILURE)
            return FAILURE;
    if (ac == 5)
        if (isNum(av[3]) == FAILURE or isNum(av[4]) == FAILURE
        or twoIQ(std::atof(av[1]), std::atof(av[2]),
        std::atof(av[3]), std::atof(av[4])) == FAILURE)
            return FAILURE;
    return SUCCESS;
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        displayHelp();
        return 0;
    }
    if (iQ(ac, av) == FAILURE)
        return 84;
    if (ac != 3 and ac != 4 and ac != 5)
        return 84;
    return 0;
}
