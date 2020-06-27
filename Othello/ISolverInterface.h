#ifndef INCLUDE_GUARD_SOLVERINTERFACE
#define INCLUDE_GUARD_SOLVERINTERFACE
#include "../Util/Common.h"

typedef struct _XY {
  int x;
  int y;
  _XY(int xx, int yy) : x(xx), y(yy) {}
} XY, *PXY;

class SolverInterface {
  int** board_data;
  vector<XY> candidate;

  virtual void Solve(int* out_x, int* out_y);
};

#endif
