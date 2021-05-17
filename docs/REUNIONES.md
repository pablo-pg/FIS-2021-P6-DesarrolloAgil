# Historial de reuniones 

## Reuniones con el cliente
**Fecha:** 22/04/2021 <br>
**Motivo:** Primera reunión con el cliente. <br>
**Descripción:** El cliente relató su proyecto y le ofrecimos el posible resultado. <br>
La idea es crear una base de datos basasda en una tabla de hash para una frutería, coon sus respectivos campos y que se deba iniciar sesión para modificar los datos. Solo el dueño podrá añadir nuevos productos, mientras que los demás registrados podrán modificar sus campos. <br>
Hemos propuesto dos ficheros, uno para usuarios y otro para los productos y le gustó la idea.<br> 
**Tiempos:** 2 semanas para: login, base de datos sin límites, aplicación cliente. <br>


**Fecha:** 12/05/2021 <br>
**Motivo:** Segunda reunión con el cliente. <br>
**Descripción:** Entrega del primer prototipo del software. Al cliente le ha satisfecho. Para el segundo prototipo nos pide implementar el registro de nuevos usuarios  y poder borrarlos, así como un perfil de los mismos. <br>
De cara a la base de datos, también nos pide poder borrar un producto y modificar las limitaciones de tamaño actuales. <br> 
**Tiempos:** 1 semana para implementar perfiles, registro de usuarios y eliminación de usuarios y productos. <br>


## Reuniones con el equipo de desarrollo
**Fecha:** 28/04/2021 <br>
**Motivo:** Primera reunión con el equipo de desarrollo. <br>
**Descripción:** Se trasladan las preocupaciones del cliente al equipo de desarrollo. <br>
Se comienza con la elaboración del informe asociado al proyecto:
* Formato y estructura del escrito.
* Historias de usuario.
* Requisitos funcionales para el software de la primera entrega. <br>

**Tiempos:** Se abordarán los temas restantes del informe en la siguiente reunión. <br> <br>


**Fecha:** 29/04/2021 <br>
**Motivo:** Segunda reunión con el equipo de desarrollo. <br>
**Descripción:** Se tratan los problemas que había con el formato del informe así como se proponen mejoras en el contenido. Se avanza conjuntamente con el informe y se decide utilizar dos scripts para la documentación y cumplimiento de la guía de estilo del código fuente.  
**Tiempos:** Se desarrollará profundamente el código en las próximas reuniones. <br> <br>


**Fecha:** 04/05/2021 <br>
**Motivo:** Tercera reunión con el equipo de desarrollo. <br>
**Descripción:** Se decide reescribir la mayoría de párrafos del informe por motivos estéticos. Se plantea si un usuario puede comprar y vender (lo elige el usuario al entrar al programa) o está definido según el usuario(desde el csv). Para acercarnos al modelo de negocio C2C se decide la primera opción. Se avanza profundamente con el código de backend (base de datos y productos). Se discute la conveniencia de usar structs en vez de clases y se decide usar structs por la mayoría de atributos públicos y la facilidad a la hora de instanciar un objeto. <br>
**Tiempos:** Se prevé la finalización del login y la interfaz que tendrá el usuario en 1 semana. Mañana habrá otra reunión para seguir con el desarrollo de código. <br> <br>


**Fecha:** 05/05/2021 <br>
**Motivo:** Cuarta reunión con el equipo de desarrollo. <br>
**Descripción:** Se decide que habrá un máximo de productos posibles a almacenar. Si la tabla de datos se llena, no se añadirán más poductos. Se avanza en las clase hash y base de datos. Se decide implementar una clase propia vector con fin de facilitar la tabla de hash.<br>
**Tiempos:** Se prevé la finalización del login y la interfaz que tendrá el usuario en 1 día. Mañana habrá otra reunión para seguir con el desarrollo de código. <br> <br>


**Fecha:** 06/05/2021 <br>
**Motivo:** Quinta reunión con el equipo de desarrollo. <br>
**Descripción:** Sesión exclusiva de desarrollo. Se decide no implementar la clase vector. Se termina el backend y se genera el primer ejecutable listo para llevar a producción. Falta por relacionar frontend con backend.<br>
**Tiempos:** Se prevé la finalización del primer pedido en fecha. Habrá una nueva reunión con el cliente la próxima semana.<br> <br>

**Fecha:** 15/05/2021 <br>
**Motivo:** Primera reunión con el equipo de desarrollo tras la primera entrega. <br>
**Descripción:** Reorganización de tareas, así como planteamientos de los desarrollos de los nuevos requerimientos del usuario (eliminar usuarios y perfiles). Distribución de tareas: <br>
* Equipo 1: Front-end de la eliminación de productos, registro y eliminación de usuarios. <br>
* Equipo 2: Eliminación de productos desde la base de datos. <br>
* Equipo 3: Reorganización de la tabla de hash tras eliminación, redimensionar tabla de hash.<br>

**Tiempos:** 1 semana y media para las tareas de los 3 equipos. <br><br>

**Fecha:** 17/05/2021 <br>
**Motivo:** Reunión del grupo de trabajo 3. <br>
**Descripción:** Implementar mecanismo para redimensionar de la tabla y del back-end de la eliminación de productos. <br>
**Tiempos:** 4 horas. <br><br>
