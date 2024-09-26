#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
@author: vasha
DMOJ - A su lado
Tematica: Aritmetica y algebra: Inecuaciones + Busqueda Binaria
Idea: Dado cuatro valores A, B, C y D se quiere hallar el menor valor de x 
entero positivo tal qque se cumpla la siguiente desigualdad:
  ( A + Bx )  <=  D(Cx)
Para buscar el valor de x podemos iterar desde 0 hasta 10⁵ encontrar el primero 
que cumpla la condición o podemos realizar una busqueda binaria en el rango [0, 10⁵]
conn una estrategia de lower_bound para quedarnos con el  menor valor que cumple 
la condición.
"""
import math

#Begin the template for read data from console o file
buffer = []
bufferFile = []
READ_FILE = False
MOD = 10**9+7
MAX_N = 10**6+10

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

def f(A,B,C,D,x):
   term1 = (A+B*x)
   term2 = C*x
   return term1  <= D * term2 

def search(A,B,C,D):
   ll = 0
   lr = 10**5+1
   answer = -1
   while ll <= lr:
      pivot = (ll+lr)//2
      fx = f(A,B,C,D,pivot)
      if fx:
         answer = pivot if answer== -1 else min(pivot,answer) 
         lr = pivot -1
      else:
         ll = pivot + 1
   return answer

def solve():
   A = nextInt()
   B = nextInt()
   C = nextInt()
   D = nextInt()
   answer = search(A,B,C,D)
   print(answer)
   
      
def main():
    #activeReadFile()
    solve()

if __name__ == '__main__':
    main()