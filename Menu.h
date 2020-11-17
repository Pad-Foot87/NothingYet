#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

typedef struct {
 int idCancion;
 char titulo[30];
 char artista[20];
 int duracion;
 char album[20];
 int anio;
 char genero[20];
 char comentario[100]; //Opcional
 int eliminado; // indica 1 o 0 si la canción fue eliminada
}stCancion;


typedef struct
{
 stCancion c;
 struct nodoArbolCancion *izq;
 struct nodoArbolCancion *der;
}nodoArbolCancion;


typedef struct
{
 int idPlaylist;
 int idUsuario;
 int idCancion;
}stPlaylist;


typedef struct
{
 stCancion c;
 struct nodoListaCancion *sig;
}nodoListaCancion;


typedef struct
{
 int idUsuario;
 char nombreUsuario[30];
 char pass[20];
 int anioNacimiento; //Opcional
 char genero; //Opcional
 char pais[20]; //Opcional
 char correoElectronico[50];
 int eliminado; // indica 1 o 0 si el cliente fue eliminado
 int aprobado;//indique 1 o 0 si el cliente esta aprobado por el admin
 int tipoUsuario;//1 admin
}stUsuario;


typedef struct
{
 stUsuario usr;
 nodoListaCancion *listaCanciones;
}stCelda;


void DesignMainMenu();

int UserPass(stCelda *user, int activeUser, int *onLine);

void MenuUser(stCelda *user, int currentUser, int *onLine);
void DesignMenuUser(char user[]);

void MenuUserProfile(stCelda user[], int currentUser);
void DesignMenuUserProfile(stCelda user[], int currentUser);

void MenuUserPlaylist(stCelda user[], int currentUser);

void DesignMenuUserPlaylist(char user[]);

#endif // MENU_H_INCLUDED
