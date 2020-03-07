/*
Shreyash H. Turkar
2020
*/

#pragma once 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>


#define DEBUG
#ifdef DEBUG
#define print(A) printf(A);
#endif
#ifndef DEBUG
#define print(A) 
#endif

typedef struct node{
    char *expression;
    char *expansion;
    char **args;
    int argc;
    struct node *next;
}node;

node* insert(node* head, char *define);

node* search(node *head, char* Texpression);

void analys_define(node *input, char *define);

void display(node *temp);