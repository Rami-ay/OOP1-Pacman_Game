// --- includes --- 
#include "DataBase.h"


//constructor:

DataBase::DataBase()
{
	 //item:
    doorTexture.loadFromFile("door.png");
    cookieTexture.loadFromFile("cookie.png");
    wallTexture.loadFromFile("wall.png");
    elfTexture.loadFromFile("elf.png");
    keyTexture.loadFromFile("key.png");
    giftLifeTexture.loadFromFile("lifeGift.png");
    SnowFlakeTexture.loadFromFile("snowflake.png");
    HourGlassTexture.loadFromFile("additionalTime.png");
    emptyTexture.loadFromFile("empty.png");
    lifeTexture.loadFromFile("life.png");
    freezeTexture.loadFromFile("freeze.png");
    pacsheetTex.loadFromFile("sprite_sheet.png");
    //sprite
    doorSprite = sf::Sprite(doorTexture);
    cookieSprite  = sf::Sprite(cookieTexture);
    wallSprite = sf::Sprite(wallTexture);
    elfSprite = sf::Sprite(elfTexture);
    pacmanSprite = sf::Sprite(pacsheetTex);
    keySprite = sf::Sprite(keyTexture);
    giftLifeSprite = sf::Sprite(giftLifeTexture);
    SnowFlakeSprite = sf::Sprite(SnowFlakeTexture);
    HourGlassSprite = sf::Sprite(HourGlassTexture);
    emptySprite = sf::Sprite(emptyTexture);
    emptySprite.setColor(sf::Color::Red);
    lifeSprite = sf::Sprite(lifeTexture);
    freezeSprite = sf::Sprite(freezeTexture);
   
    
   
}