"""
@author: vasha
DMOJ - Velas. (https://dmoj.uclv.edu.cu/problem/velas)
Tematica: Dos punteros
Idea: Dada una serie de puntos ubicados en un rayo númericos se quiere buscar
k puntos que están a la menos distancia posible. Lo primero será ordenar las 
posiciones de forma ascendente.
Para solucionar el problema vamos a utilizar dos punteros al arreglo los cuales
vamos a estar a distancia de k posiciones. Estos lo hacemos por todos los i lo
que los punteros estarán en i y i+k ahora analizamos valores que estan en esas
posiciones :
   Si [k+i] < 0 significa que los puntos estan todos la izquierda del cero que
   es el punto de inicio por tanto la distancia a recorrer el valor almacenado
   abs([i])
   Si [i] > 0 significa que los puntos estan todos la derecha del cero que
   es el punto de inicio por tanto la distancia a recorrer el valor almacenado
   [i+k]
   Para otro cualquier caso significa que hay puntos a la izquierda y derecha 
   del cero por lo que podemos ir primero a la izquierda y luego a la derecha 
   o vicersa . En cualquier caso habra una tramo (a la derecha o izquierda del 
   cero) que se repetira por tanto la solución para este caso será:
      min( abs([i])*2 + [k+i] , abs([i]) + 2*[k+i] )
   Simplificando todo lo anterior dos que queda que la solución sera el menor
   valor que puede generar todas posibles tuplas (i,i+k) lo cual podemos 
   expresar de la siguiente manera:   
       (values[e]-values[b])+min(abs(values[b]),abs(values[e]))
   Donde e es i+k y b es i
"""
from collections import deque
		

if __name__ == "__main__":
  [n,k] = input().split()
  n = int(n)
  k = int(k)	
  values = input().split()
  values = [int(x) for x in values]
  b = 0
  e = k-1
  distance = 2*abs(values[n-1])+2*abs(values[0])
  while e < n :
      t = (values[e]-values[b])+min(abs(values[b]),abs(values[e]))
      distance = min(t,distance)
      b = b + 1
      e = e + 1
  print(distance)
  