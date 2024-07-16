from tabla import Tabla
from persistenciaException import PersistenciaException
from pelicula import Pelicula

class Peliculas(Tabla):

    def __init__(self, user, password, host, database, nomTablaPeliculas):
        super().__init__(user, password, host, database)
        self.__nomTablaPeliculas = nomTablaPeliculas

    def obten(self, pelicula):
        operacion = f"SELECT * FROM {self.__nomTablaPeliculas} WHERE numCatalogo = '{pelicula.numCatalogo}'"
        try:
            resultado = super().obten(operacion)
            if resultado is not None:
                numCatalogo, titulo, genero, clasificacion, actor1, actor2, productora = resultado
                return Pelicula(numCatalogo, titulo, genero, clasificacion, actor1, actor2, productora)
            else:
                return None
        except Exception as e:
            msj = self.msj_error(e)
            raise PersistenciaException(msj)

    def agrega(self, pelicula):
        operacion = f"INSERT INTO {self.__nomTablaPeliculas} (numCatalogo, titulo, genero, clasificacion, actor1, actor2, productora) VALUES ('{pelicula.numCatalogo}', '{pelicula.titulo}', '{pelicula.genero}', '{pelicula.clasificacion}', '{pelicula.actor1}', '{pelicula.actor2}', '{pelicula.productora}')"
        try:
            super().actualiza(operacion)
        except Exception as e:
            msj = self.msj_error(e)
            raise PersistenciaException(msj)

    def actualiza(self, pelicula):
        operacion = f"UPDATE {self.__nomTablaPeliculas} SET titulo = '{pelicula.titulo}', genero = '{pelicula.genero}', clasificacion = '{pelicula.clasificacion}', actor1 = '{pelicula.actor1}', actor2 = '{pelicula.actor2}', productora = '{pelicula.productora}' WHERE numCatalogo = '{pelicula.numCatalogo}'"
        try:
            super().actualiza(operacion)
        except Exception as e:
            msj = self.msj_error(e)
            raise PersistenciaException(msj)

    def elimina(self, pelicula):
        operacion = f"DELETE FROM {self.__nomTablaPeliculas} WHERE numCatalogo = '{pelicula.numCatalogo}'"
        try:
            super().actualiza(operacion)
        except Exception as e:
            msj = self.msj_error(e)
            raise PersistenciaException(msj)
        
    def lista(self):
        operacion = f"SELECT * FROM {self.__nomTablaPeliculas}"
        try:
            resultados = super().consulta(operacion)
            peliculas = []
            if resultados:
                for resultado in resultados:
                    numCatalogo, titulo, genero, clasificacion, actor1, actor2, productora = resultado
                    pelicula = Pelicula(numCatalogo, titulo, genero, clasificacion, actor1, actor2, productora)
                    peliculas.append(pelicula)
            return peliculas
        except Exception as e:
            msj = self.msj_error(e)
            raise PersistenciaException(msj)

    def listaGenero(self, genero):
        operacion = f"SELECT * FROM {self.__nomTablaPeliculas} WHERE genero = '{genero:s}';"
        try:
            resultados = super().consulta(operacion)
            peliculas = []
            if resultados:
                for resultado in resultados:
                    numCatalogo, titulo, genero, clasificacion, actor1, actor2, productora = resultado
                    pelicula = Pelicula(numCatalogo, titulo, genero, clasificacion, actor1, actor2, productora)
                    peliculas.append(pelicula)
            return peliculas
        except Exception as e:
            msj = self.msj_error(e)
            raise PersistenciaException(msj)
        
    def listaActor(self, actor):
        operacion = f"SELECT * FROM {self.__nomTablaPeliculas} WHERE actor1 = '{actor:s}';"
        try:
            resultados = super().consulta(operacion)
            peliculas = []
            if resultados:
                for resultado in resultados:
                    numCatalogo, titulo, genero, clasificacion, actor1, actor2, productora = resultado
                    pelicula = Pelicula(numCatalogo, titulo, genero, clasificacion, actor1, actor2, productora)
                    peliculas.append(pelicula)
            return peliculas
        except Exception as e:
            msj = self.msj_error(e)
            raise PersistenciaException(msj)
        
    def listaProductora(self, productora):  
        operacion = f"SELECT * FROM {self.__nomTablaPeliculas} WHERE productora = '{productora:s}';"
        try:
            resultados = super().consulta(operacion)
            peliculas = []
            if resultados:
                for resultado in resultados:
                    numCatalogo, titulo, genero, clasificacion, actor1, actor2, productora = resultado
                    pelicula = Pelicula(numCatalogo, titulo, genero, clasificacion, actor1, actor2, productora)
                    peliculas.append(pelicula)
            return peliculas
        except Exception as e:
            msj = self.msj_error(e)
            raise PersistenciaException(msj)   