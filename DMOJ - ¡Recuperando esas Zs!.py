#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
@author: vasha
DMOJ - ¡Recuperando esas Zs!
Tematica: String
Idea: Dada una cadena determinar si tien 3 o mas z sin importar la 
capitalización
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
    #global READ_FILE
    READ_FILE= True
#End the template for read data from console o file

def proccess(y):
   is_capicua = 1
   fill = 0
   max_digit = -1
   y = str(y)
   begin = 0
   end = len(y)-1
   while begin < end:
      a = int(y[begin])
      b= int(y[end])
      if a != b:
         is_capicua = 0
         fill = fill + abs(a-b)
      max_digit = max(max_digit,max(a,b))   
      begin = begin + 1
      end = end - 1
   return is_capicua,fill,max_digit

def solve():
   cases = nextInt()
   for i in range(0,cases):
      string = readData().lower()
      print("Time to take a nap." if string.count('z') >= 3 else "Perry saves the day!")
      

def main():
    #activeReadFile()
    solve()

if __name__ == '__main__':
    main()