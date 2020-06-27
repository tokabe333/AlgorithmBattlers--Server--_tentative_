#ifndef INCLUDE_GUARD_OTHELLO
#define INCLUDE_GUARD_OTHELLO

#include "../Util/Common.h"
#include "../Util/IGameInterface.h"

// class Othello : public IGame {
class Othello : public IGame {
 public:
  ull WhiteBoard;     // ���̔Ֆ�
  ull BlackBoard;     // ���̔Ֆ�
  int ElapsedTurn;    // �o�߃^�[��
  int** BoardData;    // �Ֆʏ��(�\���o�[�ɏグ��)
  int BoardSize = 8;  // �ՖʃT�C�Y(���̏�8�Œ�)

 private:
  ull (*WhiteSolver)(ull);  // ���̃\���o�[
  ull (*BlackSolver)(ull);  // ���̃\���o�[

  void Show(ull black, ull white);

 public:
  // �R���X�g���N�^�C�e�v���C���[�̃\���o�[��n���ď�����
  Othello(ull (*whiteSolver)(ull), ull (*blackSolver)(ull));

  // @override �Ֆʕ\������
  void Show();

  // ����\��
  ull Candidate(bool turn);

  // �΂�u������
  void PutStone(bool turn, ull point);

  // �e�^�[���̏��� false���܂��������s true�������I��
  bool TurnProcess(int player);

  // �I������
  void EndProcess();

  // �\���o�[�ɓn���f�[�^�����
  void TranslateBitToArray();

  // static:----------------------------------------

  //
  static int Count(ull t);

  // �΂̐�����
  static ull BitCount(ull player);
};

#endif