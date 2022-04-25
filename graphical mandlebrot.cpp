// sfml base template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include<complex>
#include<vector>




std::complex<double> mandle(std::complex<double>z, std::complex<double>c, int detail) {
    //sortof efficient, it doesn't re initialize variables, which is good 
    z = pow(z, 2) + c;
    detail += 1;
    if (detail >= 30 || abs(z) >= 2) return z;
    std::cout << z << std::endl;
    mandle(z, c, detail);
}
int main()
{
    std::vector<sf::CircleShape*> list;
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Basic Sfml renderwindow", sf::Style::None);
    window.setFramerateLimit(60);
    
    std::complex<double>z(0, 0);
    std::complex<double>c(1, .4);

    std::complex<double> f;
    std::vector<std::complex<double>*> points;
    for (int fraction = 0; fraction <= 10; fraction += 1) {
        list.push_back(new sf::CircleShape());
        list[fraction]->setRadius(10);

        
        points.push_back(new std::complex<double>);
        points[fraction] = mandle(z, { real(c) / fraction ,imag(c) + fraction }, 0);
        list[fraction]->setPosition(0,0);
    }
    
    


    window.clear(); //uncomment this to make clear screen, to stop screen from smudging 
    window.display();
}

