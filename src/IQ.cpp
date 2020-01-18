/*
** EPITECH PROJECT, 2019
** 205IQ
** File description:
** IQ.cpp
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include "IQ.hpp"

bool densityProb(int mu, int sigma)
{
    double density(0.0);

    if (mu != 100 or (sigma != 15 and sigma != 24))
        return FAILURE;
    for (int x = 0; x <= 200; ++x) {
        density = (1. / (sigma * std::sqrt(2. * M_PI)))
        * std::exp(-std::pow(x - mu, 2) / (2. * std::pow(sigma, 2)));
        std::cout << std::fixed << std::setprecision(5)
                  << x << ' ' <<  density << std::endl;
    }
    return SUCCESS;
}

bool oneIQ(int mu, int sigma, int iq1)
{
    double density(0.0);
    double ip = 100.0;

    if (mu != 100 or (sigma != 15 and sigma != 24) or iq1 < 0 or iq1 > 200)
        return FAILURE;
    for (double x = 0; x < iq1 * ip; ++x)
        density += (1.0 / ip / (sigma * std::sqrt(2. * M_PI)))
        * std::exp(-std::pow(x / ip - mu, 2) / (2. * std::pow(sigma, 2)));
    std::cout << std::fixed << std::setprecision(1)
              <<  density * 100 << '%';
    return SUCCESS;
}

bool twoIQ(int mu, int sigma, int iq1, int iq2)
{
    double density(0.0);
    double ip = 100.0;

    if (mu != 100 or (sigma != 15 and sigma != 24)
    or iq1 < 0 or iq1 > 200 or iq2 < 0 or iq2 > 200 or iq2 < iq1)
            return FAILURE;
    for (double x = iq1 * ip; x < iq2 * ip; ++x)
        density += (1.0 / ip / (sigma * std::sqrt(2. * M_PI)))
        * std::exp(-std::pow(x / ip - mu, 2) / (2. * std::pow(sigma, 2)));
    std::cout << std::fixed << std::setprecision(1)
              <<  density * 100 << '%';
    return SUCCESS;
}
