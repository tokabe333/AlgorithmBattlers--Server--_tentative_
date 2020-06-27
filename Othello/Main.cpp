#include "../Util/Common.h"



int main() {
  // Solver solve = Monkey;
  cout << "んごんご" << endl;
  Othello othello(Monkey, Monkey);
  cout << "ゲーム開始" << endl;

  for (int i = 0; i < 10; ++i) {
    int player = 1;
    while (!othello.turn_process(player)) {
      player *= -1;
    }
    othello.show();
    othello.end_process();
  }

  return 0;
}