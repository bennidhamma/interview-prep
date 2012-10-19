using System;
using System.Collections.Generic;
using System.Linq;

namespace googleprep
{
    public class FourSum : Backtracker<int>
    {
        int[] nums;
        int target, sum;
        List<List<int>> solutions;
        List<int> cur;

        public List<List<int>> ComputeFourSums (int[] nums, int target)
        {
            var a = new List<int>(4);
            this.nums = nums;
            this.target = target;
            this.sum = 0;
            solutions = new List<List<int>> ();
            cur = new List<int> ();
            Backtrack (a, 0);
            return solutions;
        }

        public override bool IsSolution (List<int> a, int k)
        {
            return sum == target && k == 4;
        }

        public override void ProcessSolution (List<int> a, int k)
        {
            var l = new List<int> ();
            foreach (int i in a)
                l.Add (nums [i]);
            l.Sort ();
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

        public override IEnumerable<int> ConstructCandidates (List<int> a, int k)
        {
            if (k == 4)
                yield break;
            for (int i = 0; i < nums.Length; i++)
                if (! a.Contains (i) && sum + nums [i] <= target)
                    yield return i;
        }

        public override void MakeMove (List<int> a, int k)
        {
            sum += nums [a [k]];
            cur.Add (nums [a [k]]);
        }

        public override void UnmakeMove (List<int> a, int k)
        {
            sum -= nums [a [k]];
            cur.RemoveAt (cur.Count - 1);
        }
    }
}

