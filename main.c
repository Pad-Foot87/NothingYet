#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "GOTOXY.h"
#include "SetColor.h"
#include "AnimatedMenu.h"
#include "Menu.h"

#define flush fflush(stdin)



int main()
{
	int user = -1;
	int onLine = 0;
	int option = 0;

	stCelda usuarios[3];

	strcpy(usuarios[0].usr.nombreUsuario,"MDQcaquita");
	strcpy(usuarios[1].usr.nombreUsuario,"eldie54");
	strcpy(usuarios[2].usr.nombreUsuario,"Juancito");
	strcpy(usuarios[3].usr.nombreUsuario,"Pebete");

	usuarios[0].usr.idUsuario = 1;
	usuarios[1].usr.idUsuario = 2;
	usuarios[2].usr.idUsuario = 3;
	usuarios[3].usr.idUsuario = 4;

	usuarios[1].usr.anioNacimiento = 1987;
	usuarios[1].usr.genero = 'M';
	strcpy(usuarios[1].usr.pais,"Congo");
	strcpy(usuarios[1].usr.correoElectronico,"pebete@gmail.com");

	strcpy(usuarios[0].usr.pass,"1234");
	strcpy(usuarios[1].usr.pass,"**345");
	strcpy(usuarios[2].usr.pass,"pebete");
	strcpy(usuarios[3].usr.pass,"caca1234");

	onLine = 0;

	AniMenu();

	do
	{
		DesignMainMenu();

		flush;
		scanf("%d",&option);


			switch(option)
			{
				case 1:
				{
					printf("Menu de admin...");
					break;
				}

				case 2:
				{


					if( (user == -1) || (onLine == 0) )
					{
						user = UserPass(usuarios,4,&onLine);
					}

					MenuUser(usuarios,user,&onLine);

					break;
				}

				case 3:
				{
					printf("Menu para registracion");
					break;
				}
			}

	}while(option != 4);

	return 0;
}
