#include <iostream>
#include <string>
#include "Player.h"

using namespace Assignment_2;

Player::Player()
{
}

Player::~Player()
{
}

void Player::setPlayerName(std::string playerName)
{
	_playerName = playerName;
}

void Player::setPlayerHealth(int playerHealth)
{
	_playerHealth = playerHealth;
}

std::string Player::getPlayerName() const
{
	return _playerName;
}

int Player::getPlayerHealth() const
{
	return _playerHealth;
}
