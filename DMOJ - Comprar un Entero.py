"""
 DMOJ - Comprar un Entero
 Temática: Busqueda Binaria
  
 Idea: El costo de comprar un entero N es A*N + B*d(N), donde d(N) es la
 cantidad de dígitos de N (calculada como ⌊log10(N)⌋+1). Este costo es
 monótono creciente respecto a N (A>0 garantiza crecimiento). Por tanto,
 podemos buscar binariamente el mayor entero N en el intervalo [1, 10^9]
 que satisfaga costo(N) ≤ X. En cada paso se evalúa el pivote y se
 ajusta el rango: si el costo es ≤ X, guardamos el candidato y probamos
 valores mayores; en caso contrario, reducimos el límite superior. La
 complejidad es O(log(10^9)) ≈ O(1). 

"""
from functools import cmp_to_key, reduce
from collections import deque
import math

# Comparadores en Estructuras de Datos
import heapq
import sys

mov_r = [2, 2, -2, -2, 1, -1, 1, -1]
mov_c = [1, -1, 1, -1, 2, 2, -2, -2]

MOD = 10**9 + 7


def read_nonempty():
    s = sys.stdin.readline()
    while s is not None and s.strip() == "":
        s = sys.stdin.readline()
    return s.strip()


def solve():
    input_line = read_nonempty
    A,B,X = map(int,input_line().split())
    answer = 0
    begin = 1
    end = 1000000000
    while begin <= end:
        pivot = (begin+end)//2
        pX = A*pivot + B* (math.floor(math.log10(pivot))+1);
        if pX <= X:
            answer = max(answer,pivot)
            begin = pivot + 1
        else:
            end = pivot - 1
    print(answer)


if __name__ == "__main__":
    solve()
