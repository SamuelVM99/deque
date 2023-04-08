#include "deque_como_lista_ligada.h"
#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#include <locale.h>

int main() { 
    //Teste commit Samuel
    //Essa linha faz os acentos e caracteres especiais funcionarem.
    setlocale(LC_ALL,"");

    //Constantes referentes a cada opção que o usuário pode executar.
    #define FINALIZAR_PROGRAMA 0
    #define ADICIONAR_INICIO 1
    #define ADICIONAR_FINAL 2
    #define REMOVER_INICIO 3
    #define REMOVER_FINAL 4
    #define BUSCAR_PRIMEIRO 5
    #define BUSCAR_ULTIMO 6
    #define ORGANIZAR_ASC 7
    #define ORGANIZAR_DESC 8
    #define IMPRIMIR 9

    //Condições que validam se o programa deve continuar sendo executado.
    bool finalizar = false;
    int escolha = 0;

    /* Essa seção do código serve para testes até que todas as funções estejam prontas para que
    possamos testa-las. Se desejar pode utilizar os objetos e a lista abaixo para testes das funções */
    //Instânciamento dos objetos e ponteiros que serão alocados dentro da lista dupla.

    ObjInterno* p = (ObjInterno*) malloc(sizeof(ObjInterno));
    ObjInterno* p2 = (ObjInterno*) malloc(sizeof(ObjInterno));
    ObjInterno* p3 = (ObjInterno*) malloc(sizeof(ObjInterno));

    //Popula os objetos
    p->dado = 30;
    p2->dado = 40;
    p3->dado = 10;

    p->proximo = p2;
    p->anterior = NULL;

    p2->anterior = p;
    p2->proximo = p3;

    p3->anterior = p2;
    p3->proximo = NULL;

    //Instância a lista e popula ela com o tamanho, primeiro objeto e último objeto.
    ListaDupla* list = NULL;
    list = criarLista(list);
    //list->primeiro = p;
    //list->ultimo = p3;
    //list->tamanho = 3;

    //Loop do menu
    while(!finalizar) {
        printf("-------------------SELECIONE A AÇÃO-------------------\n");
        printf("%d para finalizar o programa\n", FINALIZAR_PROGRAMA);
        printf("%d para adicionar um novo objeto ao início da lista\n", ADICIONAR_INICIO);
        printf("%d para adicionar um novo objeto ao final da lista\n", ADICIONAR_FINAL);
        printf("%d para remover um objeto ao início da lista\n", REMOVER_INICIO);
        printf("%d para remover um objeto ao final da lista\n", REMOVER_FINAL);
        printf("%d para buscar um objeto ao início da lista\n", BUSCAR_PRIMEIRO);
        printf("%d para buscar um objeto ao final da lista\n", BUSCAR_ULTIMO);
        printf("%d para organizar a lista de forma ascendente\n", ORGANIZAR_ASC);
        printf("%d para organizar a lista de forma descendente\n", ORGANIZAR_DESC);
        printf("%d para imprimir a lista completa\n", IMPRIMIR);

        //Lê o input do usuario e guarda sua escolha, que será utilizada no switch case
        printf("\nOpção: ");
        scanf("%d", &escolha);
        printf("\n");

        /* Valida se o input do usuário é um input válido
            Caso não seja, é impresso uma mensagem e esse loop é ingorado 
            seguindo para um novo loop e uma nova escolha do usuário */
        if(escolha < 0 || escolha > 9) {
            printf("\nOpção inválida, tente novamente!\n\n");
            continue;
        }


        //Switch case que será utilizado para definir qual função executar, baseado na opção do usuário.
        int valor = 0;
        switch (escolha) {
        case FINALIZAR_PROGRAMA:
            finalizar = true;
            printf("\nFinalizando o programa!\n");
            break;

        case ADICIONAR_INICIO:
            printf("Informe o dado que deseja adicionar\n");
            int dadoNovo;
            scanf("%d", &dadoNovo);
            addInicio(list, dadoNovo);
            break;

        case ADICIONAR_FINAL:
            printf("Informe o dado que deseja adicionar\n");
            scanf("%d", &valor);
            addFinal(list, valor);
            break;

        case REMOVER_INICIO:
            removeInicio(list);
            break;

        case REMOVER_FINAL:
            removeFinal(list);
            break;

        case BUSCAR_PRIMEIRO:
            buscaPrimeiro(list);
            break;

        case BUSCAR_ULTIMO:
            buscaUltimo(list);
            break;

        case ORGANIZAR_ASC:
            organizaAscendente(list);
            break;

        case ORGANIZAR_DESC:
            OrganizaDescendente(list);
            break;

        case IMPRIMIR:
            imprimeLista(list);
            break;
        }
    }
        free(list);
        return 0;
}