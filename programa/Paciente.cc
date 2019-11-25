#include "Pacientes.h"

Paciente::Paciente(int telefono)
{
  id_=0;
  telefono_=telefono;
  nombre_="";
  apellidos_="";
  direccion_="";
  fechanacimiento_->a=0;
  fechanacimiento_->m=0;
  fechanacimiento_->d=0;
  codpostal_=0;
  tipo_=-1;
}

void Paciente::mostrarPaciente()
{
  cout<<"ID: "<<id_<<endl;
  cout<<"NOMBRE: "<<nombre_<<endl;
  cout<<"APELLIDOS: "<<apellidos_<<endl;
  cout<<"DIRECCION: "<<direccion_<<endl;
  char* fecha=escribeFecha(fechanacimiento_);
  cout<<"FECHANACIMIENTO: "<<fecha<<endl;
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
  ifstream file("citas.txt")




}

void Paciente::AddPaciente(Paciente p)
{
  list<Paciente> aux;
  list<Paciente>::iterator i;
  ifstream file;
  file.open("Pacientes.txt");
  string cad;
  for (i=aux.begin();i!=aux.end();i++)
  {
    getline(file,cad,"||");
    i->id_=stoi(cad);
    getline(file,cad,"||");
    i->nombre_=cad;
    getline(file,cad,"||");
    i->apellidos_=cad;
    getline(file,cad,"||");
    i->direccion_=cad;
    getline(file,cad,"/");
    (i->fechanacimiento_)->d=stoi(cad);
    getline(file,cad,"/");
    (i->fechanacimiento_)->m=stoi(cad);
    getline(file,cad,"||");
    (i->fechanacimiento_)->a=stoi(cad);
    getline(file,cad,"||");
    i->telefono_=stoi(cad);
    getline(file,cad,"||");
    i->codpostal_=stoi(cad);
    getline(file,cad,"\n");
    i->tipo_=stoi(cad);
    aux.push_back(i);
  }
  file.close();
  i++;
  aux.resize(i,p);
  ofstream archivo;
  archivo.open("Pacientes.txt");
  for (i=aux.begin();i!=aux.end();i++)
  {
    archivo<<i->id_<<"||";
    archivo<<i->nombre_<<"||";
    archivo<<i->apellidos_<<"||";
    archivo<<(i->fechanacimiento_)->d<<"/";
    archivo<<(i->fechanacimiento_)->m<<"/";
    archivo<<(i->fechanacimiento_)->a<<"||";
    archivo<<i->telefono_<<"||";
    archivo<<i->codpostal_<<"||";
    archivo<<i->tipo_<<endl;
  }
  archivo.close();
}
