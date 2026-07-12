#include <stdio.h>
#include <stdlib.h>

typedef struct Tlist {
    int value;
    struct Tlist* next;
} Tlist;

Tlist* create_head(int value);
void add_node(Tlist* head, int value);
void print_list (Tlist* head);
Tlist* reverse(Tlist* head);
void free_list (Tlist* head);

int main() {
    Tlist* head=create_head(3);
    if (head==NULL) {
        printf("Memory error");
        return 1;
    }
    for (int i=4; i<16; i+=3) {
        add_node(head, i);
    }
    // add_node(head, 6);
    // add_node(head, 8);
    // add_node(head, 10);
    print_list(head);
    printf("\n");
    head=reverse(head);
    printf("\n");
    print_list(head);
    free_list(head);
    return 0;
}

Tlist* reverse(Tlist* head) {

    Tlist* prev=NULL;
    Tlist* current=head;
    Tlist* neighbour=NULL;

    while (current!=NULL) {
        printf("%d ",current->value);
        neighbour=current->next;
        current->next=prev;
        prev=current;
        current=neighbour;
    }
    return prev;
}

Tlist* create_head(int value) {
    Tlist* head = calloc(1,sizeof(Tlist));
    if (head==NULL) {
        printf("Memory error");
        return NULL;
    }
    head->value=value;
    head->next=NULL;
    return head;
}

void add_node(Tlist* head, int value) {
    if (head==NULL) return;
    Tlist* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next=calloc(1,sizeof(Tlist));
    if (current->next==NULL) {
        printf("Memory error");
        return;
    }
    current->next->value=value;
    current->next->next=NULL;

}

void free_list (Tlist* head) {
    Tlist* temp=head;
    while (head!=NULL) {
        temp=head->next;
        free(head);
        head=temp;
    }
}
void print_list (Tlist* head) {
    Tlist* current=head;
    while (current!=NULL) {
        printf("%d -->> ",current->value);
        current=current->next;
    }
}
