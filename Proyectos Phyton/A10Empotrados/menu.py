#menu.py
#Alumno; Jose Jesus Orozco Hernandez ID; 00000229141
#Programa que tabula e integra funciones.


import os

def menu ():
    #Desplegia el menu y regresa la opcion
    while True:
        print("Escriba la opcion deseada:  \nI - integrar \n T - tabular S - salir")
        opcion= input()
        if opcion == "T" or opcion=="I" or opcion=="S" or opcion == "t" or opcion=="i" or opcion=="s":
            break
        else:
            print("La opción ingresada no es válida")
        break

    return opcion

def leeDatosIntegracion ():
    ##Lee los límites de integración y el número de rectángulos.
    os.system('cls')
    print('\nCalculo del area de bajo de la curva de Y= X^3-2X+3')
    xI = float(input('Escriba el valor para Xi: '))
    xF = float(input('Escriba el valor para Xf: '))
    n = int(input('Escriba el numero de triangulos el numero de rectangulos: '))
    return xI, xF, n

def integrar(xI,xF,n):
        ##Se integra la funcion
	base=(xF-xI)/n
	sumaH=0
	rectangulo=1
	x=xI
	while rectangulo<=n:
		h=x**3-2*x+3
		sumaH=sumaH+abs(h)
		x=x+base
		rectangulo+=1
	area= base*sumaH
	print ('\nEl area entre los valores es : {:.2f}'.format(area))
	
	input("Si desea continuar , presione alguna tecla")


def leeDatosTabulación ():
    # Leera los valores de los límites inferior, superior y el incremento.
    os.system('cls')
    print ("Tabulacion con respecto a Y= X^3-2X+3")
    xi = float(input('Escriba el límite inferior: '))
    xf = float(input('Escriba  el límite superior: '))
    n = int(input('Escriba el el incremento : '))
    return xi, xf, n

def tabular(xI,xF,n):

	# Tabular la funcion
	print("")
	print("   X         Y ")
	print("______   _______")
	while xI<=xF:
		x=xI
		y=x**3 -2*x+3

		print('{:.2f}   {:.2f}'.format(x,y))
		xI=xI+n
	input("Si desea continuar , presione alguna tecla")

# Se despliega el menu

while True:
    opcion = menu()
    if opcion == "I" or opcion=="i":
        datos = leeDatosIntegracion()
        integrar(datos[0],datos[1],datos[2])
    elif opcion == "T" or opcion=="t":    
        datos = leeDatosTabulación()
        tabular(datos[0],datos[1],datos[2])
    elif opcion=="S" or opcion=="s": 
        break
    