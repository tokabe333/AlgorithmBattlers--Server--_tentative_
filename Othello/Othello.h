#include "../Util/Common.h"
#include "../Util/IGameInterface.h"

class Othello {
 public:
  ull WhiteBoard;
  ull BlackBoard;
  int ElapsedTurn;
  int Scores;

 private:
  random_device RD{};
  ull (*WhiteSolver)(ull);
  ull (*BlackSolver)(ull);

  void Show(ull black, ull white);

 public:
  Othello(ull (*whiteSolver)(ull), ull (*blackSolver)(ull));
  void Show();

  ull Candidate(ull black, ull white, bool turn);
  void PutStone(ull *black, ull *white, bool turn, ull point);
  int Count(ull t);
  ull BitCount(ull player);

  ull Player1Sover(ull cand);
};
