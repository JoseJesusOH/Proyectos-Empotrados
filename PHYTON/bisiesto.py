#bisiesto.py
#
#Alumno; José Jesús Orozco Hernández
#ID; 00000229141
#Creado el 30/01/2023


#titulo del programa
print ("Programa que indica si un año es bisiesto o no ")

#lee el año que se quiere consultar
año =int(input("\nIngresa el año que desea consultar: "))

#determina si el año es bisiesto o no
if ((año %4 == 0 and año %100!=0) or año %400==0):
	
	# Escribe si el años es bisiesto
	print ('\n',año, " es un año bisiesto")

else:
	#Escribe que el año no es bisiesto
	print ('\n',año," no es un año bisiesto")

