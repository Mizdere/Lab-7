// This program will read in a group of test scores (positive integers from 1 to 100)
// from the keyboard and then calculate and output the average score
// as well as the highest and lowest score. There will be a maximum of 100 scores.

// Last Modified Date: 4/17/2024

#include <iostream>
#include <fstream> // Include for file operations
using namespace std;

typedef int GradeType[100];  // declares a new data type: an integer array of 100 elements

float findAverage(const GradeType, int);
int findHighest(const GradeType, int);
int findLowest(const GradeType, int);

int main()
{
    GradeType grades;   // the array holding the grades. 
    int numberOfGrades; // the number of grades read.
    int pos = 0;        // index to the array.
    float avgOfGrades;  // contains the average of the grades. 
    int highestGrade;   // contains the highest grade.
    int lowestGrade;    // contains the lowest grade.

    ifstream inFile;    // File stream variable
    inFile.open("gradfile.txt"); // Open the file

    if (!inFile) {
        cout << "Unable to open file" << endl;
        return 1; // Return error if file cannot be opened
    }

    // Read grades from the file until end of file
    while (inFile >> grades[pos] && pos < 100) {
        pos++;
    }
    numberOfGrades = pos; // Assign number of grades read
    inFile.close(); // Close the file after reading

    // Call to the function to find average
    avgOfGrades = findAverage(grades, numberOfGrades);
    cout << endl << "The average of all the grades is " << avgOfGrades << endl;

    // Call to the function that calculates the highest grade
    highestGrade = findHighest(grades, numberOfGrades);
    cout << "The highest grade is " << highestGrade << endl;

    // Call to the function that calculates the lowest grade
    lowestGrade = findLowest(grades, numberOfGrades);
    cout << "The lowest grade is " << lowestGrade << endl;

    return 0;
}


//********************************************************************************
// findAverage
//
// task:           This function receives an array of integers and its size.
//                 It finds and returns the average of the numbers in the array
// data in:        array of floating point numbers
// data returned:  average of the numbers in the array
//
//********************************************************************************

float findAverage(const GradeType array, int size)
{
    float sum = 0;    // holds the sum of all the numbers

    for (int pos = 0; pos < size; pos++)
        sum += array[pos];

    return (sum / size);  // returns the average
}

//****************************************************************************
// findHighest
//
// task:           This function receives an array of integers and its size.
//                 It finds and returns the highest value of the numbers in 
//                 the array
// data in:        array of floating point numbers
// data returned:  highest value of the numbers in the array
//
//****************************************************************************

int findHighest(const GradeType array, int size)
{
    int highest = array[0]; // assume first element is highest initially

    for (int pos = 1; pos < size; pos++)
    {
        if (array[pos] > highest)
            highest = array[pos];
    }

    return highest;
}

//****************************************************************************
// findLowest
//
// task:           This function receives an array of integers and its size.
//                 It finds and returns the lowest value of the numbers in 
//                 the array
// data in:        array of floating point numbers
// data returned:  lowest value of the numbers in the array
//
//****************************************************************************

int findLowest(const GradeType array, int size)
{
    int lowest = array[0]; // assume first element is lowest initially

    for (int pos = 1; pos < size; pos++)
    {
        if (array[pos] < lowest)
            lowest = array[pos];
    }

    return lowest;
}

