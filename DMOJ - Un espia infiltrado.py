"""
DMOJ - Un espia infiltrado
Tematica : Trabajo matrices

Idea : Se tiene una matriz que representa un mapa donde se distingue tres
simbolos:

. -> celda vacia
# -> celda con un muro
P -> celda ocupada por un guardian

Algunos de los guardias son espias pero se necesita determinar la cantidad
mínima y maxima de posibles espias que existen entre los guardias conociendo
unicamente los siguiente:
	- Un verdadero guardia se ubica en una posición que a lo sumo tendrá
	un muro en alguna de las posiciones adyacentes. 
	- Un verdadero espias tratara de ubicarse en alguna posición que tenga
	la maxima cantidad de muros en posiciones adyacentes

Dos celdas son adyacentes si comparten un lado en común. 

Para buscar la minima cantidad de espias posibles contaremos aquellos 
guardias que en su posición tienen dos o mas muros adyacentes. Mientras
para buscar la máxima cantidad de espía contaremos aquellos guardias que 
su posición es al menos adyacentes a un muro.

"""
import sys

mov_r = [0, 0, 1,-1]
mov_c = [1,-1, 0, 0]

def countWall(r,c,rows,columns,board):
	s = 0
	for i in range(0,len(mov_c)):
		rr = r + mov_r[i]
		cc = c + mov_c[i]
		if 0 <= rr and rr < rows and 0 <= cc and cc < columns and board[rr][cc] == '#':
			s = s + 1
	return s

if __name__ == "__main__":
	rows,columns=[int(e) for e in input().split()]
	board = ['' for e in range(0,rows)]
	for i in range(0,rows):
		board[i] =str(input())
	
	maxSpy = 0
	minSpy = 0
	
	for i in range(0,rows):
		for j in range(0,columns):
			if board[i][j] == 'P':
				cWall = countWall(i,j,rows,columns,board)
				if cWall >= 1:
					maxSpy = maxSpy + 1
				if cWall >= 2:
					minSpy = minSpy + 1
	
	print(minSpy,maxSpy)
    
    
