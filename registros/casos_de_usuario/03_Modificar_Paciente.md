
## Modificar Paciente

**ID**: 03
**Descripción**: Permite modificar uno o varios datos de un paciente

**Actores principales**: Secretario

**Precondiciones**:
* Existencia de pacientes en lista
* Haber seleccionado un paciente

**Flujo principal**:
1. El secretario desea modificar los datos de un paciente
2. El secretario abre el cuadro de diálogo de búsqueda en el menú principal
3. El secretario introduce el nombre y apellidos del paciente
4. El sistema muestra por pantalla los datos del paciente
5. El sistema pregunta que datos del usuario desea modificar
6. El secretario modifica los datos del paciente

**Postcondiciones**:

* Se muestra un mensaje informando de la correcta modificación de los datos

**Flujos alternativos**:

3.a Si no existe el usuario, se muestra un mensaje de error

