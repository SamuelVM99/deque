#include "deque_como_lista_ligada.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

ListaDupla* criarLista(ListaDupla* list){
    list->tamanho = 0;
    list->primeiro = NULL;
    list->ultimo = NULL;

    return list;
}

void addInicio(ListaDupla* list, int tamanho) {

}

void addFinal(ListaDupla* list, int dado) {
    list->tamanho++;
    ObjInterno* ultimoAntigo = list->ultimo;

    ObjInterno* ptrNovo = (ObjInterno*) malloc(sizeof(ObjInterno));
    ptrNovo->dado = dado;
    ptrNovo->anterior = ultimoAntigo;
    ptrNovo->proximo = NULL;

    ultimoAntigo->proximo = ptrNovo;

    list->ultimo = ptrNovo;

}

void removeInicio(ListaDupla* list, int tamanho) {

}

void removeFinal(ListaDupla* list, int tamanho) {

}

ObjInterno* buscaPrimeiro(ListaDupla* list) {
    imprimeObjeto(list->primeiro);
    return list->primeiro;
}

ObjInterno* buscaUltimo(ListaDupla* list) {
    imprimeObjeto(list->ultimo);
    return list->ultimo;
}

void organizaAscendente(ListaDupla* list) {

}

void OrganizaDescendente(ListaDupla* list) {

}

int imprimeLista(ListaDupla* list) {
    /* Valida se o primeiro objeto está nulo, caso esteja será retornado 0, pois não há 
        elementos dentro da lista, será impresso uma mensagem, finalizando assim a função */
    if(list->primeiro == NULL) {
        printf("A lista está vazia!");
        return 0;
    }

    // Declara o primeiro objeto que será utilizado no loop de impressão
    ObjInterno objAtual = *list->primeiro;

    for (int i = 0; i < list->tamanho; i++) {
        printf("Dado do objeto na posicao %d: %d\n", i+1, objAtual.dado);

        /* Após imprimir o valor é utilizado a mesma variável para guardar o próximo
        objeto que será impresso na próxima iteração */
        if(objAtual.proximo == NULL) {
            break;
        }
        objAtual = *objAtual.proximo;
    }
    
    //Caso tudo tenha dado certo retorna 1, que não será utilizado para nada.
    return 1;
}

void imprimeObjeto(ObjInterno* objeto) {
    printf("Dado: %d\n", objeto->dado);
    printf("Próximo objeto: %p\n", objeto->proximo);
    printf("Objeto anterior: %p\n", objeto->anterior);
}