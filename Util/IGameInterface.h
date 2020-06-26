#include "common.h"

class IGame {
 public:
  int* Scores;
  string* PlayerNames;

  virtual void Show();

  virtual bool TurnProcess(int player);

  virtual void EndProcess();
};