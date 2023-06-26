#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phone
{
  int ddd;
  int number;
} Phone;

typedef struct birthDate
{
  int day;
  int month;
  int year;
} BirthDate;

typedef struct contact
{
  char name[256];
  char email[256];
  Phone phone;
  BirthDate birthDate;
  char note[512];
} Contact;

Contact readContact()
{

  Contact newContact;

  printf("Digite o nome: ");
  fgets(newContact.name, 256, stdin);

  // printf("Digite o email: ");
  // fgets(newContact.email, 256, stdin);

  // // getchar();

  // printf("Digite o DDD: ");
  // scanf("%d", &newContact.phone.ddd);

  // printf("Digite o Telefone: ");
  // scanf("%d", &newContact.phone.number);

  // printf("Digite o dia de nascimento: ");
  // scanf("%d", &newContact.birthDate.day);

  // printf("Digite o mês de nascimento: ");
  // scanf("%d", &newContact.birthDate.month);

  // printf("Digite o ano de nascimento: ");
  // scanf("%d", &newContact.birthDate.year);

  // getchar();

  // printf("Digite uma observação: ");
  // fgets(newContact.note, 512, stdin);

  return newContact;
}

void printMenu()
{
  printf("[1] Cadastrar contato\n");
  printf("[2] Excluir contato\n");
  printf("[3] Alterar contato\n");
  printf("[4] Pesquisar contato pelo nome\n");
  printf("[5] Imprimir contatos\n");
  printf("[6] Sair\n");
}

void printAllContacts(Contact *contacts, int actual_contacts)
{

  for (int i = 0; i < actual_contacts; i++)
  {
    printf("Nome: %s", contacts[i].name);
  }
}

void addContact(Contact *contacts, int *actual_contacts, int max_contacts)
{

  Contact newContact;
  newContact = readContact();

  if (*actual_contacts <= max_contacts)
  {
    contacts[*actual_contacts] = newContact;
    *actual_contacts = *actual_contacts + 1;
  }
  else
  {
    //[a, b]
    *actual_contacts = *actual_contacts + 1; // 3

    Contact *newArray;
    newArray = (Contact *)malloc(*actual_contacts * sizeof(Contact)); // 3

    for (int i = 0; i < *actual_contacts - 1; i++) // 2
    {
      newArray[i] = contacts[i];
    }

    newArray[*actual_contacts - 1] = newContact;
    printAllContacts(newArray, *actual_contacts);
    contacts = newArray;
  }
}

int main()
{

  int max_contacts;
  int actual_contacts = 0;

  int op;
  // char nome[256];

  printf("Digite o máximo de contatos: ");
  scanf("%d", &max_contacts);

  Contact *contacts;
  contacts = (Contact *)malloc(max_contacts * sizeof(Contact));

  while (1)
  {

    printMenu();
    printf("Digite uma opcao: ");
    scanf("%d", &op);

    getchar();

    switch (op)
    {

    case 1:
      addContact(contacts, &actual_contacts, max_contacts);
      printAllContacts(contacts, actual_contacts);
      break;
    case 2:
      printf("Nome para remover: ");
      // fgets(nome, 256, stdin);

      // remover(&minhaLista, nome);

      // mostrarLista(&minhaLista);
      break;
    case 3:
      printf("Nome para alterar: ");
      // fgets(nome, 256, stdin);

      // alterar(&minhaLista, nome);
      break;
    case 4: // remover determinado elemento
      printf("Nome para buscar: ");
      // fgets(nome, 256, stdin);

      // buscar(&minhaLista, nome);
      break;
    case 5: //  mostrar lista
      // if (estaVazia(&minhaLista))
      // {
      //   printf("Lista vazia");
      // }
      // else
      // {
      //   mostrarLista(&minhaLista);
      // }
      break;
    case 6: // abandonar o programa
      exit(0);
    }
  }

  return 0;
}
