#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct price {
    char name[100];
    int original;
    int discount;
    struct price *next;
};

struct price * make_price(char *n, int o, int d) {
    struct price *p = malloc(sizeof(struct price));
    strcpy(p->name, n);
    p->original = o;
    p->discount = d;
    return p;
}

void print_price(struct price *p) {
    printf("A %s with a %d%% discount at a base price of $%d is $%0.2f.\n", p->name, p->discount, p->original, (p->original - (p->original * (p->discount * .01))));
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
    while (node->next) {
        free_list(node);
        node = (node->next);
    }
    return node;
}

int main() {
    srand(time(NULL));
    char name[100] = "basketball";
    int original = 30;
    int discount = rand() % 100;

    struct price *item = make_price(name, original, discount);

    char name2[100] = "football";
    int original2 = 20;

    print_list(insert_front(item, name2, original2, discount));
    free_list(item);
    
    return 0;

}