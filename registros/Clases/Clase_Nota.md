**Clase:** *Nota*

Esta clase representa una nota que toma el secretario sobre uno de sus pacientes

**Datos**

+ **fecha** *fecha* Fecha de creación de la nota
+ **hora** *hora* Hora de creación de la nota
+ **paciente** *número* Número que identifica al paciente del que se toma la nota
+ **nota** *cadena de caracteres* Nota que el secretario toma de sus pacientes

**Métodos**

- **Nota** Constructor de la clase que inicializa fecha y hora con la del equipo de que esté usando
+ **mostraRegistro** Esta función muestra por pantalla la nota
+ **modificable** Esta función devulve verdadero o falso en función de si se puede o no modificar la nota
+ **borrarCita** Esta función elimina la nota del registro de notas del paciente