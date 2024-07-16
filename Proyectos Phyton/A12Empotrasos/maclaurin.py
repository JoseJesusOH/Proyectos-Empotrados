# maclaurin.py
#Elumno; José Jesus Orozco Hernandez ID; 00000229141
#Modulo que continene las funciones para calcular seno, exponenciales y tabuñar funciones

import math
#Calcula el seno(x) usando n términos de la serie de Maclaurin.
def seno(x, n):
    ronda = 0
    sumatoria = 0
    while ronda <= n :
        if ronda % 2 == 0 :
            sumatoria += math.radians(x**(2*ronda+1)/math.factorial(2*ronda+1))
        else:
            sumatoria -= math.radians(x**(2*ronda+1)/math.factorial(2*ronda+1))
        ronda+=1
    return sumatoria

#Calcula el exp(x) usando n términos de la serie de Maclaurin:
def exp(x, n):
    ex = 1
    for i in range (1, n):
        termino = x**i/math.factorial (i)
        ex = ex + termino
        i += 1
    return ex

def tabulaFuncion(f, x, nMin, nMax, incN):
    if f == "S": 
        print("-------------------------------------------------------------")
        print("|   Funcion   |   x       |    nMin   |   nMax   |   inc X  |")
        print("-------------------------------------------------------------") 
        for n in range(nMin, nMax, incN):
            s=seno(x,n)
            print("|{:^13}|{:^11.4f}|{:^11}|{:^11}|{:^10}|".format("seno(x,n)", s, nMin, nMax, n))
    else :
        print("-------------------------------------------------------------")
        print("|   Funcion   |   x       |    nMin   |   nMax   |   inc X  |")
        print("-------------------------------------------------------------") 
        for n in range(nMin, nMax, incN):
            ex=exp(x,n)
            print("|{:^13}|{:^11.4f}|{:^11}|{:^11}|{:^10}|".format("expo(x,n)", ex, nMin, nMax, n))

