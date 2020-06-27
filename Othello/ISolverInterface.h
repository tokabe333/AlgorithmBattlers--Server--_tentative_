#ifndef INCLUDE_GUARD_SOLVERINTERFACE
#define INCLUDE_GUARD_SOLVERINTERFACE
#include "../Util/Common.h"

typedef struct _XY {
  int X;
  int Y;
  _XY(int x, int y) : X(x), Y(y) {}
} XY, *PXY;

class SolverInterface {
  int** BoardData;
  vector<XY> Candidate;

  virtual void Solve(int* out_x, int* out_y);
};

#endif
