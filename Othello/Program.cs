using System;
using System.Collections.Generic;
using System.Diagnostics;

namespace Othello {
	class Program {
		public static void Main (string[] args) {

		} //End_Method

		public static void Array_List_SpeedTest () {
			//var othello = new Othello ();
			var sw = new Stopwatch ();
			int n = 100000;
			int nn = 10000;
			var array = new long[n];
			sw.Start ();
			for (int j = 0; j < nn; ++j) {
				for (long i = 0; i < n; ++i) { array[i] = i; }
			}
			sw.Stop ();
			Console.WriteLine ("Array:" + sw.ElapsedMilliseconds);
			var list = new List<long> (array);
			sw.Reset ();
			sw.Start ();

			for (int j = 0; j < nn; ++j) { for (int i = 0; i < n; ++i) { list[i] = i; } }
			sw.Stop ();
			Console.WriteLine ("List:" + sw.ElapsedMilliseconds);
		} //End_Method
	} //End_Class
} //End_Namespace