from MesaRectangular2 import MesaRectangular2
from MesaRedonda2 import MesaRedonda2

mesas = [
    MesaRectangular2('Cubierta Pino', 1.0, 1.0, 'Pata Pino'),
    MesaRectangular2('Cubierta Pino', 1.0, 1.2, 'Pata Pino'),
    MesaRectangular2('Cubierta Cedro', 1.2, 1.5, 'Pata Cedro'),
    MesaRedonda2('Cubierta Pino', 0.50, 'Pino'),
    MesaRedonda2('Cubierta Pino', 0.60, 'Pino'),
    MesaRedonda2('Cubierta Cedro', 0.75, 'Cedro')
]

print(f"Se han creado {mesas.__len__()} mesas.\n")

for mesa in mesas:
    print(mesa)
    print(f"Área de la cubierta: {mesa.area()} m^2")
    print(f"Costo de la mesa: ${mesa.costo():.2f}\n")