## Añadir paciente

**ID**: 02
**Descripción**: Se agrega un paciente a la lista de pacientes de la clínica, introduciendo sus datos

**Actores principales**: Secretario

**Precondiciones**:
* Ninguna

**Flujo principal**:
1. El secretario desea agregar un nuevo paciente
2. El secretario selecciona la opción de agregar paciente
3. El secretario introduce los datos del nuevo paciente
4. El sistema pide el secretario que confime si los datos son correctos
5. El sistema guarda los datos del paciente

**Postcondiciones**:

* Se abre el menu de opciones para ese paciente

**Flujos alternativos**:

3.a Si algun dato no es valido se pedirá al secretario que lo vuelva a introducir

4.a Si el secretario no confirma los datos se cancela la acción

5.a Si el usuario agregado ya existe, se preguntará al administrador si quiere modificar este o no

