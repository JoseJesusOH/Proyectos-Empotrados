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
esp32 = serial.Serial('COM6', BAUD_RATE, timeout=1)

while True:

    # Lee el puerto serie. Elimina los dos ultimos caracteres que
    # son el salto de linea
    data = esp32.readline()[:-2]
    dataNuevo= data
    
    
    # Si se leyeron datos del puerto serie
    if data:
        sdata = data.decode('utf-8')
        if sdata == 'Alarma-ON':
            esp32.write(b'Alarma-ON')
            print('Alarma Activada')
            print('Si desea desactivar la alarma ingrese: Alarma-OFF')
            comando= input()
            if comando == "Alarma-OFF":
                esp32.write(b'Alarma-OFF')
            print('Alarma-DESACTIVADA')
            data = esp32.readline()[:-2]


        



