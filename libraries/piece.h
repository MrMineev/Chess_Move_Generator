#pragma once

#include <iostream>

using namespace std;

class Piece {
 private:
   int type;

 public:
   static const int EMPTY = -1;
   static const int PAWN = 0;
   static const int BISHOP = 1;
   static const int ROOK = 2;
   static const int KING = 3;
   static const int QUEEN = 4;
   static const int KNIGHT = 5;

   Piece(int _type) : type(_type) {}

   int get_type() {
     return type;
   }

   void set_type(int _type) {
     type = _type;
   }
};


