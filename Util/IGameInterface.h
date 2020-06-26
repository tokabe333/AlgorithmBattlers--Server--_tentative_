#include "common.h"

class IGame {
 public:
  int* Scores;
  string* PlayerNames;

  virtual void Show();

  virtual void TurnProcess(int player);
};