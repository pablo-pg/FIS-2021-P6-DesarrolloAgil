# FIS-2021-P6-DesarrolloAgil

## Índice
- [Información general](#información-general).
- [Información general técnica](#información-general-técnica).
- [Participantes](#participantes).



## Información general
El objetivo es implementar una pequeña base de datos que permita al cliente almacenar todos los productos de su frutería, así como permitir añadir, modificar y eliminar los elementos de la misma. Para hacer esto deberá haberse iniciado sesión satisfactoriamente. <br>

## Información general técnica
Sistema de gestión de versiones y archivos: GitHub <br>
Ramas: main <br>
Lenguajes del proyecto: C++, Makefile, Markdown <br>
Lenguaje: Español <br>
Organización de archivos:
* README.md: Información general del proyecto, así como participantes y especificaciones técnicas.
* CAMBIOS.md: Registro de todos los cambios hechos en el sistema de archivos por los miembros del proyecto.
* .gitignore: Fichero de configuración de git para que no realice seguimientos de objetos compilados o ejecutables de C++.
Desarrollo:
- Una clase para una tabla de Hash que funcione con un tipo de dato que sea la clase producto, de modo que permita almacenar productos. La tabla de hash es cerrada y se usará la función de dispersión pseuroaleatoria y de exploración redispersión con de nuevo la pseudoaleatoria. La base de datos se guardará en un .cvs y los usuarios en otro .csv, ya que requiere que los usuarios estén registrados para poder acceder y modificar la tabla. En el fichero de los usuarios estará el nombre de usuario y la contraseña correspondiente codificada con un hash que será el que servirá para comparar con la pass que introduzca el usuario. <br>


## Participantes
A continuación se listan los participantes del proyecto:
* Ana Virginia Giambona Díaz (alu0101322650): Programador
* Alejandro Rodríguez Rojas (alu0101317038): **Cliente**
* Andrés Pérez Castellano (alu0101313511): Programador
* Dana Choque Zárate (alu0101328348): Programador
* Daniele Vitale (alu0101329017): Programador
* Pablo Pérez González (alu0101318318): **Manager**


### Extra
Gestión ficheros: [Gestión](https://www.geeksforgeeks.org/csv-file-management-using-c/).
