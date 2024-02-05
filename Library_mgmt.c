// LIBRARY MANAGEMENT SYSTEM
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BOOKS 100

int book_count = 0;

// Book structure
struct book {
    char title[50];
    char author_name[30];
    int id;  
};

// Adding book function
void add_book(struct book Book[]) {
    int n;
    printf("\nEnter number of books to be added: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        if(book_count < MAX_BOOKS) {
            printf("\nEnter following details ->\n");
            printf("\t\nTitle of book: ");
            scanf(" %[^\n]", Book[book_count].title);

            printf("\t\nAuthor: ");
            scanf(" %[^\n]", Book[book_count].author_name);

            Book[book_count].id = book_count + 1;
            book_count++;

            printf("\nBook added successfully...\n");
        }
        else {
            printf("\n ! Maximum number of books reached...\n");
        }
    }
}

// Displaying book function
void display_books(struct book Book[]) {
    printf("\nLIBRARY CATALOG...\n");
    printf("+----+----------------------+---------------+\n");
    printf("| ID |        Title         |    Author     |\n");
    printf("+----+----------------------+---------------+\n");

    for (int i = 0; i < book_count; i++) {
        printf("| %-2d | %-20.20s | %-13.13s |\n", Book[i].id, Book[i].title, Book[i].author_name); 
          // for tab width
    }

    printf("+----+----------------------+---------------+\n");
}

// Search book function (binary search)
// Sorting is already done, due to unique ids
// Search using first letter, author name.
void search_by_first_letter(struct book Book[], char firstLetter) {
    printf("\nSearch results for books starting with '%c':\n", firstLetter);
    printf("+----+----------------------+---------------+\n");
    printf("| ID |        Title         |    Author     |\n");
    printf("+----+----------------------+---------------+\n");

    for (int i = 0; i < book_count; i++) {
        if (Book[i].title[0] == firstLetter || Book[i].title[0] == firstLetter + 32) {
            // Case-insensitive search
            printf("| %-2d | %-20.20s | %-13.13s |\n", Book[i].id, Book[i].title, Book[i].author_name);
        }
    }

    printf("+----+----------------------+---------------+\n");
}

// Search by author first name
void search_by_author_first_name(struct book Book[], char firstName[]) {
    printf("\nSearch results for books by author's first name '%s':\n", firstName);
    printf("+----+----------------------+---------------+\n");
    printf("| ID |        Title         |    Author     |\n");
    printf("+----+----------------------+---------------+\n");

    for (int i = 0; i < book_count; i++) {
        // Extracting the first name of the author
        char authorFirstName[30];
        sscanf(Book[i].author_name, "%s", authorFirstName);

        if (strcmp(authorFirstName, firstName) == 0) {
            printf("| %-2d | %-20.20s | %-13.13s |\n", Book[i].id, Book[i].title, Book[i].author_name);
        }
    }

    printf("+----+----------------------+---------------+\n");
}

// Delete book function (by ID)
void delete_book(struct book Book[]) {
display_books(Book);
    // Displaying the catalog to see the IDs of books
    int deleteID;
    printf("\nEnter the ID of the book to delete: ");
    scanf("%d", &deleteID);

    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (Book[i].id == deleteID) {
            // Shifting the remaining books to fill the gap
            for (int j = i; j < book_count - 1; j++) {
                Book[j] = Book[j + 1];
            }
            book_count--;
            found = 1;
            printf("\nBook with ID %d deleted successfully.\n", deleteID);

            // Renumbering the IDs
            for (int j = i; j < book_count; j++) {
                Book[j].id = j + 1;
            }

            break;
        }
    }


    if (!found) {
        printf("\nBook with ID %d not found.\n", deleteID);
    }
}

int main() {
    struct book Book[MAX_BOOKS];

    int choice;
    do {
        printf("       SELECT OPTION        \n");
        printf("+--------------------------+\n");
        printf("| 1. Add book              |\n");
        printf("| 2. Display books         |\n");
        printf("| 3. Search book           |\n");
        printf("| 4. Delete book           |\n");
        printf("| 5. Exit...               |\n");
        printf("+--------------------------+\n");

        printf("\nEnter choice = ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book(Book);
                break;

            case 2:
                display_books(Book);
                break;

            case 3:
                {
                    int search_choice;
                    printf("           SEARCH BY           \n");
                    printf("+-----------------------------+\n");
                    printf("| 1. Search by first letter   |\n");
                    printf("| 2. Search by Author         |\n");
                    printf("+-----------------------------+\n");

                    printf("Enter search choice : ");
                    scanf("%d", &search_choice);

                    switch (search_choice) {
                        case 1:
                            {
                                char first_letter;
                                printf("\nEnter first letter to search for: ");
                                scanf(" %c", &first_letter);
                                search_by_first_letter(Book, first_letter);
                            }
                            break;

                        case 2:
                            {
                                char searchFirstName[30];
                                printf("\nEnter the author's first name to search for: ");
                                scanf(" %[^\n]", searchFirstName);
                                search_by_author_first_name(Book, searchFirstName);
                            }
                            break;

                        default:
                            printf("\nInvalid choice...");
                            break;
                    }
                }
                break;

            case 4:
            delete_book(Book);
            break;

            case 5:
            printf("\nBye...");
            break;

            default:
            printf("\nINVALID CHOICE...");
            break;
        }
    } while (choice != 5);

    return 0;
}
