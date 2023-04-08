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

    imprimeLista(list);
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
    imprimeLista(list); 
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
    if (list->tamanho > 0)
    {   
        ObjInterno* ultimoAntigo = list->ultimo;

        if (list->tamanho > 1)
        {
            list->ultimo = ultimoAntigo->anterior;
            list->ultimo->proximo = NULL;
        }

        if (list->tamanho == 1)
        {
            list->primeiro = NULL;
        }

        free(ultimoAntigo);
        list->tamanho--;

        printf("\nObjeto removido da lista com sucesso!\n");
    }
    else
    {
        printf("\nNão foi possível remover o objeto da lista pois a mesma já está vazia\n");
    }
}

ObjInterno* buscaPrimeiro(ListaDupla* list) {
    imprimeObjeto(list->primeiro);
    return list->primeiro;
}

ObjInterno* buscaUltimo(ListaDupla* list) {
    imprimeObjeto(list->ultimo);
    return list->ultimo;
}

int organizaAscendente(ListaDupla* list) {

    // Valida se a lista é nula, vazia o use tem somente um objeto para evitar uma "organização" inútil
    if(list->tamanho == 0 || list->tamanho == 1 || list == NULL) {
        return 0;
    }

    /* Coloca todos os objetos da lista em um array */
    ObjInterno* array[list->tamanho];
    ObjInterno* aux = NULL;

    array[0] = list->primeiro;
    
    for(int i = 1; i < list->tamanho; i++) {

        if(array[i - 1]->proximo != NULL) {
            array[i] = array[i - 1]->proximo;
        }

    }

    /* Organiza o array do menor para o maior levando em consideração o "dado" dentro dos objetos */

    int trocas = 1;
    while(trocas != 0) {
        trocas = 0;

        for(int i = 0; i < list->tamanho; i++) {

            if(i + 1 < list->tamanho) {

                if(array[i]->dado > array[i + 1]->dado) {
                    trocas++;

                    aux = array[i];

                    array[i] = array[i + 1];
                    array[i + 1] = aux;
                }
            }
        }
    }

    /* Depois de organizado, ajusta os ponteiros de acordo com suas posições no array */
    for(int i = 0; i < list->tamanho; i++) {
        if(i + 1 < list->tamanho) {
            array[i]->proximo = array[i + 1];
        }
    }

    for(int i = list->tamanho -1; i >= 0; i--) {
        if(i - 1 >= 0) {
             array[i]->anterior = array[i - 1];
        }
    }

    /* Define novamente o primeiro e último objeto da lista e garante que seus
       anteriores e próximos sejam nulos para evitar erros */
    list->primeiro = array[0];
    list->ultimo = array[list->tamanho - 1];

    list->primeiro->anterior = NULL;
    list->ultimo->proximo = NULL;

    return 1;
}

void OrganizaDescendente(ListaDupla* list) {
    // Valida se a lista é nula, vazia o use tem somente um objeto para evitar uma "organização" inútil
    if(list->tamanho == 0 || list->tamanho == 1 || list == NULL) {
        return;
    }

    // cria um array de item da lista
    ObjInterno* array[list->tamanho];
    ObjInterno* objAux = NULL;

    // adiciona o primeiro item da lista dentro da primeira posição do array
    array[0] = list->primeiro;

    // percorre a lista colocando todos itens dentro do array de forma não organizada
    for (int i = 0; i < list->tamanho; i++)
    {
        if (array[i-1]->proximo != NULL)
        {
            array[i] = array[i-1]->proximo;
        }
    }
    
    int trocou = 1;
    while (trocou != 0)
    {
        trocou = 0;

        for (int i = 0; i < list->tamanho; i++)
        {
            if (i + 1 < list->tamanho)
            {
                if (array[i]->dado < array[i+1]->dado)
                {
                    trocou++;
                    objAux = array[i];

                    array[i] = array[i+1];
                    array[i+1] = objAux;    
                }
            }
        }
    }

    /* Depois de organizado, ajusta os ponteiros de acordo com suas posições no array */
    for(int i = 0; i < list->tamanho; i++) {
        if(i + 1 < list->tamanho) {
            array[i]->proximo = array[i + 1];
        }
    }

    for(int i = list->tamanho -1; i >= 0; i--) {
        if(i - 1 >= 0) {
            array[i]->anterior = array[i - 1];
        }
    }

    list->primeiro = array[0];
    list->ultimo = array[list->tamanho - 1];

    list->primeiro->anterior = NULL;
    list->ultimo->proximo = NULL;
    
    return;
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