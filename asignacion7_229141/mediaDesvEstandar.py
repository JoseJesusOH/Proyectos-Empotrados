#mediaDesvEstandar.py
#Alumno Jose Jesus Orozco Hernandez
#ID; 00000229141

import math


print('Programa que calcual la media y desviacion estandar de las calificaciones de un grupo de alumnos')

#Lectura del total de alumnos
totalGrupo=int(input ('Ingrese número de alumnos del grupo: '))

#Variables a utilizar
suma=0
sumaCuadrado=0
cuadrado=0
i=totalGrupo
contador=1

#miesntras el numero de alumnos sea mayor a 0 se ejecutara el contenido de la sentencia while
while i>0:
	
	#lee la calificacion 
	print('Digite la calificacion del alumno '+str(contador))
	califificacion=float (input())
	
	#suma de calificaciones
	suma=suma+califificacion
	#Se eleva al cubo la calificacion
	cuadrado=califificacion**2

	#Suma de los cuadrados
	sumaCuadrado=sumaCuadrado+cuadrado
	
	#disminuye en 1 el total de alumnos declarados
	i-=1

	#aumenta en 1 el contador de calificaciones ingresadas
	contador+=1

#Calculo de la media
media=suma/totalGrupo

#Media del cuadrado
mediaCuadraCalifi=sumaCuadrado/totalGrupo

#calcula la desviacion estandar
desEstandar= math.sqrt((mediaCuadraCalifi-(media**2)))

#imprime la media y desviacion
print('\n\nLa media del grupo ingreesado es: {0:.2f}'.format(media))
print('\nLa desviación estandar es: {0:.2f}'.format(desEstandar))
print("")