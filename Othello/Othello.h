#include "../Util/Common.h"
#include "../Util/IGameInterface.h"

// class Othello : public IGame {
class Othello {
 public:
  ull WhiteBoard;   // 白の盤面
  ull BlackBoard;   // 黒の盤面
  int ElapsedTurn;  // 経過ターン

 private:
  ull (*WhiteSolver)(ull);
  ull (*BlackSolver)(ull);

  void Show(ull black, ull white);

 public:
  // コンストラクタ，各プレイヤーのソルバーを渡して初期化
  Othello(ull (*whiteSolver)(ull), ull (*blackSolver)(ull));

  // @override 盤面表示くん
  void Show();

  // 候補手表示
  ull Candidate(bool turn);

  // 石を置く処理
  void PutStone(bool turn, ull point);

  // 各ターンの処理 false→まだ試合続行 true→試合終了
  bool TurnProcess(int player);

  // 終了処理
  void EndProcess();

  // static:----------------------------------------

  //
  static int Count(ull t);

  // 石の数判定
  static ull BitCount(ull player);
};
