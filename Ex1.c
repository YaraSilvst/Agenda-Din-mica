#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Pessoa{
  int codigo;
  char nome[40];
  char telefone[15];
  char email[50];
  char aniversario[11];
  char anotacoes[100];

  struct Pessoa *proximo;
} Pessoa;

void listar(Pessoa *aux){
  while(aux != NULL){
    printf("Codigo: %i\n", aux->codigo);
    printf("Nome: %s\n", aux->nome);
    printf("Telefone: %s\n", aux->telefone);
    printf("Email: %s\n", aux->email);
    printf("Aniversario: %s\n", aux->aniversario);
    printf("Anotacoes: %s\n", aux->anotacoes);
    printf("\n-----------------\n");
    aux = aux->proximo;
  }
}

int main(void) {

    Pessoa *p = NULL, *aux, *ultimo;
    int op;

    do {
        aux = malloc(sizeof(Pessoa));

        printf("Digite o codigo: ");
        scanf("%i", &aux->codigo);

        printf("Digite o nome: ");
        scanf("%s", aux->nome);

        printf("Digite o telefone: ");
        scanf("%s", aux->telefone);

        printf("Digite o email: ");
        scanf("%s", aux->email);

        printf("Digite o aniversario: ");
        scanf("%s", aux->aniversario);

        printf("Digite anotacoes: ");
        scanf("%s", aux->anotacoes);

        printf("\n-----------------\n");

        aux->proximo = NULL;

        if(p == NULL){
        p = aux;
        ultimo = aux;
        }
        else{
        ultimo->proximo = aux;
        ultimo = aux;
        }

      printf("\nDeseja cadastrar outro contato? 1-Sim | 0-Nao\n");
      scanf("%i", &op);
      printf("\n-----------------\n");

    } while (op>0);

      listar(p);

      return 0;
}