import encuesta2

print('Este programa permite manejar la información sobre')
print('las encuestas de los alumnos')
alumnos = []
while True:
    print('\nSeleccione una opción:')
    print('1. Leer encuesta')
    print('2. Desplegar encuesta')
    print('3. Desplegar alumnos por categoría')
    print('4. Desplegar alumnos por sexo')
    print('5. Desplegar alumnos por carrera')
    print('6. Restaurar encuesta')
    print('7. Salir')
    opcion = input()

    if opcion == '1':
        alumnos = encuesta2.leeEncuesta(alumnos)
    elif opcion == '2':
        if alumnos:
            encuesta2.despliegaEncuesta(alumnos)
        else:
            print('No hay encuestas registradas.')
    elif opcion == '3':
        if alumnos:
            print('Alumnos clasificados por categoría.')
            alumnosCategoria = encuesta2.clasificaAlumnosCategoria(alumnos)
            encuesta2.despAlumnosCategoria(alumnosCategoria)
        else:
            print('No hay encuestas registradas.')
    elif opcion == '4':
        if alumnosCategoria:
            print('Alumnos clasificados por sexo.')
            alumnosSexo = encuesta2.clasificaAlumnosSexo(alumnosCategoria)
            encuesta2.despAlumnosSexo(alumnosSexo)
        else:
            print('No hay encuestas registradas.')
    elif opcion == '5':
        if alumnosCategoria:
            print('Alumnos clasificados por carrera.')
            alumnosCarrera = encuesta2.clasificaAlumnosCarrera(alumnosCategoria)
            encuesta2.despAlumnosCarrera(alumnosCarrera)
        else:
            print('No hay encuestas registradas.')
    elif opcion == '6':
        alumnos = []
        print('Encuesta restaurada.')
    elif opcion == '7':
        break
    else:
        print('Opción inválida. Intente de nuevo.')