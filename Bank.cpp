#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<string.h>

using namespace std;
struct B_Customer
{
	char name[23];
	int acc_no;
	float amount;
	char login_id[34];
	char password[34];
};

void Bank_customer();
void Bank_employee();
void Bank_admin();
void New_customer(struct B_Customer B[]);
int Old_customer(struct B_Customer B[]);
int total_employee = 0;
void old_check_balance(struct B_Customer B[],int n);
void old_Deposite(struct B_Customer B[],int n);
void old_Transfer(struct B_Customer B[],int n);
void old_Withdraw(struct B_Customer B[],int n);
void old_Update(struct B_Customer B[],int n);
int main()
{
	
	int i,choice = 0;
	do
	{
		cout<<"\n\t\t\t****\t Welcome to HUluluuu Bank\t*****";
		cout<<"\n\t Enter 1: \t Bank Customer";
		cout<<"\n\t Enter 2: \t Bank Employee";
		cout<<"\n\t Enter 3: \t Bank Admin \t";
		cout<<"\n\t Enter 0: \t EXIT \t";
		cin>>choice;
		system("CLS");
		switch(choice)
		{
			case 1:Bank_customer();
			break;
			case 2:Bank_employee();
			break;
			case 3:Bank_admin();
			break;
			case 0: cout<<"\n\t\t\t Thank for coming to our Bank\n";
			break;
			default:
				cout<<" You have entered wrong choice Pls try again";
			
		}
	}while(choice!=0);
	return 0;
}
void Bank_customer()
{
	struct B_Customer B[34];
	int i,choice = 0;
	do
	{
		cout<<"\n\t Enter 1: \t New Customer";
		cout<<"\n\t Enter 2: \t Existing Customer\t";
		cout<<"\n\t Enter 0: \t Exit\t";
		cin>>choice;
		system("CLS");
		if(choice==0)
			cout<<"\n\t Thanks\n";
		else	
			if(choice==1)
			New_customer(B);
			else if(choice == 2)
					{
						int result = Old_customer(B);
						if(result == -1)
						{
							cout<<"\n\t YOUR ACCOUNT IS BLOCKED CONTACT NEAREST BRANCH\n";
							return ;
						}
					}
				else
					{
						cout<<"\nYou have entered wrong choice try again\n";
					}
	}while(choice!=0);
		
		
	
}


void New_customer(struct B_Customer B[])
{

	int i;
	cout<<"\n\t Enter customer Name:\t";
	cin>>B[total_employee].name;
	cout<<"\n\t Enter customer Account Number:\t";
	cin>>B[total_employee].acc_no;
	cout<<"\n\t Enter Starting Deposited amount:\t";
	cin>>B[total_employee].amount;
	cout<<"\n\t Enter Login Id:\t";
	cin>>B[total_employee].login_id;
	cout<<"\n\t Enter Password:\t";
	cin>>B[total_employee].password;
	total_employee++;
	cout<<"\n\t\t\t*****\t Your Account Created Successfully\t*****";
	cout<<"\n\t Now, Login with your user name and password\n";
	Old_customer(B)	;
	
}
int Old_customer(struct B_Customer B[])
{
	char l_id[34],pswd[34];
	int cid=-1,fail_login_count =0,fail_pswd_count = 0, choice=0;

	int i;
	//cout<<"\n\t\t\t Hi, Login  Id and password";
L:	cout<<"\n\t Enter Login Id \t";
	cin>>l_id;
	for(i=0;i<total_employee;i++)
	{
			if(strcmp(l_id,B[i].login_id)==0)
			{
				cid = i;
				break;
			}
	}
	if(i==total_employee)
	{
		cout<<"\n\t You have entered wrong Login id";
		fail_login_count++;
		if(fail_login_count==3)
		{
			cout<<"\n\t######Your account is blocked contact to Bank Manager\n";
			return -1;
		}
		else
		goto L;
		
	}

L1:	cout<<"\n\t Enter Password \t";
	cin>>pswd;
	if(strcmp(pswd,B[cid].password)==0)
		{
			do
			{
				cout<<"\nLogin Successful\n";
				cout<<"\n\t Enter 1: \t Check Balance";
				cout<<"\n\t Enter 2: \t Deposite amount";
				cout<<"\n\t Enter 3: \t Transfer Amount";
				cout<<"\n\t Enter 4: \t Withdraw amount";
				cout<<"\n\t Enter 5: \t Update Information";
				cout<<"\n\t Enter 0: \t Exit\t";
				cin>>choice;
				system("CLS");
				switch(choice)
				{
					case 1:old_check_balance(B,cid);
					break;
					case 2:old_Deposite(B,cid);
					break;
					case 3:old_Transfer(B,cid);
					break;
					case 4:old_Withdraw(B,cid);
					break;
					case 5:old_Update(B,cid);
					break;
					case 0: cout<<"\n\t\t\t Thank for coming to our Bank\n";
					break;
					default:
						cout<<" You have entered wrong choice Pls try again";
					
				}
			}while (choice!=0);
			
		}
	else
	{
		cout<<"\nLogin  NOOT Successful\n";
		fail_pswd_count++;
		if(fail_pswd_count==3)
		{
			cout<<"\n\t######Your account is blocked contact to Bank Manager\n";
			return -1 ;
		}
		else
		goto L1;
	}
	
		
	
	
	
}


void old_check_balance(struct B_Customer B[],int cid)
{
	cout<<"\n\t Your Account Balance is : \t "<<B[cid].amount<<"\n";
}
void old_Deposite(struct B_Customer B[],int cid)
{
		cout<<"\n\t Your Account Balance is : \t "<<B[cid].amount<<"\n";
		cout<<"\n\t Enter amount you want to deposite:\t";
		int amt;
		cin>>amt;
		B[cid].amount += amt;
		cout<<"\n\t Your Account Balance is : \t "<<B[cid].amount<<"\n";
}
void old_Transfer(struct B_Customer B[],int cid)
{
		cout<<"\n\t Enter the Account number of receiver";
		int accno;
		cin>>accno;
		int R_cid = -1;
		for(int i=0;i<total_employee;i++)
		{
			if(accno == B[i].acc_no)
			{
				R_cid = i;
			}
		}
		if(R_cid == -1)
		{
			cout<<"\n\t Receiver account number not found\n\t Try again\n";
			old_Transfer(B,cid);
		}
		else
		{
			cout<<"\n\t Your Account Balance is : \t "<<B[cid].amount<<"\n";
			cout<<"\n\t Enter the amount to be transfer:\t";
			float amount;
			cin>>amount;
			if(amount <= B[cid].amount)
			{
				B[cid].amount -= amount;
				B[R_cid].amount += amount;
				cout<<"\n\t Your Account Balance is : \t "<<B[cid].amount<<"\n";
				cout<<"\n\t Amount Transferred\n";
			}
			else
			cout<<"\n\t You cant withdraw this much of amount\n";
		}
		
		
}
		

void old_Withdraw(struct B_Customer B[],int cid)
{
		cout<<"\n\t Your Account Balance is : \t "<<B[cid].amount<<"\n";
		cout<<"\n\t Enter amount you want to withdraw:\t";
		int amt;
		cin>>amt;
		if(amt <= B[cid].amount)
		{
			B[cid].amount -= amt;
			cout<<"\n\t Your Account Balance is : \t "<<B[cid].amount<<"\n";
		}
		else
		cout<<"\n\t You cant withdraw this much of amount\n";
}
void old_Update(struct B_Customer B[],int cid)
{
		cout<<"\n\tSelect the field that you want to update\n";
		cout<<"\n\t Enter 1: \t Update Name";
		cout<<"\n\t Enter 2: \t Update Login Id";
		cout<<"\n\t Enter 3: \t Update Password";
		int choice = 0;
		int cnt=0;
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"\n\tEnter new name: \t";
					char nm[34];
					cin>>nm;
					strcpy(B[cid].name,nm);
					cout<<"\n\t Name updated successfully\n";
					break;
			case 2: 
					cout<<"\n\t************\t\n";
					L3: cout<<"\n\tEnter new login_id: \t";
					char id[34];
					cin>>id;
					cnt=0;
					for(int i=0;i<total_employee;i++)
					{
						if(strcmp(id,B[i].login_id)==0)
						{
							cnt++;
						}
					}
					if(cnt==0)
					{
						strcpy(B[cid].login_id,id);
						cout<<"\n\t Login id update successfully\n";
					}
					else
					{
						cout<<"\n\t This login id is not available\n Try again\n";
						goto L3;
							
					}
					
					break;
			case 3: 
					cout<<"\n\t Enter new password: \t";
					char pswd[34];
					cin>>pswd;
					strcpy(B[cid].password,pswd);
					cout<<"\n\t Password updated successfully \n";
					break;
			default:
				cout<<"You have entered wrong choice\n";
		}
}



void Bank_employee()
{
	cout<<"\n Hi this is Bank Employee Dashboard \n";
}

void Bank_admin()
{
	cout<<"\n Hi this is admin Dashboard \n";
}

