//Option 1: Write the complete age population program given in the Pre-lab
//Reading Assignment.
//Statement of the problem:
//Given a list of ages (1 to 100) from the keyboard, the program will tally
//how many people are in each age group.

// Last Modified Date: 4/17/2024

#include <iostream>

// Function to tally ages. Updates the ageCounts array.
void tallyAges(int ageCounts[], int age) {
    if(age >= 1 && age <= 100) {
        ageCounts[age]++;
    }
}

// Function to display the tally of ages.
void displayAgeTally(const int ageCounts[]) {
    for(int i = 1; i <= 100; i++) {
        if(ageCounts[i] > 0) {
            std::cout << "The number of people " << i << " years old is " << ageCounts[i] << std::endl;
        }
    }
}

int main() {
    int ageCounts[101] = {0}; // Array to hold age counts, initialized to zero.
    int age;

    while(true) {
        std::cout << "Please input an age from one to 100, put -99 to stop: ";
        std::cin >> age;

        if(age == -99) {
            break; // Exit condition.
        }

        if(age < 1 || age > 100) {
            std::cout << "Invalid age. Please try again.\n";
            continue; // Skip the rest of the loop.
        }

        // Tally the age.
        tallyAges(ageCounts, age);
    }

    // Display the tally of ages.
    displayAgeTally(ageCounts);

    return 0;
}
