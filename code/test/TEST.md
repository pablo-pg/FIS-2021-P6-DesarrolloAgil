# Elaboración de pruebas unitarias y de integración

## IMPORTANTE: llame a su fichero "test*", más información a continuación

En esta carpeta puede ubicar las pruebas que use para evaluar la fiabilidad<br>
del software que construye.<br><br>

Para ello, puede crear un archivo de código C++ para probar todas aquellas<br>
funcionalidades relacionadas. Intente seguir la convención de nombres<br>
expuesta en el título, ello facilita la labor de herramientas automáticas<br>
en el proyecto.<br><br>

Por ejemplo: para probar la clase ***MiClase***, puede crear el archivo<br>
***test_miclase.cc***. Puede ejecutarlo manualmente, o acudir al script<br>
***code/tools/run_tests.sh*** para que lo haga por usted, además del resto<br>
de pruebas en este directorio.<br><br>

Cualquier commit es abortado si el código no pasa las pruebas.<br>
Para evitarlo de forma puntual, use la opción --no-verify.<br>