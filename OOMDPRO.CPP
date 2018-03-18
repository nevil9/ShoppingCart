#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
using namespace std;
class user
{
	protected:
	string username;
	string password;
};
class New_user:public user
{
	public:

	static int count;
	void set_up(string u,string p)
	{
	    cout<<u;
		username=u;
		password=p;

	}
	void display()
	{
		cout<<endl<<"Username is "<<username;
		cout<<endl<<"Password is "<<password;
	}
	string get_user()
	{
		return username;
	}
	string get_pass()
	{
		return password;
	}
};
int New_user::count;
New_user *nu;
void check(string u,string p,int x)
{
int f=0;
	while(x>=0)
	{
	if(u==nu[x].get_user())
	{
	       //	cout<<endl<<nu[x].get_pass();
		if(p==nu[x].get_pass())
		{
			cout<<endl<<"You are logged in!!! ";
			f=1;
			break;
		}
		else
			cout<<endl<<"Incorrect password !!!";
			f=1;
			cout<<"No user exist";
			break;
	}
	else
		x--;
	}
	if(f==0)
		cout<<"No user exist";
}

int main()
{

int i=0,j=0,n;
string uname,pass;

	do
	{
	cout<<endl<<"Press 1 for new user login"<<endl<<"Press 2 for existing user" <<endl<<"Press 3 to exit"<<endl;
	cin>>n;
	switch(n)
	{
		case 1:
		    cout<<"Enter user name : ";
			cin>>uname;
			cout<<"Enter password : ";
			cin>>pass;
			cout<<endl<<uname;
			nu[j].set_up(uname,pass);
			j++;
			break;
		case 2:
		    cout<<"Enter user name: ";
			cin>>uname;
			cout<<"Enter password: ";
			cin>>pass;
			cout<<"hello";
			check(uname,pass,j);
	}
	}while(n!=3);
	while(i<j)
	{
		nu[i].display();
		i++;
	}

}

