## Eliminar notas

**ID**: 13         
**Descripción**: Se elimina una nota de un paciente
**Actores principales**: Secretario

**Precondiciones**:
* Existencia de notas asociada a un paciente
* Haber seleccionado un paciente
**Flujo principal**:
1. El secretario desea eliminar una nota sobre un paciente
2. El secretario selecciona la nota que desea eliminar
3. Se le pide confirmación al secretario si está seguro de eliminar la nota
4. El sistema elimina la nota 

**Postcondiciones**:

* Se muestra un mensaje de eliminado con éxito

**Flujos alternativos**:

3.a Si el secretario no confirma para eliminar la nota, volverá a la selección para eliminar alguna otra nota
