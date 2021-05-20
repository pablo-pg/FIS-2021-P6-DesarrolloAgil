# Uso de las herramientas de programación que proporciona el proyecto

## IMPORTANTE: situarse siempre en este directorio al ejecutar cualquier herramienta

## Formato automático de código

Ejecute el script ***auto_format.sh***, para formatear todo el código fuente del proyecto,<br>
según lo establecido en la guía de estilos **Google C++ Style Guide**([Detalles](https://google.github.io/styleguide/cppguide.html)).<br><br>


## Generar documentación

Ejecute el script ***generate_docs.sh***, para documentar todo el código fuente del proyecto,<br>
en base a comentarios Doxygen presentes en él. Luego revise ***docs/api/API.md***.<br><br>


## Ejecutar pruebas

Ejecute el script ***run_tests.sh***, para correr todas las pruebas unitarias y de integración,<br>
recogidas en el directorio ***code/test/*** y así evaluar la fiabilidad del software.<br>
Realizar un commit también implica la ejecución de este script, con el fin de minimizar<br>
la introducción de errores en código de producción.<br><br>

## Automatizar eventos en el repositorio

El script ***install_hooks.sh*** activa correctamente el servicio de Git Hooks, para<br>
así gestionar distintos eventos en el repositorio, por ejemplo un commit.<br>
