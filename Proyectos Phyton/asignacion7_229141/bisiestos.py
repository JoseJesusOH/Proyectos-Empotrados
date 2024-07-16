#bisiestos.py
#Alumno Jose Jesus Orozco Hernandez
#ID; 00000229141

print ('\nPrograma que indica que año es bisiesto en un rango de años\n')

añoInicial =int(input ('Ingresa el año inicial que desea consultar: '))

añoFinal =int(input ('\nIngresa el año final que desea consultar: '))
print('')

while añoInicial<=añoFinal:
	if ((añoInicial %4 == 0 and añoInicial %100!=0) or añoInicial %400==0):
		print (int(añoInicial), '  es un año bisiesto')
	añoInicial+=1
