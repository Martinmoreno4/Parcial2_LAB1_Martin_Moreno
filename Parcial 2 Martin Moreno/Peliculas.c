#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Peliculas.h"

void mostratPelicula(eMovie* movie)
{
    printf("%4d  %10s        %10s          %.2f\n", movie->id_peli, movie->titulo, movie->genero, movie->rating);
}


int pelicula_setId(eMovie* this,int id)
{
    int todoOk = 0;
    if(this!=NULL && id > 0)
    {
        this ->id_peli= id;
        todoOk= 1;
    }
    return todoOk;
}

int pelicula_getId(eMovie* this,int* id)
{
    int todoOk = 0;
    if(this!=NULL && id != NULL)
    {
        *id = this->id_peli;
        todoOk= 1;
    }
    return todoOk;
}

int pelicula_setTitulo(eMovie* this,char* titulo)
{
    int todoOk = 0;
    if(this!=NULL && titulo != NULL && strlen(titulo) > 3)
    {
        strcpy(this->titulo, titulo);
        todoOk=1;
    }
    return todoOk;
}

int pelicula_getTitulo(eMovie* this,char* titulo)
{
    int todoOk = 0;
    if(this!=NULL && titulo != NULL)
    {
        strcpy(titulo, this->titulo);
        todoOk= 1;
    }
    return todoOk;
}

int pelicula_setGenero(eMovie* this,char* genero)
{
    int todoOk = 0;
    if(this!=NULL && genero != NULL && strlen(genero) > 3)
    {
        strcpy(this->genero, genero);
        todoOk=1;
    }
    return todoOk;
}

int pelicula_getGenero(eMovie* this,char* genero)
{
    int todoOk = 0;
    if(this!=NULL && genero != NULL)
    {
        strcpy(genero, this->genero);
        todoOk= 1;
    }
    return todoOk;
}

int pelicula_setRating(eMovie* this,float rating)
{
    int todoOk = 0;
    if(this!=NULL && rating > 0)
    {
        this->rating = rating;
        todoOk= 1;
    }
    return todoOk;
}

int pelicula_getRating(eMovie* this,float* rating)
{
    int todoOk = 0;
    if(this!=NULL && rating != NULL)
    {
        *rating = this->rating;
        todoOk= 1;
    }
    return todoOk;
}



eMovie* newMovie()
{
    eMovie* nuevaPelicula = (eMovie*) malloc(sizeof(eMovie));
    if(nuevaPelicula!=NULL)
    {
        nuevaPelicula->id_peli = 0;
        strcpy(nuevaPelicula->titulo, "Titulo pelicula");
        strcpy(nuevaPelicula->genero, "sin genero");
        nuevaPelicula->rating = 0;
    }
    return nuevaPelicula;
}


eMovie* newMovieParam(int id, char* titulo, char* genero, float rating)
{
    eMovie* nuevaPelicula = newMovie();
    if(nuevaPelicula!=NULL)
    {
        if(!(pelicula_setId(nuevaPelicula, id)
        && pelicula_setTitulo(nuevaPelicula, titulo)
        && pelicula_setGenero(nuevaPelicula, genero)
        && pelicula_setRating(nuevaPelicula, rating)))
        {
            free(nuevaPelicula);
            nuevaPelicula = NULL;
        }
    }
    return nuevaPelicula;
}
