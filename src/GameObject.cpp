#include "GameObject.h"



GameObject::GameObject(){}

void GameObject::initObjectPac(int currentCol, int currentRow, int boardCol, int boardRow, sf::Sprite newSprite)
{
	m_sprite = newSprite;
	m_sprite.setTextureRect(sf::IntRect(40 * 1, 40 * 0, 40, 40));
	m_sprite.setPosition(725 - (boardCol * 48 / 2) + (currentCol * icon_width), 500 - (boardRow * 48 / 2) + (currentRow * icon_height));
	m_startPosition = m_sprite.getPosition();
}
//function that sets the sprite position and the sprite pic:
void GameObject::initObject(int currentCol, int currentRow, int boardCol, int boardRow, sf::Sprite newSprite)
{
	m_sprite = newSprite;
	m_sprite.setPosition(725 - (boardCol * 48 / 2) + (currentCol * icon_width), 500 - (boardRow * 48 / 2) + (currentRow * icon_height));
	m_startPosition=m_sprite.getPosition();
}
//function that draws the sprite on a given window:
void GameObject::draw(sf::RenderWindow* main_window)
{
	main_window->draw(m_sprite);
}
bool GameObject::checkCollision(const GameObject& other) const
{
	if (&other == this)
		return false;


	return m_sprite.getGlobalBounds().intersects(other.m_sprite.getGlobalBounds());
}
sf::Sprite GameObject::getSprite() const
{
	return m_sprite;
}


void GameObject::resetSuperPacman()
{
	is_super = false;
	m_sprite.setColor(sf::Color::Yellow);
}

void GameObject::activeSuperPacman()
{
	is_super = true;
	m_sprite.setColor(sf::Color::Red);
}

