#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>
#include <cctype>
#include <windows.h>
#include <algorithm>
using namespace std;

bool MainFallbackResp;

string concatID;

void Keyword(ifstream & stream, string token) { //Search for keyword/username inside text file database
    string line;
    while (getline(stream, line)) {
        if (line.find(token) != string::npos) {
            cout << line << endl;
            std::string::iterator end_pos = std::remove(line.begin(), line.end(), ' '); //remove trailling/any white spaces in between (eg admin Admin123 --> adminAdmin123)
			line.erase(end_pos, line.end());
            cout << line;
            concatID = line; //assign to a global variable
        }
    }
}

void login()
{
	char trackingNo[10],Resp;
	//char username[30], password[20],uname_db[30], pword_db[30];
	string username,password,creds_db,creds;
	cout << "\n Choose Login type \n 1. Staff \n 2. Customers? Track yur order Here. \n Response >> ";
	cin >> Resp;
	
	ifstream loginDB;
	loginDB.open("LoginDB.txt"); 
	
	switch (Resp) {
		case '1' : {
			
			cout << "\n Username \t >> \t ";
			cin >> username;
	
			cout << " Password \t >> \t ";
   			// cout << password << endl;
			cin >> password;
			
			//getline(loginDB, uname_db);
			//getline(loginDB, pword_db);
			
			
			Keyword(loginDB, username);
			creds = username + password; //concatenate both variable (eg admin + Admin123 --> adminAdmin123)
			if (creds == concatID)
				MainFallbackResp = true;
			else 
				MainFallbackResp = false;
			
			
			break;
		}
		case '2' : {
			cout << "\n Tracking No \t >> \t ";
			cin >> trackingNo;	
			break;
		}
	}
	
}

void heading()
{
	cout << "\n Crimson Business Transaction Management System (BTMS)";
	cout << "\n Welcome! Please enter your credentials to begin!" << endl;
	cout << "\n =============================================================" << endl;
	cout << endl;
}




int main()
{
	
	while (MainFallbackResp == false) 
	{
		heading();
		login();	
		system("CLS");
		cout << " =========================================================================" << endl;
		cout << " ====== ==== ==== Invalid Credentials! Please try again. ==== ==== ======" << endl;
		cout << " =========================================================================" << endl;
	}
	system("CLS");
	cout << "Login Success";
	
	return 0;
}
