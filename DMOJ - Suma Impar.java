// DMOJ - Suma Impar
/*
Tematica: Add- Hoc

Idea Basica: Dada la colección de números suma todos los pares positivos, mientras los impares 
los almacenos los ordenos cojo el mayor de los impares se los sumo a la suma de los pares positivos. Luego con los
impares restantes voy seleccionado de dos en dos mientras la suma de ambos sea positivos y se los voy adicionando 
a la suma que doy como resultado.
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
    private final int MAX_N = 1000001;
    private final int MAX_TREE = (MAX_N << 2);
    
    private int [] movX = { 0, 0, 1, -1};
    private int [] movY = {-1, 1, 0,  0};
    private long [] cards ={1,10,100,1000,10000};
    private long MOD =1000000009;
   
    public void solve() throws Exception {
        int nNumber = nextInt(),cElements=0;
        long answer=0,number;
        List<Long> impares = new ArrayList<Long>();
        for(int i=0;i<nNumber;i++){
            number=nextLong();
            if(number%2==0 && number>=0)answer+=number;
            else if(Math.abs(number%2)==1 ) impares.add(number);
        }
        
        Collections.sort(impares);
       
        
        answer+=impares.get(impares.size()-1);
        impares.remove(impares.size()-1);
        
        int pivot = impares.size()-2;
        
        while(pivot >=0 && (impares.get(pivot) + impares.get(pivot+1)) >=0 ){
            answer+=(impares.get(pivot)+impares.get(pivot+1));
            pivot-=2;
        }
        
        
        out.printf("%d\n",answer);
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
