/*
 * CMSC140
 * Instructor: Prof. Charles Naegeli
 * Project 4
 * Description: This program calculates the average number of days employees are absent in a year and writes the data to a file.
 * Due Date: 11-18-2024
 * I pledge that I have completed the programming assignment independently.
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Aaron Kingston
 *///

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//the global output file variables
ofstream outFile("employeeAbsences.txt");

// the prototype fucntions
int getNumOfEmployees();
int getTotalDaysAbsent(int numEmployees);
double calculateAvgDaysAbsent(int numEmployees, int totalDaysAbsent);

int main() {
    cout << "Welcome to the Employee Absences Program!\n";

    //etting the number of employess in the company
    int numEmployees = getNumOfEmployees();

    // Get how many days the employess have been absent
    int totalDaysAbsent = getTotalDaysAbsent(numEmployees);

    // Calculate the ammount of average days that employees hav ebeen absent
    double avgDaysAbsent = calculateAvgDaysAbsent(numEmployees, totalDaysAbsent);
    outFile << fixed << setprecision(2);
    outFile << "\nAverage Days Absent: " << avgDaysAbsent << endl;

    // close output fikle.
    outFile.close();

    // Final message
    cout << "Data has been written to 'employeeAbsences.txt'.\n";
    cout << "Programmer: Aaron Kingston" << endl;


    return 0;
}

// Function to get the number of employees
int getNumOfEmployees() {
    int numEmployees;
    do {
        cout << "Enter the number of employees: ";
        cin >> numEmployees;
        if (numEmployees < 1) {
            cout << "Error: The number of employees must be at least 1.\n";
        }
    } while (numEmployees < 1);
    return numEmployees;
}

// Function to get the total days absent
int getTotalDaysAbsent(int numEmployees) {
    int totalDaysAbsent = 0;

    //the file header
    outFile << "Employee Absences Report\n";
    outFile << "-------------------------\n";

    for (int i = 0; i < numEmployees; ++i) {
        int employeeID, daysMissed;

        cout << "Enter employee ID (4 digits or fewer): ";
        cin >> employeeID;

        do {
            cout << "Enter the number of days missed: ";
            cin >> daysMissed;
            if (daysMissed < 0) {
                cout << "Error: Days missed cannot be negative.\n";
            }
        } while (daysMissed < 0);

        //writing to the output file
        outFile << "Employee ID: " << employeeID
                << ", Days Missed: " << daysMissed << endl;

        totalDaysAbsent += daysMissed;
    }

    return totalDaysAbsent;
}

// Function to calculate the average days absent
double calculateAvgDaysAbsent(int numEmployees, int totalDaysAbsent) {
    return static_cast<double>(totalDaysAbsent) / numEmployees;
}







