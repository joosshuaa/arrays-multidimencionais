#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EQUIPES 2
#define ALUNOS 6
#define MAX_NOME 30 // Definido o tamanho máximo do nome do aluno


struct Aluno {
    char nome[30];
    char sexo;
    float nota;
};

void acrescentarPonto(struct Aluno equipe[][ALUNOS], int equipeAtual) {
    for(int i = 0; i < ALUNOS; i++) {
        if(equipe[equipeAtual][i].sexo == 'F') {
            equipe[equipeAtual][i].nota += 1.0;
        }
    }
}

void adicionarAluno(struct Aluno equipe[][ALUNOS], int equipeAtual) {
    for(int i = 0; i < ALUNOS; i++) {
        if(equipe[equipeAtual][i].nota == -1) {
            printf("Digite o nome do novo aluno: ");
            scanf("%s", equipe[equipeAtual][i].nome);
            printf("Digite o sexo do novo aluno (M ou F): ");
            scanf(" %c", &equipe[equipeAtual][i].sexo);
            printf("Digite a nota do novo aluno: ");
            scanf("%f", &equipe[equipeAtual][i].nota);
            break;
        }
    }
}

int main() {
    struct Aluno equipe[EQUIPES][ALUNOS] = {0};
    // -1 indica que o aluno não tem nota atribuída ainda
    for(int i = 0; i < EQUIPES; i++) {
        for(int j = 0; j < ALUNOS; j++) {
            equipe[i][j].nota = -1;
        }
    }

    // Atribuindo valores para as estruturas
    char nomes[EQUIPES][ALUNOS][30] = {
        {"Alice", "Bruno", "Carla", "Daniel", "Eduardo", "Fernanda"},
        {"Gabriela", "Henrique", "Isabela", "João", "Paulo", "Leonardo"}
    };
    char sexo[EQUIPES][ALUNOS] = {
        {'F', 'M', 'F', 'M', 'M', 'F'},
        {'F', 'M', 'F', 'M', 'M', 'M'}
    };
    float notas[EQUIPES][ALUNOS] = {
        {9.5, 8.0, 7.5, 6.0, 5.5, 7.0},
        {6.5, 8.5, 7.0, 8.0, 9.0, 6.0}
    };

    // Copiando valores das matrizes para as estruturas
    for(int i = 0; i < EQUIPES; i++) {
        for(int j = 0; j < ALUNOS; j++) {
            struct Aluno aluno = {
                .nota = notas[i][j],
                .sexo = sexo[i][j]
            };
            strcpy(aluno.nome, nomes[i][j]);
            equipe[i][j] = aluno;
        }
    }

    //Determinando qual equipe tem a maior quantidade de mulheres
    int mulheresEquipe1 = 0, mulheresEquipe2 = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < ALUNOS; j++) {
            if(equipe[i][j].sexo == 'F') {
                if(i == 0) {
                     mulheresEquipe1++;
                } else {
                    mulheresEquipe2++;
                }
            }
        }
    }
    printf("Equipe com mais mulheres: ");
    if(mulheresEquipe1 > mulheresEquipe2) {
        printf("Equipe 1\n");
    } else if(mulheresEquipe2 > mulheresEquipe1) {
        printf("Equipe 2\n");
    } else {
        printf("Empate\n");
    }
    // d) Criando uma nova estrutura com alunas que atendem as condições do projeto
    struct AlunaProjeto {
        char nome[MAX_NOME];
    };
    struct AlunaProjeto alunasProjeto[ALUNOS*2];
    int count = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < ALUNOS; j++) {
            if(equipe[i][j].sexo == 'F' && equipe[i][j].nota >= 8.0) {
                strcpy(alunasProjeto[count].nome, equipe[i][j].nome);
                count++;
            }
        }
    }

    // e) Imprimindo nomes das alunas que podem participar do projeto
    printf("Alunas que podem participar do projeto:\n");
    for(int i = 0; i < count; i++) {
        printf("%s\n", alunasProjeto[i].nome);
    }   
    return 0;
}
