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
    file.getline(cad,64,'|');                 //No lo entiendo
    sscanf(cad,"%2d/%2d/%4d",&f.d,&f.m,&f.a);
    t.setFecha(f);
    file.getline(cad,64,'|');   //Hora....
    sscanf(cad,"%2d:%2d",&h.h,&h.m);
    t.setHora(h);
    file.getline(cad,64,'|');
    t.setMedicamento(str);
    file.getline(cad,64,'|');
    t.setConcentracion(str);
    file.getline(cad,64,'|');
    t.setRegularidad(str);
    file.getline(cad,64,'|');   //Fecha....
    sscanf(cad,"%2d/%2d/%4d",&f.d,&f.m,&f.a);
    t.setFechaInicio(f);
    file.getline(cad,64,'|');   //Fecha....
    sscanf(cad,"%2d/%2d/%4d",&f.d,&f.m,&f.a);
    t.setFechaFinal(f);
    file.getline(cad,64,'|');
    file.getline(cad,32,'|');
    t.setEstado(stoi(cad));
    file.getline(cad,64,'|');
    t.setComentario(str);
    aux.push_back(t);
    }
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
/*
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
*/

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

void AgregaP()
{
  Paciente p(0);
  fecha f;
  string auxs;
  int auxi;
  cout<<"Introdzuca nombre del paciente"<<endl;
  cin>>auxs;
  p.setNombre(auxs);
  cout<<"Introdzuca apellidos del paciente"<<endl;
  cin>>auxs;
  p.setApellidos(auxs);
  cout<<"Introdzuca la dirección del paciente"<<endl;
  cin>>auxs;
  p.setDireccion(auxs);
  cout<<"Introdzuca la fecha de nacimiento del paciente"<<endl;
  leerFecha(f);
  p.setFechanacimiento(f);
  cout<<"Introdzuca el telefono del paciente"<<endl;
  cin>>auxi;
  p.setTelefono(auxi);
  cout<<"Introdzuca el cod.postal del paciente"<<endl;
  cin>>auxi;
  p.setCodPostal(auxi);
  cout<<"Introdzuca el tipo del paciente"<<endl;
  cin>>auxi;
  p.setTipo(auxi);
  AddPaciente(p);
}