#include "Board.h"


Board :: Board(Board& other){//copy c'tor
    this -> num = other.num;
    this -> mat = new Character*[other.num];
    
    for (int i = 0; i < this->num; ++i){
        this->mat[i] = new Character[other.num];
    }
    for(int i = 0; i < this->num; i++){
        for(int j = 0; j < this->num; j++){
            this->mat[i][j] = other.mat[i][j];
        }
    }
}

Board :: Board (int n){
    this-> num = n;
    this -> mat = new Character*[this->num];
    
    for (int i = 0; i < this->num; ++i)
        this->mat[i] = new Character[this->num];

    init();//initial Board
}

Board :: ~Board(){
    del();
}

void Board:: del(){  //distructor

    for (int i = 0; i < num; i++){ //free
	    delete[] mat[i];
    }
	delete[] mat;
}

void Board :: init(){ //to initial board
    for (int x = 0; x < this->num; ++x){
        for (int y = 0; y < this->num; ++y){
            this->mat[x][y] = this->space;
        }
    }
}

int Board :: size() const{
    return num;
}

Character& Board :: operator [] (Coordinate c) {
    
    if (c.getRow() >= this -> num || c.getColumn() >= this -> num || c.getRow() < 0 || c.getColumn() < 0 ){
        IllegalCoordinateException coordinateException;
        coordinateException.set_f(c.getRow());
        coordinateException.set_s(c.getColumn());
        throw coordinateException;
    }
    return this -> mat[c.getRow()][c.getColumn()];
}

Character Board :: operator [] (Coordinate c) const {//read only
    return this -> mat[c.getRow()][c.getColumn()];
}

Board& Board::operator=(char place){//play turn
    if (place == '.'){
        init();
    }
    
    else if (place != 'X' && place != 'O' && place != '.'){
        IllegalCharException charException;
        charException.set_t(place);
        throw charException;
    }
    
    else{
        for(int i = 0; i < num; i++)
            for(int j = 0; j < num; j++)
                mat[i][j] = place;
    }
    
    return *this;
}

Board& Board::operator=(const Board& obj){//copy Board

    if (this==&obj){
        return *this;
    }
    
    del();
    
    num = obj.num;
    mat = new Character*[num];  
	for (int i = 0; i < num; i++){
		mat[i] = new Character[num];
        for (int j = 0; j < num; j++) 
            mat[i][j] = obj.mat[i][j];
    }
    return *this;
}


bool operator== (Board const& x, Board const& y){
    if (x.num != y.num)
        return false;

    for (int i = 0; i < x.num ; ++i) {
        for (int j = 0; j < x.num ; ++j) {
            if(x.mat[i][j].getChar() != y.mat[i][j].getChar())
                return false;
        }
    }
    return true;
}

bool operator!= (Board const& x, Board const& y){
    if (x.num != y.num)
        return true;

    for (int i = 0; i <x.num ; ++i) {
        for (int j = 0; j <x.num ; ++j) {
            if(x.mat[i][j].getChar() != y.mat[i][j].getChar())
                return true;
        }
    }
    return false;
}
