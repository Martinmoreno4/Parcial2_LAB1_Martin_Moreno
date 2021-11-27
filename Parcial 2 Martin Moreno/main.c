#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Peliculas.h"
int menu();

int main()
{
    srand (time(NULL));
    int aleatorio;
    int seIngresaronDatos = 0;
    //int rta;
    char seguir = 's';
    char confirma;

    LinkedList* listaPeliculas = ll_newLinkedList();
    do{
        switch(menu())
        {
            case 1:
                if(!loadFromText("movies.csv",listaPeliculas))
                {
                    printf("Problema al cargar las peliculas\n");
                }
                else
                {
                    printf("peliculas cargadas correctamente\n");
                    seIngresaronDatos=1;
                }
                break;

            case 2:
                system("cls");
                if(!ListMovie(listaPeliculas))
                {
                printf("Problema al mostrar las peliculas\n");
                }
                else
                {
                    printf("\n peliculas listadas correctamente!\n");
                }
                break;

            case 3:
                if(seIngresaronDatos==0)
                {
                    printf("ingrese primero los datos\n");
                }
                else
                {
                    listaPeliculas =ll_map(listaPeliculas, aleatorioRating);

                }
                break;

            case 4:
                if(seIngresaronDatos==0)
                {
                    printf("ingrese primero los datos\n");
                }
                else
                {
                    listaPeliculas =ll_map(listaPeliculas, aleatorioGenero);
                }
                break;

            case 5:
                if(seIngresaronDatos==0)
                {
                    printf("ingrese primero los datos\n");
                }
                else
                {

                }
                break;

            case 6:
                if(seIngresaronDatos==0)
                {
                    printf("ingrese primero los datos\n");
                }
                else
                {

                }
                break;

            case 7:
                if(saveAsText("movie2.csv",listaPeliculas))
                {
                    printf("datos cargados al archivo de texto\n");
                }else
                {
                    printf("error al cargar al archivo\n");
                }
                break;

            case 8:
                printf("Confirma salida?: ");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = tolower(confirma);
                if(confirma == 's')
                {
                    seguir = 'n';
                }
                break;
            default:
            printf("Opcion invalida!!!\n");
        }
        system("pause");
    }while(seguir == 's');
    return 0;
}

int menu()
{
    int opcion;
    system("cls");

    printf("*** Menu ***\n\n");
    printf("1. Cargar archivo\n");
    printf("2. Imprimir lista\n");
    printf("3. Asignar rating\n");
    printf("4. Asignar género\n");
    printf("5. Filtrar por género\n");
    printf("6. Ordenar películas\n");
    printf("7. Guardar películas\n");
    printf("8. Salir.\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}
