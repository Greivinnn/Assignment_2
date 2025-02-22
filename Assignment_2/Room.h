#pragma once
#include <string>
#include <iostream>

namespace Assignment_2
{
	class GameEngine;

	class Room
	{
	public:
		Room(bool isExit, int roomNumber);
		~Room();

		void setRoomNumber(int roomNumber);
		int getRoomNumber() const;
		std::string getItem() const;
		bool hasTrap() const;
		void setTrap(bool trap);
		bool hasHealingPotion() const;
		void setHealingPotion(bool item);
		bool getIsExit() const;
		void setIsExit(bool isExit); 

	private:
		bool _item;
		bool _trap;
		bool _isExit = false;
		int _roomNumber;

		friend class GameEngine;
	};
}