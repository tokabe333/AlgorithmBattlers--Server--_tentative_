#ifndef INCLUDE_GUARD_IGAMEINTERFACE
#define INCLUDE_GUARD_IGAMEINTERFACE

#include "common.h"

class IGame {
 public:
  int* scores;
  string* player_names;

  virtual void show();

  virtual bool turn_process(int player);

  virtual void end_process();
};

#endif