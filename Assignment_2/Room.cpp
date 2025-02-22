#include <string>
#include <iostream>
#include "Room.h"

using namespace Assignment_2;

// Updated constructor to support traps and potions
Room::Room(bool isExit, int roomNumber)
    : _isExit(isExit), _roomNumber(roomNumber), _trap(false), _item(false)
{
    if (!isExit) // No trap or potion in the winning room
    {
        int chance = rand() % 3; // 0 = nothing, 1 = trap, 2 = potion
        if (chance == 1)
        {
            _trap = true;
        }
        else if (chance == 2)
        {
            _item = true;
        }
    }
}

Room::~Room()
{
}

// Room Number
void Room::setRoomNumber(int roomNumber)
{
    _roomNumber = roomNumber;
}

int Room::getRoomNumber() const
{
    return _roomNumber;
}

// Traps
bool Room::hasTrap() const
{
    return _trap;
}

void Room::setTrap(bool hasTrap)
{
    _trap = hasTrap;
}

// Healing Potions
bool Room::hasHealingPotion() const
{
    return _item;
}

void Room::setHealingPotion(bool hasHealingPotion)
{
    _item = hasHealingPotion;
}

// Exit Room
bool Room::getIsExit() const
{
    return _isExit;
}

void Room::setIsExit(bool isExit)
{
    _isExit = isExit;
}
