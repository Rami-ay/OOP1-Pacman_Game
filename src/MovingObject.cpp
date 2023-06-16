#include "MovingObject.h"



//constructor:
MovingObject::MovingObject() {}

//function that gets the input key and handle
//the pacman movement:
void MovingObject::handleInput(sf::Event event)
{
	int frame = 40;
	m_prevPosition = m_sprite.getPosition();
	switch (event.key.code)
	{
	case sf::Keyboard::Left:
		m_sprite = m_database.pacmanSprite;
		m_sprite.setTextureRect(sf::IntRect(frame, 40 * row, frame, frame));
		m_sprite.setPosition(m_prevPosition);
		m_sprite.move(-6, 0);

		row = ((row + 1) % 3) + 6;
		row++;
		break;

	case sf::Keyboard::Right:

		m_sprite = m_database.pacmanSprite;
		m_sprite.setTextureRect(sf::IntRect(frame, 40 * row, frame, frame));
		m_sprite.setPosition(m_prevPosition);
		m_sprite.move(6, 0);

		row = (row + 1) % 3;
		row++;
		break;

	case sf::Keyboard::Up:
		m_sprite = m_database.pacmanSprite;
		m_sprite.setTextureRect(sf::IntRect(frame, 40 * row, frame, frame));
		m_sprite.setPosition(m_prevPosition);
		m_sprite.move(0, -6);

		row = ((row + 1) % 3) + 8;
		row++;
		break;

	case sf::Keyboard::Down:
		m_sprite = m_database.pacmanSprite;
		m_sprite.setTextureRect(sf::IntRect(frame, 40 * row, frame, frame));
		m_sprite.setPosition(m_prevPosition);
		m_sprite.move(0, 6);

		row = ((row + 1) % 3) + 3;
		row++;
		break;
	}
}

int MovingObject::getlives()
{
	return live;
}

//this function handles the elf movement, the elf first
//reaches the center of the map then start the persuit of the pacman
// to make the game fair for the player the ghost gets the updated 
//pacman location every five moves he takes:
void MovingObject::moveElf(int boardCol, int boardRow, sf::Vector2f pacman_position, std::vector<std::unique_ptr<StaticObject>>& objects,
	float chaseProbability) 
{
	m_prevPosition = m_sprite.getPosition();
	sf::Vector2f closeNeighbor;
	srand(time(NULL));
	float gamble = (float)rand() / RAND_MAX;
	sf::Vector2f neighbors[4] = { 
		{m_sprite.getPosition().x + 6,m_sprite.getPosition().y},
		{m_sprite.getPosition().x - 6,m_sprite.getPosition().y},
		{m_sprite.getPosition().x ,m_sprite.getPosition().y + 6},
		{m_sprite.getPosition().x ,m_sprite.getPosition().y - 6} 
	};
	if (gamble < chaseProbability)
	{
		//get the closest neighbor to the target:
		closeNeighbor = closestNeighbor(pacman_position, m_sprite.getPosition(), neighbors);
	}
	else 
	{
		//get random neighbor:
		int randomIndex = rand() % 4;
		closeNeighbor = neighbors[randomIndex];
	}
	if (validNeighbor(closeNeighbor, boardCol, boardRow)) 
	{
		bool collided = false;
		for (auto& obj : objects) 
		{
			if (checkCollision((*obj)))
			{
				collided = true;
				break;
			}
		}
		if (!collided)
			m_sprite.setPosition(closeNeighbor);
		else 
		{
			sf::Vector2f closestValidNeighbor;
			float closestDistance = std::numeric_limits<float>::max();
			for (int i = 0; i < 4; i++) {
				if (validNeighbor(neighbors[i], boardCol, boardRow)) 
				{
					float dist = distance(pacman_position, neighbors[i]);
					if (dist < closestDistance) 
					{
						closestValidNeighbor = neighbors[i];
						closestDistance = dist;
					}
				}
			}
			if (closestDistance != std::numeric_limits<float>::max()) 
			{
				m_sprite.setPosition(closestValidNeighbor);
			}
		}
	}
}
//function that mesures the distance of two vector2f points:
float MovingObject::distance(const sf::Vector2f& p1, const sf::Vector2f& p2) 
{
	float dx = p2.x - p1.x;
	float dy = p2.y - p1.y;
	return sqrt(dx * dx + dy * dy);
}
//function that returns the position of a vector2f that is closest to the target vector2f.
sf::Vector2f MovingObject::closestNeighbor(const sf::Vector2f& target, const sf::Vector2f& current, sf::Vector2f neighbors[4]) 
{
	sf::Vector2f closest = neighbors[0];
	float minDistance = distance(closest, target);

	for (int i = 1; i < 4; i++) {
		float dist = distance(neighbors[i], target);
		if (dist < minDistance) {
			closest = neighbors[i];
			minDistance = dist;
		}
	}
	return closest;
}

bool MovingObject::validNeighbor(sf::Vector2f closeNeighbor, int boardCol, int boardRow)
{
	if (closeNeighbor.x >= (725 - (boardCol * icon_width / 2)) && closeNeighbor.x <= (725 + (boardCol * icon_width / 2))
		&& closeNeighbor.y >= (500 - (boardRow * icon_height /2)) && closeNeighbor.y <= (500 + (boardRow * icon_height / 2)))
	{
		return true;
	}
	else
		return false;
}

sf::Vector2f MovingObject::getSpritePos()const
{
	return m_sprite.getPosition();
}



bool MovingObject::getISuper() const
{
	return is_super;
}
void MovingObject::setISuper(bool status)
{
	is_super = status;
}