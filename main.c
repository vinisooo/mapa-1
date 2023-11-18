#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

struct Client {
    char cpf[12];
    char name[100];
    int  serviceType;
};

int main() {
    setlocale(LC_ALL, "Portuguese");

    struct Client clients[50];
    int clientsLen = 0;

    menu(clients, &clientsLen);
}

int menu(struct Client clients[], int *clientsLen){
    int serviceNum = 0;

    system("cls");

    printf("Bem-vindo ao sistema de atendimento!\n\n");
    printf("1 - Solicitar Atendimento!\n");
    printf("2 - Listar Atendimentos Registrados!\n");
    printf("3 - Listar atendimento por Setor\n");
    printf("4 - Sair\n");

    while(serviceNum < 1 || serviceNum > 4){
        printf("Digite a opção desejada: \n");
        scanf("%d", &serviceNum);
        fflush(stdin);
    }

    system("cls");

    switch (serviceNum){
        case 1:
            registerService(clients, clientsLen);
            break;
        case 2:
            renderServices(clients, clientsLen);
            break;
        case 3:
            findService(clients, clientsLen);
            break;
        case 4:
            break;
        default:
            menu(clients, clientsLen);
    }


    return 0;
}

int registerService (struct Client clients[], int *clientsLen) {
    struct Client client;

    printf("Insira seu nome:\n");
    gets(client.name);
    fflush(stdin);

    printf("Insira seu CPF:\n");
    gets(client.cpf);
    fflush(stdin);

    printf("Insira o atendimento:\n");
    printf("1 - Abertura de Conta\n");
    printf("2 - Caixa\n");
    printf("3 - Gerente Pessoa Física\n");
    printf("4 - Gerente Pessoa Jurídica\n");

    while(client.serviceType < 1 || client.serviceType > 4){
        scanf("%d", &client.serviceType);
        fflush(stdin);
    }

    clients[*clientsLen] = client;
    (*clientsLen)++;

    printf("Solicitação cadastrada com suceso!\n\n");
    system("pause");
    menu(clients, clientsLen);
    return 0;
}

int renderServices(struct Client clients[], int *clientsLen){
    if(*clientsLen < 0){
        printf("Nenhum serviço foi encontrado");
        return 0;
    }

    int i;
    for(i = 0; i < *clientsLen; i++){
        renderService(clients[i]);
    }

    system("pause");
    menu(clients, clientsLen);
    return 0;
}

int renderService(struct Client client) {
    printf("nome: %s\n", client.name);
    printf("cpf: %s\n", client.cpf);
    printf("serviço: ");
    switch(client.serviceType){
        case 1:
            printf("1 - Abertura de Conta\n");
            break;
        case 2:
            printf("2 - Caixa\n");
            break;
        case 3:
            printf("3 - Gerente Pessoa Física\n");
            break;
        case 4:
            printf("4 - Gerente Pessoa Jurídica\n");
            break;
        default:
            printf("indefinido\n");
    }
    printf("================================\n");

    return 0;
}

int findService(struct Client clients[], int *clientsLen) {
    int serviceNum = 0;
    int i;
    bool found = false;

    printf("1 - Abertura de Conta\n");
    printf("2 - Caixa\n");
    printf("3 - Gerente Pessoa Física\n");
    printf("4 - Gerente Pessoa Jurídica\n");

    while(serviceNum < 1 || serviceNum > 5) {
        printf("Insira o serviço:\n");
        scanf("%d", &serviceNum);
    }

    for(i= 0; i < *clientsLen; i++){
        if(clients[i].serviceType == serviceNum){
            found = true;
            renderService(clients[i]);
        }
    }

    if(!found){
        printf("Nenhum resultado foi encontrado\n");
    }

    system("pause");
    menu(clients, clientsLen);
    return 0;
}
