#pragma once
#include <string>
#include <iostream>

namespace Assignment_2
{
	class GameEngine;

	class Room
	{
	public:
		Room(std::string item, std::string trap, bool isExit, int roomNumber);
		~Room();

		int getRoomNumber() const;
		std::string getItem() const;
		void setItem(std::string item);
		std::string getTrap() const;
		void setTrap(std::string trap);
		bool getIsExit() const;
		void setIsExit(bool isExit);
		void setRoomNumber(int roomNumber);

	private:
		std::string _item;
		std::string _trap;
		bool _isExit = false;
		int _roomNumber;

		friend class GameEngine;
	};
}