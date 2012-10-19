using System;
using System.Collections.Generic;
using System.IO;

namespace googleprep
{
    public class Trie
    {
        // STATIC 

        static Trie standard;

        public static Trie Standard {
            get {
                if (standard == null)
                    BuildStandardTrie ();
                return standard;
            }
        }

        static void BuildStandardTrie ()
        {
            standard = new Trie () { Character = '\0' };
            foreach (string word in File.ReadLines ("/usr/share/dict/american-english")) {
                standard.Insert (word);
            }
        }

        // INSTANCE

        public char Character {get; set;}
        public List<Trie> Children {get; set;}
        public bool IsWord { get; set; }

        public Trie Next (char c)
        {
            if (this.Children == null)
                return null;
            foreach (var t in Children)
                if (t.Character == c)
                    return t;
            return null;
        }

        public void Insert (string s)
        {
            var t = this;
            foreach (var character in s) {
                var next = t.Next (character);
                if (next == null) {
                    next = new Trie () { Character = character };
                    if (t.Children == null)
                        t.Children = new List<Trie> ();
                    t.Children.Add (next);
                }
                t = next;
            }
            t.IsWord = true;
        }
    }
}

