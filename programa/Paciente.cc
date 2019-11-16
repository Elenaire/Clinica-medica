#include "Paciente.h"

	private:
		int id_;				//Numero para poder seleccionar al paciente cuando se está buscando
		string nombre_;
		string apellidos_;
		string direccion_;
		struct fecha fechanacimiento_;
		int telefono_;
		int codpostal_;
		int tipo_;

list <Tratamiento> Paciente::getTratamientos(){
	/*Lee del fichero de tratamientos del paciente una lista de tratamientos*/
}


bool Paciente::addTratamiento(Tratamiento t){
	//Inserta el tratamiento al final del fichero de tratamientos del paciente, si por algun motivo no puede devulve false
}