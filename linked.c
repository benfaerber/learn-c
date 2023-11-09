#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

node_t* list_new(int val) {
    node_t* item = (node_t *) malloc(sizeof(node_t));
    item->val = val;
    item->next = NULL;
    return item;
}

void list_print(node_t * lst) {
    node_t* current = lst;
    while (current != NULL) {
        printf("%d, ", current->val);
        current = current->next;
    }
    printf("\n");
}

void list_push(node_t* lst, int item) {
    node_t* current = lst;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = item;
    current->next->next = NULL;
}


int list_pop(node_t* lst) {
    node_t* current = lst;
    while (current->next != NULL) {
        node_t* pan = current;
        current = current->next; 
        if (current->next == NULL) {
            int last = current->val;
            pan->next = NULL;
            free(current);
            return last;
        }
    }
    return -1;
}

void list_merge(node_t* a, node_t* b) {
    node_t* end_a = a;
    while (end_a->next != NULL) {
        end_a = end_a->next;
    }

    node_t* to_add = b;
    while (to_add->next != NULL) {
        end_a->next = to_add;
        to_add = to_add->next; 
        end_a = end_a->next;
    }
}


int main() {
    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    head->val = 1;
    head->next = (node_t *) malloc(sizeof(node_t));

    head->next->val = 2;
    head->next->next = NULL;
       
    list_push(head, 12);

    list_print(head);
    
    int outp = list_pop(head);
    list_print(head);
    printf("Got from pop: %d", outp);
    
    node_t* my_list = list_new(10);
    list_push(my_list, 5);
    list_push(my_list, 16);
    
    printf("My_list: ");
    list_print(my_list);
    
    list_merge(head, my_list);
    list_print(head); 
    
    free(head);
    return 0;
}
