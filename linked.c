#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define LIST_EMPTY (-1)
#define LIST_NOT_FOUND (-1)

typedef struct node {
    int val;
    struct node * next;
} node_t;

node_t* list_new(int start_val) {
    node_t* item = (node_t *) malloc(sizeof(node_t));
    item->val = start_val;
    item->next = NULL;
    return item;
}

void list_print(node_t * lst) {
    node_t* current = lst;
    while (current != NULL) {
        printf("%d, ", current->val);
        current = current->next;
    }
    printf("\n\n");
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
    return LIST_EMPTY;
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

int list_count(node_t* lst) {
    int c = 1;
    node_t* current = lst;
    while (current->next != NULL) {
        c++;
        current = current->next;
    }
    return c;
}


int list_at(node_t* lst, int index) {
    int c = 0;
    node_t* current = lst;
    while (current->next != NULL) {
        if (c == index) {
            return current->val;
        }
        
        c++;
        current = current->next;
    }
    return LIST_NOT_FOUND;
}

// Make tomorrow:
int list_remove_at(node_t* lst, int index) {
    int c = 0;
    node_t* current = lst;
    while (current->next != NULL) {
        if (c == index - 1) {
            node_t* to_remove = current->next;
            int removed_val = to_remove->val;
            current->next = to_remove->next;
            free(to_remove); 
            return removed_val; 
        }
        
        c++;
        current = current->next;
    }
    return LIST_NOT_FOUND;
}

int main() {
    node_t * head = list_new(1);
    list_push(head, 4);
    list_push(head, 2);
    list_push(head, 12);

    list_print(head);
    
    int outp = list_pop(head);
    list_print(head);
    printf("Got from pop: %d", outp);
    
    node_t* my_list = list_new(8);
    list_push(my_list, 10); 
    list_push(my_list, 5);
    list_push(my_list, 16);
    
    printf("My_list: \n");
    list_print(my_list);
    
    list_merge(head, my_list);
    list_print(head); 

    int item = list_at(head, 3);
    printf("\nGot: %d\n", item);


    int size = list_count(head);
    printf("\nSize: %d\n", size);

    printf("Before:");
    list_print(head);
    list_remove_at(head, 4);

    printf("After:");
    list_print(head);
    
    free(head);
    free(my_list);
    return 0;
}
