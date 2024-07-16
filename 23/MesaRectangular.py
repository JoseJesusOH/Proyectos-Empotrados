from Mesa import Mesa

class MesaRectangular(Mesa):
    def __init__(self, costo_cubierta, ancho, largo, costo_pata):
        super().__init__("Mesa Rectangular", costo_cubierta)
        self.ancho = ancho
        self.largo = largo
        self.costo_pata = costo_pata
        
    def calculaArea(self):
        return self.ancho * self.largo
        
    def calculaCosto(self):
        return self.calculaArea() * self.costoCubierta + 4 * self.costo_pata
        
    def __str__(self):
        return f"{self.tipoMesa} de {self.ancho} x {self.largo} m, con costo de cubierta {self.costoCubierta} y costo de pata {self.costo_pata}"
        
    def __repr__(self):
        return f"MesaRectangular({self.costoCubierta}, {self.ancho}, {self.largo}, {self.costo_pata})"
        

if __name__ == "__main__":
    mesasRectangulares = [MesaRectangular(50.0, 1.0, 1.0, 30.0), 
                          MesaRectangular(70.0, 1.0, 1.2, 40.0), 
                          MesaRectangular(100.0, 1.2, 1.5, 50.0)]
                          
    for i, mesa in enumerate(mesasRectangulares):
        print(f"Mesa {i+1}: {mesa}")
        print(f"Area de cubierta: {mesa.calculaArea()} m^2")
        print(f"Costo de mesa: ${mesa.calculaCosto():.2f}\n")
