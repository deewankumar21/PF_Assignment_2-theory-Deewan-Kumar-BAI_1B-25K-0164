#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

void AddNewBook(int isbns[100], char titles[100][50], float prices[100],
                int quantities[100], int *bookcount);
void ProcessSale(int isbns[100], char titles[100][50], float prices[100],
                 int quantities[100], int bookcount);
void GenerateLowStockReport(int isbns[100], char titles[100][50], float prices[100],
                            int quantities[100], int bookcount);

int main() {
    int isbns[MAX_BOOKS] = {0};
    char titles[MAX_BOOKS][50] = {{0}};
    float prices[MAX_BOOKS] = {0};
    int quantities[MAX_BOOKS] = {0};
    int choice;
    int bookcount = 0;

    do {
        printf("\n===== Liberty Books Inventory System =====\n");
        printf("1. Add a New Book\n");
        printf("2. Process a Sale\n");
        printf("3. Generate Low-Stock Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                AddNewBook(isbns, titles, prices, quantities, &bookcount);
                break;

            case 2:
                ProcessSale(isbns, titles, prices, quantities, bookcount);
                break;

            case 3:
                GenerateLowStockReport(isbns, titles, prices, quantities, bookcount);
                break;

            case 4:
                printf("Exiting program... Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 4);

    return 0;
}

void AddNewBook(int isbns[100], char titles[100][50], float prices[100],
                int quantities[100], int *bookcount) {

    if (*bookcount >= MAX_BOOKS) {
        printf("Inventory is full! Cannot add more books.\n");
        return;
    }

    int newisbn;
    printf("\nEnter ISBN: ");
    scanf("%d", &newisbn);

    for (int i = 0; i < *bookcount; i++) {
        if (isbns[i] == newisbn) {
            printf("A book with this ISBN already exists!\n");
            return;
        }
    }

    printf("Enter Title: ");
    scanf(" %[^\n]", titles[*bookcount]);

    printf("Enter Quantity: ");
    scanf("%d", &quantities[*bookcount]);

    printf("Enter Price: ");
    scanf("%f", &prices[*bookcount]);

    isbns[*bookcount] = newisbn;

    printf("\nBook Added Successfully!\n");
    printf("ISBN: %d\n", isbns[*bookcount]);
    printf("Title: %s\n", titles[*bookcount]);
    printf("Quantity: %d\n", quantities[*bookcount]);
    printf("Price: Rs. %.2f\n", prices[*bookcount]);

    (*bookcount)++;
}

void ProcessSale(int isbns[100], char titles[100][50], float prices[100],
                 int quantities[100], int bookcount) {

    int isbn, sold, found = 0;

    printf("\nEnter ISBN number: ");
    scanf("%d", &isbn);

    for (int i = 0; i < bookcount; i++) {
        if (isbns[i] == isbn) {
            found = 1;
            printf("Enter number of copies sold: ");
            scanf("%d", &sold);

            if (quantities[i] < sold) {
                printf("Not enough copies in stock!\n");
            } else {
                quantities[i] -= sold;
                printf("%d copies of '%s' (ISBN: %d) sold successfully.\n",
                       sold, titles[i], isbn);
            }
            break;
        }
    }

    if (!found) {
        printf(" Book with ISBN %d not found in inventory.\n", isbn);
    }
}
void GenerateLowStockReport(int isbns[100], char titles[100][50], float prices[100],
                            int quantities[100], int bookcount) {

    printf("\n===== LOW STOCK REPORT (Below 5 Copies) =====\n");
    int found = 0;

    for (int i = 0; i < bookcount; i++) {
        if (quantities[i] < 5) {
            printf("ISBN: %d | Title: %s | Quantity: %d | Price: Rs. %.2f\n",
                   isbns[i], titles[i], quantities[i], prices[i]);
            found = 1;
        }
    }

    if (!found) {
        printf(" All books have sufficient stock!\n");
    }
}
