# pruebaEncueta2.py

#Por Giovanni Garrido
#ID 00000228724
#Creado el 25/11/2022
# Programa que maneja para probar el funcionamiento de encuesta2.py
# 

# imports
import encuesta2

print('Este programa permite manejar la información sobre')
print('las encuestas de los alumnos')

# Se leen los datos de los alumnos
alumnos = encuesta2.leeEncuesta()

# Se despliega la tabla con los datos de los alumnos
print()
encuesta2.despliegaEncuesta(alumnos)

# clasifica la cantidad de alumnos
alumnosCategoria=encuesta2.clasificaAlumnosCategoria(alumnos)

# se despliegue una tabla con el número de alumnos de cada categoría: sexo, carrera.

encuesta2.despAlumnosCategoria(alumnosCategoria)

#cuenta cuantos alumnos hay en cada sexo

alumnosSexo=encuesta2.clasificaAlumnosSexo(alumnosCategoria)

# Se despliega la tabla con los cantidad de alumnos de cada sexo

encuesta2.despAlumnosSexo(alumnosSexo)

#cuenta cuantos alumnos hay en cada carrera

alumnosCarrera=encuesta2.clasificaAlumnosCarrera(alumnosCategoria)

# Se despliega la tabla con los cantidad de alumnos de cada carrera

encuesta2.despAlumnosCarrera(alumnosCarrera)
print()