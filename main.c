#include "list.h"

int main() {
    srand(time(NULL));
    char name[100] = "basketball";
    int original = 30;
    int discount = rand() % 100;

    struct price *item = make_price(name, original, discount);

    char name2[100] = "football";
    int original2 = 20;

    struct price *p = insert_front(item, name2, original2, discount);
    print_list(p);
    p = remove_node(p, 20);
    print_list(p);
    print_list(free_list(p));
    
    return 0;

}