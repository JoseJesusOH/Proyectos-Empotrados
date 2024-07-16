from Mesa import Mesa
import math

class MesaRedonda(Mesa):
    def __init__(self, costoCubierta: float, radio: float, costoPedestal: float):
        super().__init__("Mesa Redonda", costoCubierta)
        self.radio = radio
        self.costoPedestal = costoPedestal

    def calculaArea(self):
        return math.pi * self.radio ** 2

    def calculaCosto(self):
        area = self.calculaArea()
        costo = area * self.costoCubierta + self.costoPedestal
        return costo

    def __str__(self):
        return f"{self.tipoMesa}: costo cubierta={self.costoCubierta}, radio={self.radio}, costo pedestal={self.costoPedestal}"

    def __repr__(self):
        return f"MesaRedonda({self.costoCubierta}, {self.radio}, {self.costoPedestal})"

if __name__ == "__main__":
    mesasRedondas = [
        MesaRedonda(50.0, 0.50, 200.0),
        MesaRedonda(70.0, 0.60, 250.0),
        MesaRedonda(100.0, 0.75, 500.0)
    ]

    for i, mesa in enumerate(mesasRedondas):
        print(f"Mesa {i+1}: {mesa}")
        print(f"Area de cubierta: {mesa.calculaArea()}")
        print(f"Costo de mesa: {mesa.calculaCosto()}\n")
