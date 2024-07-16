#areaVolumenEsfera.py
#
#Alumno; José Jesús Orozco Hernández
#ID; 00000229141
#Creado el 27/01/2023

print ("Programa que indica a una cajera número y denominación de los ")
print ("billetes que necesita darle a un cliente al hacer un retiro")
print ("---------------------------------------------------------------")
#Lee la cantidad a retirar
cantidad =float(input ("\nIngresa la cantidad a retirar: "))

#condiciona que el retiro debe ser multiplo de 50
if cantidad %50 == 0:
	

	#calcula la cantidad de billetes a entregar de cada denominacion
	billete1000 = cantidad // 1000
	residuo = cantidad % 1000
	
	billete500 = residuo // 500
	residuo %= 500
	
	billete100 = residuo // 100
	residuo %= 100

	billete50 = residuo // 50
	residuo %= 50	
 #escribe la cantidad y denominacion de los billetes a entregar
	print ("--------------------------------------------------------")
	print ("Resultados de la operacion; ")
	print ("dar {:^5d} billetes de $1000".format(int(billete1000)))
	print ("dar {:^5d} billetes de $500".format(int(billete500)))
	print ("dar {:^5d} billetes de $100".format(int(billete100)))
	print ("dar {:^5d} billetes de $50".format(int(billete50)))
 #escribe mensaje si el retiro no es multiplo de 50
else:
	print ("cantidad incorrecta, debe ser multiplo de 50")

