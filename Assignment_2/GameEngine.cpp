#include <iostream>
#include <string>
#include <cstdlib>
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

void GameEngine::PrintArt()
{
	system("pause");
	system("cls");

	std::cout << "______            _        _______  _______  _______  _          _______  _______  _______  _______  _______  _______ \n";
	std::cout << "(  __ || | |     /|( (    /|(  ____| (  ____  |(  ___  )( (    /|  (  ____ |(  ____ ||(  ____||(___  )(  ____ )(  ____ \n";
	std::cout << "| (   | )| )   ( ||  |  ( || (    ||/| (     /| (   ) ||   |  ( |  | (    |/| (    ||/| (    || (   ) || (    )|| (     \n";
	std::cout << "| |   ) || |   | ||   || | || |      | (__    | |   | ||    | | |  | (__    | (_____ | |      | (___) || (____)|| (__    \n";
	std::cout << "| |   | || |   | || ( | |) || | ____ |  __)   | |   | || (|  |) |  |  __)   (_____  )| |      |  ___  ||  _____)|  __)   \n";
	std::cout << "| |   ) || |   | || |  |   || | ||_  )| (     | |   | || |  |   |  | (            ) || |      | (   ) || (      | (      \n";
	std::cout << "| (__/  )| (___) || )   |  || (___) || (____/ | (___) || )   |  |  | (____/|/||____) || (____/| )   ( || )      | (____/\n";
	std::cout << "(______/ (_______)|/    )_)(_______)(_______/(_______)|/    )_)  (_______/||_______)(_______/|/     ||||/       (_______/\n";
}

void GameEngine::PrintArt2()
{
	std::cout << "\n\n\n";
	std::cout << "_______   _______  _______  _______    _______           _______   _______ \n";
	std::cout << "(  ____ |(  ___  )(       )(  ____ ||  (  ___  )| |     /|(  ____ (  ____ )\n";
	std::cout << "| (    | | (   ) || () () || (    ||/  | (   ) || )   ( || (    ||/|(    )|\n";
	std::cout << "| |      | (___) || || || || (__      | |   | | | |   | || (__    | (____)|\n";
	std::cout << "| | ____ |  ___  || |(_)| ||  __)     | |   | | ( (   ) )|  __)   |    __)\n";
	std::cout << "| | ||_  )| (   ) |||   | || (        | |   | | | ||_/ / | (      | (|(   \n";
	std::cout << "| (___) || )   ( || )   ( || (____/||  | (___) |  |   /  | (____/|||) ||__\n";
	std::cout << "(_______)|/     ||||     |||(_______/  (_______)   |_/   (_______/|/   ||__/\n";

}

void GameEngine::YouLostGame()
{
    PrintArt();
    PrintArt2();
    std::cout << "\n\nYou have lost. Better luck next time..." << "\n\n";
    return;
}

void GameEngine::YouWinGame()
{
	PrintArt();
	PrintArt2();
	std::cout << "\n\nYou have won! Congratulations!" << "\n\n";
	return;
}

void GameEngine::startGame()
{
	PrintArt();

	std::cout << "Welcome to the Dungeon Escape Game!" << "\n\n";

	int playerHealth = 100;
	int totalRooms = 15;
	std::string playerName;

	std::cout << "Enter player name: ";
	std::cin >> playerName;

	// Generate rooms
	std::vector<Room> rooms;
	for (int i = 1; i <= totalRooms; ++i)
	{
		rooms.emplace_back(i);
	}

    // Generate a random spawn room for the player
    int spawnRoomIndex = rand() % totalRooms;
    Room spawnRoom = rooms[spawnRoomIndex];

    // Generate a random winning room making sure it is at least 7 numbers away from the spawn room
    int winningRoomIndex;
    do
    {
        winningRoomIndex = rand() % totalRooms;
    } while (abs(winningRoomIndex - spawnRoomIndex) < 7);
    Room winningRoom = rooms[winningRoomIndex];

    // Create the player
    _playerHealth = playerHealth;
    _currentRoom = spawnRoom.getId();
    _winningRoom = winningRoom.getId();

    Player player;
    player.setPlayerName(playerName);
    player.setPlayerHealth(playerHealth);

    while (_currentRoom != _winningRoom)
    {
        PrintArt();

        std::cout << "Player name: " << player.getPlayerName() << "\n";
        std::cout << "Player health: " << player.getPlayerHealth() << "\n";
        std::cout << "Player current room: " << _currentRoom << "\n\n";

        char choice;

        std::cout << "Choose a door to move to the next room (A, W, D): ";
        std::cin >> choice;

        switch (choice)
        {
        case 'A':
        case 'W':
        case 'D':
            _currentRoom++;
            break;
        default:
            std::cout << "Invalid choice!" << "\n";
            continue;
        }

        if (_currentRoom == _winningRoom)
        {
			YouWinGame();
            break;
        }

        // Check for trap or healing potion
        if (rand() % 3 == 0)
        {
            // Trap
            int damage = rand() % 21 + 20; // Random damage between 20 and 40
            player.setPlayerHealth(player.getPlayerHealth() - damage);
            std::cout << "You encountered a trap and lost " << damage << " health!" << "\n";
        }
        else if (rand() % 3 == 1)
        {
            if (player.getPlayerHealth() >= 100)
            {
                std::cout << "You have found a potion, but your health is maxed out." << "\n";
            }
            else
            {
                // Healing potion
                int heal = rand() % 16 + 15; // Random healing between 15 and 30
                player.setPlayerHealth(player.getPlayerHealth() + heal);
                std::cout << "You found a healing potion and gained " << heal << " health!" << "\n";
            }
        }
        else
        {
            std::cout << "You have found an empty room." << "\n";
        }

        if (player.getPlayerHealth() == 0 || player.getPlayerHealth() < 0)
        {
            YouLostGame();
            return;
        }
    }
}




