## Añadir cita

**ID**: 06         
**Descripción**: Se añade una cita a la agenda.

**Actores principales**: Secretario

**Precondiciones**:
* Haber seleccionado un paciente

**Flujo principal**:
1. El secretario desea añadir una cita para un paciente
2. El secretario selecciona la opción de añadir cita
3. El secretario introduce la fecha de la cita, el paciente y tiene la opcion de añadir un comentario a la cita
4. Se pide confirmación para guardar la cita

**Postcondiciones**:

* Se muestra un mensaje informando de que se ha añadido correctamente

**Flujos alternativos**:

3.a. Si el secretario habia selecionado previamente a un paciente no se pedira que introduzca al paciente

3.b Si algun dato no es valido se pedirá al secretario que lo vuelva a introducir

4.a Si el secretario no confirma la cita se cancela la acción

