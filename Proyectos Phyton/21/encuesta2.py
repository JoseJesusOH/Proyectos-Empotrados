import math
from collections import Counter

def leeEncuesta(alumnos):
    while True:
        matricula = input("Ingrese la matricula del alumno (0 para terminar): ")
        if matricula == "0":
            break
        while True:
            sexo = input("Ingrese el sexo del alumno ('M' o 'F'): ")
            if sexo == "M" or sexo == "F":
                break
            else:
                print("Sexo inválido, por favor ingrese 'M' o 'F'")
        carrera = input("Ingrese la carrera del alumno, por ejemplo: 'IQ', 'ISW'.: ")
        alumnoT = (matricula, sexo, carrera)
        alumnos.append(alumnoT)
    return alumnos


def despliegaEncuesta(alumnos):
    print("Lista de alumnos:")
    print("|-----------|------|---------|")
    print("| Matricula | Sexo | Carrera |")
    print("|-----------|------|---------|")
    for matricula, sexo, carrera in alumnos:
        print("|{:11}|{:6}|{:9}|".format(matricula, sexo, carrera))
        print("|-----------|------|---------|")
def clasificaAlumnosCategoria(alumnos):
    catSexo = []
    catCarrera = []
    for _, sexo, carrera in alumnos:
        catSexo.append(sexo)
        catCarrera.append(carrera)

    alumnosCategoria = {"sexo": catSexo, "carrera": catCarrera}
    return alumnosCategoria

def despAlumnosCategoria(alumnosCategoria):
    sexoL = alumnosCategoria["sexo"]
    carreraL = alumnosCategoria["carrera"]
    print("Alumnos por categoría:")
    print("|-----------------|")
    print("|    CATEGORÍA    |")
    print("|-----------------|")
    print("| Sexo  | Carrera |")
    print("|-------|---------|")
    print("|{:7}|{:9}|".format(len(sexoL), len(carreraL)))
    print("|-------|---------|")

def clasificaAlumnosSexo(alumnosCategoria):
    sexoL = alumnosCategoria["sexo"]
    conteo = Counter(sexoL)
    alumnosSexo = {}
    for clave in conteo:
        valor = conteo[clave]
        alumnosSexo[clave] = valor

    return alumnosSexo

def despAlumnosSexo(alumnosSexo):
    print("Alumnos por sexo:")
    print("|-----------------|")
    print("| Sexo  | Alumnos |")
    print("|-------|---------|")

    for sexo in alumnosSexo:
        print("|{:7}|{:9}|".format(sexo, alumnosSexo[sexo]))
        print("|-------|---------|")

def clasificaAlumnosCarrera(alumnosCategoria):
    carreraL = alumnosCategoria["carrera"]
    conteo = Counter(carreraL)
    alumnosCarrera = {}

    for clave in conteo:
        valor = conteo[clave]
        alumnosCarrera[clave] = valor

    return alumnosCarrera

def despAlumnosCarrera(alumnosCarrera):
    print("Alumnos por carrera:")
    print("|----------|---------|")
    print("| Carrera  | Alumnos |")
    print("|----------|---------|")

    for carrera in alumnosCarrera:
        print("|{:10}|{:9}|".format(carrera, alumnosCarrera[carrera]))
        print("|----------|---------|")