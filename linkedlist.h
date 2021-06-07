#ifndef SINGLE_LINKED_LINKEDLIST_H
#define SINGLE_LINKED_LINKEDLIST_H

#include <stdlib.h>

#define list_create_auto(values) \
    list_create((char*) values, sizeof(*values), (sizeof(values)/sizeof(*values)))

struct list_entry {
    void* value;
    struct list_entry* next;
};

void list_insert(struct list_entry*, int, void*);
void list_remove(struct list_entry*, int);
struct list_entry* list_create(char*, size_t, int);
struct list_entry* list_get_mem_at_indx(struct list_entry*, int);
void* list_get_val_at_index(struct list_entry*, int);
void list_print_all_elements_int(struct list_entry*);

void list_insert(struct list_entry *start, int index, void *value) {
    struct list_entry* prev = list_get_mem_at_indx(start, index - 1);
    struct list_entry* curr = prev->next;

//    struct list_entry* new_val = malloc(sizeof(struct list_entry));
    struct list_entry* new_val = calloc(1, sizeof(struct list_entry));
    new_val->value = value;
    new_val->next = curr;
    prev->next = new_val;
}

struct list_entry* list_get_mem_at_indx(struct list_entry* start, int index) {
    // start[0] is start.value
    // start[1] is start.next.value
    // start[2] is start.next.next.value

    int idx = 0;
    struct list_entry* curr = start;

    while (idx < index) {
        if (curr->next == NULL) {
            printf("out of bounds\n");
            exit(5);
        }

        curr = (curr->next);
        idx++;
    }

    return curr;
}

void* list_get_val_at_index(struct list_entry* start, int index) {
    return list_get_mem_at_indx(start, index)->value;
}

void list_remove(struct list_entry *start, int index) {
    struct list_entry* prev = list_get_mem_at_indx(start, index - 1);
    struct list_entry* curr = prev->next;
    prev->next = curr->next;
}

struct list_entry* list_create(char* values, size_t unit_size, int length) {
    struct list_entry* res = calloc(1, sizeof(struct list_entry));

    // res.value is values[0]
    // res.next.value is values[1]
    // res.next.next.value is values[2]
    res->value = (void*) &values[0];

    int ind = 0;
    struct list_entry* curr = res;
    while (ind < length) {
        curr->value = values[ind * unit_size];

        if (ind + 1 < length) {
            curr->next = calloc(1, sizeof(struct list_entry));
        }

        ind++;
        curr = curr->next;
    }

    return res;
}

void list_print_all_elements_int(struct list_entry* inp) {
    struct list_entry* curr = inp;
    int idx = 0;

    printf("{ ");
    while (curr->next != NULL) {
        printf("%d, ", curr->value);

        curr = curr->next;
        idx++;
    }
    printf("%d }", curr->value);
}

#endif //SINGLE_LINKED_LINKEDLIST_H