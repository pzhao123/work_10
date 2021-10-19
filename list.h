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

void print_price(struct price *p);

struct price * make_price(char *n, int o, int d);

void print_list(struct price *node);

struct price * insert_front(struct price *node, char *n, int o, int d);

struct price * free_list(struct price *node);

struct price * remove_node(struct price *node, int o);