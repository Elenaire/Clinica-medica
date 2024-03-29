#include "Paciente.h"
#include "funciones.h"
#include <iostream>
#include <unistd.h>
//#include <direct.h>
void leerPacientes(list<Paciente> &p);

//Para crear una carpeta es con mkdir Nombredelacarpeta;
//Para borrarla rmdir Nombredelacarpeta;

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
void Paciente::mostrarPaciente(int n){
  if(n==0){
    cout<<endl<<"ID: "<<id_<<endl;
  }
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
  cout<<endl;
}

list <Cita> Paciente::getCitas()
{
  list <Cita> aux;
  Cita c(id_);
  fecha f;
  hora h;
  char cad[256];
  string str;
  ifstream file;
  file.open("Agenda/..."); //NO SE EL PATH
  if(file.is_open())
  {
    while(!file.eof())
    {
      file.getline(cad,64,'|');
      sscanf(cad,"%2d/%2d/%4d",&f.d,&f.m,&f.a);
      c.setFecha(f);
      file.getline(cad,64,'|');
      sscanf(cad,"%2d:%2d",&h.h,&h.m);
      c.setHora(h);
      getline(file,str,'|');
      c.setComentario(str);
      aux.push_back(c);
    }
    file.close();
    //aux.pop_back()     //ESTO LO DEJO COMENTADO PORQUE NO SE SI DARA EL MISMO ERROR QUE EN TRATAMEINTOS
  }
  return aux;
}

list <Tratamiento> Paciente::getTratamientos(){
  list <Tratamiento> aux;
  Tratamiento t(id_);
  fecha f;
  hora h;
  char cad[256];
  string str;
  ifstream file;
  file.open("Pacientes/"+to_string(id_)+"/Tratamientos.txt");
    if(file.is_open()){
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
      file.close();
      aux.pop_back();     //Esto es porque me lee uno mas de la cuenta y no se como hacer para que no lo lea
    }
    return aux;
}

list <Nota> Paciente::getNotas()
{
  list <Nota> aux;
  Nota n(id_);
  fecha f;
  hora h;
  char cad[256];
  string str;
  ifstream file;
  file.open("Pacientes/"+to_string(id_)+"/Notas.txt");
    if(file.is_open()){
      while(!file.eof())
      {
        file.getline(cad,64,'|');
        sscanf(cad,"%2d/%2d/%4d",&f.d,&f.m,&f.a);
        n.setFecha(f);
        file.getline(cad,64,'|');   //Hora....
        sscanf(cad,"%2d:%2d",&h.h,&h.m);
        n.setHora(h);
        getline(file,str,'\n');
        n.setContenido(str);
        aux.push_back(n);
      }
      file.close();
      aux.pop_back();     //LO pongo por si da el errror de TRatamientos
    }
  return aux;
}

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

void Paciente::mostrarHistorial()
{
  int k;
  cout<<"Indique que historial quiere visualizar"<<endl<<"1.Notas\n2.Tratamientos\n3.Notas y tratamientos"<<endl;
  cin>>k;
  switch(k)
  {
    case 1:
    {
      list <Nota> notas;
      list <Nota>::iterator n;
      notas=getNotas();
      int i=1;
      for(n=notas.begin();n!=notas.end();n++)
      {
        cout<<i<<".";
        (*n).mostrarRegistro();
        cout<<endl;
        i++;
      }
      cout<<"Seleccione una Nota(SI DESEA SALIR, SELECCIONE: 0)"<<endl;
      cin>>i;
      if(i>0)
      {
            n=notas.begin();
            advance(n,i-1);
            (*n).modificarNota();
            cout<<"Se va a guardar la nota: "<<n->getContenido()<<endl;
            cout<<"Está seguro de querer guardar los cambios (s/n)"<<endl;
            char c;
            cin>>c;
            if(c=='s')
            {
              fstream file;
              file.open("Pacientes/"+to_string(id_)+"/Notas.txt");
              if(file.is_open())
              {
                for(n=notas.begin();n!=notas.end();n++)
                {
                  cout<<"Estoy escribiendo "<<n->getContenido()<<endl;
                  file<<escribeFecha(n->getFecha())<<'|'<<escribeHora(n->getHora())<<'|'<<n->getContenido()<<endl;
                }
              }
              file.close();
              cout<<"Se ha modificado la nota"<<endl;
            }
      }
    }break;
    case 2:
    {
      list <Tratamiento> tratamientos;
      list <Tratamiento>::iterator t;
      tratamientos=getTratamientos();
      int i=1;
      for(t=tratamientos.begin();t!=tratamientos.end();t++)
      {
        cout<<i<<".";
        (*t).mostrarRegistro();
        cout<<endl;
        i++;
      }
      cout<<"Seleccione un Tratamiento(SI DESEA SALIR, SELECCIONE: 0)"<<endl;
      cin>>i;
      if(i>0)
      {
          t=tratamientos.begin();
          advance(t,i-1);
          modificarTratamiento(*t);
          cout<<"Esta seguro de querer modificar el tratamiento(s/n)"<<endl;
          char c;
          cin>>c;
          if(c=='s')
          {
            fstream file;
            file.open("Pacientes/"+to_string(id_)+"/Tratamientos.txt");
            if(file.is_open())
            {
              for(t=tratamientos.begin();t!=tratamientos.end();t++)
              {
                file<<escribeFecha(t->getFecha())<<"|"<<escribeHora(t->getHora())<<'|'<<t->getMedicamento()<<'|'<<t->getConcentracion()<<'|'<<t->getRegularidad()<<'|'<<escribeFecha(t->getFechaInicio())<<'|'<<escribeFecha(t->getFechaFinal())<<'|'<<t->getEstado()<<'|'<<t->getComentario()<<endl;
              }
            }
            file.close();
            cout<<"Se ha modificado El tratamiento"<<endl;
          }
      }
    }break;
    case 3:
    {
      list <Nota> notas;
      list <Nota>::iterator n;
      notas=getNotas();
      int i=1;
      for(n=notas.begin();n!=notas.end();n++)
      {
        cout<<i<<".";
        (*n).mostrarRegistro();
        cout<<endl;
        i++;
      }
      list <Tratamiento> tratamientos;
      list <Tratamiento>::iterator t;
      tratamientos=getTratamientos();
      i=1;
      for(t=tratamientos.begin();t!=tratamientos.end();t++)
      {
        cout<<i<<": ";
        (*t).mostrarRegistro();
        cout<<endl;
        i++;
      }
      sleep(5);
    }break;
  }
}


bool Paciente::addTratamiento(const Tratamiento t){
  fstream file;
  file.open("Pacientes/"+to_string(id_)+"/Tratamientos.txt",ios::out|ios::app|ios::ate);
  if(file.is_open()){
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
  file.open("Pacientes/"+to_string(id_)+"/Notas.txt",ios::out|ios::app|ios::ate);
  if(file){
    file<<escribeFecha(n.getFecha())<<"|"<<escribeHora(n.getHora())<<"|"<<n.getContenido()<<endl;
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
  leerPacientes(aux);
  char elec;
  string carpeta;
  cout<<"Está seguro de querer elimina el paciente "<<nombre_<<" (s/n)"<<endl;
  cin>>elec;
  if(elec=='s')
  {
    ofstream archivo;
    archivo.open("Pacientes.txt",ios::trunc);
    for(i=aux.begin();i!=aux.end();i++)
    {
      if((i->getID())!=id_)
      {
        archivo<<endl<<i->getID()<<'|';
        archivo<<i->getNombre()<<'|';
        archivo<<i->getApellidos()<<'|';
        archivo<<escribeFecha(i->getFechanacimiento())<<'|';
        archivo<<i->getTelefono()<<'|';
        archivo<<i->getCodPostal()<<'|';
        archivo<<i->getTipo();
      }
    }
    archivo.close();
    carpeta="Pacientes/"+to_string(id_);
    rmdir(carpeta.c_str());
  }
}


void Paciente::modificarPaciente()
{
  list<Paciente> aux;
  list<Paciente>::iterator i;
  leerPacientes(aux);
  int elec;
  cout<<"Indique que campos quiere modificar"<<endl<<"1 Nombre\n2 Apellidos\n3 Direccion\n4 Fecha de nacimiento\n5 Telefono\n6.Codigo Postal\n7 Tipo\n8 Modificar todos los campos"<<endl;
  cin>>elec;
  switch(elec)
  {
    case 1:
    {
      string name;
      cout<<"Indique el nuevo nombre del paciente"<<endl;
      getline(cin,name);
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
      getline(cin,surname);
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
      getline(cin,adress);
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
      fecha f;
      bool bucle=true;
      cout<<"Indique la nueva fecha de nacimiento"<<endl;
      while(bucle){
        if(leerFecha(f)!=true){
          printf("Formato de fecha incorrecto, introduzca dia/mes/año\n");
        }
        else if(dias(f,HOY)<0){
          printf("Esa fecha aun no ha pasado\n");
        }
        else{
          bucle=false;
        }
      }
      for(i=aux.begin();i!=aux.end();i++)
      {
        if((i->getID()==id_))
        {
          i->setFechanacimiento(f);
        }
      }
    }break;
    case 5:
    {
      string tlf;
      cout<<"Indique el nuevo telefono del paciente"<<endl;
      getline(cin,tlf);
    	getline(cin,tlf);
      for(i=aux.begin();i!=aux.end();i++)
      {
        if((i->getID()==id_))
        {
          if(aux.size()>0){
        		i->setTelefono((stoi(tlf)));
        	}else{
          i->setTelefono(0);
          }
        }
      }
    }break;
    case 6:
    {
      string cp;
      cout<<"Indique el nuevo codigo postal del paciente"<<endl;
      getline(cin,cp);
      for(i=aux.begin();i!=aux.end();i++)
      {
        if((i->getID()==id_))
        {
          if(aux.size()>0){
        		i->setCodPostal((stoi(cp)));
        	}else{
            i->setCodPostal(0);
          }
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
      string name,surname,adress,tlf,cp;
      int type;
      cout<<"Indique el nuevo nombre del paciente"<<endl;
      getline(cin,name);
      cout<<"Indique el nuevo apellido del paciente"<<endl;
      getline(cin,surname);
      cout<<"Indique la nueva direccion del paciente"<<endl;
      getline(cin,adress);
      cout<<"Indique el nuevo telefono del paciente"<<endl;
      getline(cin,tlf);
    	getline(cin,tlf);
      cout<<"Indique el nuevo codigo postal del paciente"<<endl;
      getline(cin,cp);
      cout<<"Indique el nuevo tipo del paciente"<<endl;
      cin>>type;
      for(i=aux.begin();i!=aux.end();i++)
      {
        if(i->getID()==id_)
        {
          i->setNombre(name);
          i->setApellidos(surname);
          i->setDireccion(adress);
          if(aux.size()>0){
        		i->setTelefono(stoi(tlf));
        	}
        	else{
        		i->setTelefono(0);
        	}
          if(aux.size()>0){
        		i->setCodPostal(stoi(cp));
        	}
        	else{
        		i->setCodPostal(0);
        	}
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
