## Añadir una cita a la agenda

**ID**: 06         
----------------------------------------------------------------------------------------------------------------------
**Descripción**: Se introduce una cita y esta se añade al registro de citas.

**Actores principales**: Secretario

**Precondiciones**:
* Ninguna

**Flujo principal**:
1. El secretario desea añadir una cita para un paciente
2. El secretario se desplaza a la opción añadir cita dentro de un paciente
3. El secretario introduce la fecha de la siguiente cita y la guarda
4. El sistema muestra por pantalla si el usuario introduce un dato erróneo
5. Al terminar se muestra por pantalla un mensaje de acción llevada a cabo con éxito

**Postcondiciones**:

* Se añade la cita al registro de cita.

**Flujos alternativos**:

4.a. Si introduce un dato erróneo se manda un mensaje de error y pide de nuevo el dato
