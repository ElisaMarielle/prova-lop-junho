#include <stdio.h>
#include <string.h>
//Som & Arte

typedef struct{
    char banda[20];
    int ano, quant, genero;
} Cadastrar;

Cadastrar cd[100];
int numCd=0;

void cadastrarCD();
void listarCD();
void consultarCD();
void vender();

int main(){
    int op;
    
    do{
        printf("\033[34m");
        printf("\n ----- Som & Arte ----- \n");
        printf("\033[0m");
        
        printf("1. Cadastrar CD\n");
        printf("2. Pesquisar CD\n");
        printf("3. Consultar CD\n");
        printf("4. Vender CD\n");
        printf("0. Sair\n");
        printf(" ");
        scanf("%d",&op);
        
        switch(op){
            case 1:
              cadastrarCD();
              break;
            case 2:
              listarCD();
              break;
            case 3:
              consultarCD();
              break;
            case 4:
              vender();
              break;
            case 0:
              printf("\nSaindo. . .\n");
              break;
            default:
              printf("\nOpção inválida.\n");
              break;
        }
        
        printf("\nEnter para continuar.\n");
        getchar();
        getchar();
        system("clear");
        
    }while(op!=0);
    
    return 0;
}

void cadastrarCD(){
    printf("\033[34m");
    printf("\n ----- Cadastrar CD ----- \n");
    printf("\033[0m");
    
    printf("Nome da banda: ");
    scanf(" %[^\n]",cd[numCd].banda);
    printf("Ano de lançamento: ");
    scanf("%d",&cd[numCd].ano);
    printf("Gênero:\n");
    printf("1 - Rock\n2 - Metal\n3 - Pop\n4 - Kpop\n 5 - MPB\n 6 - Eletrônica\n");
    scanf("%d",&cd[numCd].genero);
    printf("Quantidade no estoque: ");
    scanf("%d",&cd[numCd].quant);
    
    printf("\nCadastro completo!\n");
    numCd++;
}

void vender(){
    printf("\033[34m");
    printf("\n ----- Vender CD ----- \n");
    printf("\033[0m");
    
    int q;
    float total;
    
    printf("Quantos CDs deseja vender?: ");
    scanf("%d",&q);
    
    for(int i=0;i<numCd;i++){
        if(q<=cd[i].quant){
            total=q*8.00; //8.00 é o preço fixo de todos os CDs
            printf("Valor final: $%.2f reais",total);
            cd[i].quant-=q;
            return;
        }
    }
}

void listarCD(){
    printf("\033[34m");
    printf("\n ----- Listar CDs ----- \n");
    printf("\033[0m");
    
    int gen, ec=0;
    
    do{
     printf("Você deseja listar os CDs por qual gênero?:\n");
     printf("1. Rock\n");
     printf("2. Metal\n");
     printf("3. Pop\n");
     printf("4. Kpop\n");
     printf("5. MPB\n");
     printf("6. Eletrônica\n");
     printf("0. Sair\n");
     scanf("%d",&gen);
     system("clear");
     
     for(int i=0;i<numCd;i++){
         if(cd[i].genero==gen || gen==0){
             ec=1;
             printf("Banda: %s\n",cd[i].banda);
             printf("Ano: %d\n",cd[i].ano);
             printf("Gênero: ");
             if(cd[i].genero==1) printf("Rock\n");
             else if(cd[i].genero==2) printf("Metal\n");
             else if(cd[i].genero==3) printf("Pop\n");
             else if(cd[i].genero==4) printf("Kpop\n");
             else if(cd[i].genero==5) printf("MPB\n");
             else if(cd[i].genero==6) printf("Eletrônica\n");
             else if(gen==0) break;
             printf("Quantidade: %d\n",cd[i].quant);
             
             printf("\033[34m");
             printf("\n------------------------\n");
             printf("\033[0m");
            }
        }
    }while(gen!=0);
}

void consultarCD(){
    char b[20];
    int ec=0;
    
    printf("Digite o nome da banda para consultar: ");
    scanf(" %[^\n]",b);
    getchar();
    system("clear");
    
    for(int i=0;i<numCd;i++){
         if(strcmp(cd[i].banda, b)==0){
             ec=1;
             printf("Banda: %s\n",cd[i].banda);
             printf("Ano: %d\n",cd[i].ano);
             printf("Gênero: ");
             if(cd[i].genero==1) printf("Rock\n");
             else if(cd[i].genero==2) printf("Metal\n");
             else if(cd[i].genero==3) printf("Pop\n");
             else if(cd[i].genero==4) printf("Kpop\n");
             else if(cd[i].genero==5) printf("MPB\n");
             else if(cd[i].genero==6) printf("Eletrônica\n");
             printf("Quantidade: %d\n",cd[i].quant);
             
             printf("\033[34m");
             printf("\n------------------------\n");
             printf("\033[0m");
            }
        }
        if(!ec){
                printf("CD da banda %s não encontrado.\n",b);
		    }
}



