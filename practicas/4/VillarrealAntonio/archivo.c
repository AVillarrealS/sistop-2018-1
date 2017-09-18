///Programa crea un archivo, con datos introducidos desde la computadora
///Después lee dicho archivo

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

///Crear estructura
struct ejemplo{
    char nombre[50];
    char cuenta[20];
}esj;

void main(){

   printf("Nombre: ");
   gets(esj.nombre);

   printf("Cuenta: ");
   gets(esj.cuenta);

///Crear archivo con datos de la estructura

   FILE *myf;
   myf= fopen("arch_ejem.txt","w");

            if (myf==NULL){

                printf("No se pudo crear");

                return;
            }

///Pasarle los datos al archivo de texto
	fwrite(&esj,sizeof(esj),1,myf);

printf("\nArchivo guardado");

     fclose(myf);

///Leemos archivo

     int i=0;

     myf= fopen("arch_ejem.txt","r");

            if (myf==NULL){

                printf("No se pudo leer");

                return;
            }
    while(!feof(myf)){

        fread(&esj,sizeof(esj),1,myf);

        if(i==0){
        printf("\n\nNombre: %s \nCuenta: %s", esj.nombre, esj.cuenta);
        }

        i++;

    }

getch();
}
