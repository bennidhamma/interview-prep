using System;
using System.Collections.Generic;

namespace googleprep
{
	public class PermuteString : Backtracker
	{
		public string Input {get; set;}
		public int NumberOfSolutions { get; set; }

		public PermuteString ()
		{
			
		}

		#region implemented abstract members of googleprep.Backtracker
		public override bool IsSolution (int[] a, int k)
		{
			return k == Input.Length;
		}

		public override void ProcessSolution (int[] a, int k)
		{
			NumberOfSolutions++;
			char[] output = new char[a.Length];
			for (int i = 0; i < k; i++)
				output[i] = Input[a[i]];
			Console.WriteLine (new String(output));
		}

		public override int[] ConstructCandidates (int[] a, int k)
		{
			int i;
			List<int> candidates;
			candidates = new List<int>();
			bool[] inPermutation = new bool[Input.Length];
			//create a bit vector to map the presence or absence of each letter in the current solution.
			for (i = 0; i < inPermutation.Length; i++) 
				inPermutation[i] = false;
			for (i = 0; i < k; i++)
				inPermutation[ a[i] ] = true;

			for (i = 0; i < inPermutation.Length; i++)
				if (! inPermutation[i])
					candidates.Add (i);
			return candidates.ToArray();
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

