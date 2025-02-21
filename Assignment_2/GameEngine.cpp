#include <iostream>
#include <string>
#include "Room.h"
#include "Player.h"
#include "GameEngine.h"

using namespace Assignment_2;

GameEngine::GameEngine()
{
}

GameEngine::~GameEngine()
{
}

void GameEngine::startGame()
{
	int playerHealth = 100;
	int currentRoom;
	int randomRoom = rand() % 3 + 1;
	std::string playerName;

	std::cout << "Game started!" << std::endl;

	std::cout << "Enter player name: ";
	std::cin >> playerName;
	

	_playerHealth = playerHealth;
	_currentRoom = randomRoom;

	Player player;
	player.setPlayerName(playerName);
	player.setPlayerHealth(playerHealth);



}

void GameEngine::endGame()
{
	std::cout << "Game ended!" << std::endl;
}


