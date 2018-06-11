#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <time.h>

using namespace std;


void Register();
void Login();

int main()
{
	Login();
	return 0;
}

void Register()
{
    char us_name[50],pass[50],confirm[50];
    do
    {
         cout<<"\n--------ACCOUNT SETUP PAGE--------";
         cout<<"\nEnter Username:";
         cin>>us_name;
         correct:
         cout<<"\n";
         cout<<"\nEnter Password:";
         cin>>pass;
         cout<<"\n";
         cout<<"\nConfirm Password:";
         cin>>confirm;
         }while(strcmp(pass,confirm)!=0);
        cout<<"\n\nName:"<<us_name;
        cout<<"\nPassword:"<<pass;
        cout<<"\n\nWriting Data To File";
        cout<<"\nPlease wait";
        for(int i=0;i<=10;i++)
        {
            cout<<".";
        }
        ofstream userfile ("user.txt");
        if(userfile.is_open())
        {
            userfile << us_name<<"\n";
            userfile.close();
        }
        ofstream passfile ("pass.txt");
        if(passfile.is_open())
        {
            passfile << pass << "\n";
            passfile.close();
        }
}
void Login()
{
	char login_un[50], login_pw[50], username[50], password[50];
	int c;
	ifstream uin("user.txt");
	ifstream pin("pass.txt");
	
	cout<<"Main\n\n"
		<<"(1) Login\n"
		<<"(2) Register\n"
		<<"(3) Quit\n";
	cin>> c;
	
	
	
	if (c==1)
	{
		uin.getline(username, 50);
		while (strcmp(login_un, username) !=0)
		{
			cout<<"Username: ";
			cin.getline(login_un, 50);
			if (strcmp(login_un, username) ==0) break;
			else
				cout<<"\nInvalid Username.\n";
		}
		
		pin.getline(password, 50);
		while (strcmp(login_pw, password) !=0)
		{
			cout<<"\nPassword: ";
			cin.getline(login_pw, 50);
			if (strcmp(login_pw, password) ==0)
			{
			 cout<<"You are succesfully logged in.";
			 break;
			}
			else
				cout<<"\nInvalid Password\n";
		}
		
	}
	
	else if (c==2)
	{
	    Register();
	}
	
	else if (c==3)
	{
		cout<<"Quitting\n";
		exit(1);
	}
	return;
}
