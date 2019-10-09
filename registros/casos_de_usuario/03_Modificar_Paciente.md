## Modificar Paciente

**ID**: 03
**Descripción**: Permite modificar uno o varios datos de un paciente

**Actores principales**: Secretario

**Precondiciones**:
* Existencia de pacientes en lista
* Haber seleccionado un paciente

**Flujo principal**:
1. El secretario desea modificar los datos de un paciente
2. El secretario selecciona la opción de modificar paciente
3. El sistema pregunta que datos del usuario desea modificar
4. El sistema pide confirmación de cambios
5. El secretario modifica los datos del paciente

**Postcondiciones**:

* Se muestra un mensaje informando de la correcta modificación de los datos

**Flujos alternativos**:

3.a Si algun dato no es valido se pedirá al secretario que lo vuelva a introducir

