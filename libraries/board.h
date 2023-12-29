#pragma once

#include <iostream>
#include <vector>

#include "piece.h"

using namespace std;

#define MP make_pair

typedef pair<pair<int, int>, pair<int, int>> MOVE;

class Board {
 private:
   vector<vector<Piece>> board;

 public:
  Board() {
    board.resize(8, vector<Piece>(8, Piece(-1)));
  }

  // first - x, second - y

  void set_standard() {
    board[0][0].set_type(Piece::ROOK); 
    board[0][1].set_type(Piece::KNIGHT); 
    board[0][2].set_type(Piece::BISHOP); 
    board[0][3].set_type(Piece::QUEEN); 
    board[0][4].set_type(Piece::KING); 
    board[0][5].set_type(Piece::BISHOP); 
    board[0][6].set_type(Piece::KNIGHT); 
    board[0][7].set_type(Piece::ROOK); 

    for (int i = 0; i < 8; i++) {
      board[1][i].set_type(Piece::PAWN);
    }

    for (int i = 0; i < 8; i++) {
      board[6][i].set_type(Piece::PAWN);
    }

    board[7][0].set_type(Piece::ROOK); 
    board[7][1].set_type(Piece::KNIGHT); 
    board[7][2].set_type(Piece::BISHOP); 
    board[7][3].set_type(Piece::QUEEN); 
    board[7][4].set_type(Piece::KING); 
    board[7][5].set_type(Piece::BISHOP); 
    board[7][6].set_type(Piece::KNIGHT); 
    board[7][7].set_type(Piece::ROOK); 
  }

  vector<MOVE> bishop_moves(int old_x, int old_y) {
    vector<MOVE> pseudo_legal;
    int x = old_x;
    int y = old_y;
    while (x < 8 && y < 8) {
      if (board[x][y].get_type() != Piece::EMPTY) {
        pseudo_legal.push_back(MP(MP(old_x, old_y), MP(x, y)));
      } else {
        break;
      }
      x++;
      y++;
    }

    x = old_x;
    y = old_y;
    while (x > -1 && y > -1) {
      if (board[x][y].get_type() != Piece::EMPTY) {
        pseudo_legal.push_back(MP(MP(old_x, old_y), MP(x, y)));
      } else {
        break;
      }
      x--;
      y--;
    }

    x = old_x;
    y = old_y;
    while (x > -1 && y < 8) {
      if (board[x][y].get_type() != Piece::EMPTY) {
        pseudo_legal.push_back(MP(MP(old_x, old_y), MP(x, y)));
      } else {
        break;
      }
      x--;
      y++;
    }

    x = old_x;
    y = old_y;
    while (x < 8 && y > -1) {
      if (board[x][y].get_type() != Piece::EMPTY) {
        pseudo_legal.push_back(MP(MP(old_x, old_y), MP(x, y)));
      } else {
        break;
      }
      x++;
      y--;
    }

    return pseudo_legal;
  }

  vector<MOVE> rook_moves(int old_x, int old_y) {
    vector<MOVE> pseudo_legal;
    int x = old_x;
    int y = old_y;
    while (y < 8) {
      if (board[x][y].get_type() != Piece::EMPTY) {
        pseudo_legal.push_back(MP(MP(old_x, old_y), MP(x, y)));
      } else {
        break;
      }
      y++;
    }

    x = old_x;
    y = old_y;
    while (y > -1) {
      if (board[x][y].get_type() != Piece::EMPTY) {
        pseudo_legal.push_back(MP(MP(old_x, old_y), MP(x, y)));
      } else {
        break;
      }
      y--;
    }

    x = old_x;
    y = old_y;
    while (x > -1) {
      if (board[x][y].get_type() != Piece::EMPTY) {
        pseudo_legal.push_back(MP(MP(old_x, old_y), MP(x, y)));
      } else {
        break;
      }
      x--;
    }

    x = old_x;
    y = old_y;
    while (x < 8) {
      if (board[x][y].get_type() != Piece::EMPTY) {
        pseudo_legal.push_back(MP(MP(old_x, old_y), MP(x, y)));
      } else {
        break;
      }
      x++;
    }

    return pseudo_legal;
  }

  vector<MOVE> knight_moves(int x, int y) {
    vector<MOVE> res;

    if (x + 2 < 8 && y + 1 < 8 && board[x + 2][y + 1].get_type() != Piece::EMPTY) {
      res.push_back(MP(MP(x, y), MP(x + 2, y + 1)));
    }

    if (x + 2 < 8 && y - 1 > -1 && board[x + 2][y - 1].get_type() != Piece::EMPTY) {
      res.push_back(MP(MP(x, y), MP(x + 2, y - 1)));
    }

    if (x + 1 < 8 && y + 2 < 8 && board[x + 1][y + 2].get_type() != Piece::EMPTY) {
      res.push_back(MP(MP(x, y), MP(x + 1, y + 2)));
    }

    if (x + 1 < 8 && y - 2 > -1 && board[x + 1][y - 2].get_type() != Piece::EMPTY) {
      res.push_back(MP(MP(x, y), MP(x + 1, y - 2)));
    }

    if (x - 1 > -1 && y + 2 < 8 && board[x - 1][y + 2].get_type() != Piece::EMPTY) {
      res.push_back(MP(MP(x, y), MP(x - 1, y + 2)));
    }

    if (x - 1 > -1 && y - 2 > -1 && board[x - 1][y - 2].get_type() != Piece::EMPTY) {
      res.push_back(MP(MP(x, y), MP(x - 1, y - 2)));
    }

    if (x - 2 > -1 && y + 1 < 8 && board[x - 2][y + 1].get_type() != Piece::EMPTY) {
      res.push_back(MP(MP(x, y), MP(x - 2, y + 1)));
    }

    if (x - 2 > -1 && y - 1 > -1 && board[x - 2][y - 1].get_type() != Piece::EMPTY) {
      res.push_back(MP(MP(x, y), MP(x - 2, y + 1)));
    }

    return res;
  }

  vector<MOVE> queen_moves(int x, int y) {
    vector<MOVE> bishop = bishop_moves(x, y);
    vector<MOVE> rook = rook_moves(x, y);
    vector<MOVE> res;
    for (int i = 0; i < bishop.size(); i++) {
      res.push_back(bishop[i]);
    }
    for (int i = 0; i < rook.size(); i++) {
      res.push_back(rook[i]);
    }
  }

  vector<MOVE> king_moves(int x, int y) {
    vector<MOVE> res;
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
      }
    }
  }

  vector<MOVE> pawn_moves(int x, int y) {
  }
};


