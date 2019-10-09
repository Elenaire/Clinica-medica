## Añadir Tratamiento

**ID**: 9
**Descripción**: Añade un tratamiento a un paciente

**Actores principales**: Secretario

**Precondiciones**:
* Haber seleccionado un paciente

**Flujo principal**:
1. El secretario desea añadir un tratamiento a un paciente
2. El secretario selecciona la opción de añadir tratamiento
3. El secretario introduce los datos del tratamiento
4. El sistema pide al secretario que confime si el tratamiento es correcto
5. El sistema guarda el tratamiento del paciente

**Postcondiciones**:

* Se muestra un mensaje informando de que se ha añadido correctamente

**Flujos alternativos**:

3.a Si algun dato no es valido se pedirá al secretario que lo vuelva a introducir

4.a Si el secretario no confirma los cambios se volveran a pedir los datos
