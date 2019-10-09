## Consultar tratamiento

**ID**: 09
**Descripción**: Accede a los datos del tratamiento de un paciente

**Actores principales**: Secretario

**Precondiciones**:
* Existencia de Tratamientos

**Flujo principal**:
1. El secretario desearía consultar un tratamiento
2. El secretario introduce los identificadores para acceder al tratamiento
3. El secretario accede a los datos del tratamiento

**Postcondiciones**:

* Se muestran por pantalla los datos del tratamiento

**Flujos alternativos**:

2.a Si el secretario introduce mal los datos, el sistema mandará un mensaje de error y le pedirá que los introduzca de nuevo
