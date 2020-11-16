//  main.c
//  agendaAcademica
//
//  Created by Mizia Lima, Aline Jardim, Eduardo Henrique Martins.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//MARK: STRUCTS
struct Aluno {
    char nome[30];
    char email[30];
    char codigoIF[10];
};

struct Atividade {
    int status;   //0-Aberto 1-Fechado
    char atividade[1000];  //descrever atividade
};

struct Professor {
    char nome[30];
    char email[30];
    char codigoIF[10];
    struct Atividade listaAtividades[50];
};

//MARK: VARÁVEIS GLOBAIS
struct Professor professores[50] = { };

struct Aluno alunos[50] = { };

int contadorProf = 0, contadorAluno = 0;
int indexProfessorLogado = 0, indexAlunoLogado = 0;
int a, b, c, e, f;
char g;

int controle = 50;

//MARK: FUNÇÕES
void cadastrarAluno() {
    if(contadorAluno <= 49){
        printf("Olá Alunx, preencha seus dados!\n");
        printf("Nome: ");
        fflush(stdin);
        scanf("%[^\n]%*c", alunos[contadorAluno].nome);
        
        printf("E-mail: ");
        fflush(stdin);
        scanf("%[^\n]%*c", alunos[contadorAluno].email);
        
        printf("Códifo IF: ");
        fflush(stdin);
        scanf("%[^\n]%*c", alunos[contadorAluno].codigoIF);
        
        printf("Cadastro realizado com sucesso!\n");
        contadorAluno++;
    }
    else {
        printf("Máximo de alunos cadastrados!\n");
    }
}

void cadastrarProfessor() {
    if(contadorProf <= 49){
        //if verificar se o contadorProfessor no limite
        printf("Olá Professxr, preencha seus dados!\n");
        printf("Nome: ");
        fflush(stdin);
        scanf("%[^\n]%*c", professores[contadorProf].nome);
        
        printf("E-mail: ");
        fflush(stdin);
        scanf("%s", professores[contadorProf].email);
        
        printf("Códifo IF: ");
        fflush(stdin);
        scanf("%[^\n]%*c", professores[contadorProf].codigoIF);
        printf("Cadastro realizado com sucesso!\n");
        contadorProf++;
    } else {
        printf("Máximo de professores cadastrados!\n");
    }
}

void cadastrarUsuario() {
    printf("Opção Cadastrar\n");
    printf("Escolha:    1 - Professor   |    2 - Aluno: ");
    fflush(stdin);
    scanf("%d", &b);
    
    if(b == 1){
        cadastrarProfessor();
    }
    else if (b == 2){
        cadastrarAluno();
    }
    else if (b != 1 || b != 2) {
        printf("Valor inválido.\n");
    }
}

int validarLoginProfessor(char login[]) {
    int index = 0;
    for (index = 0; index < contadorProf; index++) {
        if(strcmp(professores[index].email, login) == 0) {
            indexProfessorLogado = index;
            return 1;
        }
    }
    return 0;
}

int validarLoginAluno(char login[]) {
    int index = 0;
    for (index = 0; index < contadorAluno; index++) {
        if(strcmp(alunos[index].email, login) == 0) {
            indexAlunoLogado = index;
            return 1;
        }
    }
    return 0;
}

void cadastrarNovaAtividade() {
    char h;
    
    printf("Deseja cadastrar uma nova atividade? s - sim | n - nao: ");
    fflush(stdin);
    scanf("%c", &h);
    
    if(h == 's' || h == 'S'){
        printf("Descreva a atividade:\n");
        fflush(stdin);
        scanf("%[^\n]%*c", professores[indexProfessorLogado].listaAtividades[0].atividade);
        professores[indexProfessorLogado].listaAtividades[0].status = 1;
        printf("ponto");
    }
    else {
        printf("Retorne ao menu de professor.\n");
    }
}

void mudarStatusAtividade() {
    //printf("Listar atividades\n");
    //listaatividades;
    //printf("Deseja alterar o status de qual atividade? ")
    //int escolha
}

void listarAtividades(){
    //listarAtividades no array.
}

void menuProfessor(){
    for(int i=0; i<contadorProf; i++){
        printf("Olá professxr!\n");
        printf("-----------------------------------------------------------\n");
        printf("                  MENU OPTIONS PROFESSOR                \n");
        printf("-----------------------------------------------------------\n");
        
        printf("Escolha:   1 - Nova Atividade    |  2 - Mudar Status Atividade (Inativa)  |  3 - Listar Atividades: (Inativa) ");
        fflush(stdin);
        scanf("%d", &e);
        
        switch (e) {
            case 1:
                cadastrarNovaAtividade();
                break;
                
            case 2:
                //mudarStatusAtividade();
                //Salvar em arquivo;
                //Cria arquivo
                break;
                
            case 3:
                //Lista as atividades
                break;
                
            default:
                break;
        }
    }
}

void menuAluno(){
        printf("Olá alunx!\n");
        printf("-----------------------------------------------------------\n");
        printf("                  MENU OPTIONS ALUNO                \n");
        printf("-----------------------------------------------------------\n");
        
        printf("Escolha:   1 - Listar Atividades (Inativa)    |  2 - Verificar Status Atividades (Inativa) ");
        fflush(stdin);
        scanf("%d", &f);
        
        if(f == 1){
            //Listar as atividades salvas;
        }
        else if(f == 2){
            //professor[atividade]
            //Verificar atividades open e close 0 e 1
        }
        else if(f != 1 || f != 2) {
            printf("Comando inválido!\n");
        }
    }

void efetuarLogin() {
    printf("Opção Login\n");
    printf("Escolha:    1 - Professor   |    2 - Aluno: ");
    fflush(stdin);
    scanf("%d", &c);
    
    if(c == 1){
        char email[30];
        printf("Entre com seu e-mail: ");
        fflush(stdin);
        scanf("%[^\n]%*c", email);
        
        if(validarLoginProfessor(email) == 1) {
            printf("Login realizado com sucesso!\n");
            menuProfessor();
            
        } else {
            printf("Login inválido, retorne ao menu e cadastre seu login.\n");
        }
    }
    
    if(c == 2){
        char email[30];
        printf("Entre com seu e-mail: ");
        fflush(stdin);
        scanf("%[^\n]%*c", email);
        
        if(validarLoginAluno(email) == 1) {
            printf("Login realizado com sucesso!\n");
            menuAluno();
            
        } else {
            printf("Login inválido, retorne ao menu e cadastre seu login.\n");
        }
    }
}

//MARK: COMECA O PROGRAMA
int main(){
    printf("-----------------------------------------------------------\n");
    printf(" Seja bem vindx à agenda de notificações acadêmicas do IFSP \n");
    printf("-----------------------------------------------------------\n");
    
    printf("Opções:\n");
    printf("1 - Cadastrar\n");
    printf("2 - Login\n");
    
    printf("Escolha uma opção: ");
    fflush(stdin);
    scanf("%d", &a);
    
    switch (a) {
        case 1:
            cadastrarUsuario();
            
        case 2:
            efetuarLogin();
            
        default:
            printf("Opção inválida!\n");
            break;
        }
    return 0;
}
