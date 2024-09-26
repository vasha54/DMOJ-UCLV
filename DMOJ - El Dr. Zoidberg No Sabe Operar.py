#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
@author: vasha
DMOJ - El Dr. Zoidberg No Sabe Operar
Tematica: Aritmetica Sumatoria de Gauss
Idea: El doctor solo podra operar si sumando los valores en orden dado siempre 
la suma de los valores es igual o mayor que la sumatoria de gauss hasta el inesimo
elemento y al final la suma de los n elementos es igual a la sumatoria de gauss
hasta n. 
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


def solve():
   is_operable = True
   n = nextInt()
   sums_x = 0
   sums_gauss = 0
   for i in range(1,n+1):
      x = nextInt()
      sums_x = sums_x + x
      sums_gauss = sums_gauss + i
      is_operable = False if sums_x < sums_gauss else is_operable
      
   is_operable = False if sums_x != sums_gauss else is_operable   
   print("Si" if is_operable else "No")
    
      

def main():
    #activeReadFile()
    solve()

if __name__ == '__main__':
    main()