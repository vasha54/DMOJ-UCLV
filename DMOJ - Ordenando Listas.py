#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
@author: vasha
DMOJ - Ordenando Listas.
Tematica: Ordenamiento + Fuerza bruta
Idea: Dada dos colecciones de valores se quiere calcular con cual de las dos el
algoritmo de ordenamiento seleccion realiza la menor cantidad de operaciones de
intercambios. Realizar el aloritmo y contar la cantidad de de intercambios
"""
import math

#Begin the template for read data from console o file
buffer = []
bufferFile = []
READ_FILE = False
MOD = 10**9+7

def readData():
    global READ_FILE
    global bufferFile
    if READ_FILE:
        if len(bufferFile) ==0:
            with open("Input.txt",'r') as file:
                data=file.read()
            bufferFile=data.split('\n')
        line = bufferFile[0]
        bufferFile.pop(0)
        return line
    else:
        return input()

def next():
    global buffer
    try:
        if len(buffer) == 0:
            buffer = readData().split()
        token = buffer[0]
        buffer.pop(0)
        return token
    except EOFError:
        return None

def nextInt():
   token = next()
   return int(token) if token is not None else None

def nextStr():
   token = next()
   return str(token) if token is not None else None
    
def activeReadFile():
    global READ_FILE
    READ_FILE= True
#End the template for read data from console o file

def selection_sort(array):
   n = len(array)
   swaps = 0
   for i in range(n):
      min_idx = i
      for j in range(i+1,n):
         if array[j] < array[min_idx]:
            array[j], array[min_idx] = array[min_idx], array[j]
            swaps = swaps + 1
   return swaps

def burble_sort(array):
   n = len(array)
   swaps = 0
   for i in range(n):
      for j in range(n-1):
         if array[j] > array[j+1]:
            array[j], array[j+1] = array[j+1], array[j]
            swaps = swaps + 1
   return swaps
  
def solve():
   N = nextInt()
   M = nextInt()
   
   values_n = [ nextInt() for i in range(N) ]
   values_m = [ nextInt() for i in range(M) ]
   
   print(min(selection_sort(values_m),selection_sort(values_n)))
      

def main():
    #activeReadFile()
    solve()

if __name__ == '__main__':
    main()