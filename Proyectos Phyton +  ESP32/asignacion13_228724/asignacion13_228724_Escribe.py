#
# escribeESP32.py
#
# Este programa lee envia y recibe mensajes a un Microcontrolador
# ESP32 por el puerto serie
#

import serial

BAUD_RATE = 115200
esp32 = serial.Serial('COM4', BAUD_RATE, timeout=5)

while True:
    print('')
    print('Para encender todos los LEDs, teclea el comando "on"')
    print('Para apagar tdos los LEDs, teclea el comando "off"')
    print('Recorrer los LEDs de izquierda a derecha , teclea el comando "ltr"')
    print('Recorrer los LEDs de derecha a izquierda, teclea el comando "rtl"')
    print('Para salir, teclea el comando "exit"')
    print()
    comando = input('Comando deseado? ')
    print()
    if comando == 'exit':
        break
    if comando == 'on':
        esp32.write(b'on')
  
    elif comando == 'off':
        esp32.write(b'off')

    elif comando == 'ltr':
        esp32.write(b'ltr')

    elif comando == 'rtl':
        esp32.write(b'rtl')

    elif comando == 'flash':
        esp32.write(b'flash')

    else:
        esp32.write(bytes(comando,'utf-8'))

    # Lee el puerto serie. Elimina los dos ultimos caracteres que
    # son el salto de linea
    data = esp32.readline()[:-2]
    # Si se leyeron datos del puerto serie
    if data:
        # Convierte la cadena de bytes a una cadena
        sdata = data.decode('utf-8')
        print(sdata)

