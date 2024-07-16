class Articulo:
    def __init__(self, numCatalogo, titulo=None, genero=None, clasificacion=None):
        self._numCatalogo = numCatalogo
        self._titulo = titulo
        self._genero = genero
        self._clasificacion = clasificacion
        
    @property
    def numCatalogo(self):
        return self._numCatalogo
    
    @property
    def titulo(self):
        return self._titulo
    
    @titulo.setter
    def titulo(self, titulo):
        self._titulo = titulo
        
    @property
    def genero(self):
        return self._genero
    
    @genero.setter
    def genero(self, genero):
        self._genero = genero
        
    @property
    def clasificacion(self):
        return self._clasificacion
    
    @clasificacion.setter
    def clasificacion(self, clasificacion):
        self._clasificacion = clasificacion
    
    def __eq__(self, articulo):
        return self.numCatalogo == articulo.numCatalogo
    
    def __ne__(self, articulo):
        return self.numCatalogo != articulo.numCatalogo
    
    def __str__(self):
        return f"{self.numCatalogo}, {self.titulo}, {self.genero}, {self.clasificacion}"
    
    def __repr__(self):
        return f"{__name__}.{type(self).__name__}({self.numCatalogo}, {self.titulo}, {self.genero}, {self.clasificacion})"
