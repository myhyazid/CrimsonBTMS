#include <iostream>
#include <fstream>
#include <cstring>
//#include <string>
#include <cmath>
#include <cctype>
#include <windows.h>
using namespace std;

bool MainFallbackResp;

void login()
{
	char trackingNo[10],Resp;
	string username,password;
	cout << "\n Choose Login type \n 1. Staff \n 2. Customers? Track yur order Here. \n Response >> ";
	cin >> Resp;
	switch (Resp) {
		case '1' : {
			
			cout << "\n Username \t >> \t ";
			cin >> username;
	
			cout << " Password \t >> \t ";
   			// cout << password << endl;
			cin >> password;
			
			if (username == "test" && password == "test123")
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
	
	cout << "Login Success";
	
	return 0;
}
