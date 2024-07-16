from videojuego import Videojuego

class VideojuegoED:
    def __init__(self, videojuego: Videojuego, existencia: int, disponibilidad: int):
        self.__videojuego = videojuego
        self.__existencia = existencia
        self.__disponibilidad = disponibilidad
    
    @property
    def videojuego(self) -> Videojuego:
        return self.__videojuego
    
    @videojuego.setter
    def videojuego(self, videojuego: Videojuego):
        self.__videojuego = videojuego
    
    @property
    def existencia(self) -> int:
        return self.__existencia
    
    @existencia.setter
    def existencia(self, existencia: int):
        self.__existencia = existencia
    
    @property
    def disponibilidad(self) -> int:
        return self.__disponibilidad
    
    @disponibilidad.setter
    def disponibilidad(self, disponibilidad: int):
        self.__disponibilidad = disponibilidad
    
    def __eq__(self, videojuegoED) -> bool:
        return self.__videojuego == videojuegoED.videojuego
    
    def __ne__(self, videojuegoED) -> bool:
        return self.__videojuego != videojuegoED.videojuego
    
    def __str__(self) -> str:
        return f"{self.__videojuego}, {self.__existencia}, {self.__disponibilidad}"
    
    def __repr__(self) -> str:
        return f"{__name__}.{type(self).__name__}({repr(self.__videojuego)}, {self.__existencia}, {self.__disponibilidad})"
        
if __name__ == "__main__":
        # Creamos los objetos Videojuego con los valores proporcionados
    videojuego1 = Videojuego("V00001", "Superman Returns", "Acción", "T-Teen", "XBox 360", "Electronic Arts", "01.01")
    videojuego2 = Videojuego("V00002", "Tomb Raider", "Acción", "T-Teen", "PS2", "Eidos", "02.11")
    videojuego3 = Videojuego("V00003", "Super Smash Bros. Brawl", "Acción", "T-Teen", "Nintendo Wii", "Nintendo", "01.05")
    # Creamos los objetos VideojuegoED con los valores proporcionados
    
    videojuegoED1 = VideojuegoED(videojuego1, 5, 3)
    videojuegoED2 = VideojuegoED(videojuego2, 7, 4)
    videojuegoED3 = VideojuegoED(videojuego3, 8, 5)
    
    # Imprimimos los datos de los tres videojuegosED utilizando __str__
    print("Datos de los videojuegosED:")
    print(videojuegoED1)
    print(videojuegoED2)
    print(videojuegoED3)
    
    # Imprimimos el videojuego de videojuegoED2
    print(f"Videojuego de videojuegoED2: {videojuegoED2.videojuego}")
    
    # Imprimimos la existencia del videojuego de videojuegoED3
    print(f"Existencia del videojuego de videojuegoED3: {videojuegoED3.existencia}")
    
    # Imprimimos la disponibilidad del videojuego de videojuegoED1
    print(f"Disponibilidad del videojuego de videojuegoED1: {videojuegoED1.disponibilidad}")
    
    # Determinamos si videojuegoED2 y videojuegoED3 son diferentes
    print(f"videojuegoED2 y videojuegoED3 son diferentes: {videojuegoED2 != videojuegoED3}")
