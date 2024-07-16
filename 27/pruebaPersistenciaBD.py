
from persistenciaBD import PersistenciaBD
from pelicula import Pelicula
from peliculaED import PeliculaED

persistencia = PersistenciaBD()
catalogo_peliculas = []

pelicula1 = Pelicula("P00001", "Orgullo y prejuicio", "Drama", "A", "Colin Firth", "Anna Chancellor", "BBC")
pelicula2 = Pelicula("P00002", "El diablo viste de moda", "Comedia", "B15", "Anne Hathaway", "Meryl Streep", "20 Century Fox")
pelicula3 = Pelicula("P00003", "El ilusionista", "Misterio", "A", "Rufus Sewell", "Edward Norton", "Quality Films")
pelicula4 = Pelicula("P00004", "Star Treck", "Ciencia Ficción", "A", "Chris Pine", "Zachary Quinto", "Paramount Pictures")

catalogo_peliculas.append(pelicula1)
catalogo_peliculas.append(pelicula2)
catalogo_peliculas.append(pelicula3)
catalogo_peliculas.append(pelicula4)
print("--------------------------------------------------------------------------")
print("Agrégale al catálogo de películas las siguientes películas")
for pelicula in catalogo_peliculas:
    try:
        peliculaED=persistencia.agregaPelicula(pelicula)
        print("La pelicula ",pelicula.numCatalogo," fue agregada exitosamente")
    except Exception as e:
        print(e.msj)
print("--------------------------------------------------------------------------")
print("Agrega de nuevo la película 2 al catálogo de películas")
try:
    persistencia.agregaPelicula(pelicula2)
except Exception as e:
    print(e.msj)
print("--------------------------------------------------------------------------")
print("Despliega la lista del catálogo de películas")
for pelicula in persistencia.consultaPeliculas():
    try:
        print(pelicula)
    except Exception as e:
        print(e.msj)
print("--------------------------------------------------------------------------")
print("Obtén del catálogo de películas, la película de número de catálogo ‘P00003’.")
peliculaObtener=None
try:
    peliculaObtener=persistencia.obtenPelicula(Pelicula("P00003"))
    print(peliculaObtener)
except Exception as e:
    print(e.msj)
print("--------------------------------------------------------------------------")
print("Cambia el género de la película de número de catálogo ‘P00001’ a ‘Romance’.")
try:
    pelicula1.genero="Romance"
    persistencia.actualizaPelicula(pelicula1)
except Exception as e:
    print(e.msj)
print("--------------------------------------------------------------------------")
print("Cambia el género de la película de número de catálogo ‘P00007’ a ‘Comedia’.")
try:
    pelicula7=Pelicula("P00007")
    pelicula7.genero="Comedia"
    persistencia.actualizaPelicula(pelicula7)
except Exception as e:
    print(e.msj)
print("--------------------------------------------------------------------------")
print("Elimina del catálogo de películas la película de número de catálogo ‘P00002’.")
try:
    persistencia.eliminaPelicula(Pelicula("P00002"))
except Exception as e:
    print(e.msj)
print("--------------------------------------------------------------------------")
print("Elimina del catálogo de películas la película de número de catálogo ‘P00009’.")
try:
    persistencia.eliminaPelicula(Pelicula("P00009"))
except Exception as e:
    print(e.msj)
print("--------------------------------------------------------------------------")
print("Despliega la lista del catálogo de películas.")
for pelicula in persistencia.consultaPeliculas():
    try:
        print(pelicula)
    except Exception as e:
        print(e.msj)
print("--------------------------------------------------------------------------")
print("Despliega la lista de películas del género ‘Misterio’ del catálogo de películas")
for pelicula in persistencia.consultaPeliculasGenero("Misterio"):
    try:
        print(pelicula)
    except Exception as e:
        print(e.msj)
print("--------------------------------------------------------------------------")
print("Despliega la lista de películas del actor ‘Chris Pine’ del catálogo de películas")
for pelicula in persistencia.consultaPeliculasActor("Chris Pine"):
    try:
        print(pelicula)
    except Exception as e:
        print(e.msj)
print("--------------------------------------------------------------------------")
print("Despliega la lista de películas de la productora ‘BBC’ del catálogo de películas")
for pelicula in persistencia.consultaPeliculasProductora("BBC"):
    try:
        print(pelicula)
    except Exception as e:
        print(e.msj)
print("--------------------------------------------------------------------------")
print("Inventaríe tres unidades de la película de número de catálogo ‘P00001’.")
try:
    persistencia.inventariarPelicula(Pelicula("P00001"),3)
except Exception as e:
    print(e.msj)
print("--------------------------------------------------------------------------")
print("Inventaríe diez unidades de la película de número de catálogo ‘P00003’.")
try:
    persistencia.inventariarPelicula(Pelicula("P00003"),10)
except Exception as e:
    print(e.msj)

print("--------------------------------------------------------------------------")
print("Inventaríe cinco unidades de la película de número de catálogo ‘P00004’.")
try:
    persistencia.inventariarPelicula(Pelicula("P00004"),5)
except Exception as e:
    print(e.msj)
print("--------------------------------------------------------------------------")
print("Despliegue la lista del inventario de películas.")
for peliculaED in persistencia.consultarInventarioPeliculas():
    try:
        print(peliculaED)
    except Exception as e:
        print(e.msj)
print("--------------------------------------------------------------------------")
print("Inventaríe dos unidades de la película de número de catálogo ‘P00003’.")
try:
    persistencia.inventariarPelicula(Pelicula("P00003"),2)
except Exception as e:
    print(e.msj)
print("--------------------------------------------------------------------------")
print("Inventaríe cuatro unidades de la película de número de catálogo ‘P00006’.")
try:
    persistencia.inventariarPelicula(Pelicula("P00006"),4)
except Exception as e:
    print(e.msj)
print("--------------------------------------------------------------------------")
print("Desinventaríe dos unidades de la película de número de catálogo ‘P00004’.")
try:
    persistencia.desinventariarPelicula(Pelicula("P00004"),2)
except Exception as e:
    print(e.msj)
print("--------------------------------------------------------------------------")
print("Despliegue la lista del inventario de películas.")
for peliculaED in persistencia.consultarInventarioPeliculas():
    try:
        print(peliculaED)
    except Exception as e:
        print(e.msj)

peliculasEDFin=persistencia.consultarInventarioPeliculas()
print("--------------------------------------------------------------------------")
print("Despliega la existencia de la película de número de catálogo ‘P00003’.")
peliculaED3=None
for peliculaED in peliculasEDFin:
    try:
        if(peliculaED.pelicula==Pelicula("P00003")):
            peliculaED3=peliculaED 
            break  
    except Exception as e:
        print(e.msj)
print(peliculaED3)
print("--------------------------------------------------------------------------")
print("Despliega la disponibilidad de la película de número de catálogo ‘P00004’.")
peliculaED4=None
for peliculaED in peliculasEDFin:
    try:
        if(peliculaED.pelicula==Pelicula("P00004")):
            peliculaED4=peliculaED 
            break  
    except Exception as e:
        print(e.msj)
print(peliculaED4)