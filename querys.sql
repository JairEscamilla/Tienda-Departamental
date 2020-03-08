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

/* 6 */
SELECT 
    idAsesor, CONCAT(nombre, apPaterno, apMaterno)
FROM pr1_asesores
LEFT JOIN quejas USING(idAsesor) 
WHERE status = True;

/* 7 */
SELECT
    idAsesor, CONCAT(nombre, apPaterno, apMaterno)
FROM pr1_asesores
    LEFT JOIN quejas USING(idAsesor) 
WHERE status = False;

/* 8  PENDIENTE POR TABLA DE COMENTARIOS*/

/* 9 PENDIENTE POR STATUS DE LAS COMPRAS */

/* 10 */
SELECT 
    username Username, nombre Nombre, apPaterno ApellidoPaterno, direccionEnvioFactura
FROM pr1_clientes;

/* PROCEDIMIENTO */
