INSERT INTO pr1_clientes(username, password, direccionEnvio, idCategoria, nombre, apPaterno, apMaterno, fechaNac, direccionFacturacion, RFC, codigoPostal) VALUES ("Jair1", "alf123", "Direccion prueba 1", 1, "Jair", "Escamilla", "Hernández", '2000-06-14', "Direccion facturacion 2", "GAFJ810702NA0", "07280");
INSERT INTO pr1_clientes(username, password, direccionEnvio, idCategoria, nombre, apPaterno, apMaterno, fechaNac, direccionFacturacion, RFC, codigoPostal) VALUES ("Gaby2", "gab123", "Direccion prueba 2", 2, "Gaby", "Uribe", "", '2000-01-08', "Direccion facturacion 2", "GAFJ810702NA1", "07281");
INSERT INTO pr1_clientes(username, password, direccionEnvio, idCategoria, nombre, apPaterno, apMaterno, fechaNac, direccionFacturacion, RFC, codigoPostal) VALUES ("Cesar3", "fido123", "Direccion prueba 3", 3, "Cesar", "Arellano", "Velazquez", '2000-05-08', "Direccion facturacion 3", "GAFJ810702NA3", "07283");
INSERT INTO pr1_clientes(username, password, direccionEnvio, idCategoria, nombre, apPaterno, apMaterno, fechaNac, direccionFacturacion, RFC, codigoPostal) VALUES ("Raul4", "ruls123", "Direccion prueba 4", 4, "Raul", "Gonzalez", "Portillo", '2000-06-22', "Direccion facturacion 4", "GAFJ810702NA5", "07284");
INSERT INTO pr1_clientes(username, password, direccionEnvio, idCategoria, nombre, apPaterno, apMaterno, fechaNac, direccionFacturacion, RFC, codigoPostal) VALUES ("Ulises5", "musk123", "Direccion prueba 5", 1, "Ulises", "Magaña", "Estrada", '2000-11-22', "Direccion facturacion 5", "GAFJ810702NA5", "07285");

/* Insertando las tarjetas */
INSERT INTO pr1_tarjetas(numeroTarjeta, fechaVencimiento, username) VALUES("1234567891023456", '2022-06-14', "Jair1");
INSERT INTO pr1_tarjetas(numeroTarjeta, fechaVencimiento, username) VALUES("1234565789189751", '2024-09-22', "Jair1");
INSERT INTO pr1_tarjetas(numeroTarjeta, fechaVencimiento, username) VALUES("8974565789189754", '2023-06-11', "Gaby2");
INSERT INTO pr1_tarjetas(numeroTarjeta, fechaVencimiento, username) VALUES("8974574569189753", '2022-03-21', "Gaby2");
INSERT INTO pr1_tarjetas(numeroTarjeta, fechaVencimiento, username) VALUES("8974565468713242", '2023-06-13', "Cesar3");
INSERT INTO pr1_tarjetas(numeroTarjeta, fechaVencimiento, username) VALUES("8974895710189734", '2022-03-11', "Cesar3");
INSERT INTO pr1_tarjetas(numeroTarjeta, fechaVencimiento, username) VALUES("8974565468713242", '2023-06-15', "Raul4");
INSERT INTO pr1_tarjetas(numeroTarjeta, fechaVencimiento, username) VALUES("8974895710189734", '2022-03-08', "Raul4");
INSERT INTO pr1_tarjetas(numeroTarjeta, fechaVencimiento, username) VALUES("8978974246713242", '2023-11-22', "Ulises5");
INSERT INTO pr1_tarjetas(numeroTarjeta, fechaVencimiento, username) VALUES("8047895710489721", '2022-12-04', "Ulises5");

/* Insertando las categorias de los clientes */
INSERT INTO pr1_categorias_clientes(nombreCategoria, descuentoEnvio) VALUES("Básico", 15);
INSERT INTO pr1_categorias_clientes(nombreCategoria, descuentoEnvio) VALUES("Básico 2", 50);
INSERT INTO pr1_categorias_clientes(nombreCategoria, descuentoEnvio) VALUES("Platino", 0);
INSERT INTO pr1_categorias_clientes(nombreCategoria, descuentoEnvio) VALUES("Golden", 100);

/* Insertando los beneficios a las categorias */
INSERT INTO pr1_categoriasClientes_beneficios(pr1_categorias_clientes_idCategoria, pr1_tipo_beneficio_idBeneficio) VALUES(1, 1);
INSERT INTO pr1_categoriasClientes_beneficios(pr1_categorias_clientes_idCategoria, pr1_tipo_beneficio_idBeneficio) VALUES(2, 4);
INSERT INTO pr1_categoriasClientes_beneficios(pr1_categorias_clientes_idCategoria, pr1_tipo_beneficio_idBeneficio) VALUES(3, 3);
INSERT INTO pr1_categoriasClientes_beneficios(pr1_categorias_clientes_idCategoria, pr1_tipo_beneficio_idBeneficio) VALUES(4, 2);
INSERT INTO pr1_categoriasClientes_beneficios(pr1_categorias_clientes_idCategoria, pr1_tipo_beneficio_idBeneficio) VALUES(4, 3);