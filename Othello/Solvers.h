#ifndef INCLUDE_GUARD_SOLVERS
#define INCLUDE_GUARD_SOLVERS
#include "../Util/Common.h"

class MonkeySolver : SolverInterface {
 private:
 public:
  MonkeySolver() { randd(time(0)); }
  void Solve(int* out_x, int* out_y, const BoardInfo* info);
  ull Solve(ull cand);
}

#endif