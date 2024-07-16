import alturas

print('Este programa permite manejar la información sobre')
print('las alturas de los alumnos')

alumnoL = []
resetear = False

while True:
    if resetear:
        alumnoL = []
        print('Se han reseteado los campos de la lista de alumnos.')
        resetear = False
    elif alumnoL:
        print('La lista de alumnos actual es la siguiente:')
        alturas.despliegaDatos(alumnoL)
    else:
        print('Aún no se han ingresado alumnos.')

    print()
    print('Elige una opción:')
    print('1. Agregar un alumno')
    print('2. Ordenar la lista de alumnos por matrícula')
    print('3. Ordenar la lista de alumnos por altura')
    print('4. Obtener la altura mayor y menor de la lista de alumnos')
    print('5. Obtener la media y desviación estándar de las alturas de la lista de alumnos')
    print('6. Obtener el número de alumnos que tienen una altura mayor a la media')
    print('7. Consultar la altura de un alumno por matrícula')
    print('8. Resetear campos de la lista de alumnos')
    print('0. Salir')

    opcion = input('>> ')

    if opcion == '1':
        alumnoL.extend(alturas.leeDatos())
    elif opcion == '2':
        alturas.ordSeleccion(alumnoL, alturas.menorMatricula)
        print('La lista de alumnos ha sido ordenada por matrícula.')
    elif opcion == '3':
        alturas.ordSeleccion(alumnoL, alturas.menorAltura)
        print('La lista de alumnos ha sido ordenada por altura.')
    elif opcion == '4':
        a = alturas.rango(alumnoL,alturas.menorAltura)
        a1 = a[0]
        a2 = a[1]
        print(f'La altura mayor es: {a1[1]:6.2f} y la altura menor es: {a2[1]:6.2f}')
    elif opcion == '5':
        b = alturas.mediaDesvEst(alumnoL)
        print(f'La media de las alturas es: {b[0]:6.2f} y la desviación estándar de las alturas es: {b[1]:6.2f}')
    elif opcion == '6':
        c = alturas.altos(alumnoL,b)
        print(f'El número de alumnos que tienen una altura mayor a la media es: {c}')
    elif opcion == '7':
        matricula = int(input('Matrícula del alumno del que deseas su altura, 0 para terminar: '))
        if matricula != 0:
            altura = alturas.secuencial(matricula, alumnoL)
            if altura != None:
                print(f'El alumno de matrícula {matricula:d} tiene una altura de {altura:.2f}')
            else:
                print('El alumno no existe')
    elif opcion == '8':
        resetear = True
    elif opcion == '0':
        break
    else:
        print('Opción inválida, por favor intenta de nuevo.')
    print()