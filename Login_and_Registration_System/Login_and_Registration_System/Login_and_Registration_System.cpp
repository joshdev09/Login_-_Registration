#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void login();
void registration();
void forgot();

int main() {

	int choice = 0;

	cout << "\t\t\t_________________________________________________________\n\n\n";
	cout << "\t\t\t                 Welcome to the login Page               \n\n\n";
	cout << "\t\t\t_______________________    MENU   _______________________\n\n\n";
	cout << "                                                               \n\n\n";

	cout << "\n\t| Press 1 to LOGIN                |";
	cout << "\n\t| Press 2 to REGISTER             |";
	cout << "\n\t| Press 3 if FORGOT PASSWORD      |";
	cout << "\n\t| Press 4 to EXIT                 |";

	cout << "\n\n";
	cout << "\n\t\t\tEnter your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 1: 
		login();
		break;

	case 2:
		registration();
		break;

	case 3:
		forgot();
		break;

	case 4:
		cout << "\t\t\tThankyou!";
		break;

	default:
		system("cls");
		cout << "\t\t\tPlease enter a valid number or select a number base on the options.";
		main();
	}
}

void login() {

	int count = 0;
	string userID, password, id, pass;
	system("cls");
	
	cout << "\t\t\t Enter the username and password: ";
	cout << "\n\n";
	cout << "\t\t\t USERNAME: ";
	cin >> userID;

	cout << "\n\n";
	cout << "\t\t\t PASSWORD: ";
	cin >> password;

	ifstream input("records.txt");

	while (input >> id >> pass)
	{
		if (id == userID && pass == password)
		{
			count = 1;
			system("cls");
		}
	}

	input.close();

	if (count == 1)
	{
		cout << userID << "\nYour LOGIN is successfull.";
		main();
	}

	else {
		cout << "\n\t LOGIN ERROR \n\t Please check your username and password.\n";
		main();
	}
}

void registration() {

	string ruserID, rpassword, rid, rpass;
	system("cls");

	cout << "\t\t\t Enter the username: ";
	cin >> ruserID;

	cout << "\t\t\t Enter the password: ";
	cin >> rpassword;

	ofstream f1("records.txt", ios::app);
	f1 << ruserID << ' ' << rpassword;
	system("cls");

	cout << "\n\t\t\t Registration is successfull! \n";
	main();
}

void forgot() {

	int option;
	system("cls");
	
	cout << "\t\t\t You forgot the password? Don't worry we got you covered \n";
	cout << "Press 1 to search your ID by username. ";
	cout << "Press 2 to go back to main menu. ";
	cout << "\t\t\tEnter your choice: ";
	cin >> option;

	switch (option)
	{

		case 1:
			{
				int count = 0;
				string suserID, sid, spass;
				cout << "\n\t\t\tEnter the username which you remembered: ";
				cin >> suserID;

				ifstream f2("records.txt");
				while (f2 >> sid >> spass)
				{
					if (sid == suserID)
					{
						count = 1;
					}
				}

				f2.close();
				if (count == 1)
				{
					cout << "\n\n Your account is found! \n";
					cout << "\n\n Your password is : " << spass;
					main();
				}

				else {
					cout << "\n\t Sorry your account is not found :( \n";
					main();
				}

				break;
			}

		case 2:
		{
			main();
		}

		default: 
			cout << "\t\t\t ERROR! Please input the correct number.";
			forgot();
	}
}