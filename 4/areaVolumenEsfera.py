#areaVolumenEsfera.py
#
#Alumno; Jose Jesús Orozco Hernández
#ID 00000229141
#Creado el 27/01/2023

import math

print ("Programa que calculara el area y volumen de una esfera a partir de su radio ")
print ("---------------------------------------------------------------------------")
#lee el radio
radio =float( input ("Ingresa el valor del radio "))

#calula el area y volumen de la esfera
area =  4 * math.pi  * radio ** 2
volumen = 4/3 * math.pi * radio**3
print ("---------------------------------------------------------------------------")
print ("Los resultados son los siguiente; ") 
#escribe el area y volumen de la esfera en notacion flotante con 6 cifras decimales
print ("El area de la esfera es: {:.6f}".format(area))
print ("El volumen de la esfera es: {:.6f}".format(volumen))

