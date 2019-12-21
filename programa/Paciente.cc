#include "Paciente.h"
#include "funciones.h"
#include <iostream>
//#include <direct.h>


//Para crear una carpeta es con mkdir("Nombredelacarpeta");

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
  cout<<endl<<"ID: "<<id_<<endl;
  cout<<"NOMBRE: "<<nombre_<<endl;
  cout<<"APELLIDOS: "<<apellidos_<<endl;
  cout<<"FECHANACIMIENTO: "<<escribeFecha(fechanacimiento_)<<endl;
  if(telefono_>=0){
    cout<<"TELEFONO: "<<telefono_<<endl;
  }
  else{
    cout<<"TELEFONO: "<<endl;
  }
  if(codpostal_>=0){
  cout<<"CODIGO POSTAL: "<<codpostal_<<endl;
  }
  else{
    cout<<"CODIGO POSTAL: "<<endl;
  }
  cout<<"DIRECCION: "<<direccion_<<endl;
  if(tipo_==0)
  {
    cout<<"TIPO: PUBLICO"<<endl;
  }else{
    cout<<"TIPO: PRIVADO"<<endl;
  }
}
/*
list <Cita> Paciente::getCitas()
{
  list <Cita> aux;
  list <Cita>::iterator c;
  ifstream file;
  file.open("citas.txt");
  string cad;
  for(c=aux.begin();c!=aux.end();c++)     //Mal
  {
  	getline(file,cad,'|');
    (c->fecha_).d=stoi(cad);
    getline(file,cad,'|');
    (c->fecha_).m=stoi(cad);
    getline(file,cad,'|');
    (c->fecha_).a=stoi(cad);
    getline(file,cad,':');
    (c->hora_).h=stoi(cad);
    getline(file,cad,':');
    (c->hora_).m=stoi(cad);
    getline(file,cad,'|');
    (c->hora_).s=stoi(cad);
    getline(file,cad,'|');
    c->paciente_=stoi(cad);
    getline(file,(c.comentario_),'\n');
    aux.push_back(c);
  }
  file.close();
  return aux;

file.getline(cad,64,'|'); 
    sscanf(cad,"%2d/%2d/%4d",&f.d,&f.m,&f.a);
    file.getline(cad,64,'|'); 
    sscanf(cad,"%2d:%2d",&h.h,&h.m);
    getline(file,cad,'|');



}
*/
list <Tratamiento> Paciente::getTratamientos(){
  list <Tratamiento> aux;
  Tratamiento t(id_);
  fecha f;
  hora h;
  char cad[256];
  string str;
  ifstream file;
  file.open(to_string(id_)+"/Tratamientos.txt");
    while(!file.eof()){
      file.getline(cad,64,'|'); 
      sscanf(cad,"%2d/%2d/%4d",&f.d,&f.m,&f.a);
      t.setFecha(f);
      file.getline(cad,64,'|');   //Hora....
      sscanf(cad,"%2d:%2d",&h.h,&h.m);
      t.setHora(h);
      getline(file,str,'|');
      t.setMedicamento(str);
      getline(file,str,'|');
      t.setConcentracion(str);
      getline(file,str,'|');
      t.setRegularidad(str);
      file.getline(cad,64,'|');   //Fecha....
      sscanf(cad,"%2d/%2d/%4d",&f.d,&f.m,&f.a);
      t.setFechaInicio(f);
      file.getline(cad,64,'|');   //Fecha....
      sscanf(cad,"%2d/%2d/%4d",&f.d,&f.m,&f.a);
      t.setFechaFinal(f);
      file.getline(cad,32,'|');
      t.setEstado(atoi(cad));
      getline(file,str,'\n');
      t.setComentario(str);
      aux.push_back(t);
      }
      aux.pop_back();     //Esto es porque me lee uno mas de la cuenta y no se como hacer para que no lo lea
    return aux;
}
/*
list <Nota> Paciente::getNotas()
{
  list <Nota> aux;
  list <Nota>::iterator n;
  ifstream file;
  file.open("citas.txt")
  string cad
  for(n=aux.begin();n!=aux.end();n++)       //Mal
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

*/
void AddPaciente(Paciente p)
{
  fstream archivo;
  archivo.open("Pacientes.txt",std::fstream::app);
  archivo<<endl<<p.getID()<<'|';
  archivo<<p.getNombre()<<'|';
  archivo<<p.getApellidos()<<'|';
  archivo<<escribeFecha(p.getFechanacimiento())<<"|";
  archivo<<p.getTelefono()<<'|';
  archivo<<p.getCodPostal()<<'|';
  archivo<<p.getDireccion()<<'|';
  archivo<<p.getTipo();
  archivo.close();
}

/*
void Paciente::mostrarHCitas()  //ESTO ES TO DE JAVI
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
    c.setPaciente(stoi(cad));
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
*/
/*
/*void Paciente::mostrarHistorial()
{
  int elec;
  cout<<"Indique que historial quiere visualizar"<<endl<<"1.Notas\n2.Tratamientos\n3.Notas y tratamientos"<<endl;
  cin>>elec;
  switch(elec)
  {
    case 1:
    {
      list <Nota> notas;
      notas=getNotas();
      mostrarRegistro(notas);
      cout<<"Elija la opción a realizar"<<endl;
      cout<<"1.Modificar\n2.Eliminar\n3.Salir"<<endl;
      int elec2;
      switch(elec2)
      {
        case 1:
        {
          modificarNota();
        }break;
        case 2:
        {
          eliminarNota();
        }break;
      }
    }break;
    case 2:
    {
      list <Tratamiento> tratamientos;
      tratamientos=getTratamientos();
      mostrarRegistro(Tratamiento);
      cout<<"Elija la opción a realizar"<<endl;
      cout<<"1.Modificar\n2.Eliminar\n3.Salir"<<endl;
      int elec3;
      switch(elec3)
      {
        case 1:
        {
          modificarCita();
        }break;
        case 2:
        {
          eliminarCita();
        }break;
      }
    }break;
    case 3:
    {
      list <Nota> notas;
      notas=getNotas();
      mostrarRegistro(notas);
      list <Tratamiento> tratamientos_;
      tratamientos_=getTratamientos();
      mostrarRegistro(tratamientos_);
    }
  }
}
*/
bool Paciente::addTratamiento(const Tratamiento t){
  fstream file;
  file.open(to_string(id_)+"/Tratamientos.txt",ios::out|ios::app|ios::ate);
  printf("Abriendo fichero\n");
  if(file){
    file<<escribeFecha(t.getFecha())<<"|"<<escribeHora(t.getHora())<<'|'<<t.getMedicamento()<<'|'<<t.getConcentracion()<<'|'<<t.getRegularidad()<<'|'<<escribeFecha(t.getFechaInicio())<<'|'<<escribeFecha(t.getFechaFinal())<<'|'<<t.getEstado()<<'|'<<t.getComentario()<<endl;
    file.close();
    return true;
  }
  else{
    return false;
  }
}
bool Paciente::addNota(const Nota n){
  fstream file;
  file.open(to_string(id_)+"/Notas.txt",ios::out|ios::app|ios::ate);
  if(file){
    file<<escribeFecha(n.getFecha())<<"|"<<escribeHora(n.getHora())<<n.getContenido()<<endl;
    file.close();
    return true;
  }
  else{
    return false;
  }
}


void Paciente::eliminarPaciente()
{
  list<Paciente> aux;
  list<Paciente>::iterator i;
  leerPacientes(&aux);
  char elec;
  cout<<"Está seguro de querer elimina el paciente "<<nombre_<<" (S/N)"<<endl;
  cin>>elec;
  if(elec=='S')
  {
    ofstream archivo;
    archivo.open("Pacientes.txt");
    for(i=aux.begin();i!=aux.end();i++)
    {
      if((i->getID())!=id_)
      {
        archivo<<i->getID()<<'|';
        archivo<<i->getNombre()<<'|';
        archivo<<i->getApellidos()<<'|';
        archivo<<escribeFecha(i->getFechanacimiento())<<'|';
        archivo<<i->getTelefono()<<'|';
        archivo<<i->getCodPostal()<<'|';
        archivo<<i->getTipo()<<endl;
      }
    }
  }
}


void Paciente::modificarPaciente()
{
  list<Paciente> aux;
  list<Paciente>::iterator i;
  leerPacientes(&aux);
  int elec;
  cout<<"Indique que campos quiere modificar"<<endl<<"1.Nombre\n2.Apellidos\n3.Direccion\n4.Fecha de nacimiento\n5.Telefono\n6.Codigo Postal\n7.Tipo\n8.Modificar todos los campos"<<endl;
  cin>>elec;
  switch(elec)
  {
    case 1:
    {
      string name;
      cout<<"Indique el nuevo nombre del paciente"<<endl;
      cin>>name;
      for(i=aux.begin();i!=aux.end();i++)
      {
        if(i->getID()==id_)
        {
          i->setNombre(name);
        }
      }
    }break;
    case 2:
    {
      string surname;
      cout<<"Indique el nuevo apellido del paciente"<<endl;
      cin>>surname;
      for(i=aux.begin();i!=aux.end();i++)
      {
        if((i->getID()==id_))
        {
          i->setApellidos(surname);
        }
      }
    }break;
    case 3:
    {
      string adress;
      cout<<"Indique la nueva direccion del paciente"<<endl;
      cin>>adress;
      for(i=aux.begin();i!=aux.end();i++)
      {
        if((i->getID()==id_))
        {
          i->setDireccion(adress);
        }
      }
    }break;
    case 4:
    {
      //AQUI VA LA FECHA PERO NO SE COMO PONERLA
    }break;
    case 5:
    {
      int tlf;
      cout<<"Indique el nuevo telefono del paciente"<<endl;
      cin>>tlf;
      for(i=aux.begin();i!=aux.end();i++)
      {
        if((i->getID()==id_))
        {
          i->setTelefono(tlf);
        }
      }
    }break;
    case 6:
    {
      int cp;
      cout<<"Indique el nuevo codigo postal del paciente"<<endl;
      cin>>cp;
      for(i=aux.begin();i!=aux.end();i++)
      {
        if((i->getID()==id_))
        {
          i->setCodPostal(cp);
        }
      }
    }break;
    case 7:
    {
      int type;
      cout<<"Indique el nuevo tipo del paciente"<<endl;
      cin>>type;
      for(i=aux.begin();i!=aux.end();i++)
      {
        if((i->getID()==id_))
        {
          i->setTipo(type);
        }
      }
    }break;
    case 8:
    {
      string name,surname,adress;
      int tlf,cp,type;
      cout<<"Indique el nuevo nombre del paciente"<<endl;
      cin>>name;
      cout<<"Indique el nuevo apellido del paciente"<<endl;
      cin>>surname;
      cout<<"Indique la nueva direccion del paciente"<<endl;
      cin>>adress;
      cout<<"Indique el nuevo telefono del paciente"<<endl;
      cin>>tlf;
      cout<<"Indique el nuevo codigo postal del paciente"<<endl;
      cin>>cp;
      cout<<"Indique el nuevo tipo del paciente"<<endl;
      cin>>type;
      for(i=aux.begin();i!=aux.end();i++)
      {
        if(i->getID()==id_)
        {
          i->setNombre(name);
          i->setApellidos(surname);
          i->setDireccion(adress);
          i->setTelefono(tlf);
          i->setCodPostal(cp);
          i->setTipo(type);
        }
      }
    }break;
  }
  cout<<"¿Está seguro de querer modificar estos campos? (S/N)"<<endl;
  char c;
  cin>>c;
  if(c=='S')
  {
    ofstream archivo;
    archivo.open("Pacientes.txt");
    for(i=aux.begin();i!=aux.end();i++)
    {
        archivo<<i->getID()<<'|';
        archivo<<i->getNombre()<<'|';
        archivo<<i->getApellidos()<<'|';
        archivo<<escribeFecha(i->getFechanacimiento())<<'|';
        archivo<<i->getTelefono()<<'|';
        archivo<<i->getCodPostal()<<'|';
        archivo<<i->getTipo()<<endl;

    }
  }
}

