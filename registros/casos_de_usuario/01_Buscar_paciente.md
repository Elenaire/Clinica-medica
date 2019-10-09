## Buscar paciente

**ID**: 01
**Descripción**: Se busca un paciente de la forma que elija el usuario y se muestra, dependiendo del metodo que se elija se muestra una lista con los pacientes.

**Actores principales**: Secretario 

**Precondiciones**:
* Tener un registro con pacientes.

**Flujo principal**:
1. El secretario desea consultar los datos de un paciente
2. El secretario selecciona la opción buscar paciente
3. El secretario selecciona el metodo de busqueda del paciente
4. El secretario instroduce los parametros de busqueda segun el metodo elegido de busqueda
5. Se muestran los datos de ese paciente

**Postcondiciones**:

* Se abre el menu de opciones de ese paciente

**Flujos alternativos**:

4.a Si no existen pacientes con los parametros introducidos se mostrara un mensaje de error

4.b Si existe mas de un usuario con los parametros introducidos se mostrara una lista con los pacientes que los cumplan ordenados por una opción por defecto y dando la opción de volver a introducir parametros de busqueda y ordenación
