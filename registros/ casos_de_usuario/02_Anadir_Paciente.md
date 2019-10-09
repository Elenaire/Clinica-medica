## Añadir paciente

**ID**: 02
**Descripción**: Se agrega un paciente a la lista de pacientes de la clínica, introduciendo sus datos

**Actores principales**: Secretario

**Precondiciones**:
* Ninguna

**Flujo principal**:
1. El secretario desea agregar un nuevo paciente
2. El secretario selecciona la opcin de agregar paciente
3. El secretario introduce los datos del nuevo paciente
4. El sistema introduce los datos del paciente en la lista

**Postcondiciones**:

* Se muestran por pantalla el nombre del paciente recien agregado

**Flujos alternativos**:

2.a Si el usuario agregado ya existe, se preguntará al administrador si quiere modificar este o no

2.b Si algun dato no es valido se pedirá al secretario que lo vuelva a introducir
