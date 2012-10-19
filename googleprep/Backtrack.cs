using System;

namespace googleprep
{
    public abstract class Backtracker
    {
        public bool Finished { get; set; }

        public abstract bool IsSolution (int[] a, int k);

        public abstract void ProcessSolution (int[] a, int k);

        public abstract int[] ConstructCandidates (int[] a, int k);

        public virtual void MakeMove (int[] a, int k)
        {
        }

        public virtual void UnmakeMove (int[] a, int k)
        {
        }

        public void Backtrack (int[] a, int k)
        {
            int[] candidates;

            if (IsSolution (a, k))
                ProcessSolution (a, k);
            else {
                candidates = ConstructCandidates (a, k);
                foreach (int c in candidates) {
                    a [k] = c;
                    MakeMove (a, k);
                    Backtrack (a, k + 1);
                    UnmakeMove (a, k);
                    if (Finished)
                        return;
                }
            }
        }
    }
}

