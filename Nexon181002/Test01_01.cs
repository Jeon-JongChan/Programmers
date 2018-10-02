using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;


class Result
{

    /*
     * Complete the 'pthFactor' function below.
     *
     * The function is expected to return a LONG_INTEGER.
     * The function accepts following parameters:
     *  1. LONG_INTEGER n
     *  2. LONG_INTEGER p
     */

    public static long pthFactor(long n, long p)
    {
        long[] primeNum = new long[p+1];
        int cnt = 0;
        if( (1 <= n && n <= Math.Pow(10,15)) && (1 <= p && p <= Math.Pow(10,9)) )
        {
            long lastNum = (n / 2) + 1;
            for(long i = 1; i <= lastNum; i++)
            {
               if(cnt > p-1) break;
                if(n % i == 0) 
                {
                    primeNum[cnt++] = i;
                }
            }
            primeNum[cnt] = n;
         }

        if(cnt < p) 
        {
            return 0;
        }
        else
        {
            return primeNum[p-1];
        }
    }

}

class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        long n = Convert.ToInt64(Console.ReadLine().Trim());

        long p = Convert.ToInt64(Console.ReadLine().Trim());

        long result = Result.pthFactor(n, p);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}