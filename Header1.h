#pragma once
#include <iostream>
// for getting a random number 
#include<time.h>
#include <string>
using namespace std;

//class for all employees
class Employee {
public:
    string firstName;
    string lastName;
    int age;
    string employeeNumber;
    string userName;



    void addEmployee();
};

//function to get basic details
void Employee::addEmployee() {
    cout << "Please enter our new employee's first name: " << endl;
    cin >> firstName;
    cout << "Please enter their last name: " << endl;
    cin >> lastName;
    cout << "Please enter their age: " << endl;
    cin >> age;
    employeeNumber = rand() % 4;
    userName = lastName + "2021";

}
class Member {
public:
    string firstName;
    string lastName;
    int age;
    string membershipNumber;
    char membershipType;
    bool paid = 0;
    //add a new members basic details 
    void addMember() {
        cout << "Please enter our new employee's first name: " << endl;
        cin >> firstName;
        cout << "Please enter their last name: " << endl;
        cin >> lastName;
        cout << "Please enter their age: " << endl;
        cin >> age;
    }
};
class Facilities {
public:
    string type;
    void bookFacility() {
        cout << "What facility would you like to book: " << endl;
    }

};

string createMemberID() {
    string idNumber;
    int number = rand() % 1000000;
    string strNumber = to_string(number);
    idNumber = "N" + strNumber;
    return idNumber;
}
