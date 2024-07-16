import encuesta2

print('Este programa permite manejar la información sobre')
print('las encuestas de los alumnos')

alumnos = encuesta2.leeEncuesta()
alumnosCategoria = []

while True:
    print("\n¿Qué acción desea realizar?")
    print("1. Mostrar lista de encuestas")
    print("2. Clasificar alumnos por categoría")
    print("3. Clasificar alumnos por sexo")
    print("4. Clasificar alumnos por carrera")
    print("5. Reiniciar lista de encuestas")
    print("6. Salir")

    opcion = input("\nIngrese el número de la opción que desea realizar: ")

    if opcion == "1":
        encuesta2.despliegaEncuesta(alumnos)
    elif opcion == "2":
        alumnosCategoria=encuesta2.clasificaAlumnosCategoria(alumnos)
        encuesta2.despAlumnosCategoria(alumnosCategoria)
    elif opcion == "3":
        if alumnosCategoria:
            alumnosSexo=encuesta2.clasificaAlumnosSexo(alumnosCategoria)
            encuesta2.despAlumnosSexo(alumnosSexo)
        else:
            print("Error: La lista de encuestas está vacía.")
    elif opcion == "4":
        if alumnosCategoria:
            alumnosCarrera=encuesta2.clasificaAlumnosCarrera(alumnosCategoria)
            encuesta2.despAlumnosCarrera(alumnosCarrera)
        else:
            print("Error: La lista de encuestas está vacía.")
    elif opcion == "5":
        alumnos = encuesta2.leeEncuesta()
        alumnosCategoria = []
        print("¡La lista de encuestas se ha reiniciado con éxito!")
    elif opcion == "6":
        print("¡Gracias por utilizar el programa!")
        break
    else:
        print("Opción inválida. Por favor ingrese un número del 1 al 6.")