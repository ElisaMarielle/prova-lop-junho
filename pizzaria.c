#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[20];
    float valor;
    int id;
} Pizza;

Pizza pizzas[100];
int numPizza=0;


/////////////////////////////////////////////////////////


typedef struct{
    char nome[20], dtn[10], numtel[20];
    int idade, id;
} Pessoa;

Pessoa cad[100];
int numcadt=0;


/////////////////////////////////////////////////////////

void cadPizza();
void cadCliente();
void listarProd();
void listarCli();
void venderPizza();


int main(){
    int op;
    
    do{
        printf("\033[33m");
        printf("\n --- Pizzaria: Nostra Pizza --- \n");
        printf("\033[0m");
        
        printf("1. Cadastrar produtos.\n");
        printf("2. Cadastrar clientes.\n");
        printf("3. Listar produtos.\n");
        printf("4. Listar clientes.\n");
        printf("5. Vender pizzas.\n");
        printf("0. Sair.\n");
        printf(" ");
        scanf("%d",&op);
        
        switch(op){
            case 1:
              cadPizza();
              break;
            case 2:
              cadCliente();
              break;
            case 3:
              listarProd();
              break;
            case 4:
              listarCli();
              break;
            case 5:
              venderPizza();
              break;
            case 0:
               printf("\nSaindo. . .\n");
               break;
            default:
              printf("\nOpção inválida.\n");
              break;
        }
        
        printf("Enter para continuar.\n");
        getchar();
        getchar();
        system("clear");
        
    }while(op!=0);
    
    return 0;
}

void cadPizza(){
    printf("\n");
    printf("Nome da pizza: ");
    scanf(" %[^\n]",pizzas[numPizza].nome);
    printf("Valor da pizza: ");
    scanf("%f",&pizzas[numPizza].valor);
    pizzas[numPizza].id=numPizza+ 1;
    
    numPizza++;
    
    printf("\nPizza cadastrada com sucesso.\n");
    
}

void cadCliente(){
    printf("\n");
    printf("Nome: ");
    scanf(" %[^\n]",cad[numcadt].nome);
    printf("Idade: ");
    scanf("%d",&cad[numcadt].idade);
    printf("Data de nascimento: ");
    scanf(" %[^\n]",cad[numcadt].dtn);
    printf("Número de telefone: ");
    scanf(" %[^\n]",cad[numcadt].numtel);
    cad[numcadt].id=numcadt+ 1;
    
    numcadt++;
    
    printf("\nCliente cadastrado com sucesso.\n");
}

void listarProd(){
    if(numPizza==0){
        printf("\nNão há nenhum produto cadastrado no momento.\n");
    }
    
    else{
        for(int i=0;i<numPizza;i++){
            printf("\n");
            printf("Nome: %s\n",pizzas[i].nome);
            printf("Preço: %.2f\n",pizzas[i].valor);
            printf("Id: %d\n",pizzas[i].id);
            
            printf("\033[33m");
            printf("\n-----------------------------------\n");
            printf("\033[0m");
            
        }
    }
}

void listarCli(){
    if(numcadt==0){
        printf("\nNão há nenhum cliente cadastrado no momento.\n");
    }
    
    else{
        for(int i=0;i<numcadt;i++){
            printf("\n");
            printf("Nome: %s\n",cad[i].nome);
            printf("Idade: %d\n",cad[i].idade);
            printf("Data de nascimento: %s\n",cad[i].dtn);
            printf("Número de telefone: %s\n",cad[i].numtel);
            printf("Id do cliente: %d\n",cad[i].id);
            
            printf("\033[33m");
            printf("\n-----------------------------------\n");
            printf("\033[0m");
            
        }
    }
}

void venderPizza(){
    int quant, id, np;
    float total=0;
    
    if(numcadt==0){
        printf("Nenhum cliente cadastrado. Não é possível fazer uma venda.\n");
        return;
    }
    
    listarProd();
    
    printf("Qual pizza deseja comprar?: ");
    scanf("%d",&np);
    if(np<1 || np>numPizza){
        printf("Pizza não encontrada.\n");
        return;
    }
    
    printf("Quantas pizzas deseja comprar?: ");
    scanf("%d",&quant);
    total= pizzas[np- 1].valor*quant;
    
    printf("Id do cliente: ");
    scanf("%d",&id);
    
    int i;
    
    if(id<1 || id!=cad[i].id){
        printf("Usário não encontrado, tente novamente.\n");
        return;
    }
    
    printf("\nCompra finalizada.\n");
    printf("Cliente: %s\n", cad[id- 1].nome);
    printf("Pizza: %s\n", pizzas[np- 1].nome);
    printf("Quantidade: %d\n", quant);
    printf("Valor total: R$ %.2f\n", total);
}


