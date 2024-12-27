//DMOJ - Fibonacci 2D
//Programación dinámica: Tabla acumulativa
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Vector;
import java.util.BitSet;
import java.util.Collections;
import java.util.Formatter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;
import java.util.Set;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.regex.*;
import java.util.Calendar;

public class Main {

    private BufferedReader in;
    private PrintWriter out;
    private StringTokenizer st;
    private final long MOD=1000000007;


    public void solve() throws IOException {

         long [][] fibonacci=new long[1010][1010];

         for(int i=0;i<1010;i++){
            fibonacci[0][i]=fibonacci[i][0]=1;
         }


         for(int i=1;i<1010;i++){
            for(int j=1;j<1010;j++){
               fibonacci[i][j]=(fibonacci[i-1][j]+fibonacci[i][j-1]+fibonacci[i-1][j-1])%MOD;
            }
         }

         String line = in.readLine();
         while( line!=null){
            eat(line);
            int cases=nextInt();
            while(cases>0){
               cases--;
               int x=nextInt();
               int y=nextInt();
               out.printf("%d\n",fibonacci[x][y]);
            }
            line = in.readLine();
         }
	 }

    Main() throws IOException {
        //in = new BufferedReader(new FileReader("Input.txt"));
       //out = new PrintWriter(new FileWriter("Output.txt"));
       in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        eat("");solve();in.close();out.close();
    }

    private void eat(String str) { st = new StringTokenizer(str);}

    String next() throws IOException {
        while (!st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) return null;
            eat(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {return Integer.parseInt(next());}

    long nextLong() throws IOException {return Long.parseLong(next());}

    double nextDouble() throws IOException {return Double.parseDouble(next());}

    public static void main(String[] args) throws IOException {new Main();}

}
