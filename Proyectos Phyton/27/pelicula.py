from articulo import Articulo

class Pelicula(Articulo):
    def __init__(self, numCatalogo, titulo=None, genero=None, clasificacion=None, actor1=None, actor2=None, productora=None):
        super().__init__(numCatalogo, titulo, genero, clasificacion)
        self.__actor1 = actor1
        self.__actor2 = actor2
        self.__productora = productora
    
    @property
    def actor1(self):
        return self.__actor1
    
    @actor1.setter
    def actor1(self, actor1):
        self.__actor1 = actor1
    
    @property
    def actor2(self):
        return self.__actor2
    
    @actor2.setter
    def actor2(self, actor2):
        self.__actor2 = actor2
    
    @property
    def productora(self):
        return self.__productora
    
    @productora.setter
    def productora(self, productora):
        self.__productora = productora
    
    def __str__(self):
        return f"{self.numCatalogo}, {self.titulo}, {self.genero}, {self.clasificacion}, {self.actor1}, {self.actor2}, {self.productora}"
    
    def __repr__(self):
        return f"Pelicula({self.numCatalogo}, {self.titulo}, {self.genero}, {self.clasificacion}, {self.actor1}, {self.actor2}, {self.productora})"

if __name__ == "__main__":
    pelicula1 = Pelicula("P00001", "Orgullo y prejuicio", "Drama", "A", "Colin Firth", "Anna Chancellor", "BBC")
    pelicula2 = Pelicula("P00002", "El diablo viste de moda", "Comedia", "B15", "Anne Hathaway", "Meryl Streep", "20 Century Fox")
    pelicula3 = Pelicula("P00003", "El ilusionista", "Misterio", "A", "Rufus Sewell", "Edward Norton", "Quality Films")

    print(pelicula1)
    print(pelicula2)
    print(pelicula3)

    print(f"Productora de la película 1: {pelicula1.productora}")

    pelicula2.titulo, pelicula3.titulo = pelicula3.titulo, pelicula2.titulo

    print(pelicula2)
    print(pelicula3)

    print(f"pelicula2 y pelicula3 son iguales: {pelicula2 == pelicula3}")
