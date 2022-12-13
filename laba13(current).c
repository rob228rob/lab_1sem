#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>


typedef struct {
    char *members;
    int length;
} Set;


Set* init(); // Инициализация множества
bool is_empty(Set *set); // Проверка множества на пустоту
void insert(Set *set, char member); // Ввод данных в множество
void print_set(Set *set); // Печать множества
Set *set_union(Set *setA, Set *setB); // Объединение
Set *set_intersection(Set *setA, Set *setB); // Пересечение
Set *set_difference(Set *setA, Set *setB); // Симметрическая разность
bool is_subset(Set *setA, Set *setB); // проверка на подмножества
bool set_equality(Set *setA, Set *setB); // проверка на эквивалентность
bool in_set(Set *setA, char member);


int main() {
    Set *setA = init();
    insert(setA, 'a');
    insert(setA, 'i');
    insert(setA, 'u');
    insert(setA, 'e');
    insert(setA, 'y');
    print_set(setA);


    FILE *my_file;
    my_file = fopen("NEWwW.txt", "r");

    char n[100];
    fgets(n, 10, my_file);
    int k = atoi(n) ;
    int ans;

    for (int i = 0; i < k; i++) {
        Set *setB = init();

        char line[256];
        fgets(line,256, my_file);
        int len_vow = 0;
        for (int j = 0; j < strlen(line); j++) {
            if (in_set(setA, line[j])) {
                insert(setB, line[j]);
                len_vow += 1;
            }
         }
        if (setB->length != len_vow) {
            ans += 1;
        } else {
        continue;
        }
    }

    printf("%d", ans);

    fclose(my_file);



    return 0;
}

Set* init() {
    Set *new_set = malloc(sizeof(Set));
    new_set->length = 0;
    new_set->members = malloc(sizeof(int));
    return new_set;
}

bool is_empty(Set *set) {
    return (set->length == 0);
}

void insert(Set *set, char member) {
    bool in_set = false;
    for (int i = 0; i < set->length; i++) {
        if (set->members[i] == member)
            in_set = true;
    }
    if (!in_set) {
        set->members =
            realloc(set->members, sizeof(char) * (set->length + 1));
    set->members[set->length] = member;
    set->length = set->length + 1;
    }
}

void print_set(Set *set) {
    for (int i = 0; i < set->length; i++) {
        if (i == (set->length - 1)) {
            printf("%d\n", set->members[i]);
        } else {
            printf("%d,", set->members[i]);
        }
    }
}


Set *set_union(Set *setA, Set *setB) {
    Set *new_set = init();
    for (int i = 0; i < setA->length; i++) {
        insert(new_set, setA->members[i]);
    }
        for (int i = 0; i < setB->length; i++) {
        insert(new_set, setB->members[i]);
    }
    return new_set;
}


Set *set_intersection(Set *setA, Set *setB) {
    Set *new_set = init();

    for (int i = 0; i < setA->length; i++)
        for (int j = 0; j < setB->length; j++)
            if (setA->members[i] == setB->members[j])
                insert(new_set, setA->members[i]);


    return new_set;
}

Set *set_difference(Set *setA, Set *setB) {
    Set *new_set = init();

    for (int i = 0; i < setA->length; i++)
    {
        bool inB = false;

        for (int j = 0; j < setB->length; j++)
            if (setA->members[i] == setB->members[j])
            inB = true;

        if (!inB) insert(new_set, setA->members[i]);
    }
    return new_set;
}

bool is_subset(Set *setA, Set *setB) {

    for (int i = 0; i < setA->length; i++)
    {
        bool inB = false;

        for (int j = 0; j < setB->length; j++)
            if (setA->members[i] == setB->members[j])
            inB = true;

    if (!inB) return false;
    }
    return true;
}

bool set_equality(Set *setA, Set *setB) {

    if (setA->length != setB->length) return false;

    return is_subset(setA, setB);
}


bool in_set(Set *set, char member) {

    bool in_set = false;
    for (int i = 0; i < set->length; i++) {
        if (set->members[i] == member)
            in_set = true;
    }
    return in_set;
}
