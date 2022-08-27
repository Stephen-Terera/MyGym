// Gym management System(MYGYM).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma warning(disable:4996)
#include <iostream>
#include <stdlib.h> 
using namespace std;
#include <mysql.h>
#include <driver.h>
#include <exception.h>
#include "functions.h"
#include "classes.h"
#include <ctime>
#include <iomanip>



int main()
{
	string sqlQuery;
	int choice = -1;
	string query;
	 

	const char* USERNAME = "root";
	const char* PASSWORD = "Securepass01";

	
	string membershipID;

	MYSQL mysql;
	MYSQL_RES* result;
	MYSQL_ROW row;
	mysql_init(&mysql);


	if (!mysql_real_connect(&mysql, "localhost",USERNAME, PASSWORD, "mygym", 0, NULL, 0))
	{
		fprintf(stderr, "Failed to log you in.Please check your login details  : %s\n",
			mysql_error(&mysql));
	}
	else {
		cout << "Welcome back !!" << endl;
		system("CLS");
		while (choice != 0) {
			displayMessage();
			cout << "\t\tPlease input your choice: ";
			cin >> choice;

			if (choice == 1) {
				//get the membership ID of the person that is loging in.
				membershipID = getMembershipID();

				//Create the query to add to the log in table and execute it.
				query = "INSERT INTO logintable(membershipID , login) VALUES('" + membershipID + "',NOW())";
				executeQuery(mysql, query);
			}

			else if (choice == 2) {

				//Creating a new members records from the Member class.
				Member newMember;
				newMember.inputInfo();
				//Creating the insert query and the executing it.
				query = "INSERT INTO members(firstName,lastName,emailAddress,age) VALUES('" + newMember.firstName + "','" + newMember.lastName + "','" + newMember.emailAddress + "','" + newMember.age + "')";
				executeQuery(mysql, query);
			}
			else if (choice == 3) {
				string change = getChange();
				membershipID = getMembershipID();
				query = updatingRecord(change, membershipID);
				executeQuery(mysql, query);

			}//Deleting a members records from our database.
			else if (choice == 4) {

				//Get the membership id of the record to be deleted.
				membershipID = getMembershipID();

				//Creating the delete query and executing it.
				query = "DELETE FROM members WHERE membershipID = '" + membershipID + "'";
				executeQuery(mysql, query);

			}
			else if (choice == 5) {
				query = bookFacility();
				executeQuery(mysql, query);

			}
			else if (choice == 6) {
				Employee newEmployee;
				newEmployee.addStaffMember();

				query = "INSERT INTO employees(firstName,lastName,emailAddress,age) VALUES('" + newEmployee.firstName + "','" + newEmployee.lastName + "','" + newEmployee.emailAddress + "','" + newEmployee.age + "')";
				executeQuery(mysql, query);
				query = newEmployee.grantPriveleges();
				executeQuery(mysql, query);

			}
			else if (choice == 7) {

				query = "SELECT *FROM MEMBERS";
				executeQuery(mysql, query);

				result = mysql_store_result(&mysql);
				int num_fields = mysql_num_fields(result);
				while ((row = mysql_fetch_row(result)))
				{

					printf("\tID %s,Name %s,lastName %s\t\n", row[0], row[1], row[2]);

				}

			}
			else if (choice == 8) {
				query = "SELECT *FROM BOOKING";
				executeQuery(mysql, query);

				result = mysql_store_result(&mysql);
				int num_fields = mysql_num_fields(result);
				while ((row = mysql_fetch_row(result)))
				{

					printf("\tID %s,Facility %s,time %s\t\n", row[0], row[1], row[2], "\n");

				}

			}
			else if (choice == 9) {
				query = "SELECT *FROM LOGINTABLE";
				executeQuery(mysql, query);

				result = mysql_store_result(&mysql);
				int num_fields = mysql_num_fields(result);
				while ((row = mysql_fetch_row(result)))
				{

					printf("\tID: %s,time: %s\t\n", row[0], row[1], "\n");

				}

			}
			else {
				cout << "Please enter a valid menu option: ";
				system("CLS");

			}

		}

	}
}
	

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
