## Modificar Notas

**ID**: 14        
**Descripción**: Se modifican notas asociadas a un paciente
**Actores principales**: Secretario

**Precondiciones**:
* Existencia de notas asociada a un paciente
* Haber seleccionado un paciente

**Flujo principal**:
1. El secretario desea modificar una nota sobre un paciente
2. El secretario selecciona la nota que desea modificar
3. El secretario modifica la nota y al terminar se le pide confirmación

**Postcondiciones**:

* El sistema modifica la nota/s del paciente

**Flujos alternativos**:

3.a Si el secretario no confirma la modificación volverá para poder seguir escribiendo o cancelar la modificación
