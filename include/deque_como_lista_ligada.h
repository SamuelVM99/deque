#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h> 

typedef struct obj_interno_lista ObjInterno;

typedef struct lista_dupla ListaDupla;

typedef struct obj_interno_lista {
    int dado;
    ObjInterno* proximo;
    ObjInterno* anterior;
} ObjInterno;

typedef struct lista_dupla {
    int tamanho;
    ObjInterno* primeiro;
    ObjInterno* ultimo;
} ListaDupla ;

//Cria uma lista vazia.
ListaDupla* criarLista(ListaDupla* list);

/// @brief Adiciona um objeto ao inicio de dada lista
/// @param list lista principal
/// @param valor valor a ser inserido
void addInicio(ListaDupla* list, int valor);

//Adiciona um objeto ao final de dada lista.
void addFinal(ListaDupla* list, int tamanho);

//Remove o primeiro objeto de dada lista.
void removeInicio(ListaDupla* list, int tamanho);

//Remove o último objeto de dada lista.
void removeFinal(ListaDupla* list, int tamanho);

//Imprime e retorna o primeiro objeto de dada lista.
ObjInterno* buscaPrimeiro(ListaDupla* list);

//Imprime e retorna o último objeto de dada lista.
ObjInterno* buscaUltimo(ListaDupla* list);

/* Organiza dada lista de forma ascendente.
    O fator de organização é o atributo dado(int) do objeto da lista. */
void organizaAscendente(ListaDupla* list);

/* Organiza dada lista de forma descendente.
    O fator de organização é o atributo dado(int) do objeto da lista.*/
void OrganizaDescendente(ListaDupla* list);

//Imprime os dados de todos os objetos de uma lista.
int imprimeLista(ListaDupla* list);

//Imprime dado objeto de uma lista.
void imprimeObjeto(ObjInterno* objeto);