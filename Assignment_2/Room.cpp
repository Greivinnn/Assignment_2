#include <string>
#include <iostream>
#include "Room.h"

using namespace Assignment_2;

Room::Room(int id)
    : _id(id)
{
}

int Room::getId() const
{
    return _id;
}
