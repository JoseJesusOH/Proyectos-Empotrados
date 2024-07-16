from abc import ABC, abstractmethod

class Mesa3(ABC):
    
    _costos = {'Cubierta Pino': 100.0,
               'Cubierta Cedro': 200.0,
               'Pedestal Pino': 500.0,
               'Pedestal Cedro': 800.0,
               'Pata Pino': 60.0,
               'Pata Cedro': 80}

    _contadorMesas = 0

    def __init__(self, tipoMesa, cubierta):
        self.tipoMesa = tipoMesa
        self.cubierta = cubierta

    @classmethod
    def getContadorMesas(cls):
        return cls._contadorMesas

    @abstractmethod
    def area(self):
        pass

    @abstractmethod
    def costo(self):
        pass

    @abstractmethod
    def __str__(self):
        pass

    @abstractmethod
    def __repr__(self):
        pass