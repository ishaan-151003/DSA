#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Book {
    char title[100];
    char author[100];
    char publication[100];
    float price;
};
int main() {
    int numBooks;
    char searchAuthor[100];
    printf("Enter the number of books: ");
    scanf("%d", &numBooks);
    struct Book *books = (struct Book*)malloc(numBooks * sizeof(struct Book));
    for (int i = 0; i < numBooks; i++) {
        printf("Book %d:\n", i + 1);
        printf("Title: ");
        scanf("%s", books[i].title);
        printf("Author: ");
        scanf("%s", books[i].author);
        printf("Publication: ");
        scanf("%s", books[i].publication);
        printf("Price: ");
        scanf("%f", &books[i].price);
    }
    printf("Enter the particular author: ");
    scanf("%s", searchAuthor);
    int found = 0;
    printf("Output:\n");
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].author, searchAuthor) == 0) {
            printf("%s, %s, %.2f\n", books[i].title, books[i].publication, books[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("No books found for author: %s\n", searchAuthor);
    }
    free(books);
    return 0;
}