#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	MYSQL *conn;
	int err;
	char dni[10]; 
	char nombre [25]; 
	int edad;
	char edads [3];
	int i;
	char consulta [80];
	//Creamos una conexion al servidor MYSQL 
	conn = mysql_init(NULL);
	if (conn==NULL) {
		printf ("Error al crear la conexion: %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//inicializar la conexi??n, entrando nuestras claves de acceso y
	//el nombre de la base de datos a la que queremos acceder 
	conn = mysql_real_connect (conn, "localhost","root", "mysql", "personas",0, NULL, 0);
	if (conn==NULL) {
		printf ("Error al inicializar la conexion: %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//Introduciremos en la base de datos 4 personas, 
	//cuyos datos pedimos al usuario
	for (i=0; i<4; i++) {
		printf ("Escribe el DNI, nombre y edad de la persona, separados por un blanco\n");
		err = scanf ("%s %s %d", dni, nombre, &edad);
		if (err!=3) {
			printf ("Error al introducir los datos \n");
			exit (1);
		}
		// Ahora construimos el string con el comando SQL
		// para insertar la persona en la base. Ese string es:
		// INSERT INTO personas VALUES ('dni', 'nombre', edad); 
		strcpy (consulta, "INSERT INTO personas VALUES ('");
		//concatenamos el dni 
		strcat (consulta, dni); 
		strcat (consulta, "','");
		//concatenamos el nombre 
		strcat (consulta, nombre); 
		strcat (consulta, "',");
		//convertimos la edad en un string y lo concatenamos 
		sprintf(edads, "%d", edad);
		strcat (consulta, edads); 
		strcat (consulta, ");");
		
		printf("consulta = %s\n", consulta);
		// Ahora ya podemos realizar la insercion 
		err = mysql_query(conn, consulta);
		if (err!=0) {
			printf ("Error al introducir datos la base %u %s\n", 
					mysql_errno(conn), mysql_error(conn));
			exit (1);
		}
	}
	// cerrar la conexion con el servidor MYSQL 
	mysql_close (conn);
	exit(0);
}
