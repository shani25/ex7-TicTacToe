#pragma once
#include <string>
#include "Coordinate.h"
#include "Board.h"

class Player{

public:
    char myChar;

    virtual const string name() const=0;
    virtual const Coordinate play(const Board& board)=0;
    char getChar(){return myChar;}
};
