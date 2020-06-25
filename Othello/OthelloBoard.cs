using System;

namespace Othello {
	class OthelloBoard {
		/// <summary>
		/// ボードサイズ
		/// </summary>
		public int N;

		/// <summary>
		/// 盤面
		/// </summary>
		public int[][] Map;

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

		//
		// public int[][] PickUpCandidate (int player) {
		// 	var retList = new int[];

		// } //End_Method
	} //End_Class
} //End_Namespace