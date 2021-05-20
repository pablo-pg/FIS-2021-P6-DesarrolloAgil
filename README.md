# FIS-2021-P6-DesarrolloAgil

## Índice
- [Información general](#información-general).
- [Ejecución](#ejecución).
- [Información general técnica](#información-general-técnica).
- [Participantes](#participantes).



## Información general
El objetivo es implementar una pequeña base de datos que permita al cliente almacenar todos los productos de su frutería, así como permitir añadir, modificar y eliminar los elementos de la misma. Por otro lado tambíen existen diversos perfiles de usuario con múltiples campos. Para hacer esto deberá haberse iniciado sesión satisfactoriamente. Debe poderse tanto comprar como vender.<br>

## Ejecución
Para ejecutar el programa debe estar en la carpeta `code/` y hay disponible un makefile con las opciones:
* `make`: Compila el programa.
* `make run`: Compila y ejecuta el programa.
* `make clear`: Borra los ejecutables.  

Si quiere ejecutar el código, tendrá que conocer las credenciales. Estas están listadas, junto a sus permisos y más datos del usuario, en `/code/data/.users.csv`. Ahí verá la lista de usuarios registrados que tienen acceso al sistema. Las contraseñas están cifradas, no las cambie o no podrá acceder. Por defecto las contraseñas son las mismas que el nombre de usuario, a excepción del usuario giovanni, que tiene su propia contraseña.

Si se accede al sistema, podrá elegir el rol si tiene más de un permiso. Ese rol le permitirá acceder a distintos menús, así como poder ejecutar más o menos funcionalidades. Si no se tiene el permiso de escritura, no se puede hacer nada. La lista total de opciónes es:
* Buscar un producto y ver sus detalles.
* Mostrar todos los productos del catálogo.
* Modificar los datos de un producto.
* Comprar un producto.
* Añadir un nuevo producto.
* Eliminar un producto existente (segundo prototipo).
* Registrar nuevos usuarios (segundo prototipo).
* Eliminar un usuario existente (segundo prototipo).
* Ver el perfil del usuario en sesión (segundo prototipo).

Cada opción le llevará a un submenú encargado de esa funcionalidad, a excepción de la que muestra todos los productos y el perfil del usuario, que simplemente los muestra. <br>

## Información general técnica
Sistema de gestión de versiones y archivos: GitHub <br>
Ramas: main <br>
Lenguajes del proyecto: C++, Makefile, Markdown <br>
Lenguaje: Español <br>
Organización de archivos:
* README.md: Información general del proyecto, así como participantes y especificaciones técnicas.
* CAMBIOS.md: Registro de todos los cambios hechos en el sistema de archivos por los miembros del proyecto.
* REUNIONES.md: Registro de los temas tratados en las reuniones, así como las decisiones tomadas.
* TOOLS.md: Pequeña guía para ejecutar los scripts.
* test/: Todos los tests del programa.
* docs/: Guarda todo lo referente a la documentación, tanto interna como de Doxygen.
* code/: Desarrollo del código, con sus cabeceras, implementaciones, los datos y la carpeta tests/.
* tools/: Scripts y sus configuraciones para documentación, auto-formato, tests y GitHooks.
* .gitignore: Fichero de configuración de git para que no realice seguimientos de objetos compilados o ejecutables de C++. <br>

Desarrollo: <br>
Una clase para una tabla de Hash que funcione con un tipo de dato que sea la clase producto, de modo que permita almacenar productos. La tabla de hash es abierta (redimensionable según la necesidad) y se usará la función de dispersión pseuroaleatoria y de exploración redispersión con de nuevo la pseudoaleatoria. La base de datos se guardará en un .csv y los usuarios en otro .csv, ya que requiere que los usuarios estén registrados para poder acceder y modificar la tabla. En el fichero de los usuarios estará el nombre de usuario, la contraseña correspondiente codificada con un hash que será el que servirá para comparar con la pass que introduzca el usuario, permisos del usuario, la valoración que tiene, los productos que tiene en venta y los métodos de pago aceptados. En el de los productos, habrá un campo de recuento, una identificación del producto, el nombre, su costo, el stock, la fecha de caducidad y el lugar de origen. <br>


## Participantes
A continuación se listan los participantes del proyecto:
* Ana Virginia Giambona Díaz (alu0101322650): Programador
* Alejandro Rodríguez Rojas (alu0101317038): **Cliente**
* Andrés Pérez Castellano (alu0101313511): Programador
* Dana Choque Zárate (alu0101328348): Programador
* Daniele Vitale (alu0101329017): Programador
* Pablo Pérez González (alu0101318318): **Manager**


### Extra
Informe del proyecto: [Informe](https://drive.google.com/file/d/15LlaNJQqJQ2t6KRNXmTwj_VW6syiE3BN/view?usp=sharing). <br>
Historias de usuario: [Hoja de cálculo](https://drive.google.com/file/d/1vppcvpkeVs_fGl6_LTKjAks1Kk0ejM55/view?usp=sharing). <br>
Nuevas Historias de usuario: [Hoja de cálculo](https://drive.google.com/file/d/165o_pnrCIlYaqdocTs87GJlKgOfKL0sb/view?usp=sharing). <br>
Gestión ficheros: [Gestión](https://www.geeksforgeeks.org/csv-file-management-using-c/). <br>
Eliminación en tablas de hash: [Eliminación](http://quegrande.org/apuntes/EI/2/Alg/teoria/08-09/tema_6_-_tablas_de_dispersion.pdf).<br>
Git Hooks: [Git hooks](https://blog.devgenius.io/automate-unit-tests-before-each-commit-by-git-hook-f331f0499786). <br>
