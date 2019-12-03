#include "Paciente.h"
#include "iostream"
#include "Tratamiento.h"

using namespace std;
Paciente buscarPaciente(){		//Sin completar Sin probar
	int menu,id,orden;
	list<Paciente> pacientes;
	list<Paciente>::iterator i;
	printf("0 Listar pacientes\nBuscar paciente por:\n1 Nombre completo\n2 Nombre\n3 Apellidos\n 4 Edad\n5 Fecha de nacimiento\n6 Dirección\n7 Código postal\n8 Pacientes públicos\n9 Pacientes privados\n-1 Salir\n");
	scanf("%d",&menu);
	if(menu>0){
		filtrarPacientes(menu,pacientes);
	}
	while(menu>=0){				//se sale con -1 o con negativo?
		mostrarPacientes(pacientes);
		printf("1 Seleccionar paciente\n2 Ordenar pacientes\n3 Filtra pacientes\n-1 Salir\n");
		scanf("%d",&menu);
		switch(menu){
			case 1:			//Seleccionar paciente
				printf("Introduzca el id del paciente\n");
				scanf("%d",&id);
				for(i=p.begin();i!=pacientes.end();++i){
					if((*i).getID()==id){
						return *i;
					}
				}
				printf("El paciente seleccionado no coincide con los que se muestran por pantalla\n");
				menu=0;
			break;
			case 2:			//Ordenar pacientes
				printf("Ordenar por:\n1 Nombre\n2 Apellidos\n3 Fecha de nacimiento");
				scanf("%d",&menu);
				if(menu>0){
					printf("¿Orden ascendente(1) o descendente(-1)? \n");  	//Ordena si es positivo ascendente, si es negativo descendente y si es 0 cancela
					scanf("%d",&orden);
					if(orden!=0){
						ordenarPacientes(menu,pacientes);
						if(orden<0){pacientes.reverse();}
					}
				}
			break;
			case 3:			//Filtrar pacientes
				printf("0 Reiniciar busqueda\n1 Nombre completo\n2 Nombre\n3 Apellidos\n 4 Edad\n5 Fecha de nacimiento\n6 Dirección\n7 Código postal\n8 Telefono\n9 Pacientes públicos\n10 Pacientes privados\n-1 Salir\n");
				do{
					scanf("%d",&menu);
				}while((menu>0)&&(filtrarPacientes(menu,pacientes)));
			break;
			default:
				if(menu>0){
					printf("Error, introduzca:\n");
					menu=0;
				}
		}
	}

}
void menuPaciente(Paciente p){
	int menu=0;
	while(menu>=0){
		mostrarPaciente();
		/*
		bla bla menu
		*/
		switch(menu){
			case 0:
				printf("1 Mostrar historial\n2 Recetar tratamiento\n3 Consultar tratamientos\n4 Añadir cita\n5 Modificar datos del paciente\n7 Eliminar paciente\n-1 Atras");
				cin>>menu;
			break;
			case 3:	//Consultar tratamientos			
				int i;
				list <Tratamiento> tratamientos;
		 		list <Tratamiento>::iterator t;
				tratamientos=p.getTratamientos();		//Modificar getTratamientos
				t=tratamientos.begin();
				while(t!=tratamientos.end()){
					if((*t).getEstado()!=0){
						tratamientos.erase(t);
					}
					else{t++;}
				}
				i=1;
				for(t=tratamientos.begin();t!=tratamientos.end();t++){			//Super mal
					printf("%d.\n",i);
					(*t).mostrarRegistro();
					i++;
				}
				printf("Selecione un tratamiento o introduzca 0:");
				cin>>i;
				if(i>0){
					if(i<=(tratamientos.size()+1)){
						modificarTratamiento(*t);			//Sin terminar		//Mal
					}
				}
			break;
			case 2:		//Añadir tratamiento +Hecho  -Funciones					ID="fichero.size"
				Tratamiento t(p.getID());
				char c;
				bool bucle=true;
				string aux;
				fecha f,f1,f2;
				hoy(f);
				printf("Medicamento: ");		//Empieza a pedir datos
				getline(cin,aux);
				t.setMedicamento(aux);
				printf("Concentración: ");
				getline(cin,aux);
				t.setConcentracion(aux);
				printf("Regularidad: ");
				getline(cin,aux);
				t.setRegularidad(aux);
				while(bucle){
					printf("Fecha de inicio: ");
					while(bucle){
						if(leerFecha(f1)!=true){
						printf("Formato de fecha incorrecto, introduzca dia/mes/año\n");
						}
						else if(dias(f,f1)<0||modificable_==false){			//Modificable_
							printf("Esa fecha ya ha pasado\n");
						}
						else{
							bucle=false;
						}
					}
					printf("Fecha de finalización: ");
					bucle=true;
					while(bucle){
						if(leerFecha(f2)!=true){
							printf("Formato de fecha incorrecto, introduzca dia/mes/año\n");
						}
						else if(dias(f1,f2)){
							printf("El tratamiento no puede finalizar antes de empezar\n");
						}
						else{
							bucle=false;
						}
					}
				}
				t.setFechaInicio(f1);
				t.setFechaFinal(f2);
				printf("Introduzca un comentario(opcional): ");
				cin>>aux;
				t.setComentario(aux);			//Termina de pedir datos
				printf("¿Desea guardar el tratamiento? s/n\n");		//Pide confirmación (Si no confirma se sale)---------
				cin>>c;
				if(c=='s'){
					if(p.addTratamiento(t)){
						printf("Tratamiento guardado correctamente\n");
					}
					else{
						printf("Ha ocurrido un error inesperado\n");
					}
				}
			break;
			default:
				if(menu>0){
					printf("Error, introduzca:\n");
					menu=0;
				}
			}
	}
	//......
}

int main(){
	int menu=0;	
	hoy(HOY);		
	//modificable_=false;
	/*
	Inicio
	*/
	printf("Hola, bla bla bla\n");
	while(menu>0){
		switch(menu){
			case 0:
			printf("1 Seleccionar paciente\n2 Añair paciente\n3 Añadir cita\n4 Consultar agenda\n");
				cin>>menu;
			break;
			case 1:		//Buscar paciente +Hecho  -Funciones
				Paciente p=buscarPaciente();
				menuPaciente(p);
				menu=0;
			break;
			case 2:		//Añadir paciente

			break;
			case 3:		//Añadir cita

			break;
			case 4:		//Consultar agenda

			break;
			default:
			if(menu>0){
				printf("Error, introduzca:\n");
				menu=0;
			}
			else{
				printf("Cerrando programa...\n");
			}
		}
	}
	//......
}