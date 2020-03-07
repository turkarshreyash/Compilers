#include"linkedlist.h"

node* insert(node* head, char *define){
    node* temp = (node*)malloc(sizeof(node));
    analys_define(temp,define);
    temp->next = head;
    return temp;
}

node* search(node *head, char *expression){
    node *temp = head;
    while(temp != NULL && strcmp(temp->expression,expression)){
        temp = temp->next;
    }
    return temp; 
}

void analys_define(node *head, char* define){
    uint16_t i = 7;
    uint16_t temp,temp2;
    while(define[i] == ' '){
        i++;
    }
    uint8_t inside_bracket = 0;
    printf("/*Marco Name: ");
    temp = 0;
    head->expression = (char*)malloc(sizeof(char)*255);
    while(define[i] != ' ' && define[i] != '('){
        printf("%c",define[i]);
        head->expression[temp] = define[i];
        temp++;
        i++;
    }
    head->expression[temp] = '\0';
    if(define[i] == '('){
        temp = i;
        uint16_t arg_count = 1;
        //count number of parameters count "," + 1
        temp++;
        while(define[temp] != ')'){
            if(define[temp] == ','){
                arg_count++;
            }
            temp++;
        }
        head->argc = arg_count;
        head->args = (char**)malloc(sizeof(char*));

        temp = 0;
        printf("\nParameters (%d) :",arg_count);
        while(define[i] != ')'){
            printf(" ");
            i++;
            while(define[i] == ' '){
                i++;
            }
            head->args[temp] = (char*)malloc(sizeof(char)*255);
            temp2 = 0;
            while (define[i] != ' ' && define[i] != ',' && define[i] != ')'){
                head->args[temp][temp2] = define[i];
                printf("%c",define[i]);
                temp2++;
                i++;
            }
            head->args[temp][temp2] = '\0';
            temp++;
        }
    }
    printf("\n");
    i++;
    while(define[i] == ' '){
        i++;
    }
    printf("Expansion: ");
    head->expansion = (char*)malloc(sizeof(char)*255);
    temp = 0;
    while(define[i] != '\0' && define[i]){
        printf("%c",define[i]);
        head->expansion[temp] = define[i];
        temp++;
        i++;
    }
    head->expansion[temp] = '\0';

    
    printf("*/\n");
}

void display(node *temp){
    printf("-----------------------------------------------------------------------\n");
    printf("Expression = %s\n",temp->expression);
    printf("Expansion = %s\n",temp->expansion);
    printf("Arg_count = %d\n",temp->argc);
    for(int i = 0 ; i < temp->argc ; i++){
        printf("(Arg %d) %s\n",i+1,temp->args[i]);
    }
    printf("-----------------------------------------------------------------------\n");
}