## Modificar historial

**ID**: 14      
**Descripción**: Se modificar o eliminar notas recientes del historial de un paciente
**Actores principales**: Secretario

**Precondiciones**:
* Haber seleccionado una nota
* La nota debe ser reciente

**Flujo principal**:
1. El secretario desea modifica o eliminar una nota del historial de un paciente
2. El secretario selecciona la opción de modificar historial
3. El secretario selecciona la nota que desea modificar
4. El secretario introduce los nuevos datos
5. El sistema pide el secretario que confime los cambios
6. El sistema actualiza el historial

**Postcondiciones**:

* Se muestra un mensaje informando de la correcta modificación del historial

**Flujos alternativos**:

4.a Si el secretario no introduce datos la nota se eliminará

5.a Si el usuario no introduce datos se advertirá de que se va a eliminar

5.b Si el secretario no confirma, el historial no se verá modificado