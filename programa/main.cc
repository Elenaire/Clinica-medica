#include "Paciente.h"

Paciente buscarPaciente(){
	//--------------
}
void menuPaciente(Paciente p){
	int menu;
	mostrarPaciente();
	/*
	bla bla menu
	*/
	while(n!=/*salir*/)
	switch(menu){
		case 1:

		break;
		case /*añadir tratamiento*/:		//Añadir tratamiento +Hecho  -Funciones
			Tratamiento t(p.getID());
			char c;
			string aux;
			fecha f,f1,f2;
			hoy(f);
			printf("Medicamento: ");		//Empieza a pedir datos
			cin>>aux;
			t.setMedicamento(aux);
			printf("Concemtración: ");
			cin>>aux;
			t.setConcentracion(aux);
			printf("Regularidad: ");
			cin>>aux;
			t.setRegularidad(aux);
			do{
				printf("Fecha de inicio: ");
				while(leerFecha(f1)!=true){
					printf("Formato de fecha incorrecto, introduzca dia/mes/año\n");
				}						
				printf("Fecha de finalización: ");
				while(leerFecha(f2)!=true){
					printf("Formato de fecha incorrecto, introduzca dia/mes/año\n");
				}
			}while((dias(f1,f2))&&(dias(f,f1)))		//hoy?-----------------------
			t.setFechaInicio(f1);
			t.setFechaFinal(f2);
			printf("introduzca un comentario(opcional): ");
			cin>>aux;
			t.setComentario(aux);			//Termina de pedir datos
			printf("¿Desea guardar el tratamiento? s/n\n");		//Pide confirmación (Si no confirma se sale)---------
			cin>>c;
			if(c=='s'){
				if(addTratamiento(t)){
					printf("Tratamiento guardado correctamente\n");
				}
				else{
					printf("Ha ocurrido un error inesperado\n");
				}
			}
		break;
		//........
		case /*salir*/:

		break;
		default:
		//Error....
	}
	//......
}

int main(){
	int menu;
	/*
	Inicio
	*/
	while(n!=/*salir*/){
		switch(menu){
			case 1:		//Buscar paciente +Hecho  -Funciones
				Paciente p=buscarPaciente();
				menuPaciente(p);
			break;
			case 2:		//Añadir paciente

			break;
			case 3:		//Añadir cita

			break;
			case 4:		//Consultar agenda

			break;
			//........
			case /*salir*/:

			break;
			default:
			//Error....
		}
	}
	//......
}