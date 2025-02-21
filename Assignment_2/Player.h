#pragma once
#include <string>
#include <iostream>

namespace Assignment_2
{
	class GameEngine;

	class Player
	{
	public:
		Player();
		~Player();

		std::string getPlayerName() const;
		int getPlayerHealth() const;

		void setPlayerName(std::string playerName);
		void setPlayerHealth(int playerHealth);

	private:
		std::string _playerName;
		int _playerHealth;
		std::string _currentRoom;

		friend class GameEngine;
	};
}