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
  ifstream file;
  file.open("citas.txt")
  string cad
  for(c=aux.begin();c!=aux.end();c++)
  {
  	getline(file,cad,"/");
    (c->fecha_)->d=stoi(cad);
    getline(file,cad,"/");
    (c->fecha_)->m=stoi(cad);
    getline(file,cad,"||");
    (c->fecha_)->a=stoi(cad);
    getline(file,cad,":");
    (c->hora_)->h=stoi(cad);
    getline(file,cad,":");
    (c->hora_)->m=stoi(cad);
    getline(file,cad,"||");
    (c->hora_)->s=stoi(cad);
    getline(file,cad,"||");
    c->paciente_=stoi(cad);
    getline(file,(c->comentario_),"\n");
    aux.push_back(c);
  }
  file.close();
  return aux;
}

list <Tratamiento> Paciente::getTratamiento()
{
  list <Tratamiento> aux;
  list <Tratamiento>::iterator t;
  ifstream file;
  file.open("Tratamientos.txt")
  string cad
  for(t=aux.begin();t!=aux.end();t++)
  {
  	getline(file,cad,"/");
    (t->fecha_)->d=stoi(cad);
    getline(file,cad,"/");
    (t->fecha_)->m=stoi(cad);
    getline(file,cad,"||");
    (t->fecha_)->a=stoi(cad);
    getline(file,cad,":");
    (t->hora_)->h=stoi(cad);
    getline(file,cad,":");
    (t->hora_)->m=stoi(cad);
    getline(file,cad,"||");
    (t->hora_)->s=stoi(cad);
    getline(file,cad,"||");
    t->paciente_=stoi(cad);
    getline(file,(t->medicamento_),"||");
    getline(file,(t->concentracion_),"||");
    getline(file,(t->regularidad_),"||");
    getline(file,cad,"/");
    (t->fecha_inicio_)->d=stoi(cad);
    getline(file,cad,"/");
    (t->fecha_inicio_)->m=stoi(cad);
    getline(file,cad,"||");
    (t->fecha_inicio_)->a=stoi(cad);
    getline(file,cad,"/");
    (t->fecha_final_)->d=stoi(cad);
    getline(file,cad,"/");
    (t->fecha_final_)->m=stoi(cad);
    getline(file,cad,"||");
    (t->fecha_final_)->a=stoi(cad);
    getline(file,cad,"\n");
    t->estado=stoi(cad);
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
  	getline(file,cad,"/");
    (n->fecha_)->d=stoi(cad);
    getline(file,cad,"/");
    (n->fecha_)->m=stoi(cad);
    getline(file,cad,"||");
    (n->fecha_)->a=stoi(cad);
    getline(file,cad,":");
    (n->hora_)->h=stoi(cad);
    getline(file,cad,":");
    (n->hora_)->m=stoi(cad);
    getline(file,cad,"||");
    (n->hora_)->s=stoi(cad);
    getline(file,cad,"||");
    n->paciente_=stoi(cad);
    getline(file,(n->nota_),"\n");
    aux.push_back(n);
  }
  file.close();
  return aux;
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

void Paciente::mostrarRegistro()
{
	list <Cita> aux;
  list <Cita>::iterator c;
  ifstream file;
  file.open("citas.txt")
  string cad
  for(c=aux.begin();c!=aux.end();c++)
  {
  	getline(file,cad,"/");
    (c->fecha_)->d=stoi(cad);
    getline(file,cad,"/");
    (c->fecha_)->m=stoi(cad);
    getline(file,cad,"||");
    (c->fecha_)->a=stoi(cad);
    getline(file,cad,":");
    (c->hora_)->h=stoi(cad);
    getline(file,cad,":");
    (c->hora_)->m=stoi(cad);
    getline(file,cad,"||");
    (c->hora_)->s=stoi(cad);
    getline(file,cad,"||");
    c->paciente_=stoi(cad);
    getline(file,(c->comentario_),"\n");
    aux.push_back(c);
  }
  file.close();
     //??????????????????????????????????????????
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
  	getline(file,cad,"/");
    (c->fecha_)->d=stoi(cad);
    getline(file,cad,"/");
    (c->fecha_)->m=stoi(cad);
    getline(file,cad,"||");
    (c->fecha_)->a=stoi(cad);
    getline(file,cad,":");
    (c->hora_)->h=stoi(cad);
    getline(file,cad,":");
    (c->hora_)->m=stoi(cad);
    getline(file,cad,"||");
    (c->hora_)->s=stoi(cad);
    getline(file,cad,"||");
    c->paciente_=stoi(cad);
    getline(file,(c->comentario_),"\n");
    aux.push_back(c);
  }
  file.close();
  for(c=aux.begin();c!=aux.end();c++)
  {
  	if(id_=(c->paciente_))
  	{
  		cout<<(c->fecha_)->d<<endl;
  		cout<<(c->fecha_)->m<<endl;
  		cout<<(c->fecha_)->a<<endl;
  	}
  }
}


