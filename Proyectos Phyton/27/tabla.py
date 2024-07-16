
import mysql.connector
import mysql.connector.errorcode

class Tabla:
    
    def __init__(self, user, password, host, database):
        self.user = user
        self.password = password
        self.host = host
        self.database = database

    def obten(self, operacion):
        # Establece la conexion con la BD
        conexion = mysql.connector.connect(user=self.user, 
                                        password=self.password, 
                                        host=self.host, 
                                        database=self.database)
        try:
            # Obtiene un cursor de la conexion
            cursor = conexion.cursor()
            # Consulta la tabla 
            cursor.execute(operacion)
            # Obtiene los resultados de la consulta
            resultado = cursor.fetchone()
            # Regresa una tupla con el resultado de la consulta
            return resultado
        finally:
            # Si hubo una conexion con la base de datos
            if(conexion.is_connected()):
                # Cierra el cursor
                cursor.close()
                # Cierra la conexion
                conexion.close()

    def consulta(self, operacion):
        # Establece la conexion con la BD
        conexion = mysql.connector.connect(user=self.user, 
                                        password=self.password, 
                                        host=self.host, 
                                        database=self.database)
                                        
        try:
            # Obtiene un cursor de la conexion
            cursor = conexion.cursor()
            # Consulta la tabla 
            cursor.execute(operacion)
            # Obtiene los resultados de la consulta
            resultados = cursor.fetchall()
            # Regresa una lista de tuplas con los resultados de la consulta
            return resultados
        finally:
            # Si hubo una conexion con la base de datos
            if(conexion.is_connected()):
                # Cierra el cursor
                cursor.close()
                # Cierra la conexion
                conexion.close()

    def actualiza(self, operacion):
        # Establece la conexion con la BD
        conexion = mysql.connector.connect(user=self.user, 
                                        password=self.password, 
                                        host=self.host, 
                                        database=self.database)
                                        
        try:
            # Obtiene un cursor de la conexion
            cursor = conexion.cursor()
            # Actualiza la tabla
            cursor.execute(operacion)
            conexion.commit()
        except mysql.connector.IntegrityError:
            # Si ocurrio un error, rollback
            conexion.rollback()
            # Relanza la excepcion cachada
            raise 
        finally:
            # Si hubo una conexion con la base de datos
            if(conexion.is_connected()):
                # Cierra el cursor
                cursor.close()
                # Cierra la conexion
                conexion.close()

    def msj_error(self, err):
        if err.errno == mysql.connector.errorcode.ER_SYNTAX_ERROR:
            return f'Error de sintaxis en la operacion' 
        elif err.errno == mysql.connector.errorcode.ER_DUP_ENTRY:
            return f'Registro repetido' 
        elif err.errno == mysql.connector.errorcode.ER_ROW_IS_REFERENCED_2:
            return f'No se puede actualizar o borrar registro'
        elif err.errno ==  mysql.connector.errorcode.ER_NO_REFERENCED_ROW_2:
            return f'No se puede agregar o actualizar registro'
        elif err.errno ==  mysql.connector.errorcode.ER_PARSE_ERROR:
            return f'Error de sintaxis en la operacion' 


            