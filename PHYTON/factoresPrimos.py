# factoresPrimos.py
#
# Este programa determina los factores primos de un número entero.
#
# Este programa ilustra el uso de las sentencias while, break y continue.

print('Este programa determina los factores primos de un numero entero')
print()

# Lee un entero
n = int(input('Dame un numero entero: '))
print()

# Escribe el encabezado de la lista
print(f'Los factores primos de {n:d} son:')

divisor = 2
while n > 1:
    # Determina, primero,  si divisor es primo
    # Valor maximo a probar si divide a divisor, sqrt(divisor)
    rdivisor = int(divisor ** 0.5)

    # Para d en [2, rdivisor)
    d = 2
    while d <= rdivisor:
        # Si n es divisible entre d, n no es primo 
        if not divisor % d:
            break
         
        d += 1
   
    # Si divisor fue divisible entre d, no es primo
    if d <= rdivisor: 
        divisor += 1
        continue

    # Si divisor es primo, prueba si es un factor de n.
    # Si divisor es un factor de n, n será divisible entre divisor.
    # El ciclo es para detectar si divisor es un factor repetido de n
    while not n % divisor:
        # Si divisor es un factor primo, factoriza n para
        # buscar el siguiente factor primo
        n //= divisor

        # Escribe el factor primo
        print(f'{divisor:d}, ', end='')
      
    divisor += 1

