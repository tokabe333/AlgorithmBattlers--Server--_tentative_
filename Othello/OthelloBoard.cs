using System;
using System.Collections.Generic;

namespace Othello {
	class OthelloBoard {

		// -------------------  Public 変数  -------------------
		/// <summary>
		/// ボードサイズ
		/// </summary>
		public int N;

		/// <summary>
		/// 各プレイヤーのスコア
		/// </summary>
		public (int p1, int p2) Scores;

		/// <summary>
		/// 盤面
		/// </summary>
		public int[][] Map;

		// -------------------  Private 変数  -------------------
		/// <summary>
		/// 探索に用いる，8方向への移動手段
		/// </summary>
		private (int x, int y) [] Next = {
			(0, -1),
			(1, -1),
			(1, 0),
			(1, 1),
			(0, 1),
			(-1, 1),
			(-1, 0),
			(-1, -1)
		};

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="n">盤面の縦横サイズ</param>
		public OthelloBoard (int n = 8) {
			this.N = n;
			Console.WriteLine ("OthelloBoard is Creadted!!");
			Console.WriteLine ("N = " + this.N);

			this.Map = new int[this.N][];
			for (int i = 0; i < n; ++i) { this.Map[i] = new int[n]; }
			// 最初の4個を配置
			int ngo = this.N / 2;
			this.Map[ngo - 1][ngo - 1] = 1;
			this.Map[ngo - 1][ngo] = -1;
			this.Map[ngo][ngo - 1] = -1;
			this.Map[ngo][ngo] = 1;
		} //End_Constructor

		// 候補手を列挙
		public List < (int x, int y) > PickUpCandidate (int player) {
			var retList = new List < (int x, int y) > ();
			// マップ全探索
			for (int i = 0; i < this.N; ++i) {
				for (int j = 0; j < this.N; ++j) {

					if (this.Map[i][j] != 0) continue;
					bool flag = false;
					// 8方向について探索していく
					for (int k = 0; k < this.N; ++k) {
						int cx = j, cy = i;
						while (true) {
							cx += this.Next[k].x;
							cy += this.Next[k].y;
							// ガバ(盤外にでる，虚無マスを通る)
							if ((cx < 0) || (this.N <= cx) || (cy < 0) || (this.N <= cy) ||
								(this.Map[cx][cy] == 0)) { break; }
							// 自分に出会えたら嬉しい
							else if (this.Map[cx][cy] == player) {
								flag = true;
								break;
							} //End_IfElse
						} //End_While
						// ガバってなかったら候補に追加
						if (flag) {
							retList.Add ((i, j));
							break;
						} //End_If
					} //End_For
				} //End_For
			} //End_For
			return retList;
		} //End_Method

	} //End_Class
} //End_Namespace