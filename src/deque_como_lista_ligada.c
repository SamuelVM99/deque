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
        list = criarLista(list);
    }
   
    list->tamanho++;

    ObjInterno* novoPrimeiroElemento = (ObjInterno*) malloc(sizeof(ObjInterno));
    novoPrimeiroElemento->dado = valor;
    novoPrimeiroElemento->anterior = NULL;
    novoPrimeiroElemento->proximo = NULL;

    ObjInterno* primeiroElementoDaLista = list->primeiro;

    novoPrimeiroElemento->proximo = primeiroElementoDaLista;

    free(novoPrimeiroElemento);
}

void addFinal(ListaDupla* list, int dado) {
    if (list == NULL) {
        list = criarLista(list);
    }

    //Cria e popula o novo objeto
    ObjInterno *ptrNovo = (ObjInterno *)malloc(sizeof(ObjInterno));
    ptrNovo->dado = dado;
    ptrNovo->proximo = NULL;

    if(list->tamanho >= 1) {// Valida se a lista contém pelo menos um objeto para evitar acessos nulos
        ObjInterno* ultimoAntigo = list->ultimo;
        ultimoAntigo->proximo = ptrNovo;
        ptrNovo->anterior = ultimoAntigo;

        list->ultimo = ptrNovo;
    } else {// Caso a lista estivesse vazia o novo objeto é o último e também o primeiro
        ptrNovo->anterior = NULL;
        list->primeiro = ptrNovo;
        list->ultimo = ptrNovo;
    }

    list->tamanho++; 
}

void removeInicio(ListaDupla* list) {
    /* Valida se a lista já não está vazia no momento da chamada.
       caso esteja, a função não é executada e uma mensagem é exibida */
    if(list->tamanho > 0) {

    /* Passada a validação, o tamanho da lista é subtraído e 
        guardamos o objeto a ser removido em uma variável auxiliar */
    list->tamanho--;
    ObjInterno* primeiroAntigo = list->primeiro;

    /* Valida se há mais de um objeto na lista para evitar que o valor "próximo" seja NULL*/
    if(list->tamanho > 1) {
        list->primeiro = primeiroAntigo->proximo;
        list->primeiro->anterior = NULL;
    }

    //Libera a memória do objeto removido
    free(primeiroAntigo);

    printf("\nObjeto removido da lista com sucesso!\n");

    } else {
        printf("\nNão foi possível remover o objeto da lista pois a mesma já está vazia\n");
    }
}

void removeFinal(ListaDupla* list) {

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
    if(list->tamanho == 0 || list == NULL) {
        printf("\nA lista está vazia!\n");
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