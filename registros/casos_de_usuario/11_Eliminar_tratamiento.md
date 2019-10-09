## Eliminar Tratamiento

**ID**: 09
**Descripción**: Accede a los datos del tratamiento de un paciente

**Actores principales**: Secretario

**Precondiciones**:
* Haber seleccionado un tratamiento
* El tratamiento debe ser reciente

**Flujo principal**:
1. El secretario desea eliminar un tratamiento
2. El secretario selecciona eliminar el tratamiento
3. El sistema pregunta si está seguro de la eliminación
4. El secretario confirma la eliminación

**Postcondiciones**:

* Se elimina el registro del tratamiento seleccionado

**Flujos alternativos**:

4.a Si el secretario no confirma no se eliminara

