#include <string>
#include <iostream>
#include "Room.h"

using namespace Assignment_2;

Room::Room(std::string item, std::string trap, bool isExit, int roomNumber)
	: _item(item), _trap(trap), _isExit(isExit), _roomNumber(roomNumber)
{
}

Room::~Room()
{
}

void Room::setRoomNumber(int roomNumber)
{
	_roomNumber = roomNumber;
}

int Room::getRoomNumber() const
{
	return _roomNumber;
}

std::string Room::getItem() const
{
	return _item;
}

void Room::setItem(std::string item)
{
	_item = item;
}

std::string Room::getTrap() const
{
	return _trap;
}

void Room::setTrap(std::string trap)
{
	_trap = trap;
}

bool Room::getIsExit() const
{
	return _isExit;
}

void Room::setIsExit(bool isExit)
{
	_isExit = isExit;
}