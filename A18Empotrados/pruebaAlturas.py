# alturas.py

#Por Giovanni Garrido
#ID 00000228724
#Creado el 15/11/2022
# Programa que maneja para probar el funcionamiento de alturas.py
# 

# imports
import alturas

print('Este programa permite manejar la información sobre')
print('las alturas de los alumnos')

# Se leen las matriculas y alturas
alumnoL = alturas.leeDatos()

# Se despliega la tabla con las matriculas y alturas 
print()
alturas.despliegaDatos(alumnoL)

# Se ordena la lista por matriculas
alturas.ordSeleccion(alumnoL, alturas.menorMatricula)

# Se despliega la tabla con las matriculas y alturas ordenadas por matricula
print()
print('Lista de alumnos ordenados por matricula')
alturas.despliegaDatos(alumnoL)

# Se ordena la lista por matriculas
alturas.ordSeleccion(alumnoL, alturas.menorAltura)

# Se despliega la tabla con las matriculas y alturas ordenadas por matricula
print()
print('Lista de alumnos ordenados por altura')
alturas.despliegaDatos(alumnoL)

# Calcula y despliega la altura menor y mayor de los alumnos
print()
a = alturas.rango(alumnoL,alturas.menorAltura)
a1 = a[0]
a2 = a[1]
print(f'La altura mayor es: {a1[1]:6.2f} y la altura menor es: {a2[1]:6.2f}')

# Calcula y despliega la media y desviacion estandar de las alturas de los alumnos
print()
b = alturas.mediaDesvEst(alumnoL)
print(f'La media de las alturas es: {b[0]:6.2f} y la desviacion estandar de las alturas es: {b[1]:6.2f}')

# Calcula y despliega el numero de alumnos que tienen una altura mayor a la media + la desviacion estandar
print()
c = alturas.altos(alumnoL,b)
print(f'El numero de alumnos que tienen una altura mayor a la media es: {c}')

# Busqueda de los alumnos 
print()
print('Consulta de las alturas de los alumnos')
while(True):
    # Se lee la matricula 
    matricula = int(input('Matricula del alumno del que deseas su altura, 0 para terminar? '))
    if matricula == 0:
        break
    
    # Se busca la altura de un alumno de una matricula dada   
    altura = alturas.secuencial(matricula, alumnoL)
    # Si se encontro la matricula 
    if altura != None:
        print(f'El alumno de matricula {matricula:d} tiene una altura de {altura:.2f}')
    else:
        print('El alumno no existe')
    print()