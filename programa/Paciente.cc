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
  if(tipo_==0)
  {
    cout<<"TIPO: PUBLICO"<<endl;
  }else{
    cout<<"TIPO: PRIVADO"<<endl;
  }
}

/*list <Cita> Paciente::getCitas()
{
  list <Cita> aux;
  list <Cita>::iterator c;
  ifstream file;
  file.open("citas.txt");
  string cad;
  for(c=aux.begin();c!=aux.end();c++)
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
}
list <Tratamiento> Paciente::getTratamientos()   //Mal
{
  list <Tratamiento> aux;
  list <Tratamiento>::iterator t;
  ifstream file;
  file.open("Tratamientos.txt");
  string cad;
  for(t=aux.begin();t!=aux.end();t++)
  {
  	getline(file,cad,'/');
    (t->fecha_).d=stoi(cad);
    getline(file,cad,'/');
    (t->fecha_).m=stoi(cad);
    getline(file,cad,'|');
    (t->fecha_).a=stoi(cad);
    getline(file,cad,':');
    (t->hora_).h=stoi(cad);
    getline(file,cad,':');
    (t->hora_).m=stoi(cad);
    getline(file,cad,'|');
    (t->hora_).s=stoi(cad);
    getline(file,cad,'|');
    t.paciente_=stoi(cad);
    getline(file,(t.medicamento_),'|');
    getline(file,(t.concentracion_),'|');
    getline(file,(t.regularidad_),'|');
    getline(file,cad,'/');
    (t.fecha_inicio_).d=stoi(cad);
    getline(file,cad,'/');
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
}*/

void AddPaciente(Paciente p)//ESTO HAY QUE CAMBIARLO TO
{
  fstream archivo;
  archivo.open("Pacientes.txt",std::fstream::app);
  archivo<<p.getID()<<'|';
  archivo<<p.getNombre()<<'|';
  archivo<<p.getApellidos()<<'|';
  archivo<<escribeFecha(p.getFechanacimiento())<<"|";
  archivo<<p.getTelefono()<<'|';
  archivo<<p.getCodPostal()<<'|';
  archivo<<p.getTipo()<<endl;
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

void Paciente::mostrarHistorial()
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
      mostrarRegistro(Tratamiento);
    }
  }
}
/*

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
*/

void eliminarPaciente()
{
  ifstream file;
  file.open("Pacientes.txt");
  list<Paciente> aux;
  list<Paciente>::iterator i;
  string cad;
  while(getline(file,cad,'|'))
  {
    i->setID(stoi(cad));
    getline(file,cad,'|');
    i->setNombre(cad);
    getline(file,cad,'|');
    i->setApellidos(cad);
    getline(file,cad,'|');
    i->setDireccion(cad);
    //Aqui va fecha que no se como ponerlo //ELENA SI LEES ESTO PONLO TU QUE NO ME ACUERDO COMO IBA ESO
    getline(file,cad,'|');
    i->setTelefono(stoi(cad));
    i->setCodPostal(stoi(cad));
    i->setTipo(stoi(cad));
    i->mostrarPaciente();
    aux.push_back(*i);
  }
  file.close();
  cout<<"Introduzca el ID del paciente a eliminar"<<endl;
  int auxid;
  cin>>auxid;
  Paciente p(auxid);
  for(i=aux.begin();i!=aux.end();i++)
  {
    if((i->getID())==p.getID())
    {
      p=*i;
      i->setID(-1);
    }
  }
  char elec;
  cout<<"Está seguro de querer elimina el paciente "<<p.getNombre()<<" (S/N)"<<endl;
  cin>>elec;
  if(elec=='S')
  {
    ofstream archivo;
    archivo.open("Pacientes.txt");
    for(i=aux.begin();i!=aux.end();i++)
    {
      if((i->getID())!=-1)
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

void ModificarPaciente()
{
  ifstream file;
  file.open("Pacientes.txt");
  list<Paciente> aux;
  list<Paciente>::iterator i;
  string cad;
  while(getline(file,cad,'|'))
  {
    i->setID(stoi(cad));
    getline(file,cad,'|');
    i->setNombre(cad);
    getline(file,cad,'|');
    i->setApellidos(cad);
    getline(file,cad,'|');
    i->setDireccion(cad);
    //Aqui va fecha que no se como ponerlo //ELENA SI LEES ESTO PONLO TU QUE NO ME ACUERDO COMO IBA ESO
    getline(file,cad,'|');
    i->setTelefono(stoi(cad));
    i->setCodPostal(stoi(cad));
    i->setTipo(stoi(cad));
    i->mostrarPaciente();
    aux.push_back(*i);
  }
  file.close();
  cout<<"Introduzca el ID del paciente a modificar"<<endl;
  int auxid;
  cin>>auxid;
  Paciente p(auxid);
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
        if(i->getID()==p.getID())
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
        if((i->getID()==p.getID()))
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
        if((i->getID()==p.getID()))
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
        if((i->getID()==p.getID()))
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
        if((i->getID()==p.getID()))
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
        if((i->getID()==p.getID()))
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
        if(i->getID()==p.getID())
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
      if(i->getID()!=-1)
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
