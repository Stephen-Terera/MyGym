#pragma once
#include<iostream>
#include <mysql.h>
#include<string>
#include <stdlib.h> 
using namespace std;

//Get username;
string  username() {
	string username;
	cout << "\t\tPlease input your username" << endl;
	cin >> username;
	return username;
}
//Get password;
string  password() {
	string  password;
	cout << "\t\tPlease input your password" << endl;
	cin >> password;
	return password;
}

//Display menu options 
void displayMessage() {
	cout << "\n\n\t\tWelcome back !" << endl;
	cout << "\t\t 1. Sign in a member " << endl;
	cout << "\t\t 2. Add a new member " << endl;
	cout << "\t\t 3. Update records " << endl;
	cout << "\t\t 4. Remove a member" << endl;
	cout << "\t\t 5. Book a facility" << endl;
	cout << "\t\t 6.Add new employee" << endl;
	cout << "\t\t7.Show all members" << endl;
	cout << "\t\t8.Show booking table" << endl;
	cout << "\t\t9.Show login table" << endl;
}

//Execute a query that is passed from the main cpp file.
void executeQuery(MYSQL&mysql,string query){
	//qstate used to check whether or not the query is actually executed
	// will help flag if there is an error.
	int qstate;
	const char* q = query.c_str();
	qstate = mysql_query(&mysql, q);
	if (!qstate) {
		cout << "\t\tsuccess\n";
		system("CLS");
	}
	else {
		cout << "\t\tQuery failed" << mysql_error(&mysql);
	}
	
}

string getMembershipID() {
	string id;
	cout << "\t\tPlease enter the membership Number: " << endl;
	cin >> id;
	return id;
}
string getChange() {
	string change;
	cout << "\t\tPlease enter the change that is to be put in the records: " << endl;
	cin >> change;
	return change;
}
string updatingRecord(string change, string membershipID) {
	string statement;
	int choice;
	cout << "\t\t 1.First Name" << endl;
	cout << "\t\t 2.Last Name" << endl;
	cout << "\t\t 3.Email Address" << endl;
	cout << "\t\t Please input where the change is to be made: " << endl;
	cin >> choice;
	if (choice == 1) {
		statement = "UPDATE members SET firstName = '" + change + "' WHERE membershipID = '" + membershipID + "' ";
	}
	else if (choice == 2) {
		statement = "UPDATE members SET lastName = '" + change + "' WHERE membershipId = '" + membershipID + "' ";
	}
	else if (choice == 3) {
		statement = "UPDATE members SET emailAddress = '" + change + "' WHERE membershipID = '" + membershipID + "' ";
	}
	else {
		cout << "Invalid menu option selected ";
	}

	return statement;
}

string  bookFacility() {
	string facilityID;
	string id;
	string statement;
	string dateTime;
	cout << "The facilities we have available are: " << endl;
	cout <<"\t\t1."<<  "basketball courts(1-3)" << endl;
	cout << "\t\t2." << "Tennis courts (4-6)" << endl;
	cout << "\t\t3." << "Squash courts(7-9)" << endl;
	cout << "\t\t4." <<  "Badminton courts(10-12)" << endl;
	cout << "\t\t Please input choice: " << endl;
	cin >> facilityID;
	cout << "Please enter ID: " << endl;
	cin >> id;
		
	statement = "INSERT INTO booking(membershipID,facilityID,bookedTime)VALUES ('" + id + "','" + facilityID + "',NOW())";
		
	return statement;


}
