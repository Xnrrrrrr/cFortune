#include <stdio.h>   // Include standard input/output library
#include <stdlib.h>  // Include standard library
#include <string.h>  // Include string manipulation library
#include <time.h>    // Include time library

#define MAX_FORTUNE_LENGTH 100  // Define a constant for the maximum length of a fortune

// ANSI escape codes for text color

#define ANSI_RESET   "\x1B[0m"
#define ANSI_RED     "\x1B[31m"
#define ANSI_GREEN   "\x1B[32m"
#define ANSI_YELLOW  "\x1B[33m"
#define ANSI_BLUE    "\x1B[34m"
#define ANSI_MAGENTA "\x1B[35m"
#define ANSI_CYAN    "\x1B[36m"
#define ANSI_WHITE   "\x1B[37m"

void printMenu() {
    // Function to print the menu
    printf(ANSI_BLUE"--------------------------------------------------\n");
    printf("|        1. Ask a yes/no question                |\n");
    printf("|        2. Get your daily fortune               |\n");
    printf("|        3. Get your lucky numbers               |\n");
    printf("|        4. Add a custom fortune                 |\n");
    printf("|        5. List custom fortunes                 |\n");
    printf("|        6. Quit                                 |\n");
    printf("--------------------------------------------------\n"ANSI_RESET);
}

char* getRandomFortune(char* fortunes[], int size) {
    // Function to get a random fortune from an array of fortunes
    int index = rand() % size;
    return fortunes[index];
}

void listFortunes(char* fortunes[], int size) {
    // Function to list custom fortunes
    if (size == 0) {
        printf("No custom fortunes added yet.\n");
        return;
    }

    printf("Custom Fortunes:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s\n", i + 1, fortunes[i]);
    }
}

int main() {
    srand((unsigned int)time(NULL));  // Seed the random number generator with the current time

    char* yesNoFortunes[] = {
            "Yes, definitely you fucking retard.",
            "No, absolutely not dick face.",
            "It is extremely likely cunt.",
            "I'm not sure, try again later stupid.",
            "Cannot predict now."
    };

    char* dailyFortunes[] = {
            "Today is your lucky day!",
            "Be cautious in your decisions today.",
            "A shitty surprise is waiting for you.",
            "Success is not on the horizon.",
            "Your hard work will never pay off."
    };

    char* luckyNumbersFortunes[] = {
            "Your lucky numbers are: 3, 7, 12, 21, 33, 42",
            "Today's special numbers are: 8, 15, 24, 29, 36, 47",
            "Feeling lucky? Try: 4, 11, 18, 25, 30, 39",
            "Lucky numbers for today: 1, 9, 16, 22, 28, 44",
            "Pick these numbers: 2, 10, 19, 27, 35, 46"
    };

    char* customFortunes[MAX_FORTUNE_LENGTH];
    int customFortunesCount = 0;

    printf(ANSI_BLUE"-----------------------------------------------\n");
    printf("|       Welcome to the Fortune Teller!        |\n");
    printf("|   My name is C, how can I be of service?    |\n");
    printf("-----------------------------------------------\n"ANSI_RESET);

    while (1) {
        printMenu();  // Print the menu

        printf(ANSI_BLUE"Choose an option (1-6): "ANSI_RESET);
        int choice;
        scanf("%d", &choice);
        getchar();  // Consume the newline character

        switch (choice) {
            case 1: {
                printf("Ask a yes/no question: ");
                char question[100];
                fgets(question, sizeof(question), stdin);
                question[strcspn(question, "\n")] = '\0';  // Remove the newline character

                char* yesNoFortune = getRandomFortune(yesNoFortunes, sizeof(yesNoFortunes) / sizeof(yesNoFortunes[0]));
                printf("Answer: %s\n", yesNoFortune);
                break;
            }
            case 2: {
                printf("Enter your name: ");
                char name[50];
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';  // Remove the newline character

                printf("Enter your birth date (MM/DD): ");
                char birthDate[10];
                fgets(birthDate, sizeof(birthDate), stdin);
                birthDate[strcspn(birthDate, "\n")] = '\0';  // Remove the newline character

                char* dailyFortune = getRandomFortune(dailyFortunes, sizeof(dailyFortunes) / sizeof(dailyFortunes[0]));
                printf("%s's Daily Fortune: %s\n", name, dailyFortune);
                break;
            }
            case 3: {
                char* luckyNumbersFortune = getRandomFortune(luckyNumbersFortunes, sizeof(luckyNumbersFortunes) / sizeof(luckyNumbersFortunes[0]));
                printf("Lucky Numbers: %s\n", luckyNumbersFortune);
                break;
            }
            case 4: {
                printf("Enter a custom fortune: ");
                char customFortune[MAX_FORTUNE_LENGTH];
                fgets(customFortune, sizeof(customFortune), stdin);
                customFortune[strcspn(customFortune, "\n")] = '\0';  // Remove the newline character

                customFortunes[customFortunesCount] = strdup(customFortune);
                customFortunesCount++;

                printf("Custom fortune added successfully.\n");
                break;
            }
            case 5:
                listFortunes(customFortunes, customFortunesCount);
                break;
            case 6:
                printf("Exiting the Fortune Teller App. Goodbye!\n");
                for (int i = 0; i < customFortunesCount; i++) {
                    free(customFortunes[i]);
                }
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// control forward slash to comment out code block