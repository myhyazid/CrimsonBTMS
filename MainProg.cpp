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
void Dashboard ()
{
	
}
void Keyword(ifstream & stream, string token, string fx) { //Search for keyword/username inside text file database
    string line; 
    while (getline(stream, line)) {
        if (line.find(token) != string::npos) {
            cout << line << endl;
            
            if (fx == "sublogin") {
        		std::string::iterator end_pos = std::remove(line.begin(), line.end(), ' '); //remove trailling/any white spaces in between (eg admin Admin123 --> adminAdmin123)
				line.erase(end_pos, line.end()); //remove the spaces
            	cout << line;
            	concatID = line; //assign to a global variable
        	}
        	else if (fx == "tracking") {
        		line.erase(line.begin()+8,line.end()); //remove the excess information from 1 line or grab only ID.
        		cout << line;
        		concatID = line;
        	}
        }
    }
}

void login()
{
	char trackingNo[10],Resp;
	string fxName;
	string username,password,creds_db,creds;
	cout << "\n Choose Login type \n 1. Staff \n 2. Customers? Track yur order Here. \n Response >> ";
	cin >> Resp;
	
	ifstream loginDB;
	
	switch (Resp) {
		case '1' : {
			
			loginDB.open("LoginDB.txt"); 
			
			cout << "\n Username \t >> \t ";
			cin >> username;
	
			cout << " Password \t >> \t ";
			cin >> password;
			
			
			fxName = "sublogin";
			Keyword(loginDB, username, fxName);
			creds = username + password; //concatenate both variable (eg admin + Admin123 --> adminAdmin123)
			if (creds == concatID)
				MainFallbackResp = true;
			else 
				MainFallbackResp = false;
				
			loginDB.close();
			
			break;
		}
		case '2' : {
			loginDB.open("ClaimTrack.txt");
			
			cout << "\n Tracking No \t >> \t ";
			cin >> trackingNo;	
			cout << trackingNo << "ccc";
			fxName = "tracking";
			
			Keyword(loginDB, trackingNo, fxName);
			
			if (trackingNo == concatID)
				MainFallbackResp = true;
			else 
				MainFallbackResp = false;
			
			loginDB.close();
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
