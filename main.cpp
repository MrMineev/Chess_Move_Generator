#include "libraries/board.h"

using namespace std;

signed main() {
  Board b;
  b.set_standard();
  vector<MOVE> res = b.get_legal_moves();
  for (MOVE r : res) {
    cout << r.first.first << " " << r.first.second << ", " << r.second.first << " " << r.second.second << endl;
  }
  cout << "NUMBER OF LEGAL MOVES = " << b.get_legal_moves().size() << endl;
  return 0;
}


