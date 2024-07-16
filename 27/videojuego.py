from articulo import Articulo

class Videojuego(Articulo):
    def __init__(self, numCatalogo, titulo=None, genero=None,
                 clasificacion=None, consola=None, fabricante=None, version=None):
        super().__init__(numCatalogo, titulo, genero, clasificacion)
        self.__consola = consola
        self.__fabricante = fabricante
        self.__version = version
        
    def get_consola(self):
        return self.__consola
    
    def set_consola(self, consola):
        self.__consola = consola
        
    def get_fabricante(self):
        return self.__fabricante
    
    def set_fabricante(self, fabricante):
        self.__fabricante = fabricante
        
    def get_version(self):
        return self.__version
    
    def set_version(self, version):
        self.__version = version
    
    def __str__(self):
        return f"{super().__str__()}, {self.get_consola()}, {self.get_fabricante()}, {self.get_version()}"
    
    def __repr__(self):
        return f"{__name__}.{type(self).__name__}({super().__repr__()}, {self.get_consola()}, {self.get_fabricante()}, {self.get_version()})"
    
if __name__ == "__main__":
    # Creamos los objetos Videojuego con los valores proporcionados
    videojuego1 = Videojuego("V00001", "Superman Returns", "Acción", "T-Teen", "XBox 360", "Electronic Arts", "01.01")
    videojuego2 = Videojuego("V00002", "Tomb Raider", "Acción", "T-Teen", "PS2", "Eidos", "02.11")
    videojuego3 = Videojuego("V00003", "Super Smash Bros. Brawl", "Acción", "T-Teen", "Nintendo Wii", "Nintendo", "01.05")
    
    # Imprimimos los datos de los tres videojuegos utilizando __str__
    print("Datos de los videojuegos:")
    print(videojuego1)
    print(videojuego2)
    print(videojuego3)
    
    # Imprimimos el fabricante del videojuego2 utilizando la propiedad fabricante
    print("\nFabricante del videojuego2:")
    print(videojuego2.get_fabricante())
    
    # Comparamos videojuego1 y videojuego1 utilizando __eq__ y __ne__
    print("\n¿El videojuego1 es igual al videojuego1?")
    print(videojuego1 == videojuego1)
    print("\n¿El videojuego1 es diferente al videojuego2?")
    print(videojuego1 != videojuego2)
