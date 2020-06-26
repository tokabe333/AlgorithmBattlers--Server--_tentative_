#include "../Util/Common.h"
#include "../Util/IGameInterface.h"

// class Othello : public IGame {
class Othello {
 public:
  ull WhiteBoard;   // ���̔Ֆ�
  ull BlackBoard;   // ���̔Ֆ�
  int ElapsedTurn;  // �o�߃^�[��

 private:
  ull (*WhiteSolver)(ull);
  ull (*BlackSolver)(ull);

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

  // static:----------------------------------------

  //
  static int Count(ull t);

  // �΂̐�����
  static ull BitCount(ull player);
};
