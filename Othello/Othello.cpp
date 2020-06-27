#include "Othello.h"

Othello::Othello(ull (*whiteSolver)(ull), ull (*blackSolver)(ull)) {
  this->white_solver = whiteSolver;
  this->black_sover = blackSolver;

  this->black_board = 0x0000000810000000;
  this->white_board = 0x0000001008000000;

  this->board_data = new int*[this->board_size];
  for (int i = 0; i < this->board_size; ++i) {
    this->board_data[i] = new int[this->board_size];
    for (int j = 0; j < this->board_size; ++j) {
      this->board_data[i][j] = 0;
    }  // End_For
  }    // End_For
}  // End_Method

void Othello::show() {
  this->show(this->black_board, this->white_board);
}  // End_Method

void Othello::show(ull black, ull white) {
  ull counta = 0x8000000000000000;
  for (int i = 1; i <= 64; ++i) {
    if (counta & black) {
      cout << "Åõ";
    } else if (counta & white) {
      cout << "Åú";
    } else {
      cout << "Å†";
    }
    counta >>= 1;
    if (!(i % 8)) {
      cout << endl;
    }
  }
  // cout << endl;
}  // End_Method

ull Othello::candidate(bool turn) {
  ull cand = 0;
  ull player = this->black_board * turn + this->white_board * (!turn);
  ull opponent = this->black_board * (!turn) + this->white_board * turn;

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

void Othello::PutStone(bool turn, ull point) {
  ull player = this->black_board * turn + this->white_board * (!turn) + point;
  ull opponent = this->black_board * (!turn) + this->white_board * turn;

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
  this->black_board = player * turn + opponent * (!turn);
  this->white_board = opponent * (turn) + player * (!turn);
}  // End_Method

int Othello::count(ull t) {
  t = (t & 0x5555555555555555) + ((t & 0xAAAAAAAAAAAAAAAA) >> 1);
  t = (t & 0x3333333333333333) + ((t & 0xCCCCCCCCCCCCCCCC) >> 2);
  t = (t & 0x0F0F0F0F0F0F0F0F) + ((t & 0xF0F0F0F0F0F0F0F0) >> 4);
  t = (t & 0x00FF00FF00FF00FF) + ((t & 0xFF00FF00FF00FF00) >> 8);
  t = (t & 0x0000FFFF0000FFFF) + ((t & 0xFFFF0000FFFF0000) >> 16);
  t = (t & 0x00000000FFFFFFFF) + ((t & 0xFFFFFFFF00000000) >> 32);
  return t;
}  // End_Method

ull Othello::bit_count(ull player) {
  int size = 64;
  ull mask = 0x8000000000000000;
  int count = 0;

  for (int i = 0; i < size; ++i) {
    if ((mask & player) != 0) count += 1;
    // cout << "count:" << count << "   mask:" << mask << "  player:" << player
    // << "  and:" << (mask & player) << endl;
    mask = mask >> 1;
  }
  return count;
}

bool Othello::turn_process(int player) {
  ull cand = 0;
  bool turn = player == 1;
  while (true) {
    if (!Othello::count(cand)) {
      cand = this->candidate(turn);
      if (!Othello::count(cand)) {
        return true;
      }
    } else {
      cand = this->candidate(turn);
      if (!Othello::count(cand)) {
        continue;
      }
    }  // End_IfElse

    ull point = turn ? this->white_solver(cand) : this->black_sover(cand);
    this->PutStone(turn, point);
    return false;
  }  // End_While
}  // End_Method

void Othello::end_process() {
  int blackScore = Othello::bit_count(this->black_board);
  int whiteScore = Othello::bit_count(this->white_board);
  string win = whiteScore > blackScore ? "îí" : "çï";
  cout << (whiteScore == blackScore ? "à¯Ç´ï™ÇØ" : "win:" + win)
       << "    îí:" << whiteScore << " çï" << blackScore << endl;
}  // End_Method

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
  cout << "ÇÒÇ≤ÇÒÇ≤" << endl;
  Othello othello(Monkey, Monkey);
  cout << "ÉQÅ[ÉÄäJén" << endl;

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