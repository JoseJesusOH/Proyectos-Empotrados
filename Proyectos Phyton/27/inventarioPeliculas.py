from tabla import Tabla
from pelicula import Pelicula
from persistenciaException import PersistenciaException
from peliculaED import PeliculaED

class InventarioPeliculas(Tabla):

    def __init__(self, user, password, host, database, nomTablaInventarioPeliculas):
        super().__init__(user, password, host, database)
        self.__nomTablaInventarioPeliculas = nomTablaInventarioPeliculas

    def obten(self, peliculaED):
        try:
            operacion = f"SELECT * FROM {self.__nomTablaInventarioPeliculas} WHERE numCatalogo='{peliculaED.numCatalogo}'"
            resultado = super().obten(operacion)
            if resultado is None:
                return None
            pelicula = Pelicula(resultado[0])
            peliculaED = PeliculaED(pelicula, resultado[1], resultado[2])
            return peliculaED
        except Exception as e:
            raise PersistenciaException("Error al obtener la película del inventario.") from e

    def agrega(self, peliculaED):
        try:
            pelicula = peliculaED.pelicula
            operacion = f"INSERT INTO {self.__nomTablaInventarioPeliculas} (numCatalogo, existencia, disponibilidad) VALUES ('{pelicula.numCatalogo}', {peliculaED.existencia}, {peliculaED.disponibilidad})"
            super().actualiza(operacion)
        except Exception as e:
            raise PersistenciaException("Error al agregar la película al inventario.") from e

    def actualiza(self, peliculaED):
        try:
            pelicula = peliculaED.pelicula
            operacion = f"UPDATE {self.__nomTablaInventarioPeliculas} SET   existencia='{peliculaED.existencia}', disponibilidad='{peliculaED.disponibilidad}' WHERE numCatalogo='{pelicula.numCatalogo}'"
            super().actualiza(operacion)
        except Exception as e:
            raise PersistenciaException("Error al actualizar la película del inventario.") from e

    def elimina(self, peliculaED):
        try:
            operacion = f"DELETE FROM {self.__nomTablaInventarioPeliculas} WHERE numCatalogo='{peliculaED.pelicula.numCatalogo}'"
            super().actualiza(operacion)
        except Exception as e:
            raise PersistenciaException("Error al eliminar la película del inventario.") from e
        
    def lista(self):
        operacion = f"SELECT * FROM {self.__nomTablaInventarioPeliculas}"
        try:
            resultados = super().consulta(operacion)
            peliculasED = []
            for resultado in resultados:
                pelicula = Pelicula(resultado[0])
                peliculaED = PeliculaED(pelicula, resultado[1], resultado[2])
                peliculasED.append(peliculaED)
            return peliculasED
        except Exception as e:
            msj = self.msj_error(e)
            raise PersistenciaException(msj)
