#include <iostream>

/*Biblioteca muy util con varias funciones*/

#include <algorithm>
#define ENDL '\n'
#define LL long long
using namespace std;

int ordenar(int cases,LL largo [], LL ancho []){
    /*1era modificacion si vas a utilizar
    a ax y y como variables de intercambios para
    los valores del arreglos que sean del mismo tipo de datos
    esto da problema, te las deje por un detalle veras que luego no
    hace falta*/
    LL x,y;

    for(int i=0;i<cases;i++){
        /*2da modificacion hace el ordenamiento mas rapido*/
        for(int j=i+1;j<cases;j++){

            /*3era ordenamos de forma creciente*/
            if( largo[j] < largo[i] || (largo[j] == largo[i] && ancho[j] < ancho[i]) ){
               /*4ta Si quieres intercarmbiar dos valores de dos variables
               usa el metodo swap se fueron a la mierda x y y*/
               swap(largo[i],largo[j]);
               swap(ancho[i],ancho[j]);
            }
        }
    }

    /*5ta de aqui para abajo fue borron y cuenta nueva y vamos a aplicar
    lo que te explique por WhatApp*/

    /*En este arreglo en cada posicion voy almacenar la maxima torre
    que se puede construir tomando a la caja de la posicion i como base
    de la torre es decir la que va sostener a las demas por defecto
    el valor de cada posicion será 1 (torre de una caja, la caja i)*/
    int * towers = new int [cases];

    /*Variable que va almacenar la torre de mayor cantidad de cajas
    que se puede construir de todas las posibles*/
    int maxTowers =-1;

    /*Inicializo todas las posiciones del areglo con valor 1
    la funcion fill se la le pasa la posicion inicial y final
    del arreglo asi el valor por defecto en cada posicion*/
    fill(towers,towers+cases,1);

    for(int i=1;i<cases;i++){
        for(int j=0;j<i;j++){
            /*Si esto se cumple signfica que el largo de la caja
            i es mayor o igual que el largo de la caja j (ordenamiento)
            y ademas el ancho de la caja j es menor o igual que el ancho
            de la caja i por tanto puedo colocar la caja j sobre la
            caja i en la torre*/
            if( ancho[i] >= ancho[j]){
                /*Ahora voy a quedarme con la mejor torre entre
                la torre que tenia la caja i como base calculada
                hasta ese momento o la torre que tenia como base
                la caja j ahora añadiendo la caja
                i como base de esta (+1 caja)*/
                towers[i]=max(towers[i],towers[j]+1);
            }
        }
        /*Una vez determinado todas las posibles torres
        que se pueden construir utilizando la caja i como base
        y cual es la que tiene mayor cantidad de cajas
        veo si dicha cantidad es mayor de todas las posibles
        torres construida*/
        maxTowers = max(towers[i],maxTowers);
    }

    return maxTowers;
}

/*6to metodo ordenar_anacho lo vi inncesario mas adelante veras como
resolvemos que ordene por ancho y no por largo*/

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cases;
    cin>>cases;
    LL largo[cases],ancho[cases];

    for(int i=0;i<cases;i++){
        cin>>largo[i]>>ancho[i];
    }
    int a=ordenar(cases,largo,ancho);
    /*Que tal como quedo el giro de noventa grado
    de todas las cajas, ahorre codigo y tiempo de codificacion
    no te preocupe eso se coje con el tiempo*/
    int b=ordenar(cases,ancho,largo);

    cout<<max(a,b)<<ENDL;


    return 0;
}