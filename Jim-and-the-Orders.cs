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
     * Complete the 'jimOrders' function below.
     *
     * The function is expected to return an INTEGER_ARRAY.
     * The function accepts 2D_INTEGER_ARRAY orders as parameter.
     */

    public static List<int> jimOrders(List<List<int>> orders)
    {
        List<(int serve, int id)> list = new List<(int,int)>();

        for(int i = 0; i < orders.Count; i++)
            list.Add((orders[i][0] + orders[i][1], i + 1));

        list.Sort((a,b) => {
            if(a.serve == b.serve) return a.id.CompareTo(b.id);
            return a.serve.CompareTo(b.serve);
        });

        List<int> result = new List<int>();
        foreach(var x in list)
            result.Add(x.id);

        return result;
    }
    
    
    public static List<int> jimOrders4(List<List<int>> orders)
    {
        var pq = new PriorityQueue<int, (int totalTime, int index)>();

        for (int i = 0; i < orders.Count; i++)
        {
            int totalTime = orders[i][0] + orders[i][1];
            pq.Enqueue(i + 1, (totalTime, i + 1));
        }

        var result = new List<int>();

        while (pq.Count > 0)
        {
            result.Add(pq.Dequeue());
        }

        return result;
    }    
}


class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int n = Convert.ToInt32(Console.ReadLine().Trim());

        List<List<int>> orders = new List<List<int>>();

        for (int i = 0; i < n; i++)
        {
            orders.Add(Console.ReadLine().TrimEnd().Split(' ').ToList().Select(ordersTemp => Convert.ToInt32(ordersTemp)).ToList());
        }

        List<int> result = Result.jimOrders(orders);

        textWriter.WriteLine(String.Join(" ", result));

        textWriter.Flush();
        textWriter.Close();
    }
}
