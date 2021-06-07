#include <stdio.h>
#include "linkedlist.h"

int main() {
    int itms[] = { 10, 15, 5, 20 };
    struct list_entry test = *list_create_auto(itms);
    list_print_all_elements_int(&test);

    printf("\n\n");

    int testing[] = { 9, 4, 7, 6, 2 };
    struct list_entry *new_test = list_create(testing, sizeof(*testing), 5);

    list_insert(new_test, 2, 123);

    list_print_all_elements_int(new_test);
}
