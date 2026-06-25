//task 1 husna

#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string course;
};

int main() {

    Student student[5] = {
        {101, "Insyirah", 20, "Computer Science"},
        {102, "Sarah", 21, "Data Science"},
        {103, "Bat", 22, "Cybersecurity"},
        {104, "Rayyan", 19, "Software Engineering"},
        {105, "Husna", 23, "Cybersecurity"}
    };

    cout << "\n--- Student Records ---\n";
    for (int i = 0; i < 5; i++) {
        cout << "******* Student " << i + 1 << " ******\n"
             << "ID: "     << student[i].id     << endl
             << "Name: "   << student[i].name   << endl
             << "Age: "    << student[i].age    << endl
             << "Course: " << student[i].course << endl << endl;
    }

    // FIX 1: added "not found" message using a flag
    int search;
    cout << "Please enter id number: ";
    cin >> search;

    bool found = false;
    for (int i = 0; i < 5; i++) {
        if (student[i].id == search) {
            cout << "ID: "     << student[i].id     << endl
                 << "Name: "   << student[i].name   << endl
                 << "Age: "    << student[i].age    << endl
                 << "Course: " << student[i].course << endl << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student not found.\n";
    }

    string ans = "";
    cout << "Do you want to update? (yes/no): ";
    cin >> ans;

    if (ans == "yes") {
        cout << "Please enter id number: ";
        cin >> search;

        bool updateFound = false;

        for (int i = 0; i < 5; i++) {
            if (student[i].id == search) {
                updateFound = true;

                cout << "ID: "     << student[i].id     << endl
                     << "Name: "   << student[i].name   << endl
                     << "Age: "    << student[i].age    << endl
                     << "Course: " << student[i].course << endl << endl;

                // FIX 2: switch block is now INSIDE the if block (brace fixed)
                int update;
                cout << "What do you want to change?\n";
                cout << "1. id\n2. name\n3. age\n4. course\n";
                cout << "Enter choice (1-4): ";
                cin >> update;

                switch (update) {
                    case 1:
                        cout << "Enter new id: ";
                        cin >> student[i].id;
                        break;
                    case 2:
                        // FIX 3: use getline so names with spaces work
                        cout << "Enter new name: ";
                        cin.ignore();
                        getline(cin, student[i].name);
                        break;
                    case 3:
                        cout << "Enter new age: ";
                        cin >> student[i].age;
                        break;
                    case 4:
                        // FIX 3: use getline for course too
                        cout << "Enter new course: ";
                        cin.ignore();
                        getline(cin, student[i].course);
                        break;
                    default:
                        cout << "Invalid choice\n";
                }

                cout << "Record updated successfully!\n";
                break;  // stop after updating the found student
            }
        }

        if (!updateFound) {
            cout << "Student not found.\n";
        }
    }

    return 0;
}
