/* Insertando los beneficios que podrá tener el cliente */
INSERT INTO pr1_tipo_beneficio(descripcion) VALUES("Tiene un descuento de envío del 15%");
INSERT INTO pr1_tipo_beneficio(descripcion) VALUES("Tiene envío gratis");
INSERT INTO pr1_tipo_beneficio(descripcion) VALUES("Tiene envío dentro de un menor tiempo");
INSERT INTO pr1_tipo_beneficio(descripcion) VALUES("Tiene un descuento de envio de 50%");

/* Insertando departamentos de productos */
INSERT INTO pr1_departamentos(nombreDepartamento) VALUES("Deportes");
INSERT INTO pr1_departamentos(nombreDepartamento) VALUES("Electrónica");
INSERT INTO pr1_departamentos(nombreDepartamento) VALUES("Cómputo");
INSERT INTO pr1_departamentos(nombreDepartamento) VALUES("Juguetes");
INSERT INTO pr1_departamentos(nombreDepartamento) VALUES("Casa");
INSERT INTO pr1_departamentos(nombreDepartamento) VALUES("Viajes");

/* Insertando las categorias de los productos */

INSERT INTO pr1_categorias_productos(nombreCategoria, descripcionCategoria, idDepartamento) VALUES("Aparatos de ejercicio", "Aparatos para hacer deporte", 1);
INSERT INTO pr1_categorias_productos(nombreCategoria, descripcionCategoria, idDepartamento) VALUES("Ropa y accesorios", "Ropa y accesorios deportivos para dama y caballero", 1);

INSERT INTO pr1_categorias_productos(nombreCategoria, descripcionCategoria, idDepartamento) VALUES("Audio", "Aparatos digitales para reproducir audio", 2);
INSERT INTO pr1_categorias_productos(nombreCategoria, descripcionCategoria, idDepartamento) VALUES("TV y Video", "Electrónicos para reproducir video", 2);

INSERT INTO pr1_categorias_productos(nombreCategoria, descripcionCategoria, idDepartamento) VALUES("Computación", "Equipos de cómputo para cualquier tipo de uso", 3);

INSERT INTO pr1_categorias_productos(nombreCategoria, descripcionCategoria, idDepartamento) VALUES("Juegos de mesa", "Juegos de mesa para toda la familia", 4);
INSERT INTO pr1_categorias_productos(nombreCategoria, descripcionCategoria, idDepartamento) VALUES("Juegos didácticos", "Juegos para que el niño juegue y aprenda al mismo tiempo", 4);

INSERT INTO pr1_categorias_productos(nombreCategoria, descripcionCategoria, idDepartamento) VALUES("Entretenimiento", "Artículos de entretenimiento para el hogar", 5);
INSERT INTO pr1_categorias_productos(nombreCategoria, descripcionCategoria, idDepartamento) VALUES("Artículos para el hogar", "Maletas, portafolios, mochilas, etc", 5);

INSERT INTO pr1_categorias_productos(nombreCategoria, descripcionCategoria, idDepartamento) VALUES("Experiencias", "Articulos para quien suele viajar a menudo", 6);
INSERT INTO pr1_categorias_productos(nombreCategoria, descripcionCategoria, idDepartamento) VALUES("Ropa de viaje", "Ropa para viajar", 6);

/* Insertando los productos  */
INSERT INTO pr1_productos(nombreProducto, descripcion, precio, stock, costoEnvio) VALUES ("Caminadora", "Aparato para hacer ejercicio", 1500, 5, 200);
INSERT INTO pr1_productos(nombreProducto, descripcion, precio, stock, costoEnvio) VALUES ("Eliptica", "Aparato para hacer ejercicio", 1400, 5, 150);

INSERT INTO pr1_productos(nombreProducto, descripcion, precio, stock, costoEnvio) VALUES ("Chamarra deportiva", "Chamarra para hacer ejercicio", 700, 15, 100);
INSERT INTO pr1_productos(nombreProducto, descripcion, precio, stock, costoEnvio) VALUES ("Monitor deportivo", "Monitor de frecuencia cardiaca, pasos, etc", 600, 25, 50);

INSERT INTO pr1_productos(nombreProducto, descripcion, precio, stock, costoEnvio) VALUES ("Audifonos", "Audifonos para celular", 500, 15, 50);
INSERT INTO pr1_productos(nombreProducto, descripcion, precio, stock, costoEnvio) VALUES ("Bocina", "Speaker para subir el volumen de música", 600, 25, 50);

INSERT INTO pr1_productos(nombreProducto, descripcion, precio, stock, costoEnvio) VALUES ("Pantalla", "Pantalla de 40 pulgadas con conexión a Internet", 5000, 30, 150);
INSERT INTO pr1_productos(nombreProducto, descripcion, precio, stock, costoEnvio) VALUES ("Soporte", "Soporte para pantalla de 40 pulgadas", 900, 25, 100);

INSERT INTO pr1_productos(nombreProducto, descripcion, precio, stock, costoEnvio) VALUES ("Computadora", "PC de escritorio", 5000, 30, 150);
INSERT INTO pr1_productos(nombreProducto, descripcion, precio, stock, costoEnvio) VALUES ("Tablet", "Tablet Smsung con 4 GB de RAM", 2600, 25, 350);

INSERT INTO pr1_productos(nombreProducto, descripcion, precio, stock, costoEnvio) VALUES ("Turista Mundial", "Juego de mesa para toda la familia", 100, 30, 50);
INSERT INTO pr1_productos(nombreProducto, descripcion, precio, stock, costoEnvio) VALUES ("Serpientes y escaleras", "Juego de mesa de serpientes y escaleras", 20, 250, 10);

INSERT INTO pr1_productos(nombreProducto, descripcion, precio, stock, costoEnvio) VALUES ("ABC Juego Educatodo", "Lotería educativa", 410, 50, 150);
INSERT INTO pr1_productos(nombreProducto, descripcion, precio, stock, costoEnvio) VALUES ("Rompecabezas Educatodo El Elefante", "Juego para todas las edades", 120, 50, 50);

INSERT INTO pr1_productos(nombreProducto, descripcion, precio, stock, costoEnvio) VALUES ("Mis Huellas a Casa DVD", "Pelicula en formato DVD", 250, 150, 50);
INSERT INTO pr1_productos(nombreProducto, descripcion, precio, stock, costoEnvio) VALUES ("La Absoluta Colección del Bolero", "Música de bolero en CD", 120, 50, 50);

INSERT INTO pr1_productos(nombreProducto, descripcion, precio, stock, costoEnvio) VALUES ("Tapete exterior", "Tapete exterior para casa", 50, 15, 50);
INSERT INTO pr1_productos(nombreProducto, descripcion, precio, stock, costoEnvio) VALUES ("Tapete interior", "Tapete interior", 50, 15, 50);

INSERT INTO pr1_productos(nombreProducto, descripcion, precio, stock, costoEnvio) VALUES ("Tapete exterior", "Tapete exterior para casa", 50, 15, 50);
INSERT INTO pr1_productos(nombreProducto, descripcion, precio, stock, costoEnvio) VALUES ("Tapete interior", "Tapete interior", 50, 15, 50);