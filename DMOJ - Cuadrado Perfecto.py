#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
@author: vasha
DMOJ - Cuadrado Perfecto
Tematica: Busqueda 
Idea: Dado que los valores son pequeños podemos hacer una busqueda lineal por
cada posible cuadrado de los numeros del rango [1,500]
"""

#Begin the template for read data from console o file
buffer = []
bufferFile = []
READ_FILE = False

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
   squares = [i**2 for i in range(1,510)]
   N = nextInt()
   solutions = 0
   for minNumber in squares:
      maxNumber = minNumber + N
      if maxNumber > squares[-1]:
         break;
      if maxNumber in squares:
         solutions = solutions + 1
   print(solutions)
   

def main():
    #activeReadFile()
    solve()

if __name__ == '__main__':
    main()