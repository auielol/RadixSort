#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

int menu();
int getSelection(int select);
void createList();
void display();
void displayList();
void radixSort();
int maxDig();
int findDig();


bool search(int key);
