#include<iostream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//defining a structure for student info
struct Student {
    string firstName;
    string lastName;
    int rollNumber;
    double cgpa;
    vector<int> courseIDs; // Dynamic array to store course IDs
};

vector<Student> students; //to store multiple students

void addStudent() {
    Student newStudent;
    cout << "Enter the first name: ";
    cin >> newStudent.firstName;
    cout << "Enter the last name: ";
    cin >> newStudent.lastName;
    cout << "Enter the roll number: ";
    cin >> newStudent.rollNumber;
    cout << "Enter the CGPA: ";
    cin >> newStudent.cgpa;
    cout << "Enter 5 course IDs: ";
    for (int i = 0; i < 5; ++i) {
        int courseId;
        cin >> courseId;
        newStudent.courseIDs.push_back(courseId);
    }
    students.push_back(newStudent);
    cout << "Student added successfully!\n";
}

//we can search a student by his/her roll number
void searchStudentByRollNumber() {
    int rollNumber;
    cout << "Enter the roll number of the student: ";
    cin >> rollNumber;
    
    for (const auto& student : students) {
        if (student.rollNumber == rollNumber) {
            cout << "Student Details:\n";
            cout << "First Name: " << student.firstName << "\n";
            cout << "Last Name: " << student.lastName << "\n";
            cout << "CGPA: " << student.cgpa << "\n";
            cout << "Course IDs: ";
            for (int courseId : student.courseIDs) {
                cout << courseId << " ";
            }
            cout << "\n";
            return;
        }
    }
    cout << "No student found with the given roll number.\n";
}

//we can search a tsudent by his/her first name.
void searchStudentByFirstName() {
    string firstName;
    cout << "Enter the first name of the student: ";
    cin >> firstName;
    
    for (const auto& student : students) {
        if (student.firstName == firstName) {
            cout << "Student Details:\n";
            cout << "First Name: " << student.firstName << "\n";
            cout << "Last Name: " << student.lastName << "\n";
            cout << "CGPA: " << student.cgpa << "\n";
            cout << "Course IDs: ";
            for (int courseId : student.courseIDs) {
                cout << courseId << " ";
            }
            cout << "\n";
        }
    }
}


void deleteStudentByRollNumber() {
    int rollNumber;
    cout << "Enter the roll number of the student to delete: ";
    cin >> rollNumber;
    
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->rollNumber == rollNumber) {
            students.erase(it);
            cout << "Student removed successfully!\n";
            return;
        }
    }
    cout << "No student found with the given roll number.\n";
}

//we can update stdents details
void updateStudentDetails() {
    int rollNumber;
    cout << "Enter the roll number of the student to update: ";
    cin >> rollNumber;

    for (auto& student : students) {
        if (student.rollNumber == rollNumber) {
            cout << "1. Update first name\n";
            cout << "2. Update last name\n";
            cout << "3. Update roll number\n";
            cout << "4. Update CGPA\n";
            cout << "5. Update courses\n";
            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter the new first name: ";
                    cin >> student.firstName;
                    break;
                case 2:
                    cout << "Enter the new last name: ";
                    cin >> student.lastName;
                    break;
                case 3:
                    cout << "Enter the new roll number: ";
                    cin >> student.rollNumber;
                    break;
                case 4:
                    cout << "Enter the new CGPA: ";
                    cin >> student.cgpa;
                    break;
                case 5:
                    cout << "Enter 5 new course IDs: ";
                    student.courseIDs.clear();
                    for (int i = 0; i < 5; ++i) {
                        int courseId;
                        cin >> courseId;
                        student.courseIDs.push_back(courseId);
                    }
                    break;
                default:
                    cout << "Invalid choice.\n";
                    break;
            }
            cout << "Details updated successfully.\n";
            return;
        }
    }
    cout << "No student found with the given roll number.\n";
}

void countTotalStudents() {
    cout << "Total number of students: " << students.size() << "\n";
}



int main() {
    while (true) {
        cout << "Menu:\n";
        cout << "1. Add new student\n";
        cout << "2. Search student by roll number\n";
        cout << "3. Search student by first name\n";
        cout << "4. Count total students\n";
        cout << "5. Delete student by roll number\n";
        cout << "6. Update student details\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                searchStudentByRollNumber();
                break;
            case 3:
                searchStudentByFirstName();
                break;
            
            case 4:
                countTotalStudents();
                break;
            case 5:
                deleteStudentByRollNumber();
                break;
            case 6:
                updateStudentDetails();
                break;
            case 7:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
