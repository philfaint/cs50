#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int n;
    struct node* next;
} node;

int   length (node* head);
node* build  (void);
void  push   (node** head, int n);
int   pop    (node** head);
void  insert (node** head, int index, int n);
int   count  (node* head, int n);
int   getnth (node* head, int nth);
void  delete (node** head);

int main(void){
    node* list = build();

    for(node* ptr = list; ptr != NULL; ptr = ptr->next){
        printf("%i\n", ptr->n);
    }

    int k = length(list);
    printf("the length is %i\n", k);
    printf("figure 2 appears %i times in the list\n", count(list, 2));

    int m = getnth(list, 5);
    printf("0 element is %i\n", m);

    int a = pop(&list);
    int b = pop(&list);
    int c = pop(&list);
    int len = length(list);
    printf("%i %i %i %i\n", a ,b, c, len);

    delete(&list);
    return 0;
}

// builds a linked list using a push function to create a node
node* build(void){
    node* list = NULL;
    int a = 0, b = 0, c = 0;
    scanf("%i %i %i", &a, &b, &c);

    //push(&list, a);
    //push(&list, b);
    //push(&list, c);

    insert(&list, 0, a);
    insert(&list, 1, b);
    insert(&list, 1, c);

    return list;
}

// creates a node using malloc and pushes it in the front of the linked list
void push(node** head, int n){
    node* ptr = malloc(sizeof(node));
    ptr->n = n;
    ptr->next = *head;
    *head = ptr;
}

// deletes the first node from the linked list
int pop (node** head){
    int k = (*head)->n;

    node* ptr = (*head)->next;
    free(*head);
    *head = ptr;

    return k;
}

void  insert (node** head, int index, int n){
    node* current = *head;
    if(index == 0){
        push(head, n);
    }
    else{
        for(int i = 0; i<index-1; i++){
            current = current->next;
        }
        push((&current->next), n);
    }
}

// counts the amount of nodes in the list
int length(node* head){
    int count = 0;
    while(head!=NULL){
        count++;
        head = head->next;
    }
    return count;
}

// counts how many times n repeats in the linked list
int count(node* head, int n){
    int c = 0;

    for(node* ptr = head; ptr!= NULL; ptr = ptr->next){
        if(ptr->n == n){
            c++;
        }
    }
    return c;
}

// returns the nth element from the linked list
int getnth(node* head, int nth){
    int current = 0;

    for(node* ptr = head; ptr != NULL; ptr = ptr->next){
        if(current == nth){
            return ptr->n;
        }
        else{
            current++;
        }
    }
    return 0;
}

// deletes the entire linked list
void delete(node** head){
    node* ptr = *head;
    while(ptr!=NULL){
        node* ptrnext = ptr->next;
        free(ptr);
        ptr= ptrnext;
    }
}