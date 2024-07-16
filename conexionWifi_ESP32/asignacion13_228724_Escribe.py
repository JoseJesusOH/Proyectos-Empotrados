#
# escribeESP32.py
#
# Este programa lee envia y recibe mensajes a un Microcontrolador
# ESP32 por el puerto serie
#

import serial
# Crea una instancia de la clase Serial para usar el puerto serie
# y lo configura al puerto serie de la PC al que se conectara el
# Microcontrolador ESP32, la velocidad de conexion y el timeout.
# timeout es el tiempo que la funcion readline() espera por datos
# en el puerto serie. readline() interpreta el timeout como un
# fin de linea.
#
# Para saber a que puerto se conecto el Microcontrolador ESP32
# se puede checar en la esquina inferior derecha del IDE 2.0 de
# Arduino
# Velocidad de transmisión del puerto serie
BAUD_RATE = 115200
esp32 = serial.Serial('COM3', BAUD_RATE, timeout=5)

while True:
    print('')
    print('Para encender todos los LEDs, teclea el comando "on"')
    print('Para apagar tdos los LEDs, teclea el comando "off"')
    print('Recorrer los LEDs de izquierda a derecha , teclea el comando "ltr"')
    print('Recorrer los LEDs de derecha a izquierda, teclea el comando "rtl"')
    print('Flashear todos los LEDs , teclea el comando "flash"')
    print('Para salir, teclea el comando "exit"')
    print()
    comando = input('Comando deseado? ')
    print()
    if comando == 'exit':
        break
    if comando == 'on':
        esp32.write(b'on')
        #mensaje='LEDs encendidos'
  
    elif comando == 'off':
        esp32.write(b'off')
        #mensaje='LEDs apagados'

    elif comando == 'ltr':
        esp32.write(b'ltr')
        #mensaje='Barrido de izquierda a derecha'

    elif comando == 'rtl':
        esp32.write(b'rtl')
        #mensaje='Barrido de derecha a izquierda'

    elif comando == 'flash':
        esp32.write(b'flash')
        #mensaje='Flashean los LEDs'

    else:
        esp32.write(bytes(comando,'utf-8'))
        #print('Comando erroneo: ',comando)
        #mensaje='Comando no existente'
        #esp32.write(b'otro')
        
    # Lee el puerto serie. Elimina los dos ultimos caracteres que
    # son el salto de linea
    data = esp32.readline()[:-2]
    # Si se leyeron datos del puerto serie
    if data:
        # Convierte la cadena de bytes a una cadena
        sdata = data.decode('utf-8')
        print(sdata)
        # Lee el puerto serie. Elimina los dos ultimos caracteres que
        # son el salto de linea
   # data = esp32.readline()[:-2]
    # Si se leyeron datos del puerto serie
    #if data:
        # Convierte la cadena de bytes a una cadena
     #   sdata = data.decode('utf-8')
      #  print(sdata)
       # print()
