import math

def leeDatos():
    matricula = 1
    cont = 0
    alumnoL = []
    
    while(matricula > 0):
        cont += 1
        while True:
            try:
                matricula = int(input(f'Matricula del alumno {cont:d}, 0 para terminar? '))
                if matricula < 0:
                    raise ValueError('La matricula debe ser un número positivo.')
                break
            except ValueError as e:
                print(f'Error: {e}')
        if matricula == 0:
            break
        while True:
            try:
                altura = float(input(f'Altura del alumno {cont:d}? '))
                break
            except ValueError:
                print('Error: la altura debe ser un número.')
        alumnoT = matricula, altura
        alumnoL.append(alumnoT)

    return alumnoL

def despliegaDatos(alumnoL):
    print('Lista de alumnos:')
    print()
    print('|  Mat    |Altura |')
    print('|---------|-------|')
    
    for matricula, altura in alumnoL:
        print('|{:7d}  |{:5.2f}  |'.format(matricula,altura))
        print('|---------|-------|')
    
def ordSeleccion(alumnos, fmenor):
    for i in range(len(alumnos)-1):
        menor = i
        for j in range(i + 1, len(alumnos)):
            if fmenor(alumnos[j], alumnos[menor]):
                menor = j
        if menor != i:
            alumnos[menor], alumnos[i] = alumnos[i], alumnos[menor]

def menorMatricula(alumno1, alumno2):
    return alumno1[0] < alumno2[0]

def menorAltura(alumno1, alumno2):
    return alumno1[1] < alumno2[1]

def rango(alumnoL,fmenor):
    for i in range(len(alumnoL)-1):
        menor = i
        for j in range(i + 1, len(alumnoL)):
            if fmenor(alumnoL[j], alumnoL[menor]):
                menor = j
        if menor != i:
            alumnoL[menor], alumnoL[i] = alumnoL[i], alumnoL[menor]

    alumT = alumnoL[len(alumnoL)-1], alumnoL[0]
    return alumT

def mediaDesvEst(alumnosL):
    suma = 0
    sumaC = 0
    i = 0
    n = len(alumnosL)
    for matricula,altura in alumnosL:
        suma += altura
        sumaC += altura**2
    
    media = suma/n
    mediaC = sumaC/n
    desvia = math.sqrt((mediaC-(media**2)))
    
    mediaDe = (media,desvia)
    
    return mediaDe

def altos(alumnoL,mediaDe):
    media = mediaDe[0]
    desvia = mediaDe[1]
    md = media + desvia
    altos = 0
    for matricula,altura in alumnoL:
        if (altura > md):
            altos += 1
    return altos

def secuencial(matBuscar, alumnos):
    for matricula, altura in alumnos:
        if matBuscar == matricula:
            return altura
    else:
        return None