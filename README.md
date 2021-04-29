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
* .gitignore: Fichero de configuración de git para que no realice seguimientos de objetos compilados o ejecutables de C++. <br>

Desarrollo: <br>
Una clase para una tabla de Hash que funcione con un tipo de dato que sea la clase producto, de modo que permita almacenar productos. La tabla de hash es cerrada y se usará la función de dispersión pseuroaleatoria y de exploración redispersión con de nuevo la pseudoaleatoria. La base de datos se guardará en un .csv y los usuarios en otro .csv, ya que requiere que los usuarios estén registrados para poder acceder y modificar la tabla. En el fichero de los usuarios estará el nombre de usuario y la contraseña correspondiente codificada con un hash que será el que servirá para comparar con la pass que introduzca el usuario. <br>


## Participantes
A continuación se listan los participantes del proyecto:
* Ana Virginia Giambona Díaz (alu0101322650): Programador
* Alejandro Rodríguez Rojas (alu0101317038): **Cliente**
* Andrés Pérez Castellano (alu0101313511): Programador
* Dana Choque Zárate (alu0101328348): Programador
* Daniele Vitale (alu0101329017): Programador
* Pablo Pérez González (alu0101318318): **Manager**


### Extra
Informe del proyecto: [Informe](https://docs.google.com/document/d/1Cqu9R5LCX9vuGhutZgn0dbhcXVtn3AkjL7aj4dS00II/edit?ts=6089a4d2). <br>
Historias de usuario: [Plantilla](https://sites.google.com/site/oficinaproyectosinformatica/home/archivo/Plantilla%20Historias%20Usuario%20-%20Oficina%20de%20Proyectos%20de%20Informatica.xls?attredirects=0&d=1). <br>
Gestión ficheros: [Gestión](https://www.geeksforgeeks.org/csv-file-management-using-c/).
