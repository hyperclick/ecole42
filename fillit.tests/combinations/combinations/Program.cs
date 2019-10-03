using System;

namespace combinations
{
    class Program
    {
        static void Main(string[] args)
        { var r = find_all("", "1234");
            if (r != "4321")
            {
                System.Diagnostics.Debugger.Break();
            }
            Console.WriteLine("passed!");
        }

        private static string find_all(string r, string rest)
        {
            if (rest.Length == 0)
            {
                Console.WriteLine("found:\t" + r);
                return r;
            }
            for (int i = 0; i < rest.Length; i++)
            {
                char f = rest[i];
                if (can_append(r, f))
                {
                    var res = find_all(append_to_copy(r, f), rest.Remove(i, 1));
                    if (res.Length == 4)
                    {
                        return res;
                    }
                }
            }
            return "";
        }

        private static string append_to_copy(string r, char f)
        {
            return r + f;
        }

        private static bool can_append(string r, char f)
        { 
            if (r == "432" && f == '1' || r.Length != 3)
            {
                return true;
            }
            Console.WriteLine($"reject:\t{r+f}");
            return false;
        }

    }
}
