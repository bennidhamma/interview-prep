using System;
using System.Collections.Generic;

namespace googleprep
{
    public class SpaceMaker : Backtracker<string>
    {
        public SpaceMaker ()
        {
        }
        #region implemented abstract members of googleprep.Backtracker
        public override bool IsSolution (List<string> a, int k)
        {
            throw new System.NotImplementedException ();
        }

        public override void ProcessSolution (List<string> a, int k)
        {
            throw new System.NotImplementedException ();
        }

        public override IEnumerable<string> ConstructCandidates (List<string> a, int k)
        {
            throw new System.NotImplementedException ();
        }
        #endregion

    }
}

