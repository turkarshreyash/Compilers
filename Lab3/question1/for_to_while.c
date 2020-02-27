#include"for_to_while.h"

enum boolean is_empty(struct node *head){
    return head == NULL;
}

struct node* top(struct node* head){
    return head;
}

struct node* push(struct node *head, enum boolean is_for_loop, char *operation){
    struct node* temp = (node*)malloc(sizeof(node));
    temp->operation = (operation==NULL?NULL:operation);
    temp->is_for_loop = is_for_loop;
    temp->next = (head==NULL?NULL:head);
    return temp;
}

struct node* pop(struct node* head){
    if(head == NULL){
        return NULL;
    }
    return head->next;
}


struct node* replace_init(FILE *yyout, char *arr, int len, struct node *head){
    fprintf(yyout,"{");
    //extrac init 
    int i = 0;
    while(arr[i] != '('){i++;}
    i++;

    //i is at next chaRATER after (
    
    //skip white spaces and newlines
    while(arr[i]==' '||arr[i]=='\n'){i++;}
    
    if(arr[i]!=';'){
        while(arr[i]!=';'){
            fprintf(yyout,"%c",arr[i]);
            i++;
        }
        fprintf(yyout,";");
    }
    //i is at ;
    //now i is at next char
    i++;

    //skip white spaces and newlines
    while(arr[i]==' '||arr[i]=='\n'){i++;}
    //all white lines skipped no i can be at ; or a condition

    //print while
    fprintf(yyout,"\nwhile(");

    //condition
    if(arr[i]!=';'){
        while(arr[i]!=';'){
            fprintf(yyout,"%c",arr[i]);
            i++;
        }
        //now i is at ;

    }//no condition simply put 1 infinite loop
    else{
        fprintf(yyout,"1");
    }

    fprintf(yyout,"){");

    //i is at ;
    i++;

    //i is at next char

    //skip white spaces and newlines
    while(arr[i]==' '||arr[i]=='\n'){i++;}
    //all white lines skipped no i can be at ) or a variable manipulation
    
    char *operation = NULL;
    //to store operation
    if(arr[i]!=')'){
        operation = (char*)malloc(24*sizeof(char));
        int j = 0;
        while(arr[i]!=')'){
            if(arr[i] != ' ' && arr[i] != '\n'){
                //printf("S%cE",arr[i]);
                operation[j] = arr[i];
                j++;
            }
            i++;
        }
        operation[j] = '\0';
    }
    //no condition simply put 1 infinite loop
    head = push(head,TRUE,operation);
    return head;
}


struct node* replace_stop(FILE *yyout,struct node *head){
    if(top(head)->is_for_loop == TRUE){
        //printf("FOR POP\n");
        if(top(head)->operation!=NULL){
            fprintf(yyout,"%s;\n",top(head)->operation);
        }
        fprintf(yyout,"}\n"); 
    }
    
    head = pop(head);
    fprintf(yyout,"}\n");
    return head;
}


void replace(FILE *yyout,char *arr, int len){
    int i = 0;
    
    // inside the condition
    while(arr[i] != '('){i++;}
    i++;

    //skip space
    while(arr[i] == ' '){i++;}

    fprintf(yyout,"if(!(");
    //condition
    while(arr[i] != ')'){
        if(arr[i] != ' ' && arr[i] != '\n'){
            fprintf(yyout,"%c",arr[i]);
        }
        i++;
    }
    fprintf(yyout,")){\nbreak;\n}");

    fprintf(yyout,"\n}");

}