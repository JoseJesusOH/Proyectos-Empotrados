from peliculas import Peliculas
from inventarioPeliculas import InventarioPeliculas
from persistenciaException import PersistenciaException
from pelicula import Pelicula
from peliculaED import PeliculaED
class PersistenciaBD:

    def __init__(self):
        self.catalogoPeliculas = Peliculas("root", "123456", "localhost", "videocentro", "peliculas")
        self.inventarioPeliculas = InventarioPeliculas("root", "123456", "localhost", "videocentro", "inventariopeliculas")

    def obtenPelicula(self, pelicula):
        p=None
        try:
            p = self.catalogoPeliculas.obten(pelicula)
        except Exception as e:
            print(e.msj)
        if p:
            return p
        else:
            raise PersistenciaException("No se pudo obtener la película del catálogo.")

    def agregaPelicula(self, pelicula): 
        p=None
        try:
            p = self.catalogoPeliculas.obten(pelicula)
        except Exception as e:
            print(e.msj)
        if p:
            raise PersistenciaException("No se puede agregar la película al catálogo o ya existe.")
        else:
            self.catalogoPeliculas.agrega(pelicula)

    def actualizaPelicula(self, pelicula):
        p=None
        try:
            p = self.catalogoPeliculas.obten(pelicula)
        except Exception as e:
            print(e.msj)
        if p:
            try:
                self.catalogoPeliculas.actualiza(pelicula)
            except Exception as e:
                raise PersistenciaException(e.msj)
        else:
            raise PersistenciaException("No se puede actualizar la película al catálogo o no existe.")

    def eliminaPelicula(self, pelicula):
        p=None
        try:
            p = self.catalogoPeliculas.obten(pelicula)
        except Exception as e:
            print(e.msj)
        if p:
            try:
                self.catalogoPeliculas.elimina(pelicula)
            except Exception as e:
                raise PersistenciaException(e.msj)
        else:
            raise PersistenciaException("No se puede eliminar la película del catálogo o no existe.")
        
    def consultaPeliculas(self):
        return self.catalogoPeliculas.lista()
    
    def consultaPeliculasGenero(self, genero):
        return self.catalogoPeliculas.listaGenero(genero)
    
    def consultaPeliculasActor(self, actor):
        return self.catalogoPeliculas.listaActor(actor)
    
    def consultaPeliculasProductora(self, productora):
        return self.catalogoPeliculas.listaProductora(productora)
    
    def inventariarPelicula(self, pelicula, cantidad): 
        peliculaED=None
        try:
            peliculaED=self.inventarioPeliculas.obten(pelicula)
        except Exception as e:
            raise PersistenciaException(e.msj)
        if peliculaED is None:
            peliculaED=PeliculaED(pelicula,cantidad,cantidad)
            self.inventarioPeliculas.agrega(peliculaED)
        else:
            peliculaED.existencia = peliculaED.existencia+cantidad
            peliculaED.disponibilidad =peliculaED.disponibilidad +cantidad
            self.inventarioPeliculas.actualiza(peliculaED)

    def desinventariarPelicula(self, pelicula, cantidad):
        peliculaED=None
        try:
            peliculaED=self.inventarioPeliculas.obten(pelicula)
        except Exception as e:
            raise PersistenciaException(e.msj)
        if peliculaED is None:
            raise PersistenciaException("No es posible desinventariar una pelicula inexistente")
        else:
            if (peliculaED.existencia-cantidad)<=0:
                self.inventarioPeliculas.elimina(peliculaED)
            else:
                peliculaED.existencia = peliculaED.existencia-cantidad
                peliculaED.disponibilidad =peliculaED.disponibilidad -cantidad
                self.inventarioPeliculas.actualiza(peliculaED)

    def consultarInventarioPeliculas(self):
        peliculasEDCompletas=[]
        for resultado in self.inventarioPeliculas.lista():
            pelicula=self.obtenPelicula(resultado.pelicula)
            peliculaED = PeliculaED(pelicula, resultado.existencia, resultado.disponibilidad)
            peliculasEDCompletas.append(peliculaED)
        return peliculasEDCompletas
