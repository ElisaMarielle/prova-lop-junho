#include <stdio.h>

typedef struct{
    char nome[50];
    int idade;
    float nota;
} Aluno;

void listarAlunos();

Aluno alunos [3];

void listarAlunos(){
    for(int i=0;i<3;i++){
        printf("\nAluno %d:\n",i+ 1);
        printf("Nome: %s\n",alunos[i].nome);
        printf("Idade: %d\n",alunos[i].idade);
        printf("Nota: %.2f\n",alunos[i].nota);
    }
}

int main(){
    for(int i=0;i<3;i++){
        printf("\nDigite o nome do aluno %d:\n",i+ 1);
        printf("Nome: ");
        scanf(" %[^\n]",alunos[i].nome);
        printf("Idade: ");
        scanf("%d",&alunos[i].idade);
        printf("Nota: ");
        scanf("%f",&alunos[i].nota);
    }
    
    listarAlunos();
    
    return 0;
}