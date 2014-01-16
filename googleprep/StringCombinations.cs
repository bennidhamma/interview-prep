using System;
using System.Collections.Generic;

namespace googleprep
{
	public class StringCombinations : Backtracker<int>
	{
		public string Input {get; set;}
		public int NumberOfSolutions { get; set; }

		public override bool IsSolution (List<int> a, int k)
		{
			return k == Input.Length;
		}

		public override void ProcessSolution (List<int> a, int k)
		{
			string s = String.Empty;
			for (int i = 0; i < k; i++)
				if (a[i] == 1)
					s += Input[i];
			Console.WriteLine (s);
			NumberOfSolutions++;
		}

		public override IEnumerable<int> ConstructCandidates (List<int> a, int k)
		{
			yield return 0;
			yield return 1;
		}

		public void Run (string input)
		{
			Input = input;
			var a = new List<int> (input.Length);
			Backtrack (a, 0);
		}
	}
}
