
/**
 * DMOJ - Cantidad de Números
 * Temáticas: Combinatoria
 *  
 * Idea: Se tiene N dígitos de los cuales E son digitos pares y O dígitos 
 * deben ser impares. Cuantos números pueden existir en los Z(enteros) que
 * cumplan dichas condición. Vamos a calcular los que cumple dicha condición
 * en los N(naturales) ya que para los Z será el doble de los que existen
 * en los N. Exceptuando el caso para el caso E=1 y O=0 donde la respuesta
 * habrá que incrementar en uno la respuesta. 
 * 
 * La cantidad de números que puedo formar y que tengan N dígitos con E 
 * dígitos pares y O dígitos impares responden a la siguiente expresión:
 * 
 *  (N!/(E! * O!)) * 5^N
 * 
 * El 5^N viene dado porque tengo N posiciones para conformar un número
 * en cada posición puedo poner 5 posibles números (los pares o los impares)
 * 
 * N!/(E! * O!) me permite calcular todas la posibles configuraciones distintas
 * que puedo construir para un número de N dígitos con E dígitos y O
 * dígitos impares. Dos configuraciones se consideran distintas si las 
 * posiciones destinadas para los dígitos pares e impares difieren en el 
 * al menos uno. 
 * 
 * El único problema en la expresión es que considero a los números que 
 * su dígito más a la izquierda sea cero lo cual es incorrecto. Haciendo
 * un ajuste a la expresión.
 * 
 * B = 4 * ((N-1)!/((E-1)! * O!)) * 5^(N-1)
 * A = 5 * ((N-1)!/((E)! * (O-1)!)) * 5^(N-1)
 * 
 * Donde el término B serían los que cumplen la condiciones solicitadas y
 * comienzan por un dígito par, mientras el término A serían los cumplen
 * la condiciones solicitadas y comienza por digito impar. 
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
	private final int MAX_N = 500010;
	private final int MAX_TREE = (MAX_N << 2);
	private final char SYMBOL = '@';
	private final double EPS = 1e-9;

	private int[] movX = { 0, 0, 1, -1, 1, 1, -1, -1, 2, 2, -2, -2 };
	private int[] movY = { -1, 1, 0, 0, 1, -1, 1, -1, -2, 2, 2, -2 };
	private long[] cards = { 1, 10, 100, 1000, 10000 };
	private long MOD = 1000000000;

	private void solve() throws Exception {

		long[] fact = new long[19];
		long[] pow5 = new long[19];
		long ii = 1, A, B;
		fact[0] = pow5[0] = 1;

		for (int i = 1; i < fact.length; i++, ii++) {
			fact[i] = ii * fact[i - 1];
			pow5[i] = 5L * pow5[i - 1];
		}

		int E = nextInt(), O = nextInt(), N;

		while (E != 0L || O != 0L) {
			A = B = 0;
			N = E + O;

			if (E == 1 && O == 0) {
				out.printf("9\n");
			} else {
				if (O != 0) {
					A = (5L * (fact[N - 1] / (fact[E] * fact[O - 1])) * pow5[N - 1]);
				}
				if (E != 0) {
					B = (4L * fact[N - 1] / (fact[E - 1] * fact[O]) * pow5[N - 1]);
				}

				out.printf("%d\n", (A + B) * 2L);
			}

			E = nextInt();
			O = nextInt();
		}
	}

	Main() throws Exception {
		/*
		 * Esta entrada se debe activar cuando se hace una ejercicio de lectura hasta
		 * fin de fichero copiar la entrada en un fichero "Input.txt" y comentar el otro
		 * in . A la hor de enviar comentar este y descomentar el otro
		 */
		// in = new BufferedReader(new FileReader("Input.txt"));
		// out = new PrintWriter(new FileWriter("Output.txt"));
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		eat("");
		solve();
		in.close();
		out.close();
	}

	private void eat(String str) {
		st = new StringTokenizer(str);
	}

	private String next() throws Exception {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null)
				return null;
			eat(line);
		}
		return st.nextToken();
	}

	private int nextInt() throws Exception {
		return Integer.parseInt(next());
	}

	private long nextLong() throws Exception {
		return Long.parseLong(next());
	}

	private double nextDouble() throws Exception {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) throws Exception {
		new Main();
	}

}
