## Modificar paciente

**ID**: 03
**Descripción**: Permite modificar uno o varios datos de un paciente

**Actores principales**: Secretario

**Precondiciones**:
* Haber seleccionado un paciente

**Flujo principal**:
1. El secretario desea modificar los datos de un paciente
2. El secretario selecciona la opción de modificar paciente
3. El sistema pregunta que datos del paciente desea modificar
4. El secretario modifica los datos
5. El sistema pide confirmación de cambios
6. El sistema guarda los cambios

**Postcondiciones**:

* Se muestra un mensaje informando de la correcta modificación de los datos

**Flujos alternativos**:

4.a Si algun dato no es valido se pedirá al secretario que lo vuelva a introducir

5.a Si el secretario no confirma los cambios se volveran a pedir los datos
