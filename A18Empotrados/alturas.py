# alturas.py

#Por Giovanni Garrido
#ID 00000228724
#Creado el 15/11/2022
# Programa que maneja las alturas y matriculas de un grupo de alumnos
# 

# imports
import math

#funcion que lee los datos de los alumnos hasta que la matricula sea 0
def leeDatos():
    matricula = 1
    cont = 0
    alumnoL = []
    
    while(matricula > 0):
        # Contador de los alumnos
        cont += 1
        # Lee  la matricula
        matricula = int(input(f'Matricula del alumno {cont:d}, 0 para terminar? '))
        # Si la matricula es 0 se deja de leer
        if matricula == 0:
            break
        #Lee la altura    
        altura = float(input(f'Altura del alumno {cont:d}? '))
        # Crea una tupla con la matricula y altura
        alumnoT = matricula, altura
        # La agrega a la lista
        alumnoL.append(alumnoT)

    return alumnoL

# Despliega los datos de los alumnos    
def despliegaDatos(alumnoL):
    print('Lista de alumnos')
    print()
    print('|  Mat    |Altura |')
    print('|---------|-------|')
    
    for matricula, altura in alumnoL:
        print('|{:7d}  |{:5.2f}  |'.format(matricula,altura))
        print('|---------|-------|')
    
# Ordena los alumnos por el parametro dado
def ordSeleccion(alumnos, fmenor):
    for i in range(len(alumnos)-1):
        menor = i

        # busca el menor
        for j in range(i + 1, len(alumnos)):
            # Si hay uno menor, guarda su posicion en menor
            if fmenor(alumnos[j], alumnos[menor]):
                menor = j

        # Si el menor no es el primero de los no acomodados
        if menor != i:
            # intercambia sus posiciones
            alumnos[menor], alumnos[i] = alumnos[i], alumnos[menor]

# Compara los alumnos para ver cual tiene una matricula menor
def menorMatricula(alumno1, alumno2):
    return alumno1[0] < alumno2[0]

# Compara los alumnos para ver cual tiene una altura menor
def menorAltura(alumno1, alumno2):
    return alumno1[1] < alumno2[1]

# Funcion calcula la altura menor y mayor de todos los alumnos
def rango(alumnoL,fmenor):
    for i in range(len(alumnoL)-1):
        menor = i

        # busca el menor
        for j in range(i + 1, len(alumnoL)):
            # Si hay uno menor, guarda su posicion en menor
            if fmenor(alumnoL[j], alumnoL[menor]):
                menor = j

        # Si el menor no es el primero de los no acomodados
        if menor != i:
            # intercambia sus posiciones
            alumnoL[menor], alumnoL[i] = alumnoL[i], alumnoL[menor]

    alumT = alumnoL[len(alumnoL)-1], alumnoL[0]
    return alumT

# Funcion que calcula la media y desviacion estandar de las alturas de los alumnos
def mediaDesvEst(alumnosL):
    suma = 0
    sumaC = 0
    i = 0
    n = len(alumnosL)
    for matricula,altura in alumnosL:
        suma += altura
        sumaC += altura**2
    
    # calculo de la media de las alturas
    media = suma/n
    # calculo de la media de las alturas al cuadrado
    mediaC = sumaC/n
    # calculo de la desviacion estandar de las alturas
    desvia = math.sqrt((mediaC-(media**2)))
    
    mediaDe = (media,desvia)
    
    return mediaDe

# Funcion que calcula el numero de alumnos que son mas altos que la media + la desviacion estandar
def altos(alumnoL,mediaDe):
    media = mediaDe[0]
    desvia = mediaDe[1]
    md = media + desvia
    altos = 0
    for matricula,altura in alumnoL:
        if (altura > md):
            altos += 1
    return altos

# Funcion que busca la altura del alumno segun su matricula
def secuencial(matBuscar, alumnos):
    # Para cada alumno de la lista obten su matricula y altura
    for matricula, altura in alumnos:
        if matBuscar == matricula:
            return altura
    else:
        return None




