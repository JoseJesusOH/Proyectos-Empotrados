# primo2.py
#
# Este programa determina si un número entero es primo.
#
# Este programa ilustra el uso de las sentencias for y break.

print('Este programa determina si un número entero es primo')
print()

# Lee un entero
n = int(input('Dame un numero entero: '))
print()

# Valor maximo a probar si divide a n, sqrt(n)
rn = int(n ** 0.5)

# Para i en [2, rn]
for i in range(2, rn+1):
    # Si n es divisible entre i, n no es primo 
    if not n % i:
        print(f'{n:d} no es primo')
        break
else:
    print(f'{n:d} es primo')

