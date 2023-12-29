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
   int turn;

 public:
  Board() {
    board.resize(8, vector<Piece>(8, Piece(Piece::EMPTY, Piece::NEUTRAL)));
    turn = 0;
  }

  // first - row, second - column 

  void set_standard() {
    board[0][0].set(Piece::ROOK, Piece::WHITE); 
    board[0][1].set(Piece::KNIGHT, Piece::WHITE); 
    board[0][2].set(Piece::BISHOP, Piece::WHITE); 
    board[0][3].set(Piece::QUEEN, Piece::WHITE); 
    board[0][4].set(Piece::KING, Piece::WHITE); 
    board[0][5].set(Piece::BISHOP, Piece::WHITE); 
    board[0][6].set(Piece::KNIGHT, Piece::WHITE); 
    board[0][7].set(Piece::ROOK, Piece::WHITE); 

    for (int i = 0; i < 8; i++) {
      board[1][i].set(Piece::PAWN, Piece::WHITE);
    }

    for (int i = 0; i < 8; i++) {
      board[6][i].set(Piece::PAWN, Piece::BLACK);
    }

    board[7][0].set(Piece::ROOK, Piece::BLACK); 
    board[7][1].set(Piece::KNIGHT, Piece::BLACK); 
    board[7][2].set(Piece::BISHOP, Piece::BLACK); 
    board[7][3].set(Piece::QUEEN, Piece::BLACK); 
    board[7][4].set(Piece::KING, Piece::BLACK); 
    board[7][5].set(Piece::BISHOP, Piece::BLACK); 
    board[7][6].set(Piece::KNIGHT, Piece::BLACK); 
    board[7][7].set(Piece::ROOK, Piece::BLACK); 
  }

  vector<MOVE> bishop_moves(int old_x, int old_y) {
    vector<MOVE> pseudo_legal;
    int x = old_x + 1;
    int y = old_y + 1;
    while (x < 8 && y < 8) {
      if (board[x][y].get_type() == Piece::EMPTY) {
        pseudo_legal.push_back(MP(MP(old_x, old_y), MP(x, y)));
      } else {
        break;
      }
      x++;
      y++;
    }

    x = old_x - 1;
    y = old_y - 1;
    while (x > -1 && y > -1) {
      if (board[x][y].get_type() == Piece::EMPTY) {
        pseudo_legal.push_back(MP(MP(old_x, old_y), MP(x, y)));
      } else {
        break;
      }
      x--;
      y--;
    }

    x = old_x - 1;
    y = old_y + 1;
    while (x > -1 && y < 8) {
      if (board[x][y].get_type() == Piece::EMPTY) {
        pseudo_legal.push_back(MP(MP(old_x, old_y), MP(x, y)));
      } else {
        break;
      }
      x--;
      y++;
    }

    x = old_x + 1;
    y = old_y - 1;
    while (x < 8 && y > -1) {
      if (board[x][y].get_type() == Piece::EMPTY) {
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
    int y = old_y + 1;
    while (y < 8) {
      if (board[x][y].get_type() == Piece::EMPTY) {
        pseudo_legal.push_back(MP(MP(old_x, old_y), MP(x, y)));
      } else {
        break;
      }
      y++;
    }

    x = old_x;
    y = old_y - 1;
    while (y > -1) {
      if (board[x][y].get_type() == Piece::EMPTY) {
        pseudo_legal.push_back(MP(MP(old_x, old_y), MP(x, y)));
      } else {
        break;
      }
      y--;
    }

    x = old_x - 1;
    y = old_y;
    while (x > -1) {
      if (board[x][y].get_type() == Piece::EMPTY) {
        pseudo_legal.push_back(MP(MP(old_x, old_y), MP(x, y)));
      } else {
        break;
      }
      x--;
    }

    x = old_x + 1;
    y = old_y;
    while (x < 8) {
      if (board[x][y].get_type() == Piece::EMPTY) {
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

    if (x + 2 < 8 && y + 1 < 8 && board[x + 2][y + 1].get_type() == Piece::EMPTY) {
      res.push_back(MP(MP(x, y), MP(x + 2, y + 1)));
    }

    if (x + 2 < 8 && y - 1 > -1 && board[x + 2][y - 1].get_type() == Piece::EMPTY) {
      res.push_back(MP(MP(x, y), MP(x + 2, y - 1)));
    }

    if (x + 1 < 8 && y + 2 < 8 && board[x + 1][y + 2].get_type() == Piece::EMPTY) {
      res.push_back(MP(MP(x, y), MP(x + 1, y + 2)));
    }

    if (x + 1 < 8 && y - 2 > -1 && board[x + 1][y - 2].get_type() == Piece::EMPTY) {
      res.push_back(MP(MP(x, y), MP(x + 1, y - 2)));
    }

    if (x - 1 > -1 && y + 2 < 8 && board[x - 1][y + 2].get_type() == Piece::EMPTY) {
      res.push_back(MP(MP(x, y), MP(x - 1, y + 2)));
    }

    if (x - 1 > -1 && y - 2 > -1 && board[x - 1][y - 2].get_type() == Piece::EMPTY) {
      res.push_back(MP(MP(x, y), MP(x - 1, y - 2)));
    }

    if (x - 2 > -1 && y + 1 < 8 && board[x - 2][y + 1].get_type() == Piece::EMPTY) {
      res.push_back(MP(MP(x, y), MP(x - 2, y + 1)));
    }

    if (x - 2 > -1 && y - 1 > -1 && board[x - 2][y - 1].get_type() == Piece::EMPTY) {
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
    return res;
  }

  vector<MOVE> king_moves(int x, int y) {
    vector<MOVE> res;
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        if (i == 0 && j == 0) { continue; }

        if (!(x + i < 8 && x + i > -1 && y + i > -1 && y + i < 8)) {
          continue;
        }

        if (board[x][y].get_type() == Piece::EMPTY) {
          res.push_back(MP(MP(x, y), MP(x + i, y + j)));
        }
      }
    }
    
    return res;
  }

  vector<MOVE> pawn_moves(int x, int y) {
    vector<MOVE> res;
    if (board[x][y].get_color() == Piece::WHITE) {
      if (x == 1) {
        if (board[x + 2][y].get_type() == Piece::EMPTY && board[x + 1][y].get_type() == Piece::EMPTY) {
          res.push_back(MP(MP(x, y), MP(x + 2, y)));
        }
      }

      if (board[x + 1][y].get_type() == Piece::EMPTY) {
        res.push_back(MP(MP(x, y), MP(x + 1, y)));
      }

      if (y + 1 < 8 && board[x + 1][y + 1].get_color() == Piece::BLACK) {
        res.push_back(MP(MP(x, y), MP(x + 1, y + 1)));
      }

      if (y - 1 > -1 && board[x + 1][y - 1].get_color() == Piece::BLACK) {
        res.push_back(MP(MP(x, y), MP(x + 1, y - 1)));
      }
    } else if (board[x][y].get_color() == Piece::BLACK) {
      if (x == 6) {
        if (board[x - 2][y].get_type() == Piece::EMPTY && board[x - 1][y].get_type() == Piece::EMPTY) {
          res.push_back(MP(MP(x, y), MP(x - 2, y)));
        }
      }

      if (board[x - 1][y].get_type() == Piece::EMPTY) {
        res.push_back(MP(MP(x, y), MP(x - 1, y)));
      }

      if (y + 1 < 8 && board[x - 1][y + 1].get_color() == Piece::BLACK) {
        res.push_back(MP(MP(x, y), MP(x - 1, y + 1)));
      }

      if (y - 1 < 8 && board[x - 1][y - 1].get_color() == Piece::BLACK) {
        res.push_back(MP(MP(x, y), MP(x - 1, y - 1)));
      }
    }
    return res;
  }

  void add_to_array(vector<MOVE> *arr, vector<MOVE> addition) {
    for (int i = 0; i < (int)addition.size(); i++) {
      arr->push_back(addition[i]);
    }
  }

  vector<MOVE> get_legal_moves() {
    vector<MOVE> res;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (board[i][j].get_color() != turn) {
          continue;
        }
        if (board[i][j].get_type() == Piece::PAWN) {
          // cout << "PAWN = " << pawn_moves(i, j).size() << endl;
          add_to_array(&res, pawn_moves(i, j));
        } else if (board[i][j].get_type() == Piece::BISHOP) {
          // cout << "BISHOP = " << bishop_moves(i, j).size() << endl;
          add_to_array(&res, bishop_moves(i, j));
        } else if (board[i][j].get_type() == Piece::KNIGHT) {
          // cout << "KNIGHT = " << knight_moves(i, j).size() << endl;
          add_to_array(&res, knight_moves(i, j));
        } else if (board[i][j].get_type() == Piece::QUEEN) {
          // cout << "QUEEN = " << queen_moves(i, j).size() << endl;
          add_to_array(&res, queen_moves(i, j));
        } else if (board[i][j].get_type() == Piece::KING) {
          // cout << "KING = " << king_moves(i, j).size() << endl;
          add_to_array(&res, king_moves(i, j));
        } else if (board[i][j].get_type() == Piece::ROOK) {
          // cout << "ROOK = " << rook_moves(i, j).size() << endl;
          add_to_array(&res, rook_moves(i, j));
        }
      }
    }
    return res;
  }
};


