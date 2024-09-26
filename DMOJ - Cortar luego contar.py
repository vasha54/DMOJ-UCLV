#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
@author: vasha
DMOJ - Cortar luego contar.
Tematica: String + Busqueda
Idea: Buscar la forma de dividir la cadena en dos tal que la letras únicas en 
en ambas cadenas sea la mayor posible.
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
   n = nextInt()
   max_sums = 0
   string = nextStr()
   for i in range(0,n):
      max_sums = max(max_sums,len(set( set(string[0:i]).intersection(set(string[i:])))))
   print(max_sums)

def main():
    #activeReadFile()
    solve()

if __name__ == '__main__':
    main()