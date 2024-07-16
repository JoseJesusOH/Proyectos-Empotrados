# cadenas.py
#Alumno; José Jesús Orozco Hernández ID; 00000229141
#Programas con cadenas en python

import re
import itertools
print("Prueba del progama con cadenas en phyton")


"""""
 Determina y regresa la longitud de la cadena s.
"""""
def strlen(s):
    count = 0
    while s:
        count += 1
        s = s[1:]
    return count

"""""
 Una función cuentaVocales(s) que cuente el número de ocurrencias de todas las
 vocales en la cadena s.
"""""
def cuentaVocales(s):
    vowels = ['a', 'e', 'i', 'o', 'u']
    count = 0
    for i in s.lower():
        if i in vowels:
            count += 1
    return count

"""""
 Una función llamada sonAnagramas(s1, s2) que regrese True si las cadenas s1 y s2
 son anagramas, False en caso contrario. Dos cadenas son anagramas si las letras de una
 pueden reordenarse para formar la otra cadena. Por ejemplo ‘jaxa’ y ‘ajax’ son anagramas.
"""""
def sonAnagramas(s1, s2):
    if sorted(s1.lower()) == sorted(s2.lower()):
        return True
    else:
        return False


"""""
 Una función llamada esIp(s) que regrese True si la cadena s representa una dirección
 IP válida, False en caso contrario.
"""""
def esIp(s):
    ip = s.split('.')
    if len(ip) != 4:
        return False
    for i in ip:
        if not i.isnumeric() or int(i) > 255:
            return False
    return True


"""""
 Una función llamada iso2NormalTime(s) que regrese una cadena con la fecha del
parámetro s en el formato ‘aaaa-mm-dd’ convertida al formato ‘dd/mm/aaaa’.
"""""
def isoNormalTime(s):
    separaFecha = s.split('-')
    return '{}/{}/{}'.format(separaFecha[2], separaFecha[1],separaFecha[0])


"""

Una función llamada obten(s, llave) que obtenga de la cadena s un valor asociado a
una llave. La cadena contiene una serie de parejas llave: valor separadas por coma. Cada
llave y su valor están separados por dos puntos (:)
"""

def obten(s, llave):
    # Dividir cadena en parejas llave:valor
    pairs = s.split(',')
    # Buscar valor asociado a la llave dada
    for pair in pairs:
        key, value = pair.split(':')
        if key == llave:
            return value
    # Si la llave no se encuentra, regresar None
    return None
