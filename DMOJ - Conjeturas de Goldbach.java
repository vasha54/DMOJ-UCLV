// DMOJ - Conjeturas de Goldbach

/*
Tematica:Teoría de numeros + Criba de primos + Busqueda binaria 

Idea Basica: Generar todos los primos y luego para cada n buscar el menor a primo que sumado con b primo den N.
Para buscar b lo hacemos con busqueda binaria y siempre chequeando que a!=b
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
   
    public int[] generatePrimesLinearTime(int n) {
        int[] lp = new int[n + 1];
        int[] primes = new int[n + 1];
        int cnt = 0;
        for (int i = 2; i <= n; ++i) {
            if (lp[i] == 0) {
                lp[i] = i;
                primes[cnt++] = i;
            }
            for (int j = 0; j < cnt && primes[j] <= lp[i] && i * primes[j] <= n; ++j) lp[i * primes[j]] = primes[j];
        }
        return Arrays.copyOf(primes, cnt);
    }
   
    public void solve() throws Exception {
        
        int [] primes =generatePrimesLinearTime(1000010) ;
        int n = nextInt();
        
        while(n!=0){
            int a=-1,b=-1,i,f,pivote;
            boolean find=false;
            for(int k=0;k<primes.length && primes[k]<n && find == false;k++){
                a=primes[k];
                b=n - a;
                
                if(a!=b){
                    i =0 ;
                    f = primes.length-1;
                    while(i<=f && find ==false){
                        pivote = (i+f)/2;
                        if(primes[pivote]==b)
                            find=true;
                        else if(primes[pivote] > b)
                            f=pivote-1;
                        else
                            i=pivote+1;
                    }
                }
            }
            
            if(a!=-1 && b!=-1 && find )
              out.printf("%d = %d + %d\n",n,a,b);
            else
              out.printf("Goldbach conjecture is wrong\n");
            n =nextInt();
        }
        
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
