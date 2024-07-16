from Mesa3 import Mesa3

class MesaRectangular3(Mesa3):
    _numMesa = 0
    def __init__(self, material_cubierta, ancho, largo, material_patas):
        if ancho < 0 or largo < 0:
            raise ValueError("Las dimensiones de la mesa deben ser positivas.")
        super().__init__("Mesa Rectangular", material_cubierta)
        self.ancho = ancho
        self.largo = largo
        self.material_patas = material_patas
        Mesa3._contadorMesas += 1
        self.numMesa = Mesa3._contadorMesas
        
    def area(self):
        return self.ancho * self.largo
        
    def costo(self):
        return self.area() * Mesa3._costos[self.cubierta] + 4 * Mesa3._costos[self.material_patas]
        
    def __str__(self):
        return f"Mesa {self.numMesa}: {self.tipoMesa} de {self.ancho} x {self.largo} m, con cubierta de {self.cubierta} y patas de {self.material_patas}"
        
    def __repr__(self):
        return f"MesaRectangular3('{self.cubierta}', {self.ancho}, {self.largo}, '{self.material_patas}')"

if __name__ == '__main__':
    mesasRectangulares = []
    try:
        mesa1 =  MesaRectangular3('Cubierta Pino', 1.0, 1.0, 'Pata Pino')
    except Exception as e:
        print(f"No se pudo crear la mesa: {str(e)}")
    else:
        mesasRectangulares.append(mesa1)
    
    try:
        mesa2 =  MesaRectangular3('Cubierta Pino', 1.0, 1.2, 'Pata Pino')
    except Exception as e:
        print(f"No se pudo crear la mesa: {str(e)}")
    else:
        mesasRectangulares.append(mesa2)
        
    try:
        mesa3 = MesaRectangular3('Cubierta Pino', -1.0, 1.5, 'Pata Pino')
    except Exception as e:
        print(f"No se pudo crear la mesa: {str(e)}")
    else:
        mesasRectangulares.append(mesa3)
        
    try:
        mesa4 = MesaRectangular3('Cubierta Cedro', 1.2, 1.5, 'Pata Cedro')
    except Exception as e:
        print(f"No se pudo crear la mesa: {str(e)}")
    else:
        mesasRectangulares.append(mesa4)
        
    try:
        mesa5 =MesaRectangular3('Cubierta Cedro', 1.2, -1.5, 'Pata Cedro')
    except Exception as e:
        print(f"No se pudo crear la mesa: {str(e)}")
    else:
        mesasRectangulares.append(mesa5)
                          
    print(f"Número de mesas creadas: {Mesa3.getContadorMesas()}\n")
                          
    for mesa in mesasRectangulares:
        print(mesa)
        try:
            print(f"Área de la cubierta: {mesa.area():.2f}")
        except Exception as e:
            print(f"No se pudo calcular el área de la mesa: {str(e)}")
        try:
            print(f"Costo de la mesa: {mesa.costo():.2f}")
        except Exception as e:
            print(f"No se pudo calcular el costo de la mesa: {str(e)}")
