#ifndef INCLUDE_GUARD_OTHELLO
#define INCLUDE_GUARD_OTHELLO

#include "../Util/Common.h"
#include "../Util/IGameInterface.h"

// class Othello : public IGame {
class Othello : public IGame {
 public:
  ull white_board;     // 白の盤面
  ull black_board;     // 黒の盤面
  int elapsed_turn;    // 経過ターン
  int** board_data;    // 盤面情報(ソルバーに上げる)
  int board_size = 8;  // 盤面サイズ(今の所8固定)

 private:
  ull (*white_solver)(ull);  // 白のソルバー
  ull (*black_sover)(ull);   // 黒のソルバー

  void show(ull black, ull white);

 public:
  // コンストラクタ，各プレイヤーのソルバーを渡して初期化
  Othello(ull (*whiteSolver)(ull), ull (*blackSolver)(ull));

  // @override 盤面表示くん
  void show();

  // 候補手表示
  ull candidate(bool turn);

  // 石を置く処理
  void PutStone(bool turn, ull point);

  // 各ターンの処理 false→まだ試合続行 true→試合終了
  bool turn_process(int player);

  // 終了処理
  void end_process();

  // ソルバーに渡すデータを作る
  void translate_bit2array();

  // static:----------------------------------------

  // 立っているビットを数える
  static int count(ull t);

  // 石の数判定
  static ull bit_count(ull player);
};

#endif