#pragma once

#include <iostream>
#include <string>
#include <sstream>

#include "Exceptions.h" 
#include "Coordinate.h"
#include "Character.h"

using namespace std;


class Board{
  
    char space =  '.'; //for empty space
    char playerX = 'X'; 
    char playerO =  'O';
  
  
  public:
    int num;//numXnum
    Character** mat;
    
    Board(Board&);//copy c'tor
    Board (int);
    ~Board();
    void del();
    void init();
    int size() const;
    friend ostream& operator<<(ostream&, const Board&);
    Character& operator[](Coordinate);
    Character operator[](Coordinate) const;
    Board& operator=(const Board&);
    Board& operator=(char);
    friend bool operator== (Board const& x, Board const& y);
    friend bool operator!= (Board const& x, Board const& y);
    
};


inline ostream&  operator<<(ostream& out,const Board& board){
    for(int i = 0; i < board.num; i++){
        for(int j = 0; j < board.num; j++){
            out << board.mat[i][j].getChar();
        }
        out<<endl;
    }
    return out;
}
