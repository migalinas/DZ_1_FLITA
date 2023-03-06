#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    void* elements[MAX_SIZE];
    int size;
    size_t element_size;
} Set;

void initSet(Set* set, size_t element_size) {
    set->size = 0;
    set->element_size = element_size;
}

bool contains(Set* set, void* element) {
    for (int i = 0; i < set->size; i++) {
        if (memcmp(set->elements[i], element, set->element_size) == 0) {
            return true;
        }
    }
    return false;
}

void addElement(Set* set, void* element) {
    if (set->size < MAX_SIZE) {
        if (!contains(set, element)) {
            set->elements[set->size] = malloc(set->element_size);
            memcpy(set->elements[set->size], element, set->element_size);
            set->size++;
        }
    }
}

void removeElement(Set* set, void* element) {
    for (int i = 0; i < set->size; i++) {
        if (memcmp(set->elements[i], element, set->element_size) == 0) {
            free(set->elements[i]);
            for (int j = i; j < set->size - 1; j++) {
                set->elements[j] = set->elements[j + 1];
            }
            set->size--;
            break;
        }
    }
}

void printSet(Set* set, void (*print_element)(void*)) {
    printf("{ ");
    for (int i = 0; i < set->size; i++) {
        print_element(set->elements[i]);
        printf(" ");
    }
    printf("}\n");
}

void printInt(void* element) {
    printf("%d", *((int*)element));
}

void printChar(void* element) {
    printf("%c", *((char*)element));
}

void printString(void* element) {
    printf("%s", (char*)element);
}

int main() {
    Set set1, set2;
    int int_element;
    char char_element;
    char string_element[100];
    initSet(&set1, sizeof(int));
    initSet(&set2, sizeof(char));
    int choice;
    do {
        printf("1. Add element to set 1 (integer)\n");
        printf("2. Add element to set 2 (integer)\n");
        printf("3. Add element to set 1 (character)\n");
        printf("4. Add element to set 2 (character)\n");
        printf("5. Remove element from set 1 (integer)\n");
        printf("6. Remove element from set 2 (integer)\n");
        printf("7. Remove element from set 1 (character)\n");
        printf("8. Remove element from set 2 (character)\n");
        printf("9. Print set 1 (integer)\n");
        printf("10. Print set 2 (integer)\n");
        printf("11. Print set 1 (character)\n");
        printf("12. Print set 2 (character)\n");
        printf("13. Add element to set 1 (string)\n");
        printf("14. Add element to set 2 (string)\n");
        printf("15. Remove element from set 1 (string)\n");
        printf("16. Remove element from set 2 (string)\n");
        printf("17. Print set 1 (string)\n");
        printf("18. Print set 2 (string)\n");
        printf("19. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter an integer to add to set 1: ");
            scanf("%d", &int_element);
            addElement(&set1, &int_element);
            break;
        case 2:
            printf("Enter an integer to add to set 2: ");
            scanf("%d", &int_element);
            addElement(&set2, &int_element);
            break;
        case 3:
            printf("Enter a character to add to set 1: ");
            scanf(" %c", &char_element);
            addElement(&set1, &char_element);
            break;
        case 4:
            printf("Enter a character to add to set 2: ");
            scanf(" %c", &char_element);
            addElement(&set2, &char_element);
            break;
        case 5:
            printf("Enter an integer to remove from set 1: ");
            scanf("%d", &int_element);
            removeElement(&set1, &int_element);
            break;
        case 6:
            printf("Enter an integer to remove from set 2: ");
            scanf("%d", &int_element);
            removeElement(&set2, &int_element);
            break;
        case 7:
            printf("Enter a character to remove from set 1: ");
            scanf(" %c", &char_element);
            removeElement(&set1, &char_element);
            break;
        case 8:
            printf("Enter a character to remove from set 2: ");
            scanf(" %c", &char_element);
            removeElement(&set2, &char_element);
            break;
        case 9:
            printf("Set 1: ");
            printSet(&set1, &printInt);
            break;
        case 10:
            printf("Set 2: ");
            printSet(&set2, &printInt);
            break;
        case 11:
            printf("Set 1: ");
            printSet(&set1, &printChar);
            break;
        case 12:
            printf("Set 2: ");
            printSet(&set2, &printChar);
            break;
        case 13:
            printf("Enter a string to add to set 1: ");
            scanf("%s", string_element);
            addElement(&set1, string_element);
            break;
        case 14:
            printf("Enter a string to add to set 2: ");
            scanf("%s", string_element);
            addElement(&set2, string_element);
            break;
        case 15:
            printf("Enter a string to remove from set 1: ");
            scanf("%s", string_element);
            removeElement(&set1, string_element);
            break;
        case 16:
            printf("Enter a string to remove from set 2: ");
            scanf("%s", string_element);
            removeElement(&set2, string_element);
            break;
        case 17:
            printf("Set 1: ");
            printSet(&set1, &printString);
            break;
        case 18:
            printf("Set 2: ");
            printSet(&set2, &printString);
            break;
        case 19:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
        printf("\n");
    } while (choice != 19);
    return 0;
