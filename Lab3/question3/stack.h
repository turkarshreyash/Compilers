/*
Shreyash Turkar
2020
*/

#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"
#include<inttypes.h>

typedef struct stack_node{
    int next_args_fill;
    node *expansion_pointer;
    char **args;
    struct stack_node *next;
}stack_node;


stack_node* push_stack(stack_node* head, node* map_head, char *define);

stack_node* pop_stack(stack_node* head);

char* generate_define(stack_node *head);

stack_node* add_args(stack_node* head, char *yytext);