# proyectil.py
#Alumno Jose Jesus Orozco Hernandez
#ID; 00000229141

import math

print('Programa que tabula la distancia alcanzada de un proyectil para los angulos de 0 a 90')
print('con incrementos de 5 grados y determina la mayor distancia alcanzada y en que angulo se logra')

v0 = float(input("Ingrese la velocidad inicial (m/s): "))
g = 9.81

max_distance = 0
angle_at_max_distance = 0

for angle in range(0, 91, 5):
    radian_angle = math.radians(angle)
    x = (2 * v0**2 * math.sin(radian_angle) * math.cos(radian_angle)) / g
    if x > max_distance:
        max_distance = x
        angle_at_max_distance = angle

    print("Ángulo: {:.0f} grados, Distancia: {:.4f} m".format(angle, x))

print("\nÁngulo para la distancia máxima: {:.0f} grados".format(angle_at_max_distance))
print("Distancia máxima: {:.4f} m".format(max_distance))



