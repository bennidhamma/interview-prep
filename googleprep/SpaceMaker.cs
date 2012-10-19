using System;
using System.Collections.Generic;

namespace googleprep
{
    public class SpaceMaker : Backtracker<string>
    {
        int count = 0;
        string input;
        public List<string> solutions;

        public List<string> Spacify (string input)
        {
            count = 0;
            this.input = input;
            solutions = new List<string> ();
            Backtrack (new List<string>(), 0);
            return solutions;
        }

        public override bool IsSolution (List<string> a, int k)
        {
            return count == input.Length;
        }

        public override void ProcessSolution (List<string> a, int k)
        {
            solutions.Add (string.Join(" ", a));
        }

        public override IEnumerable<string> ConstructCandidates (List<string> a, int k)
        {
            var t = Trie.Standard;
            int i = count;
            while (t != null && i < input.Length) {
                t = t.Next (input [i++]);
                if (t != null && t.IsWord)
                    yield return t.Word;
            }
        }

        public override void MakeMove (List<string> a, int k)
        {
            count += a[k].Length;
        }

        public override void UnmakeMove (List<string> a, int k)
        {
            count -= a[k].Length;
        }
    }
}