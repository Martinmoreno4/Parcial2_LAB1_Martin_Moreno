#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Peliculas.h"

int parser_PeliculaDeTexto(FILE* pFile , LinkedList* arrayListPelicula)
{
    char buffer[4][128];
    int len;
    eMovie* auxPelicula;
    int i;
    len = ll_len(arrayListPelicula);
    int cant;

    if(pFile==NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

    do
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

        if(cant == 4)
        {
            auxPelicula = newMovieParam(atoi(buffer[0]),buffer[1],buffer[2],atoi(buffer[3]));
            ll_add(arrayListPelicula, auxPelicula);
            i++;
        }
        else
        {
            break;
        }

    }while( !feof(pFile) && i>len);

    fclose(pFile);

    printf("\n%d ",ll_len(arrayListPelicula));

    return 1;
}
