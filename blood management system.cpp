#include <iostream>
using namespace std;

struct Person {
    string name;
    string bloodGroup;
    string fatherName;
    string motherName;
    string address;
};

const int MAX_PERSONS = 100;

Person donors[MAX_PERSONS];
Person consumers[MAX_PERSONS];
int numDonors = 0;
int numConsumers = 0;

void addPerson(Person persons[], int& count) {
    if (count >= MAX_PERSONS) {
        cout << "Maximum limit reached. Cannot add more persons." << endl;
        return;
    }

    Person newPerson;
    cout << "Enter the name: ";
    cin >> newPerson.name;
    cout << "Enter the blood group (A+, A-, B+, B-, AB+, AB-, O+, O-): ";
    cin >> newPerson.bloodGroup;
    cout << "Enter the father's name: ";
    cin >> newPerson.fatherName;
    cout << "Enter the mother's name: ";
    cin >> newPerson.motherName;
    cout << "Enter the address: ";
    cin >> newPerson.address;

    persons[count] = newPerson;
    count++;

    cout << "Person added successfully." << endl;
}

void searchPerson(Person persons[], int count, string bloodGroup) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (persons[i].bloodGroup == bloodGroup || persons[i].bloodGroup == bloodGroup + "+" || persons[i].bloodGroup == bloodGroup + "-") {
            cout << "Name: " << persons[i].name << endl;
            cout << "Blood Group: " << persons[i].bloodGroup << endl;
            cout << "Father's Name: " << persons[i].fatherName << endl;
            cout << "Mother's Name: " << persons[i].motherName << endl;
            cout << "Address: " << persons[i].address << endl;
            cout << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No persons found with the given blood group." << endl;
    }
}

void displayPersons(Person persons[], int count) {
    for (int i = 0; i < count; i++) {
        cout << "Name: " << persons[i].name << endl;
        cout << "Blood Group: " << persons[i].bloodGroup << endl;
        cout << "Father's Name: " << persons[i].fatherName << endl;
        cout << "Mother's Name: " << persons[i].motherName << endl;
        cout << "Address: " << persons[i].address << endl;
        cout << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "Blood Bank Management System" << endl;
        cout << "1. Add a person" << endl;
        cout << "2. Search for persons with a blood group" << endl;
        cout << "3. Display all persons" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    int personType;
                    cout << "Select the person type:" << endl;
                    cout << "1. Donor" << endl;
                    cout << "2. Consumer" << endl;
                    cout << "Enter the person type: ";
                    cin >> personType;

                    if (personType == 1) {
                        addPerson(donors, numDonors);
                    } else if (personType == 2) {
                        addPerson(consumers, numConsumers);
                    } else {
                        cout << "Invalid person type. Please try again." << endl;
                    }
                }
                break;
            case 2:
                {
                    string bloodGroup;
                    cout << "Enter the blood group to search for persons: ";
                    cin >> bloodGroup;
                    cout << "Search results for donors:" << endl;
                    searchPerson(donors, numDonors, bloodGroup);
                    cout << "Search results for consumers:" << endl;
                    searchPerson(consumers, numConsumers, bloodGroup);
                }
                break;
            case 3:
                cout << "All donors:" << endl;
                displayPersons(donors, numDonors);
                cout << "All consumers:" << endl;
                displayPersons(consumers, numConsumers);
                break;
            case 4:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
