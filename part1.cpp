#include<iostream>
#include<cstdlib>
#include<ctime>


using namespace std;

void game(int Y, int X);

int main()
{
	int choice, hight=8, lenght=8;
	int moves=0;
	
	while(true)
	{
		cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"1. Start a new game"<<endl;
		cout<<"2. Change the size of the desk"<<endl;
		cout<<"3. Exit"<<endl;
		cout<<"Enter what you want to do:";
		cin>> choice;
		while(choice < 1 || choice > 3)
		{
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			cout<<"You entered an invalid option.Enter again:";
			cin>>choice;
		}
		switch (choice)
		{
			case 1:
				{
					while (true)
					{
						game(hight, lenght);
						break;
					}
					break;
				}
			case 2:
				{
					cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
					cout<<"Enter the new hight:";
					cin>> hight;
					cout<<"Enter the new lenght:";
					cin>> lenght;
					break;
				}
			case 3:
				{
					return 0;
					break;
				}
		}
	}
}




void game(int Y, int X)
{
	int count1=0 , count2=0;
	while(count1<Y)
	{
		while(count2<X+2)
		{
			if(count2==0)
			{
				cout<<char(186)<<" ";
			}
			else if(count2==X+1)
			{
				cout<<char(186)<<"\n";
			}
			else cout<<"_"<<" ";
			count2++;
		}
	count2=0;
	count1++;
	}
	

}
