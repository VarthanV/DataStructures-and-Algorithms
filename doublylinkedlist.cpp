#include <iostream>
using namespace std;
struct Node
{

    int data;
    Node *next;
    Node *prev;
};

void push(Node **head, int item);
void insertAfter(Node **prev_node, int item);
void append(Node **head, int item);

Node *head;
int main()
{
    push(&head, 22);

    return 0;
}
// ! Insert in head ..
void push(Node **head, int item)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = item;
    newNode->prev = NULL;
    newNode->next = *head;

    if( *head != NULL){
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insertAfter(Node **prev_node, int item){

}

