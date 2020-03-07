#include"stack.h"


stack_node* push_stack(stack_node* head, node* map_head, char *define){
    uint16_t i = 0;
    char *expression = (char*)malloc(sizeof(char)*255);
    while(define[i] != ' ' && define[i] != '\0'){
        expression[i] = define[i];
        i++;
    }
    expression[i] = '\0';
    node *temp = search(map_head,expression);
    if(head == NULL && temp == NULL){
        printf("%s",define);
        return NULL;
    }
    if(temp == NULL){
        head->args[head->next_args_fill] = (char*)malloc(sizeof(char)*255);
        strcpy(head->args[head->next_args_fill],expression);
        head->next_args_fill++;
        return head;
    }
    if(temp->argc == 0){
        printf("%s",temp->expansion);
        return head;
    }
    
    stack_node *new_node = (stack_node*)malloc(sizeof(stack_node));
    new_node->expansion_pointer = temp;
    
    new_node->args = (char**)malloc(sizeof(char*)*temp->argc);
    new_node->next_args_fill = 0;
    new_node->next = head;
    // if(head != NULL){
    //     printf("Current Head : %s\n",head->expansion_pointer->expression);
    // }else{
    //     printf("Empty\n");
    // }
    
    // printf("Pushing : %s\n",new_node->expansion_pointer->expression);
    //printf("Push %s no of para : %d",new_node->expansion_pointer->expression,new_node->expansion_pointer->argc);
    return new_node;
}

stack_node* add_args(stack_node* head, char *yytext){
    head->args[head->next_args_fill] = (char*)malloc(255*sizeof(char));
    strcpy(head->args[head->next_args_fill],yytext);
    //Mistake Point
    head->next_args_fill++;
    return head;
}

stack_node* pop_stack(stack_node* head){
    if(head->next == NULL){
       // printf("Poping : %s\n",head->expansion_pointer->expression);
        printf("%s",generate_define(head));
        return NULL;
    }
    head->next->args[head->next->next_args_fill] = generate_define(head);
    char *arr = (char*)malloc(sizeof(char)*255);
    strcpy(head->next->args[head->next->next_args_fill],generate_define(head));
    head->next->next_args_fill++;
    return head->next;
}

int16_t search_parameters(node* define, char *token){
    for(int16_t i = 0 ; i < define->argc ; i++){
        if(strcmp(token,define->args[i]) == 0){
            return i;
        }
    }
    return -1;
}

char* generate_define(stack_node *head){

    char* token = (char*)malloc(sizeof(char)*255);

    char *final_string = (char*)malloc(sizeof(char)*255);
    node* marco = head->expansion_pointer;
    
    uint16_t i = 0, f = 0, t = 0;
   // printf("\nExpansion : %s\n",head->expansion_pointer->expansion);
    while(marco->expansion[i] != '\0' && marco->expansion[i] != '\n'){
        while((marco->expansion[i] != '\0' && marco->expansion[i] != '\n') && !(marco->expansion[i] >= 'A' && marco->expansion[i] <= 'Z') && !(marco->expansion[i] >= 'a' && marco->expansion[i] <= 'z') && !((marco->expansion[i] >= '0' && marco->expansion[i] <= '9') && marco->expansion[i] != '_')){
            final_string[f] = marco->expansion[i];
            //printf("%c\n",marco->expansion[i]);
            i++;
            f++;
        }
        final_string[f] = '\0';
        t = 0;
        while((marco->expansion[i] >= 'A' && marco->expansion[i] <= 'Z') || (marco->expansion[i] >= 'a' && marco->expansion[i] <= 'z') || (marco->expansion[i] >= '0' && marco->expansion[i] <= '9') || marco->expansion[i] == '_'){
            token[t] = marco->expansion[i];
            //printf("%c\n",marco->expansion[i]);
            i++;
            t++;
        }
        token[t] = '\0';
        int16_t p = search_parameters(head->expansion_pointer,token); 
        if(p == -1){
            for(t=0;token[t] != '\0';t++,f++){
                final_string[f] = token[t];
            }
            //printf("%s",token);
        }else{
            for(t = 0;head->args[p][t] != '\0'; t++,f++){
                //printf("%c\n",head->args[p][t]);
                final_string[f] = head->args[p][t];
            }
           // printf("%s",head->args[p]);
        }
    }
    final_string[f] = '\0';
    return final_string;                   
}


