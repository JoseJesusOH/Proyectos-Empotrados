import serial

# Configuramos la velocidad de transmisión de datos a 115200 baudios
BAUD_RATE = 115200

# Inicializamos la conexión serie con el dispositivo ESP32
# especificando el nombre del puerto serie y la velocidad de transmisión
esp32 = serial.Serial("COM4", BAUD_RATE, timeout=1)

# Bucle infinito para permitir al usuario ingresar comandos
while True:
    # Imprimimos instrucciones para el usuario
    print('\nPara encender todos los LEDs, escribe el comando "on"')
    print('Para apagar todos los LEDs, escribe el comando "off"')
    print('Para recorrer los LEDs de izquierda a derecha, escribe el comando "ltr"')
    print('Para recorrer los LEDs de derecha a izquierda, escribe el comando "rtl"')
    print('Para salir, escribe el comando "exit"\n')
    comando = input('Comando deseado? ')

    # Si el comando es uno de los predefinidos, lo enviamos tal cual al ESP32 utilizando bytes en lugar de codificación utf-8
    if comando == 'exit':
        break
    elif comando == 'on':
        esp32.write(b'on')
    elif comando == 'off':
        esp32.write(b'off')
    elif comando == 'ltr':
        esp32.write(b'ltr')
    elif comando == 'rtl':
        esp32.write(b'rtl')
    else:
        esp32.write(comando.encode())

    # Leemos la respuesta del ESP32
    respuesta = esp32.readline().strip().decode('utf-8')
    if respuesta:
        print(respuesta)

