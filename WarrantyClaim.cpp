#include<iostream>
#include<cstring>
#include<cctype>
#include<fstream>
#include<iomanip>
#include <vector>
#include <sstream>
using namespace std;
 void AddClaim()
 { 
  int ID, time;
  string CustName, ItemDesc, Status;
  
  cout << "\nPlease enter customer ID : " ;
  cin >> ID;
  
  cout << "\nPlease enter customer name : ";
  cin >> CustName;
  
  cout << "\nPlease enter item description : ";
  cin >> ItemDesc;
  
  cout << "\nEnter the estimated time for customer to receive the warranty : ";
  cin >> time;
  
  cout << "\nEnter the status of the warranty claim : ";
  cin >> Status;
  
  ofstream outfile;
  outfile.open("WarrantyClaim.txt" , ios::app);
  outfile << "\n";
  outfile << ID << "\t " << CustName << "\t " << ItemDesc << "\t " << time << "\t " << Status << endl;
  outfile.close();
 }
 
void ViewClaim()
{  
struct details
{
	int id;
	string name;
	string custname;
	string itemdescr;
	int eta;
	string status;	
};

	details arr[100];
	
	string line;
	
	ifstream inFile("WarrantyClaim.txt");
	 if (inFile.is_open())
    {
        std::string line;
        while( std::getline(inFile,line) )
        {
            std::stringstream ss(line);

            std::string ID, fname, lname;
            std::getline(ss,ID,'\t');    std::cout<<"\t"<<ID<<"\t";
            std::getline(ss,fname,'\t'); std::cout<<"\t "<<fname<<"\t";
            std::getline(ss,lname,'\t'); std::cout<<"\t"<<lname<<"\t";

            std::vector<std::string> enrolled;
            std::string course;
            while( std::getline(ss,course,'\t') )
            {
                 enrolled.push_back(course); //std::cout<<"\t id: "<<ID<<"\t";
            }
            std::cout<<"\n m" << ID;
        }
    }
}
	
	
	

  //void UpdateClaim()
//{  ofstream outfile("custdata.txt");
   //ifstream infile("custdata.txt");
   
   //infile >>
   
   
//}
 
 
int main()
{ char ans, ch;
 AddClaim();
 ViewClaim();
 
 //cout << "\nDo you want to update the warranty claim ? (Y/N) :";
 //cin >> ans;
 
 //if ((ans == 'y') || (ans == 'y'))
 //UpdateClaim();
 
 //else
  //cout << "\nPress any key to continue :";
  //cin >> ch;
 
 return 0;
}
