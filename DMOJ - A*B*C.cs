/*
DMOJ - A*B*C 

Tematica: Fuerza Bruta

Idea basica: Dada un valor K buscar todos trios de la forma(a,b,c) que el productos de estos
valores sean menores e iguales que K. Se pueden repetir valores en los trios 
*/

using System;

namespace JudgeOnline
{
    public class Program
    {
    	private const int MAX_N = 55;
        private const long MOD = 10000009;

        private int gcd(int _a,int _b){
            while(_b>0){
                _a=_a%_b;
                _a^=_b;
                _b^=_a;
                _a^=_b;
            }
            return _a;
        }

    	
        public Program(){}

        public void solve(){
            long K = Convert.ToInt64(Console.ReadLine());
            
            long answer = 0;

            for(long a=1;a<=K;a++){
                for(long b=a;b*a<=K;b++){
                    for(long c =b;a*b*c<=K;c++){
                        if(a==b && b==c) answer++;
                        else if(a==b && b!=c) answer+=3;
                        else if(a!=b && b==c) answer+=3;
                        else if(a!=b && b!=c) answer+=6;
                    }
                }
            }

            Console.WriteLine(answer);
        }

        public static void Main(string[] args)
        {
            Program p = new Program(); 
            p.solve();
        }
    }
}

