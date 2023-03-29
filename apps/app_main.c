#include "deque_como_lista_ligada.h"
#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#include <locale.h>

int main() { 
    
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
    ObjInterno obj;
    ObjInterno obj2;
    ObjInterno obj3;

    ObjInterno* p = &obj;
    ObjInterno* p2 = &obj2;
    ObjInterno* p3 = &obj3;

    //Popula os objetos
    obj.dado = 10;
    obj2.dado = 20;
    obj3.dado = 30;

    obj.proximo = p2;
    obj.anterior = p3;

    obj2.anterior = p;
    obj2.proximo = p3;

    obj3.proximo = p;
    obj3.anterior = p2;

    //Instância a lista e popula ela com o tamanho, primeiro objeto e último objeto.
    ListaDupla listaInicial = {3, p, p3};
    ListaDupla* list = &listaInicial;

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

        /* Valida se o input do usuário é um input válido
            Caso não seja, é impresso uma mensagem e esse loop é ingorado 
            seguindo para um novo loop e uma nova escolha do usuário */
        if(escolha < 0 || escolha > 9) {
            printf("\nOpção inválida, tente novamente!\n\n");
            continue;
        }

        //Switch case que será utilizado para definir qual função executar, baseado na opção do usuário.
        switch (escolha) {
        case FINALIZAR_PROGRAMA:
            finalizar = true;
            printf("\nFinalizando o programa!\n");
            break;

        case ADICIONAR_INICIO:
            //addInicio();
            break;

        case 2:
            //addFinal();
            break;

        case 3:
            //removeInicio();
            break;

        case 4:
            //removeFinal();
            break;

        case 5:
            buscaPrimeiro(list);
            break;

        case 6:
            buscaUltimo(list);
            break;

        case 7:
            //organizaAscendente();
            break;

        case 8:
            //OrganizaDescendente();
            break;

        case 9:
            imprimeLista(list);
            break;
        }
    }
        free(list);
        return 0;
}