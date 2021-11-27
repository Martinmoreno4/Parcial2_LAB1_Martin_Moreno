#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Peliculas.h"
#include "parser.h"
#include "Controller.h"

int loadFromText(char* path , LinkedList* pArrayListPelicula)
{
    int todoOk = -1;
    FILE* pFile;

    if(path != NULL && pArrayListPelicula != NULL)
    {
        pFile = fopen(path, "r");

        if(pFile != NULL)
        {
            if(parser_PeliculaDeTexto(pFile, pArrayListPelicula))
            {
                todoOk = 1;
            }
            fclose(pFile);
        }
    }

    return todoOk;
}




int ListMovie(LinkedList* pArrayListPelicula)
{
    int todoOk=0;
    int tam = ll_len(pArrayListPelicula);
    eMovie* auxMovie;
    if(pArrayListPelicula != NULL)
    {
        todoOk=1;
        printf("  id     Titulo   Genero   Rating\n");
        for(int i=0; i<tam; i++)
        {
            auxMovie=(eMovie*) ll_get(pArrayListPelicula, i);
            if(auxMovie!= NULL)
            {
                mostratPelicula(auxMovie);
            }
        }
    }
    return todoOk;
}

int sortMovie(LinkedList* pArrayListPelicula)
{
    int todoOk=0;
    int tam = ll_len(pArrayListPelicula);
    eMovie* auxMovie;
    if(pArrayListPelicula != NULL)
    {
        todoOk=1;
        printf("  id     Titulo   Genero   Rating\n");
        for(int i=0; i<tam; i++)
        {
            auxMovie=(eMovie*) ll_get(pArrayListPelicula, i);
            if(auxMovie!= NULL)
            {
                mostratPelicula(auxMovie);
            }
        }
    }
    return todoOk;
}

int saveAsText(char* path , LinkedList* pArrayListPelicula)
{
    int todoOk = -1;
    return todoOk;
}

int aleatorioGenero(void* elemento)
{
    int rta=0;
    eMovie* e=(eMovie*) elemento;
    int aleatorio;

    aleatorio = rand()%((4 - 1) + 1)+1;

    switch(aleatorio)
    {
        case 1:
            strcpy("drama", e->genero);
            break;

        case 2:
            strcpy("comedia", e->genero);
            break;

        case 3:
            strcpy("accion", e->genero);
            break;

        case 4:
            strcpy("terror", e->genero);
            break;

        default:
            break;
    }

    return rta;
}

int aleatorioRating(void* elemento)
{
    int rta=0;
    eMovie* e=(eMovie*) elemento;
    int aleatorio;

    aleatorio = (float) (rand()%((10 - 1) + 1)+1) / 10;

    e->rating=aleatorio;

    return rta;
}
