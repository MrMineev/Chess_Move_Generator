#include "libraries/board.h"

using namespace std;

signed main() {
  Board b;
  b.set_standard();
  cout << "LEGAL MOVES = " << b.get_legal_moves().size() << endl;
  return 0;
}


