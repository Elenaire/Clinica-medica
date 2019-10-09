## Permite consultar las próximas citas de la clínica

**ID**: 05
**Descripción**: Permite visualizar las próximas citas en rangos de 7,15 o 30 días o la totalidad de las citas

**Actores principales**: Secretario

**Precondiciones**:
* Existencia de citas

**Flujo principal**:
1. El secretario desea consultar las próximas citas
2. El secretario elige la opción "Consultar citas"
3. El secretario elige el rango en el cual quiere ver las próximas citas, o todas
4. El sistema muestra por pantalla las citas en el rango seleccionado

**Postcondiciones**:

* Ninguna

**Flujos alternativos**:

5.a. Si no existen citas en el rango seleccionado, se muestra un mensaje de error
