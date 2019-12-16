#include "Paciente.h"
#include "funciones.h"
#include <iostream>

using namespace std;
Paciente::Paciente(int id)
{
  id_=id;
  telefono_=0;
  nombre_="";
  apellidos_="";
  direccion_="";
  fechanacimiento_.a=0;
  fechanacimiento_.m=0;
  fechanacimiento_.d=0;
  codpostal_=0;
  tipo_=-1;
}
int Paciente::getEdad(){
  int aux=HOY.a-fechanacimiento_.a;
  if(fechanacimiento_.m>HOY.m){
    aux--;
  }
  else if(fechanacimiento_.m==HOY.m){
    if(fechanacimiento_.d>HOY.d){
      aux--;
    }
  }
  return aux;
}

void Paciente::mostrarPaciente(){
  cout<<"ID: "<<id_<<endl;
  cout<<"NOMBRE: "<<nombre_<<endl;
  cout<<"APELLIDOS: "<<apellidos_<<endl;
  cout<<"DIRECCION: "<<direccion_<<endl;
  cout<<"FECHANACIMIENTO: "<<escribeFecha(fechanacimiento_)<<endl;
  cout<<"TELEFONO: "<<telefono_<<endl;
  cout<<"CODIGO POSTAL: "<<codpostal_<<endl;
  if(tipo_=0)
  {
    cout<<"TIPO: PUBLICO"<<endl;
  }else{
    cout<<"TIPO: PRIVADO"<<endl;
  }
}

list <Cita> Paciente::getCitas()
{
  list <Cita> aux;
  list <Cita>::iterator c;
  ifstream file;
  file.open("citas.txt");
  string cad;
  for(c=aux.begin();c!=aux.end();c++)
  {
  	getline(file,cad,'|');
    (c.fecha_).d=stoi(cad);
    getline(file,cad,'|');
    (c.fecha_).m=stoi(cad);
    getline(file,cad,'|');
    (c.fecha_).a=stoi(cad);
    getline(file,cad,':');
    (c.hora_).h=stoi(cad);
    getline(file,cad,':');
    (c.hora_).m=stoi(cad);
    getline(file,cad,'|');
    (c.hora_).s=stoi(cad);
    getline(file,cad,'|');
    c.paciente_=stoi(cad);
    getline(file,(c.comentario_),'\n');
    aux.push_back(c);
  }
  file.close();
  return aux;
}
list <Tratamiento> Paciente::getTratamientos()   //Mal
{
  list <Tratamiento> aux;
  list <Tratamiento>::iterator t;
  ifstream file;
  file.open("Tratamientos.txt")
  string cad
  for(t=aux.begin();t!=aux.end();t++)
  {
  	getline(file,cad,'/');
    (t.fecha_).d=stoi(cad);
    getline(file,cad,'/');
    (t.fecha_).m=stoi(cad);
    getline(file,cad,'|');
    (t.fecha_).a=stoi(cad);
    getline(file,cad,':');
    (t.hora_).h=stoi(cad);
    getline(file,cad,":");
    (t.hora_).m=stoi(cad);
    getline(file,cad,'|'');
    (t.hora_).s=stoi(cad);
    getline(file,cad,'|');
    t.paciente_=stoi(cad);
    getline(file,(t.medicamento_),'|');
    getline(file,(t.concentracion_),'|');
    getline(file,(t.regularidad_),'|');
    getline(file,cad,"/");
    (t.fecha_inicio_).d=stoi(cad);
    getline(file,cad,"/");
    (t.fecha_inicio_).m=stoi(cad);
    getline(file,cad,'|');
    (t.fecha_inicio_).a=stoi(cad);
    getline(file,cad,'|');
    (t.fecha_final_).d=stoi(cad);
    getline(file,cad,'/');
    (t.fecha_final_).m=stoi(cad);
    getline(file,cad,'|');
    (t.fecha_final_).a=stoi(cad);
    getline(file,cad,"\n");
    t.estado=stoi(cad);
    aux.push_back(t);
  }
  file.close();
  return aux;
}
list <Nota> Paciente::getNotas()
{
  list <Nota> aux;
  list <Nota>::iterator n;
  ifstream file;
  file.open("citas.txt")
  string cad
  for(n=aux.begin();n!=aux.end();n++)
  {
  	getline(file,cad,'/');
    (n.fecha_).d=stoi(cad);
    getline(file,cad,'/');
    (n.fecha_).m=stoi(cad);
    getline(file,cad,'|');
    (n.fecha_).a=stoi(cad);
    getline(file,cad,':');
    (n.hora_).h=stoi(cad);
    getline(file,cad,':');
    (n.hora_).m=stoi(cad);
    getline(file,cad,'|');
    (n.hora_).s=stoi(cad);
    getline(file,cad,'|');
    n.paciente_=stoi(cad);
    getline(file,(n.nota_),"\n");
    aux.push_back(n);
  }
  file.close();
  return aux;
}
void AddPaciente(Paciente p)//ESTO HAY QUE CAMBIARLO TO
{
  fstream archivo;
  archivo.open("Pacientes.txt",std::fstream::app);
  archivo<<p.id_<<'|';
  archivo<<p.nombre_<<'|';
  archivo<<p.apellidos_<<'|';
  archivo<<escribeFecha(p.fechanacimiento_)<<"|";
  archivo<<p.telefono_<<'|';
  archivo<<p.codpostal_<<'|';
  archivo<<p.tipo_<<endl;
  archivo.close();
}
void Paciente::mostrarHCitas()
{
  list <Cita> aux;
  list <Cita>::iterator c;
  ifstream file;
  file.open("citas.txt")
  string cad
  for(c=aux.begin();c!=aux.end();c++)
  {
  	getline(file,cad,'/');
    (c.fecha_).d=stoi(cad);
    getline(file,cad,'/');
    (c.fecha_).m=stoi(cad);
    getline(file,cad,'|');
    (c.fecha_).a=stoi(cad);
    getline(file,cad,':');
    (c.hora_).h=stoi(cad);
    getline(file,cad,':');
    (c.hora_).m=stoi(cad);
    getline(file,cad,'|');
    (c.hora_).s=stoi(cad);
    getline(file,cad,'|');
    c.paciente_=stoi(cad);
    getline(file,(c.comentario_),"\n"); //Javier, esto lo tienes que modificar, para que compare el numero del paciente con el ID  del paciente y solo copie los datos del paciente
    aux.push_back(c);
  }
  file.close();
  for(c=aux.begin();c!=aux.end();c++)
  {
  	if(id_=(c.paciente_))
  	{
  		cout<<(c.fecha_).d<<endl;
  		cout<<(c.fecha_).m<<endl;
  		cout<<(c.fecha_).a<<endl;
  	}
  }
}
void Paciente::mostrarHistorial()
{
  // pide k kiere hase
  // llama a funcion getListaX
  // se imprimen en mostaerRegistro
  //si todo . get citas, gt, tratamientos y get notas
}

bool Paciente::addTratamiento(const Tratamiento t){   //Sin probar
  fstream file;
  file.open(to_string(id_)+"/Tratamientos.txt",ios::out|ios::app|ios::ate);
  if(file){
    file<<escribeFecha(t.getFecha())<<"|"<<escribeHora(t.getHora())<<endl<<t.getMedicamento()<<endl<<t.getConcentracion()<<endl<<t.getRegularidad()<<endl<<escribeFecha(t.getFechaInicio())<<endl<<escribeFecha(t.getFechaFinal())<<endl<<t.getEstado()<<endl<<t.getComentario()<<endl;
    file.close();
    return true;
  }
  else{
    return false;
  }
}
bool Nombre_Apellidos(Paciente p1,Paciente p2){
  int i;
  string s1,s2;
    s1=p1.nombre_+p1.apellidos_;
    s2=p2.nombre_+p2.apellidos_;
  for(i=0;((i<s1.length())&&(i<s2.length()));i++){
    if (tolower(s1[i])<tolower(s2[i])) return true;
    else if (tolower(s1[i])>tolower(s2[i])) return false;
  }
  return ( s1.length() < s2.length() );
}
bool Apellidos_Nombre(Paciente p1,Paciente p2){
  int i;
  string s1,s2;
    s1=p1.apellidos_+p1.nombre_;
    s2=p2.apellidos_+p2.nombre_;
  for(i=0;((i<s1.length())&&(i<s2.length()));i++){
    if (tolower(s1[i])<tolower(s2[i])) return true;
    else if (tolower(s1[i])>tolower(s2[i])) return false;
  }
  return ( s1.length() < s2.length() );
}
