using System;
using System.Collections.Generic;
using System.Linq;

namespace googleprep
{
	public class FourSum : Backtracker
	{
		int[] nums;
		int target, sum;
		List<List<int>> solutions;
		List<int> cur;

		public List<List<int>> ComputeFourSums (int[] nums, int target)
		{
			int[] a = new int[4];
			this.nums = nums;
			this.target = target;
			this.sum = 0;
			solutions = new List<List<int>> ();
			cur = new List<int> ();
			Backtrack(a, 0);
			return solutions;
		}

		#region implemented abstract members of googleprep.Backtracker
		public override bool IsSolution (int[] a, int k)
		{
			return sum == target && k == 4;
		}

		public override void ProcessSolution (int[] a, int k)
		{
			var l = new List<int>();
			foreach (int i in a)
				l.Add (nums[i]);
			l.Sort();
			if (!SolutionExists (l))
				solutions.Add (l);
		}

		public bool SolutionExists (List<int> a)
		{
			foreach (var b in solutions) {
				bool exists = true;
				for (int i = 0; i < 4; i++) {
					if (a [i] != b [i]) {
						exists = false;
						break;
					}
				}
				if (exists)
					return true;
			}
			return false;
		}

		public override int[] ConstructCandidates (int[] a, int k)
		{
			if (k == 4)
				return new int[] {};
			var l = new List<int> ();
			for (int i = 0; i < nums.Length; i++)
				if (! a.Contains (i) && sum + nums [i] <= target)
					l.Add (i);
			return l.ToArray();
		}
		#endregion

		public override void MakeMove (int[] a, int k)
		{
			sum += nums[a[k]];
			cur.Add (nums[a[k]]);
		}

		public override void UnmakeMove (int[] a, int k)
		{
			sum -= nums[a[k]];
			cur.RemoveAt (cur.Count - 1);
		}
	}
}

