#pragma once
#include <iostream>
#include <stdlib.h> 
#include <mysql.h>
#include <string.h>
using namespace std;

//Blueprint for each gym member
class Member {


public:

	string firstName;
	string lastName;
	string emailAddress;
	string age;


	//Take the person's basic information and put it in the database.
	void inputInfo() {
		
		cout << "\t\tEnter our new clients first name: " << endl;
		cin >> firstName;
		cout << "\t\tEnter their last name: " << endl;
		cin >> lastName;
		cout << "\t\tEnter their  age" << endl;
		cin >> age;
		cout << "\t\tEnter their email address: " << endl;
		cin >> emailAddress;

	}
	
};

//blueprint for all employees
class Employee {
public:
	string firstName;
	string lastName;
	string emailAddress;
	string password;
	string age;
	int employeeNumber;

	string addStaffMember(){
		string statement;

		cout << "\t\tEnter our new staff member's name: " << endl;
		cin >> firstName;
		cout << "\t\tEnter their last name: " << endl;
		cin >> lastName;
		cout << "\t\tEnter their  age" << endl;
		cin >> age;
		cout << "\t\tEnter their email address: " << endl;
		cin >> emailAddress;
		cout << "\t\tAsk them to set a password that will allow them to log in :  " << endl;
		cin >> password;

		statement = "CREATE USER '" + firstName + "'@'localhost' IDENTIFIED BY '" + password + "'";
		return statement;


	}
	string grantPriveleges() {
		string statement = "GRANT ALL PRIVELEGES ON *.* TO '" + firstName + "'@'localhost'";
		return statement;
	}
};
class facility {
	string facilityType;

	void addFacilityDetails(){

		cout << "\t\tEnter the new facility type: " << endl;
		cin >> facilityType;
		
	}
};