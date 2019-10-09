## Eliminar citas

**ID**: 08
**Descripción**: Elimina todos los datos de una cita incluida la misma en el registro

**Actores principales**: Secretario

**Precondiciones**:
* Existencia de citas

**Flujo principal**:
1. El secretario desea eliminar una cita
2. El secretario seleccionaría la opción de eliminar cita
3. El secretario introduce la fecha en la que desea eliminar la cita
4. El secretario selecciona la cita de dicha fecha que desea eliminar
5. El sistema pregunta por confirmación para eliminar la cita
6. El secretario confirma la eliminación de la cita
7. El sistema elimina la cita

**Postcondiciones**:

* El sistema emite un mensaje informado de la modificación de los datos

**Flujos alternativos**:

4.a. Si el secretario introduce una fecha no válida, le saldrá un mensaje de error y se le volverá a pedir la fecha.
6.a. Si el secretario deniega la eliminación de la cita volverá a la pantalla de selección de citas para poder seleccionar otra

