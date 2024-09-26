#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
@author: vasha
DMOJ - Competencia por equipos
Tematica: Simulación
Idea: Se tiene una serie de m mesas y sillas de n colores. Se quiere que cada
mesa tenga cuatro sillas del mismo color y que exista al menos una mesa con uno
de los n colores disponibles de sillas. Para comprobar que la decoración sea posible
debemos comprobar que m>=n de no ser así uno de los n colores de sillas no se podrá
poner en al menos una de las mesas. Luego intentamos cubrir una mesa con cada color
disponible . Luego con las sillas disponibles intentamos cubrir las mesas disponibles
siempre con sillas del mismo color si al final quedan mesas cubrir entonces no
se podrá realizar la decoración deseada.
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


def solve():
   ntables = nextInt()
   nchairs = nextInt()
   chairs = [ nextInt() for i in range(0,nchairs) ]
   decoration = True
   if ntables >= nchairs:
      for i in range(0,nchairs):
         decoration = False  if 4 > chairs[i] else decoration
         ntables = ntables - 1 if 4 <= chairs[i] else ntables
         chairs[i] = chairs[i] - 4 if 4 <= chairs[i] else chairs[i]
      for i in range(0,nchairs):
         while ntables > 0 and 4 <= chairs[i]:
            ntables = ntables - 1
            chairs[i] = chairs[i] - 4
      decoration = False  if ntables > 0 else decoration
   else:
      decoration = False
      
   print("DA" if decoration else "NE")
    
      

def main():
    activeReadFile()
    solve()

if __name__ == '__main__':
    main()