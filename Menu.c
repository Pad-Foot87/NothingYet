#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Menu.h"
#include "SimpleList.h"
#include "GOTOXY.h"


#define flush fflush(stdin)
#define CHARMAX 30



void DesignMainMenu()
{
	int i;
    system("cls");

    // Esquina superior izquierda
    gotoxy(0,0);
    printf("%c",201);

    //Techo
    gotoxy(1,0);
    for(i=0; i<65;i++)
    {
        printf("%c",205);
    }

    //Cielo raso
	 gotoxy(1,2);
    for(i=0; i<65;i++)
    {
        printf("%c",205);
    }

    // Esquina superior derecha
    gotoxy(66,0);
    printf("%c",187);

    // Columna izquierda
    for(i=1; i<12;i++)
    {
        gotoxy(0,i);
        printf("%c\n",186);
    }

    // Esquina inferior izquierda
    gotoxy(0,12);
    printf("%c",200);

    // Piso
    gotoxy(1,12);
    for(i=0; i<65;i++)
    {
        printf("%c",205);
    }

    // Esquina inferior derecha
    gotoxy(66,12);
    printf("%c",188);

    // Columna derecha
    for(i=1; i<12;i++)
    {
        gotoxy(66,i);
        printf("%c\n",186);
    }

	 // Titulo
	 gotoxy(25,1);
	 printf("<< SPOTiFAy >>");

	 gotoxy(60,1);
	 printf("v1.0");

    // Opciones
    gotoxy(19,4);
    printf("1) Administradores");

    gotoxy(19,6);
    printf("2) Usuarios");

    gotoxy(19,8);
    printf("3) Registrarse");

    gotoxy(19,10);
    printf("4) Salir");

    gotoxy(2,14);
    printf("\nIngrese una opcion: ");
}

int UserPass(stCelda *user, int activeUser, int *onLine)
{

	char userName[CHARMAX];
	char password[CHARMAX];
	int i = 0;
	int j = 0;
	int length = 0;
	int flag = 0;
	char option = 's';

	if(activeUser > 0)
	{
		do
		{
			do
			{
				printf("\nNombre de usuario: ");
				flush;
				gets(userName);
				length = strlen(userName);

				if(length > CHARMAX)
				{
					printf("\nMaximo de caracteres permitido 30 - Ha ingresado %d caracteres",length);
					printf("\nPresione una tecla para ingresar nuevamente...");
					getch();
				}
			}while(length > CHARMAX);

			while( (i < activeUser) && (flag == 0) && (length < CHARMAX) )
			{
				if(strcmp(user[i].usr.nombreUsuario,userName) == 0)
				{
					printf("\nID de usuario: N%c %d ",167,user[i].usr.idUsuario);
					printf("\nUsuario: %s ",user[i].usr.nombreUsuario);
					flag = 1;
					j = i;
				}
				i++;
			}

			if(flag == 0)
			{
				i = 0;
				printf("\nNombre de usario incorrecto o inexistente! - Seleccione una opcion...");
				printf("\nIngresar nuevamente (S) - Regresar al menu principal (N): ");
				flush;
				option = getch();
			}

			if(option == 'n')
			{
				DesignMainMenu();
				j = -1;
			}
		}while( (option == 's') && (flag == 0) );


		if(flag == 1)
		{
			printf("\n\nPassword: ");
			flush;
			gets(password);

			if(strcmp(user[j].usr.pass,password) == 0)
			{
				*onLine = 1;
			}
			else
			{
				do
				{
					printf("\nContraseña Incorrecta! - Seleccionar una opcion...");
					printf("\nIngresar nuevamente (S) - Regresar al menu principal (N): ");
					flush;
					option = getch();

					if(option == 'n')
					{
						DesignMainMenu();
						j = -1;
					}
					else
					{
						printf("\n\nPassword: ");
						flush;
						gets(password);
						if(strcmp(user[j].usr.pass,password) == 0)
						{
							*onLine = 1;
							flag = 2;
						}
					}
				}while( (option == 's') && (flag == 1) );
			}
		}
	}
	else
	{
		printf("No existen usuarios - Presione una tecla para continuar...");
		j= -1;
		flush;
		getch();
	}

	return j;
}

void MenuUser(stCelda *user, int currentUser, int *onLine)
{
	int option = 0;

	do
	{
		DesignMenuUser(user[currentUser].usr.nombreUsuario);

		flush;
		scanf("%d",&option);

		switch(option)
		{
			case 1:
			{
				DesignMenuUserProfile(user, currentUser);
				break;
			}

			case 2:
			{
				MenuUserPlaylist(user,currentUser);
				break;
			}

			case 3:
			{
				printf("Escuchar cancion");
				break;
			}

			case 4:
			{
				printf("Canciones recomendadas...");
				break;
			}

			case 5:
			{
				*onLine = 0;
				option = 6;
				break;
			}

			case 6:
			{
				break;
			}

			default:
			{
				printf("Ingrese una opcion correcta...\n\n");
				system("pause");

			}
		}

	}while(option != 6);
}

void DesignMenuUser(char user[])
{
	int i;
    system("cls");

    // Esquina superior izquierda
    gotoxy(0,0);
    printf("%c",201);

    //Techo
    gotoxy(1,0);
    for(i=0; i<65;i++)
    {
        printf("%c",205);
    }

    //Cielo raso
	 gotoxy(1,2);
    for(i=0; i<65;i++)
    {
        printf("%c",205);
    }

    // Esquina superior derecha
    gotoxy(66,0);
    printf("%c",187);

    // Columna izquierda
    for(i=1; i<16;i++)
    {
        gotoxy(0,i);
        printf("%c\n",186);
    }

    // Esquina inferior izquierda
    gotoxy(0,16);
    printf("%c",200);

    // Piso
    gotoxy(1,16);
    for(i=0; i<65;i++)
    {
        printf("%c",205);
    }

    // Esquina inferior derecha
    gotoxy(66,16);
    printf("%c",188);

    // Columna derecha
    for(i=1; i<16;i++)
    {
        gotoxy(66,i);
        printf("%c\n",186);
    }

	 // Titulo
	 gotoxy(2,1);
	 printf("<< SPOTiFAy >>");

	 gotoxy(45,1);
	 printf("User: %s",user);

    // Opciones
    gotoxy(19,4);
    printf("1) Ver perfil");

    gotoxy(19,6);
    printf("2) Mostrar Playlist");

    gotoxy(19,8);
    printf("3) Escuchar cancion");

    gotoxy(19,10);
    printf("4) Canciones recomendadas...");

	 gotoxy(19,12);
    printf("5) Cerrar sesion...");

    gotoxy(19,14);
    printf("6) Salir");

    gotoxy(2,18);
    printf("\nIngrese una opcion: ");
}

void MenuUserProfile(stCelda user[], int currentUser)
{
	gotoxy(15,4);
	printf("N%c ID.............: %d ",167,user[currentUser].usr.idUsuario);

	gotoxy(15,5);
	printf("Nombre de usuario.: %s",user[currentUser].usr.nombreUsuario);

	gotoxy(15,6);
	printf("Password..........: %s",user[currentUser].usr.pass);

	gotoxy(15,7);
	printf("A%co de nacimiento.: %d",164,user[currentUser].usr.anioNacimiento);

	gotoxy(15,8);
	printf("Genero............: %c",user[currentUser].usr.genero);

	gotoxy(15,9);
	printf("Pa%cs..............: %s",161,user[currentUser].usr.pais);

	gotoxy(15,10);
	printf("E-mail............: %s",user[currentUser].usr.correoElectronico);

	gotoxy(3,12);
	printf("Volver al menu...Presione un tecla");
	getch();
	flush;
}

void DesignMenuUserProfile(stCelda user[], int currentUser)
{
		int i;
    system("cls");

    // Esquina superior izquierda
    gotoxy(0,0);
    printf("%c",201);

    //Techo
    gotoxy(1,0);
    for(i=0; i<65;i++)
    {
        printf("%c",205);
    }

    //Cielo raso
	 gotoxy(1,2);
    for(i=0; i<65;i++)
    {
        printf("%c",205);
    }

    // Esquina superior derecha
    gotoxy(66,0);
    printf("%c",187);

    // Columna izquierda
    for(i=1; i<14;i++)
    {
        gotoxy(0,i);
        printf("%c\n",186);
    }

    // Esquina inferior izquierda
    gotoxy(0,14);
    printf("%c",200);

    // Piso
    gotoxy(1,14);
    for(i=0; i<65;i++)
    {
        printf("%c",205);
    }

    // Esquina inferior derecha
    gotoxy(66,14);
    printf("%c",188);

    // Columna derecha
    for(i=1; i<14;i++)
    {
        gotoxy(66,i);
        printf("%c\n",186);
    }

	 // Titulo
	 gotoxy(17,1);
	 printf("<< Perfil de Usuario - SPOTiFAy >>");

    // Opciones
    MenuUserProfile(user,currentUser);
}

void MenuUserPlaylist(stCelda user[], int currentUser)
{
   int option = 0;

   do
	{
		DesignMenuUserPlaylist(user[currentUser].usr.nombreUsuario);

		flush;
		scanf("%d",&option);

		switch(option)
		{
			case 1:
			{
				break;
			}

			case 2:
			{
				break;
			}

			case 3:
			{
				break;
			}

			default:
			{
				printf("\n\nIngrese una opcion valida...Presione una tecla para continuar");
				getch();
			}

		}
	}while(option != 3);
}

void DesignMenuUserPlaylist(char user[])
{
	int i;
	system("cls");

   // Esquina superior izquierda
   gotoxy(0,0);
   printf("%c",201);
   //Techo
   gotoxy(1,0);
   for(i=0; i<65;i++)
   {
       printf("%c",205);
   }

	//Cielo raso
	gotoxy(1,2);
   for(i=0; i<65;i++)
   {
       printf("%c",205);
   }

   // Esquina superior derecha
   gotoxy(66,0);
   printf("%c",187);

   // Columna izquierda
   for(i=1; i<13;i++)
   {
      gotoxy(0,i);
      printf("%c\n",186);
   }

   // Esquina inferior izquierda
   gotoxy(0,13);
   printf("%c",200);

   // Piso
   gotoxy(1,13);
   for(i=0; i<65;i++)
   {
      printf("%c",205);
   }

   // Esquina inferior derecha
   gotoxy(66,13);
   printf("%c",188);

   // Columna derecha
   for(i=1; i<13;i++)
   {
      gotoxy(66,i);
      printf("%c\n",186);
   }

	// Titulo
	gotoxy(2,1);
	printf("<< SPOTiFAy >>");

	gotoxy(45,1);
	printf("User: %s",user);

   // Opciones
   gotoxy(19,5);
   printf("1) Mostrar playlist por nombre");
   gotoxy(19,7);
   printf("2) Mostrar playlist por genero");
   gotoxy(19,9);
   printf("3) Salir");
   gotoxy(1,15);
   printf("Ingrese una opcion: ");
}

void PlaylistByName(stCelda user[], int currentUser)
{

}

