#include <stdio.h>
#include <string.h>

struct Produto {
    char nome[20];
    int quant;
    float preco;
};

struct Produto prod; //vg

void cadProd();
void visuProd();
void realizarCompra();

int main(){
    int op;
    
    prod.quant=0;
    prod.preco=0.0;
    
    do {
        printf("\033[36m");
        printf("\n ----- Supermercado SuperMais ----- \n");
        printf("\033[0m");
        
        printf("1. Cadastrar produto\n");
        printf("2. Visualizar produto\n");
        printf("3. Realizar compra\n");
        printf("0. Sair\n");
        printf(" ");
        scanf("%d", &op);
        
        switch(op){
            case 1:
              cadProd();
              break;
            case 2:
              visuProd();
              break;
            case 3:
              realizarCompra();
              break;
            case 0:
              printf("\nSaindo. . .\n");
              break;
            default:
              printf("\nOpção invalida.\n");
              break;
        }
        
        printf("\nEnter para continuar.\n");
        getchar();
        getchar();
        system("clear");
        
    } while(op!= 0);
    
    return 0;
}


void cadProd(){
    printf("Nome do produto: ");
    scanf(" %[^\n]",prod.nome);
    printf("Quantidade: ");
    scanf("%d",&prod.quant);
    printf("Preço: ");
    scanf("%f",&prod.preco);
    printf("Produto cadastrado com sucesso.\n");
}

void visuProd(){
    printf("\033[36m");
    printf("\n --- Informações do produto --- \n");
    printf("\033[0m");
    
    printf("Nome: %s\n",prod.nome);
    printf("Quantidade em estoque: %d\n",prod.quant);
    printf("Preço: $%.2f reais\n",prod.preco);
}

void realizarCompra(){
    int qtdc;
    printf("Quantidade a ser comprada: ");
    scanf("%d", &qtdc);
    
    if(qtdc<=prod.quant){
        prod.quant-=qtdc;
        printf("Compra realizada.\n");
    } 
    else{
        printf("Quantidade insuficiente.\n");
    }
}


