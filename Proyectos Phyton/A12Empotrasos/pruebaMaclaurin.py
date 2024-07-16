# pruebaMaclaurin.py
#José JEsús Orozco Hernández ID; 00000229141
#
#El programa llamará al módulo maclaurin.py  para realizar las operaciones
#que se encuentran en ella , tabule la función que se pida y pregunte si 
#el usuario quiere repetir el cálculo.


import maclaurin
import os

print("Programa que importa al módulo maclaurin.py y realiza determinar funciones")
print("Calcular el seno, el exponente, o tabular")
opcion = "S"
while True:
    while True:
        f=input("Si desea tabular Seno=S o Exponencial E; ")
        if f=="S" or f=="s" or f=="E" or f=="e":
            break
        else:
            print("La opcion ingresada es invalida")
    while True: 
        try: 
            x = float(input("Escriba el valor de x: "))
            break
        except:
            print("Digite alguna caracter valido")
    while True: 
        try: 
            nMin = int(input("Escriba el valor de nMin: "))
            break
        except:
            print("Digite alguna caracter valido")

    while True: 
        try: 
            nMax = int(input("Escriba el valor de nMax: "))
            break
        except:
            print("Digite alguna caracter valido")

    while True: 
        try: 
            incN = int(input("Escriba el Valor de incN : "))
            break
        except:
            print("Digite alguna caracter valido")
   
    
    maclaurin.tabulaFuncion(f, x, nMin, nMax, incN)
    opcion = input("Si desea continuar digite S, caso contrario N ")
    if opcion=="N" or opcion=="n":
        print("Gracias vuelva pronto")
    elif opcion=="S" or opcion=="s":
        input("Gracias se reiniciaran los datos, seleccione alguna tecla para empezar") 
        os.system('cls') 
        