#pragma once
#include <string>
#include <iostream>

namespace Assignment_2
{
	class GameEngine;

    class Room
    {
    public:
        Room(int id);
        int getId() const;

    private:
        int _id;
        friend class GameEngine;
    };
}