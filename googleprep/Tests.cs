using System;
using NUnit.Framework;

namespace googleprep
{
    [TestFixture()]
    public class Tests
    {
        [Test()]
        public void PermuteString ()
        {
            PermuteString ps = new PermuteString ();
            ps.Run ("readers");
            Console.WriteLine ("Number of solutions: " + ps.NumberOfSolutions);
        }

        [Test]
        public void CombineString ()
        {
            StringCombinations sc = new StringCombinations ();
            sc.Run ("readers");
            Console.WriteLine ("Number of solutions: " + sc.NumberOfSolutions);
        }

        [Test]
        public void FourSum ()
        {
            FourSum fs = new FourSum ();
            foreach (var l in fs.ComputeFourSums (new int[] {1, 0, -1, 0, -2, 2}, 0)) {
                Console.WriteLine (string.Join (", ", l));
            }
        }
    }
}

