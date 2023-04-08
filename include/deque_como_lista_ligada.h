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

/// @brief Cria uma lista vazia.
/// @param lista
/// @return ListaDupla*
ListaDupla* criarLista(ListaDupla* list);

/// @brief Adiciona um objeto ao início de dada lista.
/// @param lista
/// @param valor do objeto à ser adicionado
void addInicio(ListaDupla* list, int valor);

/// @brief Adiciona um objeto ao final de dada lista.
/// @param lista
/// @param valor do objeto à ser adicionado
void addFinal(ListaDupla* list, int valor);

/// @brief Remove o primeiro objeto de dada lista.
/// @param lista
void removeInicio(ListaDupla* list);

/// @brief Remove o último objeto de dada lista.
/// @param lista
void removeFinal(ListaDupla* list);

/// @brief Imprime e retorna o primeiro objeto de dada lista.
/// @param lista
/// @return Primeiro ObjInterno* da lista
ObjInterno* buscaPrimeiro(ListaDupla* list);

/// @brief Imprime e retorna o último objeto de dada lista.
/// @param lista
/// @return Ultimo ObjInterno* da lista
ObjInterno* buscaUltimo(ListaDupla* list);

/// @brief Organiza dada lista de forma ascendente. O fator de organização é o atributo dado(int) do objeto da lista.
/// @param lista a ser organizada
int organizaAscendente(ListaDupla* list);

/// @brief Organiza dada lista de forma descendente. O fator de organização é o atributo dado(int) do objeto da lista.
/// @param lista a ser organizada
void OrganizaDescendente(ListaDupla* list);

/// @brief  Imprime os dados de todos os objetos de uma lista.
/// @param lista a ser impressa
int imprimeLista(ListaDupla* list);

/// @brief Imprime dado objeto de uma lista.
/// @param objeto interno de uma lista
void imprimeObjeto(ObjInterno* objeto);