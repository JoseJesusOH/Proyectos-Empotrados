# encuesta2.py

# Por Giovanni Garrido
# ID 00000228724
# Creado el 25/11/2022
# Programas con Diccionarios

# imports
import math
from collections import Counter

# funcion que lee los datos de los alumnos hasta que la matricula sea 0


def leeEncuesta():

    cont = 0
    alumnos = []

    while True:
        # Contador de los alumnos
        cont += 1
        # Lee  la matricula
        matricula = int(
            input(f'Matricula del alumno {cont:d}, 0 para terminar? '))
        # Si la matricula es 0 se deja de leer
        if matricula == 0:
            break
        # Lee el sexo
        sexo = input(f'Sexo (‘M’, ‘F’) del alumno {cont:d}? ')
        # Lee la carrera
        carrera = input(f'Carrera (Siglas de la carrera. Por ejemplo: ‘IE’, ‘ISW’, ‘IC’, LAE’, ‘LPS’, etc.) del alumno {cont:d}? ')
        # Crea una tupla con la matricula, sexo y carrera
        alumnoT = matricula, sexo, carrera
        # La agrega a la lista
        alumnos.append(alumnoT)

    return alumnos


# Despliega una tabla con la lista de matrículas, sexo y carreras de los alumnos.


def despliegaEncuesta(alumnos):
    print('Lista de alumnos')
    print()
    print('|-----------|------|---------|')
    print('| Matricula | Sexo | Carrera |')
    print('|-----------|------|---------|')

    for matricula, sexo, carrera in alumnos:
        print('|{:11d}|{:6s}|{:9s}|'.format(matricula, sexo, carrera))
        print('|-----------|------|---------|')


# cuenta cuantos alumnos hay en cada categoría (combinación de cada sexo y carrera).

def clasificaAlumnosCategoria(alumnos):
    catSexo = []
    catCarrera=[]
    alumnosCategoria={}

    for matricula, sexo, carrera in alumnos:
        catSexo.append(sexo)
        catCarrera.append(carrera)

    alumnosCategoria["sexo"]=catSexo
    alumnosCategoria["carrera"]=catCarrera

    return alumnosCategoria


# despliegue una tabla con el número de alumnos de cada categoría: sexo, carrera.

def despAlumnosCategoria(alumnosCategoria):

    sexoL=alumnosCategoria["sexo"]
    carreraL=alumnosCategoria["carrera"]

    print('Alumnos por categoria')
    print()
    print('|-----------------|')
    print('|----CATEGORIA----|')
    print('|-----------------|')
    print('| Sexo  | Carrera |')
    print('|-------|---------|')
    print('|{:7d}|{:9d}|'.format(len(sexoL),len(carreraL)))
    print('|-------|---------|')



# cuenta cuantos alumnos hay en cada sexo.

def clasificaAlumnosSexo(alumnosCategoria):

    sexoL=alumnosCategoria["sexo"]
    
    conteo = Counter(sexoL)

    alumnosSexo={}

    for clave in conteo:
        valor=conteo[clave]
        alumnosSexo[clave] = valor
    
    return alumnosSexo




# despliegue una tabla con el número de alumnos de cada sexo.

def despAlumnosSexo(alumnosSexo):
    print()
    print('Alumnos por sexo')
    print()
    print('|-----------------|')
    print('| Sexo  | Alumnos |')
    print('|-------|---------|')

    for sexo in alumnosSexo:
        print('|{:7s}|{:9d}|'.format(sexo,alumnosSexo[sexo]))
        print('|-------|---------|')
    


# cuenta cuantos alumnos hay en cada carrera.

def clasificaAlumnosCarrera(alumnosCategoria):

    carreraL=alumnosCategoria["carrera"]
    
    conteo = Counter(carreraL)

    alumnosCarrera={}

    for clave in conteo:
        valor=conteo[clave]
        alumnosCarrera[clave] = valor
    
    return alumnosCarrera


# despliegue una tabla con el número de alumnos de cada carrera.

def despAlumnosCarrera(alumnosCarrera):

    print()
    print('Alumnos por carrera')
    print()
    print('|----------|---------|')
    print('| Carrera  | Alumnos |')
    print('|----------|---------|')

    for sexo in alumnosCarrera:
        print('|{:10s}|{:9d}|'.format(sexo,alumnosCarrera[sexo]))
        print('|----------|---------|')
    

