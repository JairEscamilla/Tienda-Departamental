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

/* Insertando los comentarios de los clientes a los productos */
INSERT INTO pr1_comentarios(pr1_clientes_username, pr1_productos_idProducto, comentario) VALUES("Jair1", 4, "Me gusto mucho este producto");
INSERT INTO pr1_comentarios(pr1_clientes_username, pr1_productos_idProducto, comentario) VALUES("Gaby2", 1, "Un excelente producto");
INSERT INTO pr1_comentarios(pr1_clientes_username, pr1_productos_idProducto, comentario) VALUES("Cesar3", 10, "He tenido problemas en su uso");
INSERT INTO pr1_comentarios(pr1_clientes_username, pr1_productos_idProducto, comentario) VALUES("Ulises5", 20, "Funciona de maravilla");
INSERT INTO pr1_comentarios(pr1_clientes_username, pr1_productos_idProducto, comentario) VALUES("Raul4", 20, "No me gustó su funcionamiento");
INSERT INTO pr1_comentarios(pr1_clientes_username, pr1_productos_idProducto, comentario) VALUES("Jair1", 15, "Es una muy buena pelicula");
INSERT INTO pr1_comentarios(pr1_clientes_username, pr1_productos_idProducto, comentario) VALUES("Gaby2", 9, "Me gustó mucho el diseño de la computadora");
INSERT INTO pr1_comentarios(pr1_clientes_username, pr1_productos_idProducto, comentario) VALUES("Jair1", 1, "Me ha servido mucho para hacer ejercicio");
INSERT INTO pr1_comentarios(pr1_clientes_username, pr1_productos_idProducto, comentario) VALUES("Raul4", 21, "Esta hecho de buenos materiales");
INSERT INTO pr1_comentarios(pr1_clientes_username, pr1_productos_idProducto, comentario) VALUES("Raul4", 14, "Muy buen juego");
INSERT INTO pr1_comentarios(pr1_clientes_username, pr1_productos_idProducto, comentario) VALUES("Cesar3", 7, "Me ha gustado mucho");
INSERT INTO pr1_comentarios(pr1_clientes_username, pr1_productos_idProducto, comentario) VALUES("Ulises5", 17, "Me ha sido de mucha utilidad");
INSERT INTO pr1_comentarios(pr1_clientes_username, pr1_productos_idProducto, comentario) VALUES("Ulises5", 6, "Funciona de maravilla");
INSERT INTO pr1_comentarios(pr1_clientes_username, pr1_productos_idProducto, comentario) VALUES("Jair1", 14, "No me gustó mucho, pero cumple con su objetivo");


/* Insertando tipos de pago */
INSERT INTO pr1_tipo_pago(idTipoPago, TipoDePago) VALUES(1, "Tarjeta de crédito");
INSERT INTO pr1_tipo_pago(idTipoPago, TipoDePago) VALUES(2, "Depósito bancario");
INSERT INTO pr1_tipo_pago(idTipoPago, TipoDePago) VALUES(3, "Transferencia electrónica");
INSERT INTO pr1_tipo_pago(idTipoPago, TipoDePago) VALUES(4, "Pago en tiendas de conveniencia");

/* Insertando compras */
INSERT INTO pr1_compras(timestamp, totalPagar, idTipoPago, user, status) VALUES('2020-01-15', 1500, 1, "Jair1", True);
INSERT INTO pr1_compras(timestamp, totalPagar, idTipoPago, user, status) VALUES('2020-02-14', 500, 1, "Jair1", True);

INSERT INTO pr1_compras(timestamp, totalPagar, idTipoPago, user, status) VALUES('2020-03-12', 700, 2, "Gaby2", False);
INSERT INTO pr1_compras(timestamp, totalPagar, idTipoPago, user, status) VALUES('2020-02-09', 600, 2, "Gaby2", True);

INSERT INTO pr1_compras(timestamp, totalPagar, idTipoPago, user, status) VALUES('2020-01-06', 1700, 2, "Cesar3", True);
INSERT INTO pr1_compras(timestamp, totalPagar, idTipoPago, user, status) VALUES('2020-01-19', 2600, 2, "Cesar3", True);

INSERT INTO pr1_compras(timestamp, totalPagar, idTipoPago, user, status) VALUES('2020-02-26', 1500, 2, "Ulises5", False);
INSERT INTO pr1_compras(timestamp, totalPagar, idTipoPago, user, status) VALUES('2020-03-06', 600, 2, "Ulises5", True);


/* Insertando productos a las compras */
INSERT INTO pr1_compras_productos(pr1_compras_idCompra, pr1_productos_idProducto) VALUES(1, 1);
INSERT INTO pr1_compras_productos(pr1_compras_idCompra, pr1_productos_idProducto) VALUES(1, 1);
INSERT INTO pr1_compras_productos(pr1_compras_idCompra, pr1_productos_idProducto) VALUES(1, 10);

INSERT INTO pr1_compras_productos(pr1_compras_idCompra, pr1_productos_idProducto) VALUES(2, 21);
INSERT INTO pr1_compras_productos(pr1_compras_idCompra, pr1_productos_idProducto) VALUES(2, 15);
INSERT INTO pr1_compras_productos(pr1_compras_idCompra, pr1_productos_idProducto) VALUES(2, 11);

INSERT INTO pr1_compras_productos(pr1_compras_idCompra, pr1_productos_idProducto) VALUES(3, 2);
INSERT INTO pr1_compras_productos(pr1_compras_idCompra, pr1_productos_idProducto) VALUES(3, 3);
INSERT INTO pr1_compras_productos(pr1_compras_idCompra, pr1_productos_idProducto) VALUES(3, 4);

INSERT INTO pr1_compras_productos(pr1_compras_idCompra, pr1_productos_idProducto) VALUES(4, 5);
INSERT INTO pr1_compras_productos(pr1_compras_idCompra, pr1_productos_idProducto) VALUES(4, 13);
INSERT INTO pr1_compras_productos(pr1_compras_idCompra, pr1_productos_idProducto) VALUES(4, 14);

INSERT INTO pr1_compras_productos(pr1_compras_idCompra, pr1_productos_idProducto) VALUES(5, 5);
INSERT INTO pr1_compras_productos(pr1_compras_idCompra, pr1_productos_idProducto) VALUES(5, 13);
INSERT INTO pr1_compras_productos(pr1_compras_idCompra, pr1_productos_idProducto) VALUES(5, 14);

INSERT INTO pr1_compras_productos(pr1_compras_idCompra, pr1_productos_idProducto) VALUES(6, 10);
INSERT INTO pr1_compras_productos(pr1_compras_idCompra, pr1_productos_idProducto) VALUES(6, 7);
INSERT INTO pr1_compras_productos(pr1_compras_idCompra, pr1_productos_idProducto) VALUES(6, 4);

INSERT INTO pr1_compras_productos(pr1_compras_idCompra, pr1_productos_idProducto) VALUES(7, 20);
INSERT INTO pr1_compras_productos(pr1_compras_idCompra, pr1_productos_idProducto) VALUES(7, 16);
INSERT INTO pr1_compras_productos(pr1_compras_idCompra, pr1_productos_idProducto) VALUES(7, 12);

INSERT INTO pr1_compras_productos(pr1_compras_idCompra, pr1_productos_idProducto) VALUES(8, 21);
INSERT INTO pr1_compras_productos(pr1_compras_idCompra, pr1_productos_idProducto) VALUES(8, 10);
INSERT INTO pr1_compras_productos(pr1_compras_idCompra, pr1_productos_idProducto) VALUES(8, 14);

/* Insertando devoluciones */
INSERT INTO pr1_devoluciones(idCompra, idProductoDevuelto, comentarioDevolucion) VALUES(1, 1, "Fallas en el producto");
INSERT INTO pr1_devoluciones(idCompra, idProductoDevuelto, comentarioDevolucion) VALUES(2, 21, "No era lo que esperaba");
INSERT INTO pr1_devoluciones(idCompra, idProductoDevuelto, comentarioDevolucion) VALUES(1, 1, "Fallas en el producto");
INSERT INTO pr1_devoluciones(idCompra, idProductoDevuelto, comentarioDevolucion) VALUES(2, 45, "No me gustó el producto");
INSERT INTO pr1_devoluciones(idCompra, idProductoDevuelto, comentarioDevolucion) VALUES(5, 13, "Este producto no cumplió con mis expectativas.");
INSERT INTO pr1_devoluciones(idCompra, idProductoDevuelto, comentarioDevolucion) VALUES(7, 12, "NO me gustó el producto");
