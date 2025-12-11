#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure for storing vehicle details
struct Vehicle {
    int id;
    char model[50];
    char type[20];
    float mileage;
};

int main() {
    struct Vehicle fleet[MAX];
    int count = 0;
    int choice;

    while (1) {
        printf("\n====== FLEET MANAGEMENT SYSTEM ======\n");
        printf("1. Add Vehicle\n");
        printf("2. Display All Vehicles\n");
        printf("3. Search Vehicle by ID\n");
        printf("4. Update Vehicle Mileage\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (count >= MAX) {
                printf("Fleet is full!\n");
                continue;
            }
            printf("\nEnter Vehicle ID: ");
            scanf("%d", &fleet[count].id);
            printf("Enter Model: ");
            scanf("%s", fleet[count].model);
            printf("Enter Type (Car/Truck/Bus): ");
            scanf("%s", fleet[count].type);
            printf("Enter Mileage: ");
            scanf("%f", &fleet[count].mileage);

            count++;
            printf("Vehicle added successfully!\n");
        }
        else if (choice == 2) {
            if (count == 0) {
                printf("No vehicles in fleet.\n");
            } else {
                printf("\n---- Fleet Vehicles ----\n");
                for (int i = 0; i < count; i++) {
                    printf("ID: %d | Model: %s | Type: %s | Mileage: %.2f km\n",
                           fleet[i].id, fleet[i].model, fleet[i].type, fleet[i].mileage);
                }
            }
        }
        else if (choice == 3) {
            int searchID, found = 0;
            printf("\nEnter Vehicle ID to search: ");
            scanf("%d", &searchID);

            for (int i = 0; i < count; i++) {
                if (fleet[i].id == searchID) {
                    printf("Vehicle Found!\n");
                    printf("ID: %d | Model: %s | Type: %s | Mileage: %.2f km\n",
                           fleet[i].id, fleet[i].model, fleet[i].type, fleet[i].mileage);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Vehicle not found.\n");
            }
        }
        else if (choice == 4) {
            int updateID, found = 0;
            float newMileage;
            printf("\nEnter Vehicle ID to update mileage: ");
            scanf("%d", &updateID);

            for (int i = 0; i < count; i++) {
                if (fleet[i].id == updateID) {
                    printf("Enter new mileage: ");
                    scanf("%f", &newMileage);
                    fleet[i].mileage = newMileage;
                    printf("Mileage updated successfully!\n");
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Vehicle not found.\n");
            }
        }
        else if (choice == 5) {
            printf("Exiting Fleet Management System...\n");
            break;
        }
        else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
