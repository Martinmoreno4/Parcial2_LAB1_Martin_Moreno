#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

typedef struct
{
    int id_peli;
    char titulo[128];
    char genero[128];
    float rating;
}eMovie;


void mostratPelicula(eMovie* movie);

int pelicula_setId(eMovie* this,int id);
int pelicula_getId(eMovie* this,int* id);

int pelicula_setTitulo(eMovie* this,char* titulo);
int pelicula_getTitulo(eMovie* this,char* titulo);

int pelicula_setGenero(eMovie* this,char* genero);
int pelicula_getGenero(eMovie* this,char* genero);

int pelicula_setRating(eMovie* this,float rating);
int pelicula_getRating(eMovie* this,float* rating);

int peliculasOrdenPorRatingYGenero(void* movieA, void* movieB);

eMovie* newMovie();
eMovie* newMovieParam(int id, char* titulo, char* genero, float rating);
#endif // PELICULAS_H_INCLUDED
