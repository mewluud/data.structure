#include <stdio.h>
// 2110213529 MEWLOUD SAGHIR
// a function to add odd numbers to the beginning and even numbers to the end of the list until -1 is entered

int main()
{
    int number;
    int list[100];
    int oddIndex = 0;
    int evenIndex = 99;

    while (1)
    {
        printf("Enter a number (-1 to stop): ");
        scanf("%d", &number);

        if (number == -1)
            break;

        if (number % 2 == 1)
            list[oddIndex++] = number;
        else
            list[evenIndex--] = number;
    }

    for (int i = 0; i < 100; i++)
    {
        if (list[i] != 0)
            printf("%d ", list[i]);
    }

    return 0;
}

// 100 randomly generated numbers and sort them from largest to smallest

int compare(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

int main()
{
    int list[100];

    for (int i = 0; i < 100; i++)
    {
        list[i] = rand() % 1000; // Generate random numbers
    }

    qsort(list, 100, sizeof(int), compare);

    // Print the sorted list
    for (int i = 0; i < 100; i++)
    {
        printf("%d ", list[i]);
    }

    return 0;
}

// a function to store student information, traverse the list, and print student data

struct Student
{
    int studentNumber;
    char name[50];
    int age;
};

struct Node
{
    struct Student student;
    struct Node *next;
};

void printStudents(struct Node *head)
{
    struct Node *current = head;
    int count = 1;

    while (current != NULL)
    {
        printf("%d- %s %d %d\n", count, current->student.name, current->student.age, current->student.studentNumber);
        current = current->next;
        count++;
    }
}

int main()
{
    struct Node *head = NULL;
    struct Node *current;

    for (int i = 1; i <= 5; i++)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->student.studentNumber = 200 + i;
        sprintf(newNode->student.name, "Student%d", i);
        newNode->student.age = 18 + i;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            current = newNode;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }

    printStudents(head);

    return 0;
}

// a function to search for records by student name in the list

struct Node *searchByName(struct Node *head, const char *name)
{
    struct Node *current = head;

    while (current != NULL)
    {
        if (strcmp(current->student.name, name) == 0)
        {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

// a function to delete the next node after the node with the searched student name

void deleteNextNode(struct Node *head, const char *name)
{
    struct Node *current = head;

    while (current != NULL)
    {
        if (strcmp(current->student.name, name) == 0)
        {
            if (current->next != NULL)
            {
                struct Node *temp = current->next;
                current->next = current->next->next;
                free(temp);
                break;
            }
        }
        current = current->next;
    }
}

// a function to find and print the record with the longest name

void printLongestName(struct Node *head)
{
    struct Node *current = head;
    char longestName[50];
    int maxLen = 0;

    while (current != NULL)
    {
        int currentLen = strlen(current->student.name);
        if (currentLen > maxLen)
        {
            maxLen = currentLen;
            strcpy(longestName, current->student.name);
        }
        current = current->next;
    }

    printf("The longest name in the list: %s\n", longestName);
    printf("Length: %d\n", maxLen);
}