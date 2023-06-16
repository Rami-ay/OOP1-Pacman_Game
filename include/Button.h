//progma once prevent us from including
//multiple times:
#pragma once
// --- includes --- 
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
// ---- namspaces ---
using namespace std;
// ------------------


class Button 
{
public:

    //default constructor:
    Button();
    Button(std::string t, sf::Vector2f size, int charSize, sf::Color bgcolor, sf::Color textColor);

    void setFont(sf::Font& font);
    void setBold();
    void setBackColor(sf::Color color);
    void setTextColor(sf::Color color);
    void setPosition(sf::Vector2f pos);
    sf::RectangleShape getbutton() const;
    sf::Text getext() const;
    void setButtonInfo(string t, sf::Vector2f size, int charSize, sf::Color bgcolor, sf::Color textColor, sf::Vector2f pos
        , sf::Font& font);
    void drawTo(sf::RenderWindow& m_window);
    bool isMouseOver(sf::RenderWindow& m_window);

private:
    sf::RectangleShape button;
    sf::Text text;
};