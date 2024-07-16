#metrosPiePulgadas.py
#
#Alumno; José Jesús Orozco Hernández
#ID; 00000229141
#Creado el 27/01/2023

print ("Programa para convertir metros en su equivalante a pies y pulgadas")
print ("------------------------------------------------------------------")

#lee la cantidad de metros a convertir
metros =float( input ("Ingresa un valor en metros: "))

#calcula los metros a pies

pies = metros * 3.28084

#calcula los metros a pulgadas
pulgadas = metros *39.3701

#escribe el valor de los metros deseados en pies y en pulgadas
print ("------------------------------------------------------------------")
print ("Resultados de la conversion;")
print ("De metros a pies: "+"{:.4f} metros son: {:.4f}".format(metros, pies),"pies")
print ("De metros a pulgadas: "+"{:.4f} metros son: {:.4f}".format(metros, pulgadas),"pulgadas")
print("")

