#include "list.h"

struct price * make_price(char *n, int o, int d) {
    struct price *p = malloc(sizeof(struct price));
    strcpy(p->name, n);
    p->original = o;
    p->discount = d;
    return p;
}

void print_price(struct price *p) {
    if (p) printf("A %s with a %d%% discount at a base price of $%d is $%0.2f.\n", p->name, p->discount, p->original, (p->original - (p->original * (p->discount * .01))));
}

void print_list(struct price *node)  {
    while (node) {
        print_price(node);
        node = (node->next);
    }
}

struct price * insert_front(struct price *node, char *n, int o, int d) {
    struct price *new = make_price(n, o, d);
    new->next = node;
    return new;
}

struct price * free_list(struct price *node) {
    struct price *temp;
    while (node->next) {
        temp = (node->next);
        free(node);
        node = temp;
    }
    temp = (node->next);
    free(node);
    node = temp;
    return node;
}

struct price * remove_node(struct price *node, int o) {
    if (node->original == o) return node->next;
    struct price *temp = node;
    while (temp->next) {
        if ((temp->next)->original == o) {
            temp->next = ((temp->next)->next);
            break;
        }
        else temp = temp->next;
    }
    return node;
}