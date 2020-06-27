#include "Othello.h"

time_t timet = time(0);
mt19937 randd(timet);
ull Monkey(ull cand) {
  int point = randd() % Othello::count(cand);
  int index = 0;
  ull counta = 1;
  for (int i = 0; i < 64; ++i) {
    if (counta & cand) {
      if (index == point) {
        return counta;
      } else {
        index++;
      }
    }
    counta <<= 1;
  }
}

int main() {
  // Solver solve = Monkey;
  cout << "‚ñ‚²‚ñ‚²" << endl;
  Othello othello(Monkey, Monkey);
  cout << "ƒQ[ƒ€ŠJŽn" << endl;

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