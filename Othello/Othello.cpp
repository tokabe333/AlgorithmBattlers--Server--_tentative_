#include "Othello.h"

void Othello::Show() {
  this->Show(this->BlackBoard, this->WhiteBoard);
}  // End_Method

void Othello::Show(ull black, ull white) {
  ull counta = 0x8000000000000000;
  for (int i = 1; i <= 64; ++i) {
    if (counta & black) {
      cout << "›";
    } else if (counta & white) {
      cout << "œ";
    } else {
      cout << " ";
    }
    counta >>= 1;
    if (!(i % 8)) {
      cout << endl;
    }
  }
  // cout << endl;
}  // End_Method

ull Othello::Candidate(ull black, ull white, bool turn) {
  ull cand = 0;
  ull player = black * turn + white * (!turn);
  ull opponent = black * (!turn) + white * turn;

  ull wall = 0x7e7e7e7e7e7e7e7e;
  ull o = opponent & wall;
  ull left = o & (player << 1);
  left |= o & (left << 1);
  left |= o & (left << 1);
  left |= o & (left << 1);
  left |= o & (left << 1);
  left |= o & (left << 1);
  cand = (left << 1) & ~(player | opponent);

  ull right = o & (player >> 1);
  right |= o & (right >> 1);
  right |= o & (right >> 1);
  right |= o & (right >> 1);
  right |= o & (right >> 1);
  right |= o & (right >> 1);
  cand |= (right >> 1) & ~(player | opponent);

  wall = 0x00FFFFFFFFFFFF00;
  o = opponent & wall;
  ull up = o & (player << 8);
  up |= o & (up << 8);
  up |= o & (up << 8);
  up |= o & (up << 8);
  up |= o & (up << 8);
  up |= o & (up << 8);
  cand |= (up << 8) & ~(player | opponent);

  wall = 0x00FFFFFFFFFFFF00;
  o = opponent & wall;
  ull down = o & (player >> 8);
  down |= o & (down >> 8);
  down |= o & (down >> 8);
  down |= o & (down >> 8);
  down |= o & (down >> 8);
  down |= o & (down >> 8);
  cand |= (down >> 8) & ~(player | opponent);

  wall = 0x007e7e7e7e7e7e00;
  o = opponent & wall;
  ull rightup = o & (player << 7);
  rightup |= o & (rightup << 7);
  rightup |= o & (rightup << 7);
  rightup |= o & (rightup << 7);
  rightup |= o & (rightup << 7);
  rightup |= o & (rightup << 7);
  cand |= (rightup << 7) & ~(player | opponent);

  ull rightdown = o & (player >> 9);
  rightdown |= o & (rightdown >> 9);
  rightdown |= o & (rightdown >> 9);
  rightdown |= o & (rightdown >> 9);
  rightdown |= o & (rightdown >> 9);
  rightdown |= o & (rightdown >> 9);
  cand |= (rightdown >> 9) & ~(player | opponent);

  ull leftdown = o & (player >> 7);
  leftdown |= o & (leftdown >> 7);
  leftdown |= o & (leftdown >> 7);
  leftdown |= o & (leftdown >> 7);
  leftdown |= o & (leftdown >> 7);
  leftdown |= o & (leftdown >> 7);
  cand |= (leftdown >> 7) & ~(player | opponent);

  ull leftup = o & (player << 9);
  leftup |= o & (leftup << 9);
  leftup |= o & (leftup << 9);
  leftup |= o & (leftup << 9);
  leftup |= o & (leftup << 9);
  leftup |= o & (leftup << 9);
  cand |= (leftup << 9) & ~(player | opponent);

  return cand;
}  // End_Method

void Othello::PutStone(ull *black, ull *white, bool turn, ull point) {
  ull player = *black * turn + *white * (!turn) + point;
  ull opponent = *black * (!turn) + *white * turn;

  ull wall = 0x7e7e7e7e7e7e7e7e;
  ull o = opponent & wall;
  ull left = o & (point << 1);
  left |= o & (left << 1);
  left |= o & (left << 1);
  left |= o & (left << 1);
  left |= o & (left << 1);
  left |= o & (left << 1);
  left *= !!(player & (left << 1));

  ull right = o & (point >> 1);
  right |= o & (right >> 1);
  right |= o & (right >> 1);
  right |= o & (right >> 1);
  right |= o & (right >> 1);
  right |= o & (right >> 1);
  right *= !!(player & (right >> 1));

  wall = 0x00FFFFFFFFFFFF00;
  o = opponent & wall;
  ull up = o & (point << 8);
  up |= o & (up << 8);
  up |= o & (up << 8);
  up |= o & (up << 8);
  up |= o & (up << 8);
  up |= o & (up << 8);
  up *= !!(player & (up << 8));

  wall = 0x00FFFFFFFFFFFF00;
  o = opponent & wall;
  ull down = o & (point >> 8);
  down |= o & (down >> 8);
  down |= o & (down >> 8);
  down |= o & (down >> 8);
  down |= o & (down >> 8);
  down |= o & (down >> 8);
  down *= !!(player & (down >> 8));

  wall = 0x007e7e7e7e7e7e00;
  o = opponent & wall;
  ull rightup = o & (point << 7);
  rightup |= o & (rightup << 7);
  rightup |= o & (rightup << 7);
  rightup |= o & (rightup << 7);
  rightup |= o & (rightup << 7);
  rightup |= o & (rightup << 7);
  rightup *= !!(player & (rightup << 7));

  ull leftdown = o & (point >> 7);
  leftdown |= o & (leftdown >> 7);
  leftdown |= o & (leftdown >> 7);
  leftdown |= o & (leftdown >> 7);
  leftdown |= o & (leftdown >> 7);
  leftdown |= o & (leftdown >> 7);
  leftdown *= !!(player & (leftdown >> 7));

  ull rightdown = o & (point >> 9);
  rightdown |= o & (rightdown >> 9);
  rightdown |= o & (rightdown >> 9);
  rightdown |= o & (rightdown >> 9);
  rightdown |= o & (rightdown >> 9);
  rightdown |= o & (rightdown >> 9);
  rightdown *= !!(player & (rightdown >> 9));

  ull leftup = o & (point << 9);
  leftup |= o & (leftup << 9);
  leftup |= o & (leftup << 9);
  leftup |= o & (leftup << 9);
  leftup |= o & (leftup << 9);
  leftup |= o & (leftup << 9);
  leftup *= !!(player & (leftup << 9));

  ull rev = up | down | left | right | rightup | rightdown | leftdown | leftup;
  player |= rev;
  opponent -= rev;
  *black = player * turn + opponent * (!turn);
  *white = opponent * (turn) + player * (!turn);
}  // End_Method

int Othello::Count(ull t) {
  t = (t & 0x5555555555555555) + ((t & 0xAAAAAAAAAAAAAAAA) >> 1);
  t = (t & 0x3333333333333333) + ((t & 0xCCCCCCCCCCCCCCCC) >> 2);
  t = (t & 0x0F0F0F0F0F0F0F0F) + ((t & 0xF0F0F0F0F0F0F0F0) >> 4);
  t = (t & 0x00FF00FF00FF00FF) + ((t & 0xFF00FF00FF00FF00) >> 8);
  t = (t & 0x0000FFFF0000FFFF) + ((t & 0xFFFF0000FFFF0000) >> 16);
  t = (t & 0x00000000FFFFFFFF) + ((t & 0xFFFFFFFF00000000) >> 32);
  return t;
}  // End_Method

int count(ull t) {
  t = (t & 0x5555555555555555) + ((t & 0xAAAAAAAAAAAAAAAA) >> 1);
  t = (t & 0x3333333333333333) + ((t & 0xCCCCCCCCCCCCCCCC) >> 2);
  t = (t & 0x0F0F0F0F0F0F0F0F) + ((t & 0xF0F0F0F0F0F0F0F0) >> 4);
  t = (t & 0x00FF00FF00FF00FF) + ((t & 0xFF00FF00FF00FF00) >> 8);
  t = (t & 0x0000FFFF0000FFFF) + ((t & 0xFFFF0000FFFF0000) >> 16);
  t = (t & 0x00000000FFFFFFFF) + ((t & 0xFFFFFFFF00000000) >> 32);
  return t;
}

random_device rd{};
ull Monkey(ull cand) {
  int point = rd() % count(cand);
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
  return 0;
}

int main() {
  // Solver solve = Monkey;
  cout << "fjkdlaf;" << endl;
  Othello ot([](ull n) { return n * 334; });
  cout << "jfk;ad" << endl;
  cout << ot.WhiteSolver(334) << endl;
  return 0;
}