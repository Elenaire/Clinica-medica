## Añadir una cita a la agenda

**ID**: 06         
**Descripción**: Se introduce una cita y esta se añade al registro de citas.

**Actores principales**: Secretario

**Precondiciones**:
* Haber seleccionado un paciente

**Flujo principal**:
1. El secretario desea añadir una cita para un paciente
2. El secretario selecciona la opción de añadir cita
3. El secretario introduce la fecha de la cita, el paciente y tiene la opcion de añadir un comentario a la cita
4. Se muestran los datos y se pide confirmación para guardar la cita
5. Al terminar se muestra por pantalla un mensaje de acción llevada a cabo con éxito

**Postcondiciones**:

* Ninguna

**Flujos alternativos**:

3.a. Si el secretario habia selecionado previamente a un paciente no se pedira que introduzca al paciente

3.b Si algun dato no es valido se pedirá al secretario que lo vuelva a introducir

4.a Si el secretario no confirma los cambios se cancela la acción

