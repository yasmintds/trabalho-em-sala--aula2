#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char descricao[100];
  float valor;
  int quantidade;

} Produto;

void cadastrarProduto(Produto c) {
  printf("\nCadastrar Produto\n");
  printf("descrição: ");
  fgets(c.descricao, sizeof(c.descricao), stdin);
  c.descricao[strcspn(c.descricao, "\n")] = 0;

  printf("Valor:");
  scanf("%f", &c.valor);

  printf("Quantidade: ");
  scanf("%d", &c.quantidade);
  printf("\n");
}

void salvarProduto(Produto c) {
  FILE *arquivo = fopen("produtos.txt", "a");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return;
  }
  fprintf(arquivo, "Descrição: %s, \nValor: %.2f, \nQuantidade:%d.\n\n",
          c.descricao, c.valor, c.quantidade);
  fclose(arquivo);
}

void listarProdutos() {
  FILE *arquivo = fopen("produtos.txt", "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return;
  }
  char linha[70];
  while (fgets(linha, sizeof(linha), arquivo)) {
    printf("%s", linha);
  }
  fclose(arquivo);
}

int main() {

  Produto c;
  int opcao;
  do {
    printf("Menu de opções:\n");
    printf("1 - Cadastrar produtos \n2. Listar produtos\n3. Sair\n Escolha uma "
           "opcao:");
    scanf("%d", &opcao);
    getchar();

    switch (opcao) {
    case 1:
      cadastrarProduto(c);
      salvarProduto(c);
      break;

    case 2:
      printf("\nLista de produtos\n");
      listarProdutos();
      break;

    case 3:
      printf("\nSaindo do programa...\n");
      break;

    default:
      printf("\nOpcao invalida. \n");
      break;
    }

  } while (opcao != 3);

  return 0;
}