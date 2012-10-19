using System;
using System.Collections.Generic;

namespace googleprep
{
	public class StringCombinations : Backtracker
	{
		public string Input {get; set;}
		public int NumberOfSolutions { get; set; }

		public StringCombinations ()
		{
		}

		#region implemented abstract members of googleprep.Backtracker
		public override bool IsSolution (int[] a, int k)
		{
			return k == Input.Length;
		}

		public override void ProcessSolution (int[] a, int k)
		{
			string s = String.Empty;
			for (int i = 0; i < k; i++)
				if (a[i] == 1)
					s += Input[i];
			Console.WriteLine (s);
			NumberOfSolutions++;
		}

		public override int[] ConstructCandidates (int[] a, int k)
		{
			return new int[2] {0, 1};
		}
		#endregion

		public void Run (string input)
		{
			Input = input;
			int[] a = new int[input.Length];
			Backtrack (a, 0);
		}
	}
}

