DROP DATABASE IF EXISTS Juego;
CREATE DATABASE Juego;

USE Juego;

CREATE TABLE jugador(
	id INT(20),
	nombre VARCHAR(20),
	password VARCHAR(20),
	PRIMARY KEY (id)
)ENGINE=InnoDB;

CREATE TABLE partida(
	id INT(20),
	ganador VARCHAR(20),
	tiempo_stop FLOAT,
	PRIMARY KEY (id)
)ENGINE=InnoDB;

CREATE TABLE relacion(
	idJugador INT(20),
	idPartida INT(20), 
	puntos INT,
	FOREIGN KEY (idJugador) REFERENCES jugador(id),
	FOREIGN KEY (idPartida) REFERENCES partida(id)
)ENGINE=InnoDB;

INSERT INTO jugador VALUES (1, 'Juan', '123456');
INSERT INTO jugador VALUES (2, 'Mayra', '654321');
INSERT INTO jugador VALUES (3, 'Cristina', '123456');

INSERT INTO partida VALUES (1, 'Juan', 3.50);
INSERT INTO partida VALUES (2, 'Cristina', 5.65);
INSERT INTO partida VALUES (3, 'Juan', 4.25);
INSERT INTO partida VALUES (4, 'Mayra', 4.00);

INSERT INTO relacion VALUES (1, 1, 5);
INSERT INTO relacion VALUES (2, 1, 2);
INSERT INTO relacion VALUES (1, 2, 5);
INSERT INTO relacion VALUES (3, 2, 7);
INSERT INTO relacion VALUES (1, 3, 10);
INSERT INTO relacion VALUES (2, 3, 5);
INSERT INTO relacion VALUES (2, 4, 10);
INSERT INTO relacion VALUES (3, 4, 6);

