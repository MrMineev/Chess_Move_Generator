#define _GLIBCXX_DEBUG

#include "libraries/board.h"

using namespace std;

signed main() {
  Board b;
  b.set_standard();
  cout << "LEGAL MOVES = \n" << b.get_legal_moves().size() << endl;
  return 0;
}


