**Clase:** *Tratamiento*

Esta clase representa un tratamiento que el secretario receta a un paciente

**Datos**

+ **fecha** *fecha* Fecha en la que se guarda el tratamiento
+ **hora** *hora* Hora en la que se guarda el tratamiento
+ **paciente** *número* Número que identifica al paciente que recive el tratamiento
+ **medicamento** *cadena de caracteres* Medicamento que se receta
+ **concentración** *cadena de caracteres* Concentracion del medicamento
+ **regularidad** *cadena de caracteres* Regularidad con la que debe tomarse el medicamento
+ **fecha_inicio** *fecha* Fecha de inicio del tratamiento
+ **fecha_final** *fecha* Fecha de finalización del tratamiento
+ **estado** *número* Numero que indica el estado el tratamiento: 0 sin concluir, 1 finalizado con exito y -1 concluido (manuamente por el secretario)


**Métodos**

- **Nota** Constructor de la clase que inicializa fecha y hora con la del equipo de que esté usando
+ **mostraRegistro** Esta función muestra por pantalla los datos del tratamiento
+ **modificable** Esta función devulve verdadero o falso en función de si se puede o no modificar el tratamiento
+ **borrarTratamiento** Esta función elimina el tratamiento del registro de tratamientos del paciente