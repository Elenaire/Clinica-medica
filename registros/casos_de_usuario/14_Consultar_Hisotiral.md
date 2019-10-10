## Consultar historial

**ID**: 15     
**Descripción**: Se accede al historial de notas de un paciente
**Actores principales**: Secretario

**Precondiciones**:
* Haber seleccionado un paciente
* Existencia de historial de ese paciente

**Flujo principal**:
1. El secretario desea consultar el historial de un paciente
2. El secretario selecciona la opción consultar historial
3. Se pide al secretario que especifique que historial desea ver (notas, tratamientos, notas y tratamientos)
4. Se muestra el historial pedido por el secretario

**Postcondiciones**:

* Se abre el menu de opciones del historial

**Flujos alternativos**:

3.a Si el historial espacificado no existe se le informará al secretario de esto y finalizara la acción