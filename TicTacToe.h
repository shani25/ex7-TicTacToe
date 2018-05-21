#pragma once

#include "Board.h"
#include "Champion.h"
#include "Player.h"
#include "DummyPlayers.h"
#include "Exceptions.h"
#include <typeinfo>

using namespace std;

class TicTacToe{
    
private:
    Player* xPlayer;
    Player* oPlayer;
    Board b;
    int boardSize;
    char win;
    char turn;

public:

    TicTacToe(int);
    void play(Player& xPlayer, Player& oPlayer);
    Player& winner() const;
    const Board& board() const;
    bool checkWin() const;
    bool checkRows() const;
    bool checkCols() const;
    bool check2Diagonal() const;
    bool check1Diagonal() const;

    void setWinner(char w){ this -> win = w;}
    void setTurn(char turn){ this->turn = turn;}
    int getBoardSize() const{ return this->boardSize;}
    char getWinner() const{ return this->win;}
    char getTurn() const{ return this->turn;}
};
