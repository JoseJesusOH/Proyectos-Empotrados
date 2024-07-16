# mosaico.py

#Alumno; José Jesús Orozco Hernández
#ID; 00000229141
#Creado el 30/01/2023

import math
print("Programa que calcula el numero de cajas de mosaico que se requiere para el piso de una casa")

# lee los metros cuadrados del piso de la casa
piso = float(
    input("Ingrese los metros cuadrados que tiene el piso de la casa: "))

# lee el tipo de mosaico
tipo = input("Ingresa el tipo de mosaico (P) Primera o (S)Segunda): ")

# calculos si el piso es de primera
if tipo == "P":

    # calcula los metros de mosaico.
    metrosMosaico = piso*1.1

    # calcula la cantidad de cajas requeridas.
    cajas = math.ceil(metrosMosaico)

    # calcula el costo de las cajas de mosaico
    costo = cajas*150

# calculos si el piso es de segunda.
else:
    if tipo == "S":

        # calcula los metros de mosaico.
        metrosMosaico = piso*1.15

        # calcula la cantidad de cajas requeridas.
        cajas = math.ceil(metrosMosaico)

        # calcula el costo de las cajas de mosaico
        costo = cajas*125


# manda mensaje de error si el usuario escoge un tipo de placas no valido
    else:
        print("\nNo es un tipo valido\n")
        quit()


# escribe la cantidad de cajas a comprar y el costo total
print("\nCajas a comprar: ",cajas)
print("\nEl costo de estas cajas es de: ",costo,"\n")
