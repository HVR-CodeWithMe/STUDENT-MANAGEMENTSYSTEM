#include<conio.h>
#include<iostream>
#include<string.h>
#include<process.h>
using namespace std;
int i = 1;
struct sfio
{
	int sid;
	char fname[30];
	char lname[20];
	char sdob[13];
	char fee[10];
	char course[10];
} s[20];
class M
{
  public:int a, n,o;

	char ch;
	void add();
	void list();
	void update();
	void del();

	  M()
	{
		cout << "WELCOME TO LOGIN PORTAL\n";
		 cout<<"**********************************************\n";
		 	cout << "\t login as\n1.Admin\n2.student\n3.exit\n";
		cin>>o;
		if (o == 1)
		{
			char u[30], p[30];
			  cout << "welcome to admin portal\n";
			  	    cout<<"**********************************************\n";

			  cout<<"please enter \n\tUsername:";
			  cin >> u;
			  cout << "\n\tPassword:";
			  cin >> p;
			if (((strcmp(u, "HVR") == 0) || (strcmp(u, "MAMMU") == 0))
				&& ((strcmp(p, "0000")) == 0 || strcmp(p, "1111") == 0))
			{
				cout << "\n\n\tWELCOME\n";
				
				while(1)
				{
					cout<<"**********************************************\n";
					cout << "1.add\n2.list\n3.update\n4.delete\n5.logout\n6.exit\n";
					cout << "enter your choice\n";
					fflush(stdin);
					cin >> a;
					if(a==1)
						add();
					else if (a == 2)
						list();
					else if (a == 3)
						update();
					else if (a == 4)
						del();
					else if (a == 5)
					{
						M();
						break;
					}

					else if(a==6)
						  exit(0);
					else
					  break;
				}
			}
			else
			{
				cout<<"!!!!!!INVALID USER NAME OR PASSWORD!!!!!!\n";
				cout<<"*********************************************************\n";
				M();
			}
		}
		else if(o==2)
		{
			cout << "welcome to student portal\n";
			int id, k , o,m=0;
			char c, u[30];
					cout << "\tEnter your id :";
					cin >> id;
					cout << "\n\tEnter password:";
					cin >> u;

					for(k=1;k<=i;k++)
					{
						if ((id == s[k].sid) && (strcmp(u, s[k].sdob) == 0))
						{

							cout << "first name\t " << s[k].fname;
							cout << "\nlast name\t " << s[k].lname << "\n";
							cout << "roll num:\t" << s[k].sid << "\n";
							cout<<"date of birth"<<s[k].sdob<<"\n";
							cout<<"fess\t"<<s[k].fee<<"\n";
								cout<<"course\t"<<s[k].course<<"\n";
							m=1;
							cout<<"************************************************************\n";
						}
												
						
					}
					if(m==0)
					{
					cout<<"!!!!!!!INVALID USER NAME OR PASSWORD!!!!!!!\n";
					cout<<"************************************************************\n";
					
					M();
				}
				cout << "1.logout\n2.exit\n";
				cin >> o;
				 if (o == 1)
				{	
					 M();
				}
				else
				{
					exit(0);
				}
			
		}
		else
		exit(0);
		}

};

void M::add()
{
	cout << "enter first name\n";
	cin >> s[i].fname;
	cout << "enter last name\n";
	cin >> s[i].lname;
	cout << "enter roll number\n";
	cin >> s[i].sid;
	cout << "enter date of birth(DD-MM-YYYY)\n";
	cin >> s[i].sdob;
	cout << "enter course\n";
	cin >> s[i].course;
	cout << "fess paid or not\n";
	cin >> s[i].fee;
	i = i + 1;
}

void M::list()
{
	for (int j = 1; j < i; j++)
	{
		cout << "first name\t " << s[j].fname;
		cout << "\nlast name\t " << s[j].lname << "\n";
		cout << "roll num:\t" << s[j].sid << "\n";
		cout<<" date of birth\t"<<s[j].sdob<<"\n";
		cout<<" course\t"<<s[j].course<<"\n";
		cout<<" fess\t"<<s[j].fee<<"\n";
			    cout<<"**************************\n";

	}
	if(i==1)
	cout<<"list is empty\n";
}

void M::update()
{
	int n, j, u,S=1;
	char ch;
	cout << "enter the id of student to update details\n";
	cin >> n;
	for (j = 1; j <= i; j++)
		if (n == s[j].sid)
		{
			cout << "1.change Id \n2.change first name\n3. change last name\n4.change date of birth\n5.change course\n6.change fees status\n";
			cin >> u;
			S=0;
			switch (u)
			{
			case 1:
				cout << "Enter new id\n";
				cin >> s[j].sid;
				break;
			case 2:
				cout << "Enter new fname\n";
				cin >> s[j].fname;
				break;
			case 3:
				cout << "Enter new lname\n";
				cin >> s[j].lname;
				break;
			case 4:
				cout << "Enter new date of birth\n";
				cin >> s[j].sdob;
				break;
			case 5:
				cout << "Enter new course\n";
				cin >> s[j].course;
				break;
				
			case 6:
				cout << "fees paid or not\n";
				cin >> s[j].fee;
				break;
			}
		}
			if(S!=0)
			cout<<" !!!!!!INVALID ID!!!!!\n";
			else
			cout << "UPDATED SUCCUESSFUL\n";
	
}
void M::del()
{
	cout << "enter roll no of student to delete data\n";
	cin >> n;
	int H=0;
	for (int j = 1; j < i; j++)
	{
		if (n == s[j].sid)
		{
			H=1;
			for (int k = j; k < i; k++)
			{
				s[k].sid = s[k + 1].sid;
				strcpy(s[k].fname, s[k + 1].fname);
				strcpy(s[k].lname, s[k + 1].lname);
				strcpy(s[k].sdob, s[k + 1].sdob);
				strcpy(s[k].course, s[k + 1].course);
				strcpy(s[k].fee, s[k + 1].fee);
			
			}

		}
	i = i - 1;
		}
		if(H==0)
			cout<<" !!!!!!INVALID ID!!!!!\n";
			else
			cout << "DELETED SUCCESSFUL\n";
}

int main()
{
	M m;
}