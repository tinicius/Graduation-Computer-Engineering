#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
	int info;
	struct Nodo *prox;
};

struct ListaSimplesEnc
{

	struct Nodo *prim;
};

void criarLista(struct ListaSimplesEnc *pList)
{

	pList->prim = NULL;
}

void mostrarLista(struct ListaSimplesEnc *pList)
{

	struct Nodo *p;

	for (p = pList->prim; p != NULL; p = p->prox)
	{

		printf("%d\t", p->info);
	}

	printf("\n");
}

int estaVazia(struct ListaSimplesEnc *pList)
{
	return (pList->prim == NULL);
}

void inserirIni(struct ListaSimplesEnc *pList, int v)
{
	struct Nodo *novo;
	novo = (struct Nodo *)malloc(sizeof(struct Nodo));
	novo->info = v;
	if (estaVazia(pList))
		novo->prox = NULL;
	else
		novo->prox = pList->prim;

	pList->prim = novo;
}

void removerIni(struct ListaSimplesEnc *pList)
{

	struct Nodo *pAux = pList->prim;
	pList->prim = pList->prim->prox;
	free(pAux);
}

void inserirOrd(struct ListaSimplesEnc *pList, int valor)
{

	struct Nodo *p;

	for (p = pList->prim; p != NULL; p = p->prox)
	{

		if (valor >= p->info)
		{

			struct Nodo *aux;
			aux = p->prox;

			if (aux == NULL)
			{
				struct Nodo *novo;
				novo = (struct Nodo *)malloc(sizeof(struct Nodo));

				novo->info = valor;

				if (estaVazia(pList))
				{
					break;
				}
				else
				{
					novo->prox = p->prox;
					p->prox = novo;
				}

				break;
			}

			if (valor <= aux->info)
			{
				struct Nodo *novo;
				novo = (struct Nodo *)malloc(sizeof(struct Nodo));

				novo->info = valor;

				if (estaVazia(pList))
				{
					break;
				}
				else
				{
					novo->prox = p->prox;
					p->prox = novo;
				}

				break;
			}
		}
	}

	printf("\n");
}

void removerDet(struct ListaSimplesEnc *pList, int valor)
{

	struct Nodo *p;

	for (p = pList->prim; p != NULL; p = p->prox)
	{

		struct Nodo *aux;
		aux = p->prox;

		if (valor == aux->info)
		{

			p->prox = aux->prox;
			break;
		}
	}

	printf("\n");
}

void main()
{
	struct ListaSimplesEnc minhaLista;
	int valor, op;

	criarLista(&minhaLista);

	while (1)
	{

		printf("1 - Inserir elemento no inicio\n");
		printf("2 - Inserir elemento em ordem (so se a lista estiver ordenada)\n");
		printf("3 - Remover elemento no inicio\n");
		printf("4 - Remover elemento\n");
		printf("5 - Mostrar lista\n");
		printf("6 - Sair\n");
		printf("Opcao? ");
		scanf("%d", &op);

		switch (op)
		{

		case 1: // inserir elemento no inicio

			printf("Valor? ");
			scanf("%d", &valor);
			inserirIni(&minhaLista, valor);
			break;
		case 2: // inserir elemento ordenado
			printf("Valor? ");
			scanf("%d", &valor);

			inserirOrd(&minhaLista, valor);
			mostrarLista(&minhaLista);
			break;
		case 3: // remover o primeiro
			removerIni(&minhaLista);
			break;
		case 4: // remover determinado elemento
			printf("Valor? ");
			scanf("%d", &valor);
			removerDet(&minhaLista, valor);
			break;
		case 5: //  mostrar lista
			if (estaVazia(&minhaLista))
			{
				printf("Lista vazia");
			}
			else
			{
				mostrarLista(&minhaLista);
			}
			break;
		case 6: // abandonar o programa
			exit(0);
		}
	}
}
