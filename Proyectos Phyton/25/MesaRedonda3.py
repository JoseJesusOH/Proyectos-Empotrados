from Mesa3 import Mesa3

class MesaRedonda3(Mesa3):
    _numMesa = 0

    def __init__(self, materialCubierta, radioCubierta, materialPedestal):
        if radioCubierta < 0:
            raise ValueError("El radio de la cubierta debe ser un valor positivo")
        super().__init__("Mesa Redonda", materialCubierta)
        Mesa3._contadorMesas += 1
        self.numMesa = Mesa3._contadorMesas
        self.radioCubierta = radioCubierta
        self.materialPedestal = materialPedestal

    def area(self):
        return 3.1416 * (self.radioCubierta ** 2)

    def costo(self):
        costoCubierta = Mesa3._costos[self.cubierta]
        costoPedestal = Mesa3._costos["Pedestal " + self.materialPedestal]
        return costoCubierta + costoPedestal

    def __str__(self):
        return f"Mesa {self.numMesa}: {self.tipoMesa}, Material de cubierta: {self.cubierta}, Radio de cubierta: {self.radioCubierta}, Material de pedestal: {self.materialPedestal}"

    def __repr__(self):
        return f"MesaRedonda3('{self.cubierta}', {self.radioCubierta}, '{self.materialPedestal}')"

if __name__ == '__main__':
    mesasRedondas = []
    
    try:
        mesa1 = MesaRedonda3('Cubierta Pino', 0.50, 'Pino')
    except Exception as e:
        print(f"No se pudo crear la mesa: {str(e)}")
    else:
        mesasRedondas.append(mesa1)
    
    try:
        mesa2 = MesaRedonda3('Cubierta Pino', -0.6, 'Pino')
    except Exception as e:
        print(f"No se pudo crear la mesa: {str(e)}")
    else:
        mesasRedondas.append(mesa2)
        
    try:
        mesa3 = MesaRedonda3('Cubierta Pino', 0.6, 'Pino')
    except Exception as e:
        print(f"No se pudo crear la mesa: {str(e)}")
    else:
        mesasRedondas.append(mesa3)
        
    try:
        mesa4 = MesaRedonda3('Cubierta Cedro', 0.75, 'Cedro')
    except Exception as e:
        print(f"No se pudo crear la mesa: {str(e)}")
    else:
        mesasRedondas.append(mesa4)
        
    try:
        mesa5 = MesaRedonda3('Cubierta Cedro', -0.75, 'Cedro')
    except Exception as e:
        print(f"No se pudo crear la mesa: {str(e)}")
    else:
        mesasRedondas.append(mesa5)
                          
    print(f"Número de mesas creadas: {Mesa3.getContadorMesas()}\n")
                          
    for mesa in mesasRedondas:
        print(mesa)
        try:
            print(f"Área de la cubierta: {mesa.area():.2f}")
        except Exception as e:
            print(f"No se pudo calcular el área de la mesa: {str(e)}")
        try:
            print(f"Costo de la mesa: {mesa.costo():.2f}")
        except Exception as e:
            print(f"No se pudo calcular el costo de la mesa: {str(e)}")
