#include <iostream>
#include <string>
#include "Room.h"
#include "Player.h"
#include "GameEngine.h"

using namespace Assignment_2;

GameEngine::GameEngine()
{
	srand(time(NULL));
}

GameEngine::~GameEngine()
{
}

void GameEngine::startGame()
{
	int playerHealth = 100;
	int totalRooms = 15;
	std::string playerName;

	std::cout << "Enter player name: ";
	std::cin >> playerName;

	// Generate a random spawn room for the player
	int spawnRoom = rand() % totalRooms + 1;

	// Generate a random winning room making sure is different from the spawn room
	int winningRoom;
	do
	{
		winningRoom = rand() % totalRooms + 1;
	} while (winningRoom == spawnRoom);

	// Create the player
	_playerHealth = playerHealth;
	_currentRoom = spawnRoom;
	_winningRoom = winningRoom;

	Player player;
	player.setPlayerName(playerName);
	player.setPlayerHealth(playerHealth);
}

void GameEngine::endGame()
{
	std::cout << "Game ended!" << std::endl;
}


