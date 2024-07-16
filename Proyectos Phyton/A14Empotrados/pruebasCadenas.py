# pruebasCadenas.py
# Alumno; José Jesús Orozco Hernandez ID; 229141
# Programas con cadenas en python

import cadenas

print('Programas con Cadenas en Python')

print("Pruebas para la función strlen:")
print("La longitud de 'Hola' es:", cadenas.strlen('Hola'))
print("La longitud de '' es:", cadenas.strlen(''))
print()

print("Pruebas para la función cuentaVocales:")
print("El número de vocales en 'Hola mundo' es:", cadenas.cuentaVocales('Hola mundo'))
print("El número de vocales en 'Python' es:", cadenas.cuentaVocales('Python'))
print()

print("Pruebas para la función sonAnagramas:")
print("¿'jaxa' y 'ajax' son anagramas?:", cadenas.sonAnagramas('jaxa', 'ajax'))
print("¿'hola' y 'chao' son anagramas?:", cadenas.sonAnagramas('hola', 'chao'))
print()

print("Pruebas para la función esIp:")
print("¿'192.168.0.1' es una dirección IP válida?:", cadenas.esIp('192.168.0.1'))
print("¿'256.0.0.0' es una dirección IP válida?:", cadenas.esIp('256.0.0.0'))
print()

print("Pruebas para la función iso2NormalTime:")
print("La fecha '2023-02-23' en formato normal es:", cadenas.iso2NormalTime('2023-02-23'))
print("La fecha '2022-10-31' en formato normal es:", cadenas.iso2NormalTime('2022-10-31'))
print()

print("Pruebas para la función obten:")
cadena = 'nombre:Juan,edad:30,profesion:Ingeniero'
print("El valor asociado a la llave 'nombre' en la cadena '", cadena, "' es:", cadenas.obten(cadena, 'nombre'))
print("El valor asociado a la llave 'edad' en la cadena '", cadena, "' es:", cadenas.obten(cadena, 'edad'))
print()