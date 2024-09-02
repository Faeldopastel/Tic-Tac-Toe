#include<stdio.h>
#include<string.h>

void tab(char tab[3][3]){
    for(int i = 0; i<3; i++){
        for(int k = 0; k < 3; k++){
            tab[i][k] = ' ';
        };
    };
}

void imp_tab(char tabu[3][3]){
    printf(" %c | %c | %c\n", tabu[0][0], tabu[0][1],tabu[0][2]);
    for(int i = 0; i<3; i++){
        if(i == 2){
            printf("---");
        }else{
            printf("---|");
        }
    };
    puts(" ");
    printf(" %c | %c | %c \n", tabu[1][0], tabu[1][1],tabu[1][2]);
    for(int i = 0; i<3; i++){
       if(i == 2){
            printf("---");
        }else{
            printf("---|");
        };
    };
    puts(" ");
    printf( " %c | %c | %c\n", tabu[2][0], tabu[2][1],tabu[2][2]);

}

void jogada(char jg, int l, int c, char tabu[3][3], int *erro){
    
    if(tabu[l][c] == ' '){
        tabu[l][c] = jg;
    }else{
        printf("A posicao ja esta ocupada");
        *erro = 1;
    };

}

void vi_h(char tabu[3][3], int *end){


    for(int i = 0; i <3; i++){
        int equis = 0, bola = 0;
        for(int k = 0; k < 3; k++){
            if(tabu[i][k] == 'X'){
                equis++;
            }else if(tabu[i][k] == 'O'){
                bola++;
            };

            if(equis == 3){
                *end = 1;
            } else if(bola == 3){
                *end = 2;
            }
        }
    }

}

void vi_v(char tabu[3][3], int *end){
    
    for(int i = 0; i < 3; i++){
        int equis = 0, bola = 0;
        for(int k = 0; k < 3; k++){

            if(tabu[k][i] == 'X'){
            equis++;
            }
            else if(tabu[k][i] == 'O'){
            bola++;
            };

            if(equis == 3){
                *end = 1;
            } else if(bola == 3){
                *end = 2;
            };

        };
        
    };

}

void vi_d(char tabu[3][3], int *end){
    int bola = 0, equis = 0;

     for(int i = 0; i < 3; i++){
        for(int k = 0; k < 3; k++){
            if(((i + k) == 2) && tabu[i][k] == 'X'){
                equis++;
            }else if(((i + k) == 2)  && tabu[i][k] == 'O'){
                bola++;
            };

            if(equis == 3){
                *end = 1;
            } else if(bola == 3){
                *end = 2;
            };

        };

    };

    bola = equis = 0;
    for(int i = 0; i < 3; i++){
        for(int k = 0; k < 3; k++){
            if((i == k) && tabu[i][k] == 'X'){
                equis++;
            }else if((i == k)  && tabu[i][k] == 'O'){
                bola++;
            };

            if(equis == 3){
                *end = 1;
            } else if(bola == 3){
                *end = 2;
            };

        };

    };
}


int main(){

    char tabu[3][3];
    int l, c, end = 0, erro = 0, jgds = 0;
    char jg1[1], jg2[1];

    printf("Selecione X ou O: ");
    scanf("%s", jg1);

    while(strcmp(jg1, "X") != 0 && strcmp(jg1, "O") != 0){
        printf("Digite uma letra Valida");
        fflush(stdin);
        scanf("%s", jg1);

    };
    
    if(strcmp(jg1, "X") == 0){
        printf("Jogador 1 = X\n Jogador 2 = O\n ");
        jg2[0] = 'O';

        tab(tabu);

        while(end == 0){

            printf("jogador 1, Digite a posicao que voce quer: Formato linha [0 - 2]; Coluna [0 - 2]: ");
            scanf("%d %d", &l, &c);

            while((l < 0 || l > 2) || (c < 0 || c > 2)){
                printf("posicao invalida, Digite novamente: linha [0 - 2]; Coluna [0 - 2]: ");
                scanf("%d %d", &l, &c);
            };

            jogada('X', l, c, tabu, &erro);
            puts(" ");
            imp_tab(tabu);

            while(erro != 0){
                printf("jogador 1, Digite a posicao que voce quer novamente: linha [0 - 2]; Coluna [0 - 2]: ");
                scanf("%d %d", &l, &c);
                erro = 0;
                jogada('X', l, c, tabu, &erro);
                puts(" ");
                imp_tab(tabu);
            };

            vi_h(tabu, &end);
            vi_v(tabu, &end);
            vi_d(tabu, &end);
            jgds++;

            printf("jogador 2, Digite a posicao que voce quer: linha [0 - 2]; Coluna [0 - 2]: ");
            scanf("%d %d", &l, &c);
            jogada('O', l, c, tabu, &erro);
            puts(" ");
            imp_tab(tabu);

            while((l < 0 || l > 2) || (c < 0 || c > 2)){
                printf("posicao invalida, Digite novamente: linha [0 - 2]; Coluna [0 - 2]: ");
                scanf("%d %d", &l, &c);
            };

            while(erro != 0){
                printf("jogador 2, Digite a posicao que voce quer novamente: linha [0 - 2]; Coluna [0 - 2]: ");
                scanf("%d %d", &l, &c);
                erro = 0;
                jogada('O', l, c, tabu, &erro);
                puts(" ");
                imp_tab(tabu);
            };

            vi_h(tabu, &end);
            vi_v(tabu, &end);
            vi_d(tabu, &end);
            printf("%d", end);
            jgds++;

            if (jgds == 9)
            {
                end = 3;
            }
            

        };

    }
    else{
        printf("Jogador 1 = O\n Jogador 2 = X ");
        jg2[0] = 'X';

        tab(tabu);
        while(end == 0){

            printf("jogador 1, Digite a posicao que voce quer: Formato linha [0 - 2]; Coluna [0 - 2]: ");
            scanf("%d %d", &l, &c);

            while((l < 0 || l > 2) || (c < 0 || c > 2)){
                printf("posicao invalida, Digite novamente: linha [0 - 2]; Coluna [0 - 2]: ");
                scanf("%d %d", &l, &c);
            };

            jogada('O', l, c, tabu, &erro);
            puts(" ");
            imp_tab(tabu);

            while(erro != 0){
                printf("jogador 1, Digite a posicao que voce quer novamente: linha [0 - 2]; Coluna [0 - 2]: ");
                scanf("%d %d", &l, &c);
                erro = 0;
                jogada('O', l, c, tabu, &erro);
                puts(" ");
                imp_tab(tabu);
            };

            vi_h(tabu, &end);
            vi_v(tabu, &end);
            vi_d(tabu, &end);
            jgds++;

            printf("jogador 2, Digite a posicao que voce quer: linha [0 - 2]; Coluna [0 - 2]: ");
            scanf("%d %d", &l, &c);
            jogada('X', l, c, tabu, &erro);
            puts(" ");
            imp_tab(tabu);

            while((l < 0 || l > 2) || (c < 0 || c > 2)){
                printf("posicao invalida, Digite novamente: linha [0 - 2]; Coluna [0 - 2]: ");
                scanf("%d %d", &l, &c);
            };

            while(erro != 0){
                printf("jogador 2, Digite a posicao que voce quer novamente: linha [0 - 2]; Coluna [0 - 2]: ");
                scanf("%d %d", &l, &c);
                erro = 0;
                jogada('X', l, c, tabu, &erro);
                puts(" ");
                imp_tab(tabu);
            };

            vi_h(tabu, &end);
            vi_v(tabu, &end);
            vi_d(tabu, &end);
            printf("%d", end);
            jgds++;


            if (jgds == 9)
            {
                end = 3;
            }
            
        };
    };

    if(end == 1){
        printf("X e o vencedor");
    } else if (end == 2)
    {
        printf("O e o vencendor");
    }else{
        printf("velha");
    }

    scanf("%d", &l);
    

    return 0;

}