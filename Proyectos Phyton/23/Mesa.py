from abc import ABC, abstractmethod

class Mesa(ABC):

    def __init__(self, tipoMesa: str, costoCubierta: float):
        self.tipoMesa = tipoMesa
        self.costoCubierta = costoCubierta

    @abstractmethod
    def calculaArea(self):
        pass

    @abstractmethod
    def calculaCosto(self):
        pass

    @abstractmethod
    def __str__(self):
        pass

    @abstractmethod
    def __repr__(self):
        pass
