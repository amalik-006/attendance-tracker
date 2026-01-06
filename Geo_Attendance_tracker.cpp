//C++ Program for a Geo Attendance Tracker

#include <iostream>
#include <string>                           // For string variables
#include <cmath>                            // For sqrt() and pow()
using namespace std;

int main() {
    // Variable Setup

    // Fixed Landmark Coordinates
    const double landmarkLat = 10.6;       // Fixed Latitude
    const double landmarkLong = 10.6;      // Fixed Longitude

    // Variables to track attendance
    int totalUsers = 0;
    int presentCount = 0;
    int absentCount = 0;

    char choice;

    do {
        // User input variables
        string userName;                    // to store user's name
        double userLat;                     // to store user's latitude
        double userLong;                    // to store user's longitude

        // Input from user
        cout << "Enter your name: ";
        cin >> userName;

        // Latitude Input (with error checking)
        cout << "Enter your current latitude: ";
        cin >> userLat;

        // Check for invalid input for latitude
        if (cin.fail()) {
            cout << "Invalid input for latitude. Please enter a valid number." << endl;
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the invalid input
            continue;                                            // Skip the rest of the loop and prompt for the name and latitude again
        }

        // Longitude Input (with error checking)
        cout << "Enter your current Longitude: ";
        cin >> userLong;

        // Check for invalid input for longitude
        if (cin.fail()) {
            cout << "Invalid input for longitude. Please enter a valid number." << endl;
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the invalid input
            continue;                                            // Skip the rest of the loop and prompt for the name and longitude again
        }

        // Output Display
        cout << "\n \t User Input Summary" << endl;
        cout << "Name: " << userName << endl;
        cout << "Latitude: " << userLat << endl;
        cout << "Longitude: " << userLong << endl;

        // Landmark Coordinates
        cout << "Landmark latitude: " << landmarkLat << endl;
        cout << "Landmark Longitude: " << landmarkLong << endl;

        // Distance Calculation

        // Using Euclidean distance formula
        double distance = sqrt(pow(userLat - landmarkLat, 2) + pow(userLong - landmarkLong, 2));

        // Display Calculated Distance
        cout << "\n Calculated distance from landmark: " << distance << endl;

        // Attendance Check (if-else)
        if (distance <= 0.8) {
            cout << "Attendance Status: Present" << endl;
            presentCount++;
        }
        else {
            cout << "Attendance Status: Absent" << endl;
            absentCount++;
        }

        totalUsers++;

        // Attendance Check for Multiple Users

        // Ask if you want to continue
        cout << "\nDo you want to check another user? (yes / no): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    // Final display
    cout << "\n \t Attendance Summary " << endl;
    cout << "Total users checked: " << totalUsers << endl;
    cout << "Present: " << presentCount << endl;
    cout << "Absent: " << absentCount << endl;

    return 0;
}


