#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include <iostream>
class DataBase
{
public:

    //constructor:
    DataBase();

    //item:
    sf::Texture doorTexture;
    sf::Texture cookieTexture;
    sf::Texture wallTexture;
    sf::Texture elfTexture;
    sf::Texture keyTexture;
    sf::Texture giftLifeTexture;
    sf::Texture SnowFlakeTexture;
    sf::Texture HourGlassTexture;
    sf::Texture emptyTexture;
    sf::Texture lifeTexture;
    sf::Texture freezeTexture;
    //sprite
    sf::Sprite doorSprite;
    sf::Sprite cookieSprite;
    sf::Sprite wallSprite;
    sf::Sprite elfSprite;
    //sf::Sprite pacmanSprite;
    sf::Sprite keySprite;
    sf::Sprite giftLifeSprite;
    sf::Sprite SnowFlakeSprite;
    sf::Sprite HourGlassSprite;
    sf::Sprite emptySprite;
    sf::Sprite lifeSprite;
    sf::Sprite freezeSprite;

    //sheet 
    sf::Texture pacsheetTex;
    sf::Sprite pacmanSprite;
    sf::Sprite pacsheet;


};