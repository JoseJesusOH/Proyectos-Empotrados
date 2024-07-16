from pelicula import Pelicula

class PeliculaED:
    def __init__(self, pelicula, existencia, disponibilidad):
        if not isinstance(pelicula, Pelicula):
            raise TypeError("El atributo 'pelicula' debe ser un objeto de la clase Pelicula.")
        self._pelicula = pelicula
        self._existencia = existencia
        self._disponibilidad = disponibilidad
    
    @property
    def pelicula(self):
        return self._pelicula
    
    @pelicula.setter
    def pelicula(self, pelicula):
        if not isinstance(pelicula, Pelicula):
            raise TypeError("El atributo 'pelicula' debe ser un objeto de la clase Pelicula.")
        self._pelicula = pelicula
    
    @property
    def existencia(self):
        return self._existencia
    
    @existencia.setter
    def existencia(self, existencia):
        self._existencia = existencia
    
    @property
    def disponibilidad(self):
        return self._disponibilidad
    
    @disponibilidad.setter
    def disponibilidad(self, disponibilidad):
        self._disponibilidad = disponibilidad
    
    def __eq__(self, peliculaED):
        return self._pelicula == peliculaED.pelicula
    
    def __ne__(self, peliculaED):
        return self._pelicula != peliculaED.pelicula
    
    def __str__(self):
        return f"{self._pelicula}, {self._existencia}, {self._disponibilidad}"
    
    def __repr__(self):
        return f"PeliculaED({repr(self._pelicula)}, {self._existencia}, {self._disponibilidad})"


if __name__ == '__main__':
    # Crear objetos de la clase Pelicula
    pelicula1 = Pelicula("P00001", "Orgullo y prejuicio", "Drama", "A", "Colin Firth", "Anna Chancellor", "BBC")
    pelicula2 = Pelicula("P00002", "El diablo viste de moda", "Comedia", "B15", "Anne Hathaway", "Meryl Streep", "20 Century Fox")
    pelicula3 = Pelicula("P00003", "El ilusionista", "Misterio", "A", "Rufus Sewell", "Edward Norton", "Quality Films")

    # Crear objetos de la clase PeliculaED
    peliculaED1 = PeliculaED(pelicula1, 10, 8)
    peliculaED2 = PeliculaED(pelicula2, 10, 6)
    peliculaED3 = PeliculaED(pelicula3, 15, 5)

    # Desplegar los datos de los tres objetos de la clase PeliculaED
    print("Datos de peliculaED1:")
    print(peliculaED1)
    print("Datos de peliculaED2:")
    print(peliculaED2)
    print("Datos de peliculaED3:")
    print(peliculaED3)

    # Desplegar la película de peliculaED2
    print("Película de peliculaED2:")
    print(peliculaED2.pelicula)

    # Desplegar la existencia de la película de peliculaED3
    print("Existencia de la película de peliculaED3:")
    print(peliculaED3.existencia)

    # Desplegar la disponibilidad de la película de peliculaED1
    print("Disponibilidad de la película de peliculaED1:")
    print(peliculaED1.disponibilidad)

    # Determinar si peliculaED2 y peliculaED3 son iguales
    print("¿peliculaED2 y peliculaED3 son iguales?")
    print(peliculaED2 == peliculaED3)