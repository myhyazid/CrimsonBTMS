#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool MainFallbackResp;

string concatID,level,username;
char trackingNo[10];
void heading();

void Keyword(ifstream & stream, string token, string fx) { //Search for keyword/username inside text file database
    string line,levln; 
    while (getline(stream, line)) {
        if (line.find(token) != string::npos) {
            cout << line << endl;
            levln=line;
            if (fx == "sublogin") {
            	int length = line.length(); // Get User Row length
            	
            	levln.erase(levln.begin(), levln.end()-1);
            	level = levln;
            	
            	line.erase(line.begin()+(length-1), line.end()); //remove ID Column inside user row (set cursor to 2nd last char and erase last char)
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
        	 else if (fx == "edit") {
        		int length = line.length(); // Get User Row length
            	
            	line.erase(line.begin()+(length-3), line.end());
            	concatID= line;
			}
			}
        }
    }

void AddClaim () //void function -has no return value
{

      int ID, time,statusCode;   //initialization
	  string CustName, ItemDesc;
	  heading();
    cout << "Please enter customer ID : " << endl; // get customer ID
    cin >> ID; //
    
    cout << "Please enter customer name :  " << endl; //get customer name
    cin >> CustName;
    
    cout << "Please enter the item description : " << endl; //get item description
    cin >> ItemDesc;
    
    cout << "Enter the estimated time for customer to receive the warranty : " << endl; //get the estimated time
    cin >> time;
    
    cout << "Enter the status of the warranty claim : " << endl; //prompt for status of the warranty
    cout << "\n Status Code : \n 100 = Sent to Manufacturer \n 105 = Processing \n 200 = Arrived \n 404 = User Collected \n 500 = Refund"; //explanation on the status code
    cin >> statusCode;
    
    ofstream outfile; //send data to the file
    outfile.open("Warrantyclaim.txt", ios::app); //
    outfile<<"\n";
    //outfile<<"ID     CUSTOMERNAME     ITEMDESC     TIME     STATUS";
    
    outfile<<"\n";
    outfile<<ID<<"     "<<CustName<<"     "<<ItemDesc<<"     "<<time<<"     "<<statusCode<<endl; //display the data
    outfile.close(); //close the file
}

void EditClaim () 
{
	string arr[100] = {""}; //declaration of an array 
	string statusCode;
	string id;
	
	ifstream in; //read input from file
	string line;
	in.open("Warrantyclaim.txt");//open the
	
	int i=0; //initialize i to 0
	while (getline(in, line))
	{
		cout << line <<endl;
		arr[i] = line;
		i++;
	}
	in.close();
	
	cout << "Please choose which claim do you want to update >> " <<endl;
	cin >> id;
//	cout << line;
	
	ifstream inp;
	inp.open("Warrantyclaim.txt");
	
	Keyword(inp,id,"edit");

    
    cout << concatID; //get username and password from the file
    
	inp.close(); //close the file
	
	cout << "Enter the new status of the warranty claim : " << endl; //get new status of the warranty
    cout << "\n Status Code : \n 100 = Sent to Manufacturer \n 105 = Processing \n 200 = Arrived \n 404 = User Collected \n 500 = Refund";
    cin >> statusCode;
    
    int nova;
    ofstream outfile; // send data to the file
    outfile.open("Warrantyclaim.txt", ios::app);
	outfile <<"\n"<< concatID + "" + statusCode;
    outfile.close(); // close file
}

void AddTrans()
{
	int transID;        //initialization
	string transDesc;
	float amount;
	heading();
   cout <<"======= Add new Transaction =======" <<endl <<endl;
 
   cout << "Please enter Transaction ID: ";
   cin >> transID;
   
   cout << "Please enter Transaction Description: ";
   cin >> transDesc;
   
   cout << "Please enter amount: ";
   cin >> amount;
   
   ofstream outfile;
   outfile.open("Transaction.txt", ios::app);
   outfile<<"\n";
   //outfile<< "ID		Transaction Description		Amount";
   
   outfile << "\n";
   outfile << transID << "		" << transDesc << "		" << amount << "		" << endl;
   outfile.close();
   				
}

void addUser() //void function named addUser
{
	heading();
	string name,password;  //initialization
	ofstream outfile;
	cout<<"Please enter username :";
	cin>>name;
	cout<<"Please enter password :";
	cin>>password;
	outfile.open("LoginDB.txt",ios::app);
	outfile<<"\n";
	//outfile<<"username		password";
	outfile<<"\n";
	outfile<<name<<"    "<<password;
	outfile.close();
}

void Dashboard ()
{
	heading();
	if (level == "1") //admin
	{
		int resp;
		int counter =0;
		while (counter==0)	
		{
		cout << "\n Welcome, " << username;
		cout << "\n 1. Add New User";
		cout << "\n 2. View/Update List of Users";
		cin >>  resp;
			switch (resp) {
				case 1 : {
					addUser();
					counter++;
					break;
				}
				case 2 : {
					
					counter++;
					break;
				}
				case 3 : {
					
					counter++;
					break;
				}
				case 4 : {
					
					counter++;
					break;
				}
				default :
					{
						cout << "\n Invalid Input";
					}
		}
	}
}
	else if (level == "2") // Manager
	{
			int resp;
		int counter =0;
		while (counter==0)	
		{
		cout << "\n Welcome, " << username;
		cout << "\n 1. View Transaction";
		cout << "\n 2. Record Transaction";
		cout << "\n 3. Warranty Claim";
		cout << "\n 4. Print Report";
		cin >>  resp;
			switch (resp) {
				case 1 : {
					
					counter++;
					break;
				}
				case 2 : {
					AddTrans();
					counter++;
					break;
				}
				case 3 : {
					int resp;
					cout << "\nChoose \n 1: Add new Warranty Claim \n 2: View/Update Claim";
					cin >> resp;
					
					switch (resp) {
						case 1: AddClaim();break;
						case 2: EditClaim();break;
					}
					counter++;
					break;
				}
				case 4 : {
					
					counter++;
					break;
				}
				default :
					{
						cout << "\n Invalid Input";
					}
			};
	}
}
	else if (level == "3") // Staff
	{
		int resp;
		int counter =0;
		while (counter==0)	
		{
		cout << "\n Welcome, " << username;
		cout << "\n 1. View Transaction";
		cout << "\n 2. Record Transaction";
		cout << "\n 3. Warranty Claim";
		cout << "\n 4. Print Report";
		//cout << endl <<"\n";
		cin >>  resp;
			switch (resp) {
				case 1 : {
					
					counter++;
					break;
				}
				case 2 : {
					
					counter++;
					break;
				}
				case 3 : {
					
					counter++;
					break;
				}
				case 4 : {
					
					counter++;
					break;
				}
				default :
					{
						cout << "\n Invalid Input";
					}
			};
		}
	}
	else if (level=="4")
	{
		ifstream in;
		struct message {
			string mainmsg;
			string statcode;
			string msg;
		};
		message arr[100];
		in.open("Warrantyclaim.txt");
		string out,stat;
		
		//Keyword(in, trackingNo, "edit");
	//	cout << concatID;
	
		int i =0;
  		  while (getline(in, out)) {
        	if (out.find(trackingNo) != string::npos) {
        		stat = out;
        		
        		stat.erase(stat.begin(), stat.end()-3);
        		arr[i].statcode = stat;
        		
        		int length = out.length(); // Get User Row length
        		out.erase(out.begin()+(length-3), out.end());
            	arr[i].mainmsg = out;
            	i++;
		
			}
		}
		//cout << stat;
		for (int j=0; j<i;j++){
		if (arr[i].statcode == "100") {
			arr[i].msg="Sent_to_Manufacturer";
		}
		else if (arr[i].statcode == "105") {
			arr[i].msg = "Processing";
		}
		else if (arr[i].statcode == "200"){
			arr[i].msg = "Arrived";
		}
		else if (arr[i].statcode == "404"){
			arr[i].msg = "User_Collected";
		}
		else if (arr[i].statcode == "500"){
			arr[i].msg = "Refund";
		}
		}
		
		cout << arr[1].msg;
		for (int k=0; k<i;k++)
		{
			cout << "\n"<< arr[i].mainmsg << "" << arr[i].msg;
		}
		in.close();
	}
	else 
		cout << "\n UNAUTHORIZED ACCESS";
}


void login()
{
	char Resp;
	string fxName;
	string password,creds_db,creds;
	cout << "\n Choose Login type \n 1. Staff \n 2. Customers? Track your order Here. \n Response >> ";
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
			loginDB.open("WarrantyClaim.txt");
			level = "4";
			
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

////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////// ///////////MAIN BODY/FUNCTIONS ////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


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
	
	Dashboard();
	
	
	return 0;
}
