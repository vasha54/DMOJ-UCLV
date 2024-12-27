// DMOJ - Disjoint Set of Common Divisors

/*
Tematica: Teoría de numeros: Maximo comun divisor + Factorizar en numeros primos

Idea Basica: Hallar el gcd entre los dos numeros si es uno entonces esa es la resuesta. Si el gcd es mayor que
uno factorizar dicho gcd en numero primos y la cantidad de factores primos +1 será la respuesta

*/
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.*;
import java.lang.*;
import java.util.regex.*;


public class Main {
    
    private BufferedReader in;
    private PrintWriter out;
    private StringTokenizer st;
    private final int MAX_N = 510;
    
    private int [] movX = { 0, 0, 1, -1};
    private int [] movY = {-1, 1, 0,  0};
    private long [] cards ={1,10,100,1000,10000};
   
    public static Map<Long, Integer> factorize(long n) {
        Map<Long,Integer> factors = new HashMap<>();
        for (long d = 2; d * d <= n; d++) {
            int power=0;
            while (n % d == 0) {
                n /= d;
                power++;
            }
            if(power!=0)
                factors.put(d,power);
        }
        if (n > 1) {
            factors.put(n,1);
        }
        return factors;
    }
   
    public long GCD(long a,long b) { // a>= b
        while (b > 0){
            a=a%b;
            a ^= b; 
            b ^= a;
            a ^= b;
        }
        return a;
    }

    public void solve() throws Exception {
        long A = nextLong();
        long B = nextLong();
        long gcd = GCD(Math.max(A,B),Math.min(A,B));
        out.printf("%d\n",factorize(gcd).size()+1);
        
    }
    
    Main() throws Exception {
       /*Esta entrada  se debe activar cuando se hace una ejercicio de lectura hasta fin de fichero 
       copiar la entrada en un fichero "Input.txt" y comentar el otro in . A la hor de enviar comentar
       este y descomentar el otro
       */
       //in = new BufferedReader(new FileReader("Input.txt"));
       //out = new PrintWriter(new FileWriter("Output.txt"));
       in = new BufferedReader(new InputStreamReader(System.in));
	   out = new PrintWriter(System.out);
       eat("");
       solve();
       in.close();
       out.close();
    }

    private void eat(String str) { st = new StringTokenizer(str);}

    String next() throws Exception {
        while (!st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) return null;
            eat(line);
        }
        return st.nextToken();
    }

    int nextInt() throws Exception {return Integer.parseInt(next());}

    long nextLong() throws Exception {return Long.parseLong(next());}

    double nextDouble() throws Exception {return Double.parseDouble(next());}

    public static void main(String[] args) throws Exception {new Main();}

}
