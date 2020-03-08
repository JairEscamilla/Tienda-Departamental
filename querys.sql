/* 1 */
    SELECT 
        username Username, CONCAT(nombre, " ", apPaterno, " ", apMaterno) Cliente
    FROM pr1_clientes cl
    LEFT JOIN pr1_compras com ON cl.username = com.user GROUP BY cl.username HAVING COUNT(com.user) = (
        SELECT 
            COUNT(idCompra) Cuenta 
        FROM pr1_compras
        GROUP BY user 
        ORDER BY Cuenta DESC LIMIT 1
    );

/* 2 PREGUNTAR POR FACTURACION */
DELIMITER $
    CREATE PROCEDURE facturacionMes(anio INT, mes INT, username VARCHAR(30), OUT FacturacionTotal DECIMAL(5, 2))
    BEGIN
        DECLARE total, aux DECIMAL(5, 2);
        DECLARE salida INT;
        DECLARE curFacturacion CURSOR FOR SELECT totalPagar FROM pr1_compras WHERE user = username AND MONTH(timestamp) = mes AND YEAR(timestamp) = anio;
        DECLARE CONTINUE HANDLER FOR NOT FOUND SET salida = 1;
        SET total = 0;
        SET salida = 0;
        OPEN curFacturacion;
        curFact: REPEAT
            FETCH curFacturacion INTO aux;
            IF salida = 1 THEN 
                LEAVE curFact;
            END IF;
            SET total = total + aux;
            UNTIL salida = 1
        END REPEAT curFact;
        CLOSE curFacturacion;
        SET FacturacionTotal = total;
    END $
DELIMITER ;

/* 3 */
SELECT 
    CONCAT(nombre, " ", apPaterno, " ", apMaterno) 'Clientes que no han comprado', username Username
FROM pr1_clientes cl
LEFT JOIN pr1_compras com ON cl.username = com.user GROUP BY cl.username HAVING COUNT(com.user) = 0; 

/* 4 */
SELECT  
    CONCAT(cl.nombre, " ",  cl.apPaterno, " ", apMaterno) 'Clientes que han comprado por más de $1000'
FROM pr1_clientes cl 
LEFT JOIN pr1_compras com ON cl.username = com.user
LEFT JOIN pr1_compras_productos comprod ON com.idCompra = comprod.pr1_compras_idCompra
LEFT JOIN pr1_productos prod ON comprod.pr1_productos_idProducto = prod.idProducto WHERE prod.precio > 1000 GROUP BY cl.username ORDER BY cl.apPaterno, cl.apMaterno;

/* 5 PENDIENTE HAY QUE PREGUNTAR POR ESTE QUERY*/
SELECT 
    com.idCompra, CONCAT(cl.nombre, " ", cl.apPaterno, " ",  cl.apMaterno) Cliente, COUNT(pcp.pr1_compras_idCompra) 'Numero de productos', prod.descripcion
FROM pr1_compras com
LEFT JOIN pr1_clientes cl ON com.user = cl.username
LEFT JOIN pr1_compras_productos pcp ON com.idCompra = pcp.pr1_compras_idCompra
LEFT JOIN pr1_productos prod ON pcp.pr1_productos_idProducto = prod.idProducto
GROUP BY prod.idProducto ORDER BY idCompra;

/* 6 PREGUNTAR POR ESTE TAMBIEN */
    SELECT 
        idAsesor, CONCAT(nombre, " ", apPaterno, " ", apMaterno) 'Asesor que ha resuelto dudas'
    FROM pr1_asesores ases
    LEFT JOIN pr1_quejas quej ON ases.idAsesor = quej.pr1_asesores_idAsesor  
    WHERE status = True;

/* 7 */
SELECT
    idAsesor, CONCAT(nombre, " ", apPaterno, " ", apMaterno) 'Asesor que tiene casos abiertos'
FROM pr1_asesores ases
LEFT JOIN pr1_quejas quej ON ases.idAsesor = quej.pr1_asesores_idAsesor   
WHERE status = False;

/* 8  PREGUNTAR POR ESTE*/
delimiter $
    CREATE PROCEDURE productosDeCategoria(categoria INT)
    BEGIN 
        SELECT nombreProducto Nombre, descripcion, comentario
        FROM pr1_productos prod
        LEFT JOIN pr1_categorias_a_Productos cp ON prod.idProducto = cp.pr1_productos_idProducto
        LEFT JOIN pr1_comentarios com ON com.pr1_productos_idProducto = prod.idProducto
        WHERE cp.pr1_categorias_productos_idCategoriap = categoria;
    END $
delimiter ;
/* 9 PREGUNTAR SI ESTE SE PUEDE HACER EN 3 QUERYS */
SELECT
    COUNT(DISTINCT can.idCancelacion) Cancelaciones, COUNT(DISTINCT dev.idDevolucion) Devoluciones, nombreProducto 'Producto más devuelto'
FROM pr1_cancelacion can, pr1_devoluciones dev, pr1_productos prod WHERE prod.idProducto = (
    SELECT 
        idProductoDevuelto
    FROM pr1_devoluciones GROUP BY idProductoDevuelto ORDER BY COUNT(idProductoDevuelto) DESC LIMIT 1
);



/* 10 Preguntar si este va bien */
SELECT 
    username Username, CONCAT(nombre, " ", apPaterno, " ", apMaterno) Cliente, direccionEnvio, codigoPostal, RFC, numeroTarjeta, fechaVencimiento
FROM pr1_clientes
LEFT JOIN pr1_tarjetas USING(username);

/* PROCEDIMIENTO */
delimiter $
    CREATE DEFINER=`root`@`localhost` PROCEDURE `hacerCompra`(cliente VARCHAR(30), Producto INT, cantidadProductos INT, OUT totalVenta DECIMAL(10, 2), OUT pagoEnvio DECIMAL(10, 2))
BEGIN 
        DECLARE numProducts, prec, cEnv, descuento, nuevoStock INT;
        DECLARE pagoTotal, dineroDescontado DECIMAL(10, 2);
        DECLARE curProductos CURSOR FOR SELECT stock, precio, costoEnvio FROM pr1_productos WHERE idProducto = Producto;
        DECLARE curDescuento CURSOR FOR SELECT descuentoEnvio FROM pr1_clientes cl LEFT JOIN pr1_categorias_clientes cc ON cl.idCategoria = cc.idCategoriaC WHERE cl.username = cliente;
        SET numProducts = 0;
        SET prec = 0;
        SET cEnv = 0;
        OPEN curProductos;
        FETCH curProductos INTO numProducts, prec, cEnv;
        IF cantidadProductos <= numProducts THEN 
            SET pagoTotal = prec * cantidadProductos;
            SET pagoEnvio = cEnv * cantidadProductos;
            OPEN curDescuento;
                FETCH curDescuento INTO descuento;
                SET dineroDescontado = (pagoEnvio * descuento) / 100;
                SET totalVenta = pagoTotal;
                SET pagoEnvio = pagoEnvio - dineroDescontado;
                SET nuevoStock = numProducts - cantidadProductos;
                UPDATE pr1_productos SET stock = nuevoStock WHERE idProducto = Producto;
            CLOSE curDescuento;
        END IF;
        CLOSE curProductos;
    END $
delimiter ;
 