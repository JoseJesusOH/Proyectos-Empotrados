import math
from collections import Counter

def leeEncuesta():
    cont = 0
    alumnos = []
    while True:
        cont += 1
        matricula = int(
            input(f'Matricula del alumno {cont:d}, 0 para terminar? '))
        if matricula == 0:
            break
        while True:
            sexo = input(f'Sexo (‘M’, ‘F’) del alumno {cont:d}? ')
            if sexo in ['M', 'F']:
                break
            else:
                print('Valor inválido. Ingrese ‘M’ o ‘F’.')
        carrera = input(f'Carrera (Siglas de la carrera. Por ejemplo: ‘IE’, ‘ISW’, ‘IC’, LAE’, ‘LPS’, etc.) del alumno {cont:d}? ')
        alumnoT = matricula, sexo, carrera
        alumnos.append(alumnoT)
    return alumnos


def despliegaEncuesta(alumnos):
    print('Lista de alumnos')
    print()
    print('|-----------|------|---------|')
    print('| Matricula | Sexo | Carrera |')
    print('|-----------|------|---------|')
    for matricula, sexo, carrera in alumnos:
        print('|{:11d}|{:6s}|{:9s}|'.format(matricula, sexo, carrera))
        print('|-----------|------|---------|')

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

def clasificaAlumnosSexo(alumnosCategoria):
    sexoL=alumnosCategoria["sexo"]
    conteo = Counter(sexoL)
    alumnosSexo={}
    for clave in conteo:
        valor=conteo[clave]
        alumnosSexo[clave] = valor
    return alumnosSexo

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

def clasificaAlumnosCarrera(alumnosCategoria):
    carreraL=alumnosCategoria["carrera"]
    conteo = Counter(carreraL)
    alumnosCarrera={}
    for clave in conteo:
        valor=conteo[clave]
        alumnosCarrera[clave] = valor
    return alumnosCarrera

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
    

