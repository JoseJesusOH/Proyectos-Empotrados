import serial

BAUD_RATE = 115200

esp32 = serial.Serial("COM4", BAUD_RATE, timeout=1)

print("Bienvenido al programa de reproducción de música desde la PC mediante un zumbador controlado #17 y un LED RGB")

while True:
    print('Por favor ingrese la secuencia de notas (máximo 50):')
    secuencia_notas = input('Secuencia de notas: ')
    while not secuencia_notas.isdigit() or int(secuencia_notas) <= 0 or int(secuencia_notas) >= 50:
        print('Error: la secuencia de notas debe ser un número entero positivo menor a 50 y mayor a 0')
        secuencia_notas = input('Secuencia de notas: ')
    esp32.write(secuencia_notas.encode())
    print("En reproduccion...")
    while True:
        respuesta = esp32.readline().strip().decode('utf-8')
        if respuesta == 'FIN-REPRODUCCION':
            print('Reproducción Ok')
            break

    continuar = input('¿Desea continuar? (s/n): ')
    if continuar.lower() != 's':
        print('¡Hasta luego!')
        break