## Eliminar Tratamiento

**ID**: 09
**Descripción**: Accede a los datos del tratamiento de un paciente

**Actores principales**: Secretario

**Precondiciones**:
* Existencia de Tratamientos

**Flujo principal**:
1. El secretario desea eliminar un tratamiento
2. El secretario accede al paciente del que desea eliminar el tratamiento
3. El secretario selecciona eliminar el tratamiento
4. El sistema pregunta si está seguro de la eliminación
5. El secretario confirma la eliminación

**Postcondiciones**:

* Se elimina del registro el tratamiento seleccionado

**Flujos alternativos**:

2.a Si el secretario introduce mal los datos, el sistema mandará un mensaje de error y le pedirá que los introduzca de nuevo
4.a Si el secretario no confirma la eliminación no se realizará la eliminación

