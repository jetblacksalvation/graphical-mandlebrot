// sfml base template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include<complex>
#include<vector>




std::complex<double> mandle(std::complex<double>z, std::complex<double>c, int detail) {
    //sortof efficient, it doesn't re initialize variables, which is good 
    z = pow(z, 2) + c;
   
    
    std::cout << z << std::endl;
    return z;
}
int main()
{
    std::vector<sf::CircleShape> list;
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Basic Sfml renderwindow", sf::Style::None);
    window.setFramerateLimit(60);
    
   
    std::complex<double>c(1, .4);

    std::complex<double> f;
    std::vector<std::complex<double>> points;
    while (window.isOpen()) {


        for (int fraction = 0; fraction <= 100; fraction += 1) {//thnx criticalhex 4 fixing <3

            for (int f = 0; f <= 100; f++) {
                list.push_back(*new sf::CircleShape());
                list[fraction].setRadius(10);

                std::complex<double> n;
                points.push_back(n);
                points[fraction] = mandle({ 0,0 }, { real(c) / fraction ,imag(c) +f }, 0);
                list[fraction].setPosition(points[fraction].real() * 100, points[fraction].imag() *100);
                window.draw(list[fraction]);
            }

            list.push_back(*new sf::CircleShape());
            list[fraction].setRadius(10);

            std::complex<double> n;
            points.push_back(n);
            points[fraction] = mandle({0,0}, { real(c) / fraction ,imag(c) * fraction }, 0);
            list[fraction].setPosition(points[fraction].real()*500, points[fraction].imag()*500);
            window.draw(list[fraction]);
        }




         //uncomment this to make clear screen, to stop screen from smudging 
        window.display();
    }
}

