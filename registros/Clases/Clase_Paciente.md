**Clase:** *Paciente*

Esta clase representa a un paciente de la clinica y tiene funciones para consultar y modificar sus datos y registros

**Datos**

+ **id** *múmero* Identificador del paciente
+ **nombre** *cadena de caracteres* Nombre del paciente
+ **apellidos** *cadena de caracteres* Apellidos del paciente
+ **direccion** *cadena de caracteres* Dirección del paciente
+ **fechanacimietno** *fecha* Fecha de nacimiento del paciente
+ **telefono** *número* Telefono del paciente
+ **codpostal** *número* Codigo postal del paciente
+ **tipo** *número* Numero que indica si el paciente es publico o privado y que si se quisiera podria representar el tipo de seguro privado

**Métodos**

- **Paciente** Constructor de la clase que inicializa los datos del paciente
+ **get"----"** Observadores de los datos de la clase paciente
+ **set"----"** Moficicadores de los datos de la clase paciente que se aseguran de que los datos son correctos
+ **getCitas** Es una función que devulve una lista con todas la citas que ha tenido o tendrá un paciente
+ **getTratamientos** Es una función que en función de unos parametros devulves todos los tratamientos que está llevando un paciente o todos los que ha tenido
+ **getNotas** Es una función que devuelve una lista con las notas que el secretario ha tomado de un paciente



+ **mostraRegistro** Esta función muestra por pantalla los datos de la cita
+ **modificable** Esta función devulve verdadero o falso en función de si se puede o no modificar la cita
+ **borrarCita** Esta función elimina la cita de la agenda

+ **mostrarPaciente** Esta función muestra por pantalla los datos del paciente
+ **mostrarHCitas** Esta función muestra por pantalla el historial de citas
+ **mostrarTratamientos** Esta función muestra por pantalla los tratamientos que está llevando un paciente o todos los que ha tenido
+ **mostrarHNotas** Esta función muestra por pantalla el historial de notas
+ **mostrarHistorial** Esta función muestra por pantalla el historial de un paciente
+ **addCita** Esta función añade una cita a la agenda para el paciente
+ **addTratamiento** Esta función añade un tratamiento al paciente
+ **addNota** Esta función añade una nota al paciente
+ **guardarPaciente** Esta función añade o modifica al paciente en el fichero de pacientes
+ **borrarPaciente** Esta función	elimina al paciente del fichero de pacientes y elimina todos sus datos
    
    
    
    
