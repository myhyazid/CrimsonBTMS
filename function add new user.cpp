#include <iostream>
#include <fstream>

using namespace std;

void addUser()
{
	string name,password;
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
int main ()
{
	username();
	return 0;
}

