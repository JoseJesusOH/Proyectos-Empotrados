#bisiestos2.py
#Alumno; Jose Jesus Orozco Hernandez ID; 00000229141
#Programa que lee dos anhos y que determina todos los anhos bisiestos entre esos dos anhos


def leeAnhos():
    # Leer los años
    while True:
        anoInicial = int(input('Ingresa el año inicial: '))
        anoFinal = int(input('\nIngresa el año final: '))
        if anoInicial > anoFinal:
            print("El año inicial no debe de ser mayor al final")
        elif anoFinal < anoInicial:
            print("El año final no debe ser menor que el inicial")
        elif anoInicial == anoFinal:
            print("Los años no deben de ser iguales")
        else:
            break
    print("")
    return anoInicial, anoFinal

def esBisiesto(año):
    #Determina si es bisiesto o no
	if ((año %4 == 0 and año %100!=0) or año %400==0):
		return True



def listaBisiestos(f,añoInicial,añoFinal):
    #Despliega los años bisiestos
	for ano in range (añoInicial, añoFinal + 1):
		if f(ano):
			print("El año ", ano,"Es bisiesto")

#imprime el titulo del programa
print ('\nPrograma que determina los años bisiestos en un rango de años\n')

años=leeAnhos()

listaBisiestos(esBisiesto,años[0],años[1])


