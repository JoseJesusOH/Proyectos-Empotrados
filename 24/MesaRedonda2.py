from Mesa2 import Mesa2

class MesaRedonda2(Mesa2):
    def __init__(self, materialCubierta, radioCubierta, materialPedestal):
        super().__init__("Mesa Redonda", materialCubierta)
        self.radioCubierta = radioCubierta
        self.materialPedestal = materialPedestal

    def area(self):
        return 3.1416 * (self.radioCubierta ** 2)

    def costo(self):
        costoCubierta = Mesa2._costos[self.cubierta]
        costoPedestal = Mesa2._costos["Pedestal " + self.materialPedestal]
        return costoCubierta + costoPedestal

    def __str__(self):
        return f"{self.tipoMesa}, Material de cubierta: {self.cubierta}, Radio de cubierta: {self.radioCubierta}, Material de pedestal: {self.materialPedestal}"

    def __repr__(self):
        return f"MesaRedonda2('{self.cubierta}', {self.radioCubierta}, '{self.materialPedestal}')"
if __name__ == '__main__':
    mesasRedondas = [MesaRedonda2('Cubierta Pino', 0.50, 'Pino'), MesaRedonda2('Cubierta Pino', 0.60, 'Pino'), MesaRedonda2('Cubierta Cedro', 0.75, 'Cedro')]

    print(f"Se han creado {Mesa2._contadorMesas} mesas")

    for mesa in mesasRedondas:
        print(mesa)
        print(f"Área de la cubierta: {mesa.area():.2f}")
        print(f"Costo de la mesa: {mesa.costo():.2f}")
