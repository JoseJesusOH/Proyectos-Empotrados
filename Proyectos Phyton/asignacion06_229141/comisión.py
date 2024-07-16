#comisión.py
#
#Alumno; José Jesús Orozco Hernández
#ID; 00000229141
#Creado el 30/01/2023

print ("Programa que calcula la comision por ventas")
print ("")
#lee la cantidad vendida
venta= float(input("Ingrese la cantidad vendida en el mes: "))

#calcula la comicion dependiendo la cantidad vendida

#calcula la comision si la venta es mayor a 50000
if venta>=50000:
	comision=venta*0.1
else:

	#calcula la comision si la venta es mayor a 10000
	if venta>=10000:
		comision=venta*0.075
	else:
		
		#calcula la comision si la venta es mayor a 5000
		if venta>=5000:
			comision=venta*0.05
		else:
			
			#calcula la comision si la venta es mayor a 1000
			if venta>=1000:
				comision=venta*0.025

			#si la venta es menor a 1000 la comision es de 0		
			else:
				comision=0

#escribe la comision que corresponde de acuerdo a lo vendido
print ("\nLa comisión por la venta es de: ${0:.2f}\n".format(comision))
