## Buscar usuario por nombre y apellidos

**ID**: 04
**Descripción**: Se eliminan los datos de un paciente

**Actores principales**: Administrador

**Precondiciones**:
* Existencia de pacientes en lista
* Búsqueda del paciente a eliminar

**Flujo principal**:
1. El administrador desea eliminar un paciente
2. El administrador abre el cuadro de diálogo de búsqueda en el menú principal
3. El administrador introduce el nombre y apellidos del paciente
4. El sistema muestra por pantalla los datos del paciente
5. El administrador selecciona la opción de eliminar paciente

**Postcondiciones**:

* Se imprime un mensaje pidiendo la confirmación de la orden

**Flujos alternativos**:

4.a Si no existe el usuario, se muestra un mensaje de error
