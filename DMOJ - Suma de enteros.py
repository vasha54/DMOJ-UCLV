#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
@author: vasha
DMOJ - Suma de enteros
Tematica: Aritmetica y algebra: Sumatoria de Gauss + Busqueda binaria
Idea: Dado un numero S se quiere saber si se puede formar con las suma de todos
los números de 1 a n  mas cualquier numero p que este en el rango de 1 a n para
resolver podemos buscar para que n se cumple que:
   S - Gauss(n) <= n donde Gauss(x) = (x(x+1))/2
Para buscar el valor de n y el valor p utilizaremos busqueda binaria.
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

def search(x):
   ll = 1
   lr = 10**18
   while ll <= lr:
      pivot = (ll+lr)//2
      gauss = (pivot * (pivot+1))//2
      rest = x - gauss
      if rest >0 and rest <=pivot:
         return (pivot,rest)
      elif rest > pivot:
         ll = pivot + 1
      else:
         lr = pivot - 1
   return (0,0)

def solve():
   N = nextInt()
   answer = search(N)
   print(answer[0], answer[1] if answer[1]!=0  else '')
   
      
def main():
    #activeReadFile()
    solve()

if __name__ == '__main__':
    main()