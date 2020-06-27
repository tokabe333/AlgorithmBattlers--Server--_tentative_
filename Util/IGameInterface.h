#ifndef INCLUDE_GUARD_IGAMEINTERFACE
#define INCLUDE_GUARD_IGAMEINTERFACE

#include "common.h"

class IGame {
 public:
  int* Scores;
  string* PlayerNames;

  virtual void Show();

  virtual bool TurnProcess(int player);

  virtual void EndProcess();
};

#endif