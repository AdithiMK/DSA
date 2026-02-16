#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_at_beginning(int data)
{
    struct node *newnode = NULL;
    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

void traverse()
{
    struct node *curr = head;

    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void delete_given_data(int data)
{
    struct node *curr = head;
    struct node *prev = NULL;

    if (head == NULL)
    {
        printf("List does not exist\n");
        return;
    }

    // If head node itself holds the data
    if (curr->data == data)
    {
        head = curr->next;
        free(curr);
        return;
    }

    // Search for the node
    while (curr != NULL && curr->data != data)
    {
        prev = curr;
        curr = curr->next;
    }


    if (curr == NULL)
    {
        printf("data does not exist\n");
        return;
    }

    prev->next = curr->next;
    free(curr);
}

int main()
{
    insert_at_beginning(3);
    insert_at_beginning(5);
    insert_at_beginning(7);
    insert_at_beginning(1);
    traverse();
    delete_given_data(9); 

    return 0;
}
