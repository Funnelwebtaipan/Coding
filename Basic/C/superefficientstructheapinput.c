/*
_____________________________________________________________________

I absolutely love the C programming language, 
how you can control memory allocation to the heap. 

To master C concepts, I want to write programs where information

[*] is only stored once on the heap, 
[*] no copies to be made. 

The following program has been written by ChatGPT to help learn
the concepts. My mission is to understand this program so int he future,
I dont have to reply on ChatGPT.

The following code does:

[*] A single block of memory on the heap
[*] Inside it: the pointer array, structs, strings and ages
[*] All pointers are offsets into that one block
[*] No memory is duplicated
[*] No variables are stored more than once
[*] Program takes inputs from the user

by Funnelwebtaipan
DOHSJ BlackDeath
_____________________________________________________________________

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char *name;
    int *age;

} Person;

#define MAX_NAME_LEN 100

Person **create_people_from_user_input(int count)
{
    // Step 1: Temp input buffers
    char **temp_names = malloc(count * sizeof(char *));
    int   *temp_ages  = malloc(count * sizeof(int));
    size_t total_name_bytes = 0;

    if (!temp_names || !temp_ages) {
        perror("Temporary allocation failed");
        exit(1);
    }

    // Step 2: Collect user input
    for (int i = 0; i < count; i++)
    {
        temp_names[i] = malloc(MAX_NAME_LEN);
        if (!temp_names[i]) {
            perror("Name allocation failed");
            exit(1);
        }

        printf("Enter name for person %d: ", i + 1);
        fgets(temp_names[i], MAX_NAME_LEN, stdin);
        temp_names[i][strcspn(temp_names[i], "\n")] = '\0'; // Strip newline

        printf("Enter age for %s: ", temp_names[i]);
        scanf("%d", &temp_ages[i]);
        getchar(); // consume leftover newline

        total_name_bytes += strlen(temp_names[i]) + 1;  // +1 for null terminator
    }

    // Step 3: Calculate full malloc block size
    size_t ptr_array_size = count * sizeof(Person *);
    size_t structs_size   = count * sizeof(Person);
    size_t age_data_size  = count * sizeof(int);
    size_t total_size     = ptr_array_size + structs_size + total_name_bytes + age_data_size;

    // Step 4: Allocate one block
    void *block = malloc(total_size);
    if (!block) {
        perror("Final heap allocation failed");
        exit(1);
    }

    // Step 5: Slice up the heap block
    void *cursor = block;
    Person **people = (Person **)cursor;
    cursor = (char *)cursor + ptr_array_size;

    Person *structs = (Person *)cursor;
    cursor = (char *)cursor + structs_size;

    char *name_cursor = (char *)cursor;
    cursor = (char *)cursor + total_name_bytes;

    int *age_cursor = (int *)cursor;

    // Step 6: Transfer input data into heap block
    for (int i = 0; i < count; i++)
    {
        people[i] = &structs[i];

        size_t len = strlen(temp_names[i]) + 1;
        memcpy(name_cursor, temp_names[i], len);
        people[i]->name = name_cursor;
        name_cursor += len;

        *age_cursor = temp_ages[i];
        people[i]->age = age_cursor;
        age_cursor++;
    }

    // Step 7: Cleanup temp buffers
    for (int i = 0; i < count; i++) free(temp_names[i]);
    free(temp_names);
    free(temp_ages);

    return people;
}

void print_people(Person **people, int count)
{
    printf("\nHeap-stored People (User Input Mode):\n\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s | Age: %d\n", people[i]->name, *(people[i]->age));
    }
}

void destroy_people(Person **people)
{
    free(people); // Single block free — all data lives in it
}

int main()
{
    int count;

    printf("\n Efficient Single Heap Block Input Demo\n");
    printf("How many people to input? ");
    scanf("%d", &count);
    getchar(); // clear newline

    Person **people = create_people_from_user_input(count);
    print_people(people, count);
    destroy_people(people);

    return 0;
}
