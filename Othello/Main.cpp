#include "../Util/Common.h"

time_t start_time = time(0);
mt19937 random(time(0));

ull Monkey(ull cand) {
  int point = random() % Othello::count(cand);
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
  cout << "�񂲂�" << endl;
  Othello othello(Monkey, Monkey);
  cout << "�Q�[���J�n" << endl;

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