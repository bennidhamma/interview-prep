using System;
using System.Collections.Generic;

namespace googleprep
{
    public abstract class Backtracker<T>
    {
        public bool Finished { get; set; }

        public abstract bool IsSolution (List<T> a, int k);

        public abstract void ProcessSolution (List<T> a, int k);

        public abstract IEnumerable<T> ConstructCandidates (List<T> a, int k);

        public virtual void MakeMove (List<T> a, int k)
        {
        }

        public virtual void UnmakeMove (List<T> a, int k)
        {
        }

        public void Backtrack (List<T> a, int k)
        {
            if (IsSolution (a, k))
                ProcessSolution (a, k);
            else {
                foreach (T c in ConstructCandidates (a, k)) {
                    a.Add (c);
                    MakeMove (a, k);
                    Backtrack (a, k + 1);
                    UnmakeMove (a, k);
                    a.RemoveAt (a.Count - 1);
                    if (Finished)
                        return;
                }
            }
        }
    }
}

