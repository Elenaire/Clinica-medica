## Modificar tratamiento

**ID**: 10
**Descripción**: Permite modificar uno o varios datos de un tratamiento y borrarlo

**Actores principales**: Secretario

**Precondiciones**:
* Haber seleccionado un tratamiento
* El tratamiento debe ser reciente

**Flujo principal**:
1. El secretario desea modificar o eliminar un tratamiento
2. El secretario selecciona modificar tratamiento
3. El sistema pregunta que desea modificar
4. El secretario modifica los datos
5. El sistema pide confirmación de cambios
6. El sistema guarda los cambios


**Postcondiciones**:

* Se muestra un mensaje informando de la correcta modificación del tratamiento

**Flujos alternativos**:

3.a Si el secretario elige eliminar el tratamiento se pasará directamente al paso 5

4.a Si algun dato no es valido se pedirá al secretario que lo vuelva a introducir

5.a Si el secretario no confirma los cambios el tratamiento no se verá modificado

