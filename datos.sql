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
INSERT INTO pr1_categorias_productos(nombreCategoria, descripcionCategoria, idDepartamento) VALUES("JUegos didácticos", "Juegos para que el niño juegue y aprenda al mismo tiempo", 4);

INSERT INTO pr1_categorias_productos(nombreCategoria, descripcionCategoria, idDepartamento) VALUES("Entretenimiento", "Artículos de entretenimiento para el hogar", 5);
INSERT INTO pr1_categorias_productos(nombreCategoria, descripcionCategoria, idDepartamento) VALUES("Artículos para el hogar", "Maletas, portafolios, mochilas, etc", 5);

INSERT INTO pr1_categorias_productos(nombreCategoria, descripcionCategoria, idDepartamento) VALUES("Experiencias", "Articulos para quien suele viajar a menudo", 6);
INSERT INTO pr1_categorias_productos(nombreCategoria, descripcionCategoria, idDepartamento) VALUES("Ropa de viaje", "Ropa para viajar", 6);

/* Insertando los productos  */
INSERT INTO pr1_