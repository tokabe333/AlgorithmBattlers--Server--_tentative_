#ifndef INCLUDE_GUARD_OTHELLO
#define INCLUDE_GUARD_OTHELLO

#include "../Util/Common.h"
#include "../Util/IGameInterface.h"

// class Othello : public IGame {
class Othello : public IGame {
 public:
  ull WhiteBoard;     // 白の盤面
  ull BlackBoard;     // 黒の盤面
  int ElapsedTurn;    // 経過ターン
  int** BoardData;    // 盤面情報(ソルバーに上げる)
  int BoardSize = 8;  // 盤面サイズ(今の所8固定)

 private:
  ull (*WhiteSolver)(ull);  // 白のソルバー
  ull (*BlackSolver)(ull);  // 黒のソルバー

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

  // ソルバーに渡すデータを作る
  void TranslateBitToArray();

  // static:----------------------------------------

  //
  static int Count(ull t);

  // 石の数判定
  static ull BitCount(ull player);
};

#endif