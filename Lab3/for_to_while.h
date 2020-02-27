#ifndef FOR_WHILE
#define FOR_WHILE
#include<stdio.h>
#include<stdlib.h>

enum boolean{FALSE,TRUE}; 

typedef struct node{
    enum boolean is_for_loop;
    char *operation;
    struct node *next;
}node;

struct node* push(struct node* head, enum boolean is_for_loop, char *operation);
struct node* top(struct node* head);
struct node* pop(struct node* head);
enum boolean is_empty(node *head);


struct node* replace_init(FILE *yyout,char *arr, int len, struct node* head);
struct node* replace_stop(FILE *yyout,struct node *head);


void replace(FILE *yyout,char *, int);

#endif