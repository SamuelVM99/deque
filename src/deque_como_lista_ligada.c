#include "deque_como_lista_ligada.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

ListaDupla* criarLista(ListaDupla* list){
    list = (ListaDupla*) malloc(sizeof(ListaDupla));

    list->tamanho = 0;
    list->primeiro = NULL;
    list->ultimo = NULL;

    return list;
}

void addInicio(ListaDupla* list, int valor) {
    if (list == NULL) {
        list = criarLista(list); // é uma nova lista e atribui valor a ele
    }
   
    // Criado novo item na steack e atribui os valores
    ObjInterno* ptrNovoElemento = (ObjInterno*) malloc(sizeof(ObjInterno));
    ptrNovoElemento->dado = valor;
    ptrNovoElemento->anterior = NULL;
    ptrNovoElemento->proximo = NULL;

    // Verifica se o primeiro item da lista é nula, 
    if (list->primeiro == NULL)
    {
        // atribui o novo elemente no inicio e no fim da cabeça
        list->primeiro = ptrNovoElemento;
        list->ultimo = ptrNovoElemento;
    }
    else // o primeiro item da lista não é nula entao ja possui itens
    {
        // pega o proximo do novo elemente e atribui valor para o primeiro elemento da lista
        ptrNovoElemento->proximo = list->primeiro;
        
        // pega o primeiro item da lista e atribui valor ao item anterior do primeiro item da lista e atribui o valor do novo elemene
        list->primeiro->anterior = ptrNovoElemento;

        // e pega o primeiro item da cabeça e atriui ao novo elemente
        list->primeiro = ptrNovoElemento;
    }

    list->tamanho++;
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

    /*
    /Declara o primeiro objeto que será utilizado no loop de impressão
    ObjInterno objAtual = *list->primeiro;

    for (int i = 0; i < list->tamanho; i++) {
        printf("Dado do objeto na posicao %d: %d\n", i+1, objAtual.dado);

         Após imprimir o valor é utilizado a mesma variável para guardar o próximo
        objeto que será impresso na próxima iteração 
        
        if(objAtual.proximo == NULL) {
            break;
        }
        objAtual = *objAtual.proximo;
    }
    */
    
    ObjInterno* ptr_no_atual = list->primeiro;
     printf("Lista Cabeça -> \n");
     int count = 0;
     while (ptr_no_atual != NULL) {
        count++;
        printf("    [%d] valor -> %d \n", count, ptr_no_atual->dado);
        ptr_no_atual = ptr_no_atual->proximo;
    }
    printf(" NULL \n"); 
    //Caso tudo tenha dado certo retorna 1, que não será utilizado para nada.
    return 1;
}

void imprimeObjeto(ObjInterno* objeto) {
    printf("Dado: %d\n", objeto->dado);
    printf("Próximo objeto: %p\n", objeto->proximo);
    printf("Objeto anterior: %p\n", objeto->anterior);
}