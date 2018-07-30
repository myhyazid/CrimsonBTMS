#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void view_user()
	
	{
		string a,b;
	ifstream view_user;
	view_user.open("DBlogin.txt");
	
	do{
		view_user >> a >>b;
	cout << a <<"      "<< b << endl;
	}
	while(!view_user.eof());
}

int main()
{    
	view_user;
	
	system ("pause");	
	return  0;
}
