#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 50

// Structure to store product details
typedef struct {
    int productID;
    char productName[50];
    int quantity;
    float price;
} Product;

// Function prototypes
void addProduct(Product inventory[], int *numProducts);
void displayProducts(Product inventory[], int numProducts);
void updateStock(Product inventory[], int numProducts);
void removeProduct(Product inventory[], int *numProducts);

int main() {
    Product inventory[MAX_PRODUCTS];
    int numProducts = 0; // Keeps track of the number of products in the inventory
    int choice;

    do {
        // Display menu options
        printf("\nInventory Management System\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Update Stock\n");
        printf("4. Remove Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(inventory, &numProducts);
                break;
            case 2:
                displayProducts(inventory, numProducts);
                break;
            case 3:
                updateStock(inventory, numProducts);
                break;
            case 4:
                removeProduct(inventory, &numProducts);
                break;
            case 5:
                printf("Exiting the system...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add a new product to the inventory
void addProduct(Product inventory[], int *numProducts) {
    if (*numProducts < MAX_PRODUCTS) {
        Product newProduct;
        printf("Enter product ID: ");
        scanf("%d", &newProduct.productID);
        getchar();  // To consume the newline character
        printf("Enter product name: ");
        fgets(newProduct.productName, 50, stdin);
        newProduct.productName[strcspn(newProduct.productName, "\n")] = '\0'; // Remove newline
        printf("Enter product quantity: ");
        scanf("%d", &newProduct.quantity);
        printf("Enter product price: ");
        scanf("%f", &newProduct.price);

        inventory[*numProducts] = newProduct;
        (*numProducts)++;
        printf("Product added successfully!\n");
    } else {
        printf("Inventory is full! Cannot add more products.\n");
    }
}

// Function to display all products in the inventory
void displayProducts(Product inventory[], int numProducts) {
    if (numProducts == 0) {
        printf("No products in the inventory.\n");
    } else {
        printf("\nProduct Inventory:\n");
        printf("ID\tName\t\tQuantity\tPrice\n");
        for (int i = 0; i < numProducts; i++) {
            printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].productID, inventory[i].productName, inventory[i].quantity, inventory[i].price);
        }
    }
}

// Function to update the stock of an existing product
void updateStock(Product inventory[], int numProducts) {
    int productID, newQuantity;
    printf("Enter product ID to update: ");
    scanf("%d", &productID);

    int found = 0;
    for (int i = 0; i < numProducts; i++) {
        if (inventory[i].productID == productID) {
            found = 1;
            printf("Enter new quantity for %s: ", inventory[i].productName);
            scanf("%d", &newQuantity);
            inventory[i].quantity = newQuantity;
            printf("Stock updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Product ID not found.\n");
    }
}

// Function to remove a product from the inventory
void removeProduct(Product inventory[], int *numProducts) {
    int productID;
    printf("Enter product ID to remove: ");
    scanf("%d", &productID);

    int found = 0;
    for (int i = 0; i < *numProducts; i++) {
        if (inventory[i].productID == productID) {
            found = 1;
            // Shift products to fill the removed product's position
            for (int j = i; j < *numProducts - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*numProducts)--;
            printf("Product removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Product ID not found.\n");
    }
}
