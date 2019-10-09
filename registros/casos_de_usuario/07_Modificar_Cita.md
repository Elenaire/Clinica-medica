## Modificar cita

**ID**: 07
**Descripción**: Modficalos datos de una cita

**Actores principales**: Secretario

**Precondiciones**:
* Existencia de citas

**Flujo principal**:
1. El secretario desea modificar los datos de una cita
2. El secretario selecciona la opción de modificar cita
3. El secretario selecciona la cita
4. El secretario introduce los nuevos datos
5. El sistema pide el secretario que confime si los datos son correctos
6. El sistema guarda los nuevos datos de la cita

**Postcondiciones**:

* El sistema emite un mensaje informado de la modificación de los datos

**Flujos alternativos**:

4.a Si el secretario introduce un dato no válido en un campo, se le volverá a pedir

4.a Si el secretario no confirma los cambios la cita no se verá modificada
