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

            foreach (var l in fs.ComputeFourSums (new int[] {1, 2, 3, 4, 5, 6, 7, 8, 1, -1, 3, -2, 11, 12, 23, 14, 10}, 20)) {
                Console.WriteLine (string.Join (", ", l));
            }
        }

        [Test]
        public void FourSum2 ()
        {
            FourSum fs = new FourSum ();

            foreach (var l in fs.ComputeFourSums (new int[] {1, 2, 3, 4, 5, 6, 7, 8, 1, -1, 3, -2, 11, 12, 23, 14, 10}, 20)) {
                Console.WriteLine (string.Join (", ", l));
            }
        }
    }
}

