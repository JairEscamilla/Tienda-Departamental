-- -----------------------------------------------------
-- Table `practica1`.`pr1_categorias_clientes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `practica1`.`pr1_categorias_clientes` (
  `idCategoriaC` INT NOT NULL AUTO_INCREMENT,
  `nombreCategoria` VARCHAR(45) NOT NULL,
  `descuentoEnvio` INT NULL,
  PRIMARY KEY (`idCategoriaC`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `practica1`.`pr1_clientes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `practica1`.`pr1_clientes` (
  `username` VARCHAR(30) NOT NULL,
  `password` VARCHAR(30) NOT NULL,
  `direccionEnvio` VARCHAR(70) NULL,
  `idCategoria` INT NULL,
  `nombre` VARCHAR(50) NOT NULL,
  `apPaterno` VARCHAR(50) NOT NULL,
  `apMaterno` VARCHAR(50) NOT NULL,
  `fechaNac` DATE NOT NULL,
  `direccionFacturacion` VARCHAR(70) NOT NULL,
  `RFC` VARCHAR(15) NOT NULL,
  `codigoPostal` VARCHAR(5) NOT NULL,
  PRIMARY KEY (`username`),
  CONSTRAINT `idCategoria`
    FOREIGN KEY (`idCategoria`)
    REFERENCES `practica1`.`pr1_categorias_clientes` (`idCategoriaC`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `practica1`.`pr1_tipo_pago`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `practica1`.`pr1_tipo_pago` (
  `idTipoPago` INT NOT NULL AUTO_INCREMENT,
  `TipoDePago` VARCHAR(50) NOT NULL,
  PRIMARY KEY (`idTipoPago`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `practica1`.`pr1_productos`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `practica1`.`pr1_productos` (
  `idProducto` INT NOT NULL AUTO_INCREMENT,
  `nombreProducto` VARCHAR(50) NOT NULL,
  `descripcion` VARCHAR(250) NOT NULL,
  `precio` INT NOT NULL,
  `stock` INT NULL,
  `costoEnvio` INT NULL,
  PRIMARY KEY (`idProducto`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `practica1`.`pr1_departamentos`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `practica1`.`pr1_departamentos` (
  `idDepartamento` INT NOT NULL AUTO_INCREMENT,
  `nombreDepartamento` VARCHAR(50) NOT NULL,
  PRIMARY KEY (`idDepartamento`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `practica1`.`pr1_categorias_productos`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `practica1`.`pr1_categorias_productos` (
  `idCategoriap` INT NOT NULL AUTO_INCREMENT,
  `nombreCategoria` VARCHAR(50) NULL,
  `descripcionCategoria` VARCHAR(250) NOT NULL,
  `idDepartamento` INT NOT NULL,
  PRIMARY KEY (`idCategoriap`),
  CONSTRAINT `idDepartamento`
    FOREIGN KEY (`idDepartamento`)
    REFERENCES `practica1`.`pr1_departamentos` (`idDepartamento`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `practica1`.`pr1_tipo_beneficio`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `practica1`.`pr1_tipo_beneficio` (
  `idBeneficio` INT NOT NULL AUTO_INCREMENT,
  `descripcion` VARCHAR(50) NULL,
  PRIMARY KEY (`idBeneficio`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `practica1`.`pr1_categoriasClientes_beneficios`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `practica1`.`pr1_categoriasClientes_beneficios` (
  `pr1_categorias_clientes_idCategoria` INT NOT NULL,
  `pr1_tipo_beneficio_idBeneficio` INT NOT NULL,
  PRIMARY KEY (`pr1_categorias_clientes_idCategoria`, `pr1_tipo_beneficio_idBeneficio`),
  CONSTRAINT `fk_pr1_categorias_clientes_has_pr1_tipo_beneficio_pr1_categor1`
    FOREIGN KEY (`pr1_categorias_clientes_idCategoria`)
    REFERENCES `practica1`.`pr1_categorias_clientes` (`idCategoriaC`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_pr1_categorias_clientes_has_pr1_tipo_beneficio_pr1_tipo_be1`
    FOREIGN KEY (`pr1_tipo_beneficio_idBeneficio`)
    REFERENCES `practica1`.`pr1_tipo_beneficio` (`idBeneficio`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `practica1`.`pr1_tarjetas`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `practica1`.`pr1_tarjetas` (
  `idTarjeta` INT NOT NULL AUTO_INCREMENT,
  `numeroTarjeta` VARCHAR(16) NOT NULL,
  `fechaVencimiento` DATE NOT NULL,
  `username` VARCHAR(30) NOT NULL,
  PRIMARY KEY (`idTarjeta`),
  CONSTRAINT `username`
    FOREIGN KEY (`username`)
    REFERENCES `practica1`.`pr1_clientes` (`username`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `practica1`.`pr1_categorias_a_Productos`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `practica1`.`pr1_categorias_a_Productos` (
  `pr1_productos_idProducto` INT NOT NULL,
  `pr1_categorias_productos_idCategoriap` INT NOT NULL,
  PRIMARY KEY (`pr1_productos_idProducto`, `pr1_categorias_productos_idCategoriap`),
  CONSTRAINT `fk_pr1_productos_has_pr1_categorias_productos_pr1_productos1`
    FOREIGN KEY (`pr1_productos_idProducto`)
    REFERENCES `practica1`.`pr1_productos` (`idProducto`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_pr1_productos_has_pr1_categorias_productos_pr1_categorias_1`
    FOREIGN KEY (`pr1_categorias_productos_idCategoriap`)
    REFERENCES `practica1`.`pr1_categorias_productos` (`idCategoriap`)
    ON DELETE RESTRICT
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `practica1`.`pr1_compras`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `practica1`.`pr1_compras` (
  `idCompra` INT NOT NULL AUTO_INCREMENT,
  `timestamp` DATETIME NOT NULL,
  `totalPagar` INT NULL,
  `idTipoPago` INT NOT NULL,
  `user` VARCHAR(30),
  `status` BOOLEAN NOT NULL, 
  PRIMARY KEY (`idCompra`),
  CONSTRAINT `idTipoPago`
    FOREIGN KEY (`idTipoPago`)
    REFERENCES `practica1`.`pr1_tipo_pago` (`idTipoPago`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `user`
    FOREIGN KEY (`user`)
    REFERENCES `practica1`.`pr1_clientes` (`username`)
    ON DELETE SET NULL
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `practica1`.`pr1_compras_productos`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `practica1`.`pr1_compras_productos` (
  `pr1_compras_idCompra` INT NOT NULL,
  `pr1_productos_idProducto` INT NOT NULL,
  CONSTRAINT `fk_pr1_compras_has_pr1_productos_pr1_compras1`
    FOREIGN KEY (`pr1_compras_idCompra`)
    REFERENCES `practica1`.`pr1_compras` (`idCompra`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_pr1_compras_has_pr1_productos_pr1_productos1`
    FOREIGN KEY (`pr1_productos_idProducto`)
    REFERENCES `practica1`.`pr1_productos` (`idProducto`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `practica1`.`pr1_asesores`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `practica1`.`pr1_asesores` (
  `idAsesor` INT NOT NULL AUTO_INCREMENT,
  `nombre` VARCHAR(50) NOT NULL,
  `apMaterno` VARCHAR(50) NOT NULL,
  `apPaterno` VARCHAR(50) NOT NULL,
  PRIMARY KEY (`idAsesor`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `practica1`.`pr1_quejas`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `practica1`.`pr1_quejas` (
  `pr1_clientes_username` VARCHAR(30) NOT NULL,
  `pr1_asesores_idAsesor` INT NOT NULL,
  `idQueja` INT NOT NULL AUTO_INCREMENT,
  `comentario` VARCHAR(100) NOT NULL,
  `status` INT NULL,
  PRIMARY KEY (`idQueja`),
  CONSTRAINT `fk_pr1_clientes_has_pr1_asesores_pr1_clientes1`
    FOREIGN KEY (`pr1_clientes_username`)
    REFERENCES `practica1`.`pr1_clientes` (`username`)
    ON DELETE NO ACTION
    ON UPDATE CASCADE,
  CONSTRAINT `fk_pr1_clientes_has_pr1_asesores_pr1_asesores1`
    FOREIGN KEY (`pr1_asesores_idAsesor`)
    REFERENCES `practica1`.`pr1_asesores` (`idAsesor`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `practica1`.`pr1_devoluciones`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `practica1`.`pr1_devoluciones` (
  `idDevolucion` INT NOT NULL AUTO_INCREMENT,
  `idCompra` INT NOT NULL,
  `idProductoDevuelto` INT NOT NULL,
  `comentarioDevolucion` VARCHAR(100) NULL,
  `cantidadProductosDevueltos` INT NOT NULL,
  PRIMARY KEY (`idDevolucion`),
  CONSTRAINT `idCompra`
    FOREIGN KEY (`idCompra`)
    REFERENCES `practica1`.`pr1_compras` (`idCompra`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `practica1`.`pr1_cancelacion`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `practica1`.`pr1_cancelacion` (
  `idCancelacion` INT NOT NULL AUTO_INCREMENT,
  `comentarioCancelacion` VARCHAR(100) NULL,
  `idCompra` INT NOT NULL,
  PRIMARY KEY (`idCancelacion`),
  INDEX `fk_pr1_cancelacion_pr1_compras1_idx` (`idCompra` ASC) VISIBLE,
  CONSTRAINT `fk_pr1_cancelacion_pr1_compras1`
    FOREIGN KEY (`idCompra`)
    REFERENCES `practica1`.`pr1_compras` (`idCompra`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `practica1`.`pr1_comentarios`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `practica1`.`pr1_comentarios` (
  `idComentario` INT NOT NULL AUTO_INCREMENT,
  `pr1_clientes_username` VARCHAR(30) NOT NULL,
  `pr1_productos_idProducto` INT NOT NULL,
  `comentario` VARCHAR(50) NOT NULL,
  PRIMARY KEY (`idComentario`),
  CONSTRAINT `fk_pr1_clientes_has_pr1_productos_pr1_clientes1`
    FOREIGN KEY (`pr1_clientes_username`)
    REFERENCES `practica1`.`pr1_clientes` (`username`),
  CONSTRAINT `fk_pr1_clientes_has_pr1_productos_pr1_productos1`
    FOREIGN KEY (`pr1_productos_idProducto`)
    REFERENCES `practica1`.`pr1_productos` (`idProducto`))
ENGINE = InnoDB;

