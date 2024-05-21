#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define MAX_NAME_LENGTH 10
#define MAX_PHONE_LENGTH 20

typedef struct{
    int nAge;
    char szName[MAX_NAME_LENGTH];
    char szPhone[MAX_PHONE_LENGTH];
}Data;

typedef struct
{
	node *data;
	node* next;
}node;

void appendNode(node* head, node new_data);

void deleteNode(node* head, int nodeNum);

void modifyNode(node* head, node* selectedNode);

#endif