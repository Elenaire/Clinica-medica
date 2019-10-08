## Buscar paciente

**ID**: 01
**Descripción**: Se busca un paciente de la forma que elija el usuario y se muestra, dependiendo del metodo que se elija se muestra una lista con los pacientes.

**Actores principales**: Administrador

**Precondiciones**:
* Tener un registro con pacientes.

**Flujo principal**:
1. El administrador desea consultar los datos de un paciente
2. El administrador selecciona buscar en el menú principal
3. El administrador selecciona el metodo de busqueda del paciente
4. El administrador instroduce los parametros de busqueda segun el metodo elegido de busqueda
5. Se muestran los datos de ese paciente

**Postcondiciones**:

* Se habre el menu de opciones de pacientes

**Flujos alternativos**:

1.a Si no existen pacientes con los parametros introducidos se mostrara un mensaje de error

1.b Si existe mas de un usuario con los parametros introducidos se mostrara una lista con los pacientes que los cumplan ordenados por una opción por defecto y dando la opción de volver a introducir parametros de busqueda y ordenación
