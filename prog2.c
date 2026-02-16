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

    if (curr->data == data)
    {
        head = curr->next;
        free(curr);
        return;
    }

    while (curr != NULL && curr->data != data)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL)
    {
        printf("Data does not exist\n");
        return;
    }

    prev->next = curr->next;
    free(curr);
}

void delete_from_end()
{
    struct node *curr = head;

    if (head == NULL)
    {
        printf("List does not exist\n");
        return;
    }

    // If only one node
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    // Traverse to second last node
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }

    free(curr->next);
    curr->next = NULL;
}

int main()
{
    insert_at_beginning(1);
    insert_at_beginning(3);
    insert_at_beginning(5);
    insert_at_beginning(6);

    traverse();

    delete_given_data(9);

    delete_from_end();
    traverse();

    return 0;
}
