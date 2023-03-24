
/**
 * DMOJ -Orden de Ordeño
 * Temáticas: Add-Hoc
 *  
 *  Idea: Lo primero es tener dos estructuras en formas de arreglos una que en 
 *  la posición i me diga que vaca esta ubica ahi (las vacas las enumeramos de 1 a N) si
 *  en la posición no esta ocupada por ninguna vaca su valor será -1. De igual forma tener
 *  un arreglo donde la posición i voy a tener el valor de la posición de donde esta ubicada
 *  la vaca i de no estar ubica en el orden de ordeño el valor de la posición será -1.
 * 
 *  Una leida la entrada ubico aquellas vacas que quieren una posición en especifico.
 * 
 *  Lo siguiente será ubicar las vacas que establecieron una jerarquía de orden pero teniendo
 *  un importante detalle. Si dentro dentro de las vacas de la jerarquía esta la vaca 1 voy a ubicar
 *  a las vacas(si no estan ubicadas ya previamente) lo más a la izquierda 
 *  o al principio del orden en aquellas posiciones que vayan quedando libre 
 *  sin violar en posicionamiento de las vacas de la jeraquia entre si.
 * 
 *  En el caso que la vaca 1 no este entre las vacas de jerarquia a estas vacas 
 *  las vamos a ubicar los mas al final o la derecha posible en las posiciones que 
 *  estén disponibles simepre respetando el orden de jerarquia. Para este caso se debe
 *  comenzar a ubicar las vacas de menor a mayor jerarquia siempre y cuando no hayan
 *  sido ubicadas previemente.
 * 
 *  Si la vaca no ha sido ubicado aún todavia entonces buscamos la posición mas a la 
 *  izquierda que este disponible aún y esa será la respuesta sino la ubicación que ya 
 *  tiene la vaca 1
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
	private final int MAX_N = 10010;
	private final int MAX_TREE = (MAX_N << 2);
	private final char SYMBOL = '@';

	private int[] movX = { 0, 0, 1, -1, 1, 1, -1, -1 };
	private int[] movY = { -1, 1, 0, 0, 1, -1, 1, -1 };
	private long[] cards = { 1, 10, 100, 1000, 10000 };
	private long MOD = 10000;

	public void solve() throws Exception {
		int N = nextInt(), M = nextInt(), K = nextInt(), cow, pos, pCow, pPos;

		int[] location = new int[N + 1];
		int[] cows = new int[N + 1];
		Arrays.fill(cows, -1);
		Arrays.fill(location, -1);
		ArrayList<Integer> social = new ArrayList<Integer>();
		Strategy strategy = Strategy.STACK;

		for (int i = 0; i < M; i++) {
			cow = nextInt();
			if (cow == 1)
				strategy = Strategy.QUEUE;
			social.add(cow);
		}

		for (int i = 0; i < K; i++) {
			cow = nextInt();
			pos = nextInt();

			cows[cow] = pos;
			location[pos] = cow;
		}

		pCow = -1;
		pPos = -1;

		while (social.isEmpty() == false) {

			if (strategy == Strategy.STACK) {
				cow = social.get(social.size()-1);
				social.remove(social.size()-1);
				if (cows[cow] != -1) {
					pCow = cow;
					pPos = cows[cow];
				} else {
					pos = searchBack(location, pPos);
					cows[cow] = pos;
					location[pos] = cow;
					pCow = cow;
					pPos = cows[cow];
				}
			}else {
				cow = social.get(0);
				social.remove(0);
				if (cows[cow] != -1) {
					pCow = cow;
					pPos = cows[cow];
				} else {
					pos = searchFront(location, pPos);
					cows[cow] = pos;
					location[pos] = cow;
					pCow = cow;
					pPos = cows[cow];
				}
			}
		}

		pos = -1;

		if (cows[1] != -1)
			pos = cows[1];

		for (int i = 1; i <= N && pos == -1; i++)
			if (location[i] == -1)
				pos = i;

		out.printf("%d\n", pos);
	}

	private int searchFront(int[] location, int pPos) {
		if (pPos == -1)
			pPos = 0;
		for (int i = pPos + 1; i < location.length; i++)
			if (location[i] == -1)
				return i;
		return 0;
	}

	private int searchBack(int[] location, int pPos) {
		if (pPos == -1)
			pPos = location.length;
		for (int i = pPos - 1; i >= 1; i--)
			if (location[i] == -1)
				return i;
		return 0;
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

	private enum Strategy {
		QUEUE, STACK
	}
}
