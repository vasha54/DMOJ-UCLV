/*
DMOJ - Farnsworth y la Caja de Paradojas

Tematica: Ordenamiento

Idea basica: Dado tres números ver cuantos son iguales entre si.
*/

using System;

namespace JudgeOnline
{
    public class Program
    {
    	private const int MAX_N = 55;

    	public Program(){
    		
    	}

    	public void solve(){
            string [] valuesStr = Console.ReadLine().Split();
            int [] values = new int [valuesStr.Length];
            for(int i=0;i<values.Length;i++){
                values[i] = Convert.ToInt32(valuesStr[i]);
            }

            Array.Sort(values);

            bool allEquals = (values[0] == values[2]);
            bool onlyTwo = (values[0] == values[1] &&  values[1] != values[2]) ;
                 onlyTwo = onlyTwo || (values[0] != values[1] &&  values[1] == values[2]); 

            if( allEquals ) System.Console.WriteLine(3);
            else if( onlyTwo ) System.Console.WriteLine(2);
            else System.Console.WriteLine(1);


    	}

        public static void Main(string[] args)
        {
            Program p = new Program(); 
            p.solve();
        }
    }
}

