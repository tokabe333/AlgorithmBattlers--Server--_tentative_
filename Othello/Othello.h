#ifndef INCLUDE_GUARD_OTHELLO
#define INCLUDE_GUARD_OTHELLO

#include "../Util/Common.h"
#include "../Util/IGameInterface.h"

// class Othello : public IGame {
class Othello : public IGame {
 public:
  ull white_board;     // ���̔Ֆ�
  ull black_board;     // ���̔Ֆ�
  int elapsed_turn;    // �o�߃^�[��
  int** board_data;    // �Ֆʏ��(�\���o�[�ɏグ��)
  int board_size = 8;  // �ՖʃT�C�Y(���̏�8�Œ�)

 private:
  ull (*white_solver)(ull);  // ���̃\���o�[
  ull (*black_sover)(ull);   // ���̃\���o�[

  void show(ull black, ull white);

 public:
  // �R���X�g���N�^�C�e�v���C���[�̃\���o�[��n���ď�����
  Othello(ull (*whiteSolver)(ull), ull (*blackSolver)(ull));

  // @override �Ֆʕ\������
  void show();

  // ����\��
  ull candidate(bool turn);

  // �΂�u������
  void PutStone(bool turn, ull point);

  // �e�^�[���̏��� false���܂��������s true�������I��
  bool turn_process(int player);

  // �I������
  void end_process();

  // �\���o�[�ɓn���f�[�^�����
  void translate_bit2array();

  // static:----------------------------------------

  // �����Ă���r�b�g�𐔂���
  static int count(ull t);

  // �΂̐�����
  static ull bit_count(ull player);
};

#endif