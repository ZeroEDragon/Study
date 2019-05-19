#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    void* data;
    struct Node* next;
}node;

typedef struct List{
    node* head;
}list;

typedef struct AdjancyList{
    unsigned int size;
    list* lists;
}adjancyList;

adjancyList* createAdjancyList(unsigned int size){
    int i;
    adjancyList* newAdjancyList = (adjancyList*)malloc(sizeof(adjancyList));
    newAdjancyList->lists = (list*)malloc(sizeof(list) * size);

    for(i=0;i<size;i++){
        ((newAdjancyList->lists)[i]).head = NULL;
    }

    return newAdjancyList;
}

node* createNode(void* data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void addEdge(adjancyList* adjList, int origin, void* data){
    node* newNode = createNode(data);
    newNode->next = (((adjList->lists)[origin]).head)->next;
    ((adjList->lists)[origin]).head = newNode;
}

int main(){
    void* dest;
    int d = 6;
    dest = (void*)&d;
    adjancyList* adjList = createAdjancyList(5);
    addEdge(adjList, 2, dest);

    return 0;
}
