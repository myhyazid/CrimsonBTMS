#include <iostream>
#include <fstream>
using namespace std;

void AddTrans()
{
	int transID;
	string transDesc;
	float amount;
	
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

int main()
{
	AddTrans();
	return 0;
	
}
