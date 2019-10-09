## Añadir Tratamiento

**ID**: 10
**Descripción**: Añade un tratamiento a un paciente

**Actores principales**: Secretario

**Precondiciones**:
* Existencia del paciente

**Flujo principal**:
1. El secretario desea añadir un tratamiento a un paciente
2. El secretario introduce los datos necesarios para cumplimentar el tratamiento
3. El sistema muestra una ventana de confirmación
4. El secretario acepta la confirmación

**Postcondiciones**:

* Se guarda el tratamiento asociado al paciente

**Flujos alternativos**:

2.a Si el secretario introduce mal los datos de algún campo, el sistema mandará un mensaje de error y le pedirá que los introduzca de nuevo
3.a Si el secretario no confirma los datos se le mostrarán por pantalla y tendrá la opción de modificarlos

