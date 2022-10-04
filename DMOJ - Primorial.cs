/*
DMOJ - Primorial

Tematica: Teoria de Numero - Criba de primos

Idea basica: Para un número N saber la multiplicación de todos los numeros primeros 
hasta el incluyendolo
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
    		int cases,n;
    		ulong [] primoldial =new ulong [MAX_N];

    		for(int i=0;i<primoldial.Length;i++) primoldial[i]=(ulong)i;

    		for(int i=2;i<primoldial.Length;i++){
    			if(primoldial[i] == 1) continue;
    			for(int j=i*i;j<primoldial.Length;j+=i) primoldial[j]=1; 
    		}
			
			for(int i=2;i<primoldial.Length;i++) primoldial[i]*=primoldial[i-1]; 

			cases = Convert.ToInt32(Console.ReadLine());

			for(int i=0;i<cases;i++){
				n = Convert.ToInt32(Console.ReadLine());
				Console.WriteLine(primoldial[n]);
			}   		

    	}

        public static void Main(string[] args)
        {
            Program p = new Program(); 
            p.solve();
        }
    }
}

