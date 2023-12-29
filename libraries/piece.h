#pragma once

#include <iostream>

using namespace std;

class Piece {
 private:
   int type;
   int color;

 public:
   static const int WHITE = 0;
   static const int BLACK = 1;
   static const int NEUTRAL = 2;

   static const int EMPTY = -1;
   static const int PAWN = 0;
   static const int BISHOP = 1;
   static const int ROOK = 2;
   static const int KING = 3;
   static const int QUEEN = 4;
   static const int KNIGHT = 5;

   Piece(int _type, int _color) : type(_type), color(_color) {}

   int get_type() {
     return type;
   }

   int get_color() {
     return color;
   }

   void set(int _type, int _color) {
     color = _color;
     type = _type;
   }

   void set_color(int _color) {
     color = _color;
   }

   void set_type(int _type) {
     type = _type;
   }
};


