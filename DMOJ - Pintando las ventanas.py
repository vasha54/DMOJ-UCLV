#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
@author: vasha
DMOJ - Pintando las ventanas.
Tematica: Aritmetica-Algebra+ Teoria de número . Fibonacci , exponeciacion matricial
Idea: Si llamamos a FB(x) la cantidad de formas que se puede pintar una ventana en x
franjas pero siendo la última franja de color blanco. Veremos que:
   FB(x) = FB(x-2) + FR(x-1) donde FB(x-2) es lo mismo pero para una cantidad de
   franja igual a x-2. Mientras FR(x) indicará la cantidad de ventanas puedo crear
   tal que la última franja x sea roja. De esto tambien se deduce que:
   FR(x) = FR(x-2) + FB(x-1)
   Por tanto la solución será:
   FFinal(x) = (FB(x-1)+FB(x-2))*2 
   
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

def multiply_matrix(A,B):
   global MOD
   result = [[0 for _ in range(len(B[0]))] for _ in range(len(A))]
   for i in range(len(A)):
      for j in range(len(B[0])):
         for k in range(len(B)):
            result[i][j] = (result[i][j] + (A[i][k]*B[k][j]) % MOD)% MOD
   return result

def power_binary_matrix(A,n):
   if n == 0:
      return [[1 if i==j else 0 for j in range(len(A))] for i in range(len(A))]
   elif n == 1:
      return A
   else:
      midle = power_binary_matrix(A, n//2)
      if n%2 == 0:
         return multiply_matrix(midle, midle)
      else:
         return multiply_matrix(multiply_matrix(midle, midle),A)
  
def solve():
   N = nextInt()
   fibbo = [[1,1],[1,0]]
   result = power_binary_matrix(fibbo, N)
   print((result[0][1]*2)%MOD)
      
   

def main():
    #activeReadFile()
    solve()

if __name__ == '__main__':
    main()