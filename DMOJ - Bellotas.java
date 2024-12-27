//DMOJ - Bellotas
/*

Tematica: Add-Hoc

Idea basica: Una variable acumuladora o sumadora donde voy a ir sumando aquellos valores sean
mayores que 10 decrementados en 10 unidades.

*/
import java.io.*;
import java.math.*;
import java.util.*;


public class Main {
    
    private BufferedReader in;
    private PrintWriter out;
    private StringTokenizer st;
    
    
    public void solve() throws IOException {
		
		int cBellotas,totalBellotas=0,bellota;
        cBellotas = nextInt();
        for(int i=0;i<cBellotas;i++){
            bellota = nextInt();
            if(bellota>10)
              totalBellotas+=(bellota-10);
        }
        out.printf("%d\n",totalBellotas);
	}

    Main() throws IOException {
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
