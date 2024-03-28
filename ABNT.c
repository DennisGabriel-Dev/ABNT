#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main(){
    char nome[100];
    char format_name[100] = {""};
    char nome_final[100] = {""};
    char last_name[20] = {""};
    int next_name;
    int last_position, index = 0 ,count_spaces = 0;
    int i;

    printf("Digite seu nome: ");
    scanf("%[^\n]%*c",&nome);
    for ( i = 0; i < strlen(nome); i++)
    {
        if(nome[i] == ' '){
            last_position = i;
        }
        if(isupper(nome[i])){
            format_name[strlen(format_name)] = nome[i];
        }
    }
    
    // FORMATA ÚLTIMO NOME
    for (i = last_position; i < strlen(nome); i++)
    {
        last_name[i - last_position] = toupper(nome[i]);
        if(strlen(nome) - i == 1){
            last_name[i - last_position + 1] = ' ';
        }
    }

    for (i = 0; i < strlen(nome); i++){
        if((strlen(nome_final) < i)){
            nome_final[strlen(nome_final) + 1] = '.';
            nome_final[strlen(nome_final)] = format_name[i - index];
        }else{
            nome_final[strlen(nome_final)] = last_name[strlen(nome_final)];
            index += 1;
        }
    }

    char finish_string[50] = {0};
    for (i = 0; i < strlen(nome_final) - 2; i++)
    {
        finish_string[i] = nome_final[i];
    }
    

    printf("%s",finish_string);
    
}