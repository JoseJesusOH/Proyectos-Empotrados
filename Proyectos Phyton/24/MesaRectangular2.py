from Mesa2 import Mesa2

class MesaRectangular2(Mesa2):
    def __init__(self, material_cubierta, ancho, largo, material_patas):
        super().__init__("Mesa Rectangular", material_cubierta)
        self.ancho = ancho
        self.largo = largo
        self.material_patas = material_patas
        
    def area(self):
        return self.ancho * self.largo
        
    def costo(self):
        return self.area() * Mesa2._costos[self.cubierta] + 4 * Mesa2._costos[self.material_patas]
        
    def __str__(self):
        return f"{self.tipoMesa} de {self.ancho} x {self.largo} m, con cubierta de {self.cubierta} y patas de {self.material_patas}"
        
    def __repr__(self):
        return f"MesaRectangular2('{self.cubierta}', {self.ancho}, {self.largo}, '{self.material_patas}')"
if __name__ == "__main__":
    mesasRectangulares = [MesaRectangular2('Cubierta Pino', 1.0, 1.0, 'Pata Pino'),
                          MesaRectangular2('Cubierta Pino', 1.0, 1.2, 'Pata Pino'),
                          MesaRectangular2('Cubierta Cedro', 1.2, 1.5, 'Pata Cedro')]
                          
    print(f"Número de mesas creadas: {Mesa2.getContadorMesas()}\n")
                          
    for i, mesa in enumerate(mesasRectangulares):
        print(f"Mesa {i+1}: {mesa}")
        print(f"Área de cubierta: {mesa.area()} m^2")
        print(f"Costo de mesa: ${mesa.costo():.2f}\n")
