INSERT INTO pr1_asesores(nombre, apMaterno, apPaterno) VALUES ("Juan", "Pérez", "Rodriguez");
INSERT INTO pr1_asesores(nombre, apMaterno, apPaterno) VALUES ("Marcos", "Salinas", "Pérez");
INSERT INTO pr1_asesores(nombre, apMaterno, apPaterno) VALUES ("Andrés", "Gutierrez", "Hernández");
INSERT INTO pr1_asesores(nombre, apMaterno, apPaterno) VALUES ("Cristian", "Juárez", "Mendez");
INSERT INTO pr1_asesores(nombre, apMaterno, apPaterno) VALUES ("Alfredo", "Vega", "Mora");

/* Valores de las quejas de los asesores y usuarios */
INSERT INTO pr1_quejas(pr1_clientes_username, pr1_asesores_idAsesor, comentario, status) VALUES("Jair1", 1, "No me gustó mi producto", 0);
INSERT INTO pr1_quejas(pr1_clientes_username, pr1_asesores_idAsesor, comentario, status) VALUES("Gaby2", 4,  "Tengo problemas con un producto", 1);
INSERT INTO pr1_quejas(pr1_clientes_username, pr1_asesores_idAsesor, comentario, status) VALUES("Cesar3", 2,  "No me ha llegado mi pedido", 0);
INSERT INTO pr1_quejas(pr1_clientes_username, pr1_asesores_idAsesor, comentario, status) VALUES("Raul4", 3,  "Me cobraron de más", 0);
INSERT INTO pr1_quejas(pr1_clientes_username, pr1_asesores_idAsesor, comentario, status) VALUES("Ulises5", 3,  "Me sigue sin llegar mi producto", 1);
INSERT INTO pr1_quejas(pr1_clientes_username, pr1_asesores_idAsesor, comentario, status) VALUES("Jair1", 5,  "No me ha gustado el servicio", 1);
INSERT INTO pr1_quejas(pr1_clientes_username, pr1_asesores_idAsesor, comentario, status) VALUES("Cesar3", 2,  "Tengo problemas con el servicio", 0);