#pragma once
#include <string>
#include <iostream>
#include "Room.h"
#include "Player.h"
#include <vector>

namespace Assignment_2
{
	class GameEngine
	{
	public:
		GameEngine();
		~GameEngine();

		void startGame();
		void endGame();

	private:
		std::string _playerName2;
		int _playerHealth;
		int _currentRoom;
		int _winningRoom;
		std::vector<Room> _rooms;
	};
}