'''
calificaciones.py

Por Giovanni Garrido
ID 00000228724
Creado el 08/11/2022
Programa que captura las calificaciones numericas  (0 - 10) de un grupo
y las convierte a calificaciones de acuerdo a siguiente criterio:

mediaCalif+sCalif<=calif                                "A"
mediaCalif+0.5sCalif<=calif<mediaCalif+sCalif           "B"
mediaCalif-0.5sCalif<=calif<mediaCalif+0.5sCalif        "C"
mediaCalif-sCalif<=calif<mediaCalif-0.5sCalif:          "D"
calif<mediaCalif-sCalif                                 "F"

'''
#importa la libreria math
import math
#importa la libreria os
import os


def leeCalifs():
    ''' Esta función lee las calificaciones de los alumnos y las
        almacena en la lista calificaciones
        
        @return Una lista con las calificaciones numericas        
    '''  
    calificaciones = []

    #lee el numero de alumnos
    nAlumnos = int(input('\nIngresa el numero de alumnos: '))
   
    os.system('cls')    # Borra la pantalla

    #para cada alumno
    for alumno in range (nAlumnos):

        #lee las calificaciones y las condiciona tiene que ser un valor entre el 0 y el 10
        print()
        calificacion = float (input('Calificacion del alumno {}: '.format(alumno+1)))
        if(calificacion<=10 and calificacion>0):
            calificaciones.append(calificacion)
        #si no es un valor entre el 0 y el 10, manda mensaje de advertencia y solicita nuevamente la calificacion   
        else:
            os.system('cls')    # Borra la pantalla
            print('\nCalificaion no valida, ingrese una calificion de 0-10\n')
            calificacion = float (input('Calificacion del alumno {}: '.format(alumno+1)))
            calificaciones.append(calificacion)
        os.system('cls')    # Borra la pantalla

    #regresa las calificaciones
    return calificaciones

def mediaDesvest(calificaciones):
    ''' Esta fucion calcual la media y la desviacion estandar
        de las calificaciones del grupo.
        
        @param calificaciones la lista con las calificaciones
        @return tupla con la media y la desviacion estandar
    '''
    #inicializa variables a utilizar
    sumaCalifs = 0.0
    califCuadra = 0.0
    sumaCuadraCalifs = 0.0

    #para cada calificacion
    for calificacion in calificaciones:
        
        #acumula la suma de las calificaciones
        sumaCalifs +=calificacion
        
        #calcula el cuadrado de la calificacion
        califCuadra = calificacion**2
       
        #acumula el cuadrado de las calificaciones
        sumaCuadraCalifs +=califCuadra

    #calcula la media de la suma de los cuadrados de las calificaciones
    mediaCuadraCalifis = sumaCuadraCalifs/len(calificaciones)

    #calcula la media de las calificaciones
    mediaCalif = sumaCalifs/len(calificaciones)

    #calcula la desviacion estandar de las calificaciones
    sCalif= math.sqrt((mediaCuadraCalifis-(mediaCalif**2)))

    #regresa tupla con la media de las calificaciones y la desviacion estandar
    return mediaCalif, sCalif


def generaCalifsLetra(calificaciones, mediaCalif, sCalif):

    '''
    Esta funcion genera una lista de calificaciones con letra
    a partir de calificaciones numericas.

    @ Param calificaciones lista con las calificaciones numericas
    @ Param mediaCalif : La media de las calificaciones
    @ Param sCalif : La desviacion estandar de las calificaciones
    @ Return Una lista con calificaciones en letra



    '''

    califsLetra = []

    #para cada calificacion
    for alumno, calif in enumerate(calificaciones):

        #ejecuta la funcion obtenCalidLetra
        califsLetra.append(obtenCalifLetra(mediaCalif, sCalif,calif))

    #Regresa lista con las calificaciones en letra
    return califsLetra


def obtenCalifLetra(mediaCalif, sCalif,calif=None):
    '''
    Esta funcion resibe un calificacion numerica y la convierte
    en una calificacion con letra

    @Param mediaCalif Recibe la media de las calificaciones
    @Param sCalif Recibe la desviacion estandar de las calificaciones
    @Param calif Recibe la calificacion a convertir
    @Return califLetra regresa la calificacion con letra

    '''
    #Criterios para convertir las calificaciones numericas a calificaciones con letra
    if mediaCalif+sCalif<=calif:
        califLetra="A"
    elif mediaCalif+(0.5*sCalif)<=calif<mediaCalif+sCalif:
        califLetra="B"
    elif mediaCalif-(0.5*sCalif)<=calif<mediaCalif+(0.5*sCalif):
        califLetra="C"
    elif mediaCalif-sCalif<=calif<mediaCalif-(0.5*sCalif):
        califLetra="D"
    elif calif<mediaCalif-sCalif:
        califLetra="F"

    #Regresa la calificacion con letra
    return califLetra


def listaCalifs(calificaciones, califsLetra):

    '''
    Esta funcion despliega una tabla con las calificaciones
    nuericas y con letra de cada alumno

    @Param calificaciones Recibe las calificaciones numericas
    @Param califsLetra Recibe las calificaciones con letra

    '''

    #escribe la tabla con los valores de las calificaciones en numero y letra
    print ('\n          ALUMNO Y CALIFICACION \n')
    print (' ________________________________________')
    print ('|         |  CALIFICACION | CALIFICACION |')
    print ('| ALUMNO  |    NUMERICA   |    LETRA     |')
    print ('|_________|_______________|______________|')

    #Para cada alumno
    for alumno in range(len(calificaciones)):

        #Escribe las caliicaciones en numero y en letra del alumno
        print('|{:5d}    |{:10.2f}     |{:>7}       |'.format(alumno + 1, calificaciones[alumno],califsLetra[alumno]))
        print('|_________|_______________|______________|')



#Imprime el titulo del programa
print('\nPROGRAMA QUE CAPTURA CALIFICACIONES NUMERICAS (0-10) DE UN GRUPO')
print('          Y LAS CONVIERTE A CALIFICACIONES CON LETRA\n')

#Se leen las calificaciones numericas
calificaciones=leeCalifs()

#Se leen lamedia y la desviacion estandar
mediaCalif,sCalif=mediaDesvest(calificaciones)

#Se leen las calificacion con letra
califsLetra= generaCalifsLetra(calificaciones, mediaCalif, sCalif)

#imprime la tabla con las calificaciones numericas y con letra
listaCalifs(calificaciones, califsLetra)

#imprime la media y la desviacion estandar de las calificaciones
print ('\nLA MEDIA DE LAS CALIFICACIONES ES DE {:.2f} Y LA DESVIACION ESTANDAR ES DE {:.2f}'.format(mediaCalif,sCalif))
#Solo para hacer una pausa
input()