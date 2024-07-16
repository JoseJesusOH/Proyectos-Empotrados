# encuesta.py
# Alumno; José Jesus Orozco Hernandez
# ID 00000229141
# Creado el 15/02/2023
# Programa que realiza encuestas a alumnos de la universidad , para determinar la demanda de apartamentos y dormitorios

import os

print('Programa que realiza encuestas a alumnos de \nla universidad , para determinar la \ndemanda de apartamentos y dormitorios ')


contadorHombres = 0
sumaF = 0
encuesta = 0
sumaEdadM = 0
sumaEdadF = 0
foraneoM = 0
foraneoF = 0
sumaViviAsis = 0
sumaViviCasa = 0
sumaViviSolo = 0

contadorEncuestados = 0
edad = 0
sexo = ''
localidad = ''
contadorMujeres = 0
contadorHombres = 0
contadorMujeresForaneos = 0
contadorHombresForaneos = 0
sumaMujeresEdad = 0
sumaHombresEdad = 0
promedioEdadMujeres = 0
promedioEdadHombres = 0
sumaViviendaA = 0
sumaViviendaC = 0
sumaViviendaS = 0
contadorForaneos = 0
while True:
    contadorEncuestados += 1
    print("Encuestado ",contadorEncuestados)

    while True:
        try:
            edad = int(
                input("Ingresa tu edad, si digita 0 se finalizara la encuesta "))
            if edad < 0:
                print("La edad no debe de ser negativa")
                continue
            else:
                break
        except ValueError:
            print("Error: debes ingresar un número entero")
            continue

    if edad==0:
        break
    
    while True:
        sexo = input("Ingrese el sexo M/F: ")
        sexo=sexo.strip()
        sexo=sexo.upper()   
        if len(sexo) != 1:
            print("Solo debe de ingresar caracteres como M o F")
            continue
        elif sexo == 'M' or sexo == 'F':
            break
        else:
            print("Debe de ingresar solo M o F")

    if sexo == 'M':
        contadorMujeres += 1
        sumaMujeresEdad = edad+sumaMujeresEdad
    else:
        contadorHombres += 1
        sumaHombresEdad = edad+sumaHombresEdad

    while True:
        localidad = input("Ingrese la localidad F/L: ")
        localidad=localidad.strip()
        localidad=localidad.upper()
        if len(localidad) != 1:
            print("Solo debe de ingresar caracteres como L o F")
            continue
        elif localidad == 'L' or localidad == 'F':
            break
        else:
            print("Debe de ingresar solo L o F")

    if localidad == 'F':
        contadorForaneos += 1
        if sexo == 'M':
            contadorMujeresForaneos += 1
        else:
            contadorHombresForaneos += 1
        print("")
        while True:
            vivienda = input(
                "Vivienda deseada :‘A’ por casa de asistencia, ‘C’ por compartir casa, ‘S’ por vivir solo. ")
            vivienda=vivienda.strip()
            vivienda=vivienda.upper()
            if len(localidad) != 1:
                print("Solo debe de ingresar caracteres como A , C y S")
                continue
            elif vivienda == 'A' or vivienda == 'C' or vivienda == 'S':
                if vivienda == 'A':
                    sumaViviendaA += 1
                elif vivienda == 'C':
                    if sexo == 'F':
                        sumaViviendaC += 1
                elif vivienda == 'S':
                    if sexo == 'M':
                        sumaViviendaS += 1
                break
            else:
                print("Debe de ingresar solo L o F")
   
    if edad == 0:
        break
    print("-----------------------------------------------------")


if contadorHombres == 0 or contadorMujeres == 0:
    print("Ha finalizado el programa pero no se ha encuestado a los alumnos")
else:
    os.system('cls')
    promedioEdadHombres = sumaHombresEdad/contadorHombres
    promedioEdadMujeres = sumaMujeresEdad/contadorMujeres
    porcentajeMujeresForaneas = 100 * (contadorMujeresForaneos/contadorEncuestados)
    porcentajeHombreForaneos = 100 * (contadorHombresForaneos/contadorEncuestados)
    porcentajeForaneos = 100 * (contadorForaneos/contadorEncuestados)
    porcentajeViviendaA = 100 * (sumaViviendaA/contadorEncuestados)
    porcentajeViviendaC = 100 * (sumaViviendaC/contadorEncuestados)
    porcentajeViviendaS = 100*(sumaViviendaS/contadorEncuestados)

    print('Numero de alumnos encuestados:', contadorEncuestados)
    print('La edad promedio es: En hombres {:.0f} y en mujeres {:.0f}'.format(promedioEdadHombres, promedioEdadMujeres))
    print('El porcentaje de alumnos foraneos, hombres es:{:.2f}% y de las mujeres es: {:.2f}%'.format(porcentajeHombreForaneos, porcentajeMujeresForaneas))
    print('El porcentaje de alumnos que desean vivir en casa de asistencia es: {:.2f}%'.format(porcentajeViviendaA))
    print('El porcentaje de alumnos mujeres que desean compartir casa es: {:.2f}%'.format(porcentajeViviendaC))
    print('El porcentaje de alumnos hombres que desean vivir solos es: {:.2f}%'.format(porcentajeViviendaS))
    print('')

