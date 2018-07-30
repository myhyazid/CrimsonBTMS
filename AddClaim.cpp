#include<iostream>
#include<fstream>
using namespace std;


void AddClaim () 
{

      int ID, time;
	  string CustName, ItemDesc, Status;
	  
    cout << "Please enter customer ID : " << endl;
    cin >> ID;
    
    cout << "Please enter customer name :  " << endl;
    cin >> CustName;
    
    cout << "Please enter the item description : " << endl;
    cin >> ItemDesc;
    
    cout << "Enter the estimated time for customer to receive the warranty : " << endl;
    cin >> time;
    
    cout << "Enter the status of the warranty claim : " << endl;
    cin >> Status;
    
    ofstream outfile;
    outfile.open("Warrantyclaim.txt", ios::app);
    outfile<<"\n";
    //outfile<<"ID     CUSTOMERNAME     ITEMDESC     TIME     STATUS";
    
    outfile<<"\n";
    outfile<<ID<<"     "<<CustName<<"     "<<ItemDesc<<"     "<<time<<"     "<<Status<<endl;
    outfile.close();
}
int main()
{
	
	AddClaim();
	return 0;
}
