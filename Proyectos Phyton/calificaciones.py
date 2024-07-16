import math
import os


def leeCalifs():
    calificaciones = []

    n_alumnos = int(input('\nDigite la cantidad de alumnos a ingresar calificaciones: '))
    os.system('cls')  
    for alumno in range(n_alumnos):
        print()
        calificacion = float(input('Digite la calificacion{}: '.format(alumno+1)))
        if(calificacion <= 10 and calificacion > 0):
            calificaciones.append(calificacion)
        else:
            os.system('cls')  
            print('\nCalificacion invalida, solo calificaciones entre 0-10\n')
            calificacion = float(input('Digite la calificacion{}: '.format(alumno+1)))
            calificaciones.append(calificacion)
        os.system('cls')  
    return calificaciones


def mediaDesvest(calificaciones):
    suma_calificaciones = 0.0
    calificacion_cuadrada = 0.0
    suma_cuadrada_calificaciones = 0.0
    for calificacion in calificaciones:
        suma_calificaciones += calificacion
        calificacion_cuadrada = calificacion**2
        suma_cuadrada_calificaciones += calificacion_cuadrada
    
    media_cuadrada_calificaciones = suma_cuadrada_calificaciones/len(calificaciones)
    media_calificacion = suma_calificaciones/len(calificaciones)
    desviacion_estandar = math.sqrt((media_cuadrada_calificaciones - (media_calificacion**2)))

    return media_calificacion, desviacion_estandar


def generaCalifsLetra(calificaciones, media_calificacion, desviacion_estandar):
    calificaciones_letra = []

    for alumno, calificacion in enumerate(calificaciones):
        calificaciones_letra.append(obtenCalifLetra(media_calificacion, desviacion_estandar, calificacion))
    
    return calificaciones_letra


def obtenCalifLetra(media_calificacion, desviacion_estandar, calificacion=None):
    if media_calificacion + desviacion_estandar <= calificacion:
        calificacion_letra = "A"
    elif media_calificacion + (0.5 * desviacion_estandar) <= calificacion < media_calificacion + desviacion_estandar:
        calificacion_letra = "B"
    elif media_calificacion - (0.5 * desviacion_estandar) <= calificacion < media_calificacion + (0.5 * desviacion_estandar):
        calificacion_letra = "C"
    elif media_calificacion - desviacion_estandar <= calificacion < media_calificacion - (0.5 * desviacion_estandar):
        calificacion_letra = "D"
    elif calificacion < media_calificacion - desviacion_estandar:
        calificacion_letra = "F"
    
    return calificacion_letra


def listaCalifs(calificaciones, calificaciones_letra):
    print('\n          ALUMNO Y CALIFICACION \n')
    print(' ________________________________________')
    print('| Alumno  |  CAL Numerica |   Cal Letra  |')
    print(' ________________________________________ ')

    for alumno in range(len(calificaciones)):
        print('|{:5d}    |{:10.2f}     |{:>7}       |'.format(alumno + 1, calificaciones[alumno],calificaciones_letra[alumno]))
        print('|_________|_______________|______________|')


print('\nPrograma de captura de calificaciones numericas(0-10) de un grupo, y conversion a letra en una determinada escala ')

calificaciones=leeCalifs()

media_Calificaciones,escala_Calificaciones=mediaDesvest(calificaciones)

califsLetra= generaCalifsLetra(calificaciones, media_Calificaciones, escala_Calificaciones)

listaCalifs(calificaciones, califsLetra)

print ('\nMedia de calificaciones es de {:.2f} y su desviacion estandar es de {:.2f}'.format(media_Calificaciones,escala_Calificaciones))
input()