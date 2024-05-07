#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
@author: vasha
DMOJ - Cantidad de estudiantes según porciento.
Tematica: Teoria de Númmeros. Máximo comun divisor
Idea: Dado 5 (A,B,C,D.E) valores naturales encontrar el menor valor posible X tal
que se cumpla:
   X = AX/100 + BX/100 + CX/100 + DX/100 + EX/100
Para hallar esa tal X solo basta hallar el gcd de los valores diferentes de cero
y luego sumar el resultado de dividir cada valor por el gcd. El hallar el gcd
garantiza buscar el mayor numero natural por el cual podamos reducir o simplificar
los valores para A, B, C, D, E de forma que el resultado final y estos valores sigan
siendo entero.
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
  
def solve():
   cases = nextInt()
   while cases > 0:
      cases = cases - 1  
      A = nextInt()
      B = nextInt()
      C = nextInt()
      D = nextInt()
      E = nextInt()
      percent = [A,B,C,D,E]
      percentNotZero = [t for t in percent if t != 0 ]
      if len(percentNotZero)==0:
         print(0)
      else:
         gcd = percentNotZero[0]
         for y in percentNotZero:
            gcd = math.gcd(gcd, y)
         solution = 0
         for i in percent:
            solution = solution + i//gcd
         print(solution)
      
   

def main():
    #activeReadFile()
    solve()

if __name__ == '__main__':
    main()