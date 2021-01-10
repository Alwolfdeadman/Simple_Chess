#include<iostream>
#include<cstdlib>
#include<ctime>


using namespace std;

int random(int high, int low);
int game(int Y, int X);

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
					game(hight, lenght);
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




int game(int Y, int X)
{
	int count1=0 , count2=0;
	int oldPos[8];
	int newp;
	int moves=0;
	char fig;
	bool matted=1;

	srand(time(NULL));
	
	oldPos[0]=rand()%(X-1) + 1; //player king X
	oldPos[1]=rand()%(Y) + 0; //player king Y
	oldPos[2]=rand()%(X-1) + 1; //enemy king X
	oldPos[3]=rand()%(Y) + 0; //enemy king Y
	oldPos[4]=rand()%(X-1) + 1; //knight1 X
	oldPos[5]=rand()%(Y) + 0; //knight1 Y
	oldPos[6]=rand()%(X-1) + 1; //knight2 X
	oldPos[7]=rand()%(Y) + 0; //knight2 Y
	
	
	while(matted)
	{										//map drawing
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
				else if(count1==oldPos[1] && count2==oldPos[0])
				{
					cout<<"E"<<" ";
				}
				else if(count1==oldPos[3] && count2==oldPos[2])
				{
					cout<<"K"<<" ";
				}
				else if(count1==oldPos[5] && count2==oldPos[4])
				{
					cout<<"1"<<" ";
				}
				else if(count1==oldPos[7] && count2==oldPos[6])
				{
					cout<<"2"<<" ";
				}
				else cout<<"_"<<" ";
				count2++;
			}
		count2=0;
		count1++;
		}
		break;
		count1=0;
		count2=0;
//		cout<<"Enter the figure you want to move:";
//		cin>>fig;
//		while (fig!=75 && fig!=69 && fig!=49 && fig!=50)2
//		
//		{
//			cout<<"Not a valid pawn.Chose a valid one:";
//			cin>>fig;
//		}
//		switch (int(fig))
//		{
//			case 69:
//			{
//				cout<<"Enter the figures position:"<<endl;
//				cout<<"X=";
//				cin>>newp;
//				while(newp!=oldPos[0]+1 || newp!=oldPos[0]-1)
//				{
//					cin>>newp;
//				}
//				oldPos[0]=newp;
//				cout<<"Y=";
//				cin>>newp;
//				while(newp!=oldPos[1]+1 || newp!=oldPos[1]-1)
//				{
//					cin>>newp;
//				}
//				oldPos[0]=newp;
//				break;
//			}
//			case 75:
//			{
//				cout<<"Enter the figures position:"<<endl;
//				cout<<"X=";
//				cin>>newp;
//				while(newp==oldPos[2]+1 || newp==oldPos[2]-1)
//				{
//					cin>>newp;
//				}
//				oldPos[2]=newp;
//				cout<<"Y=";
//				cin>>newp;
//				while(newp==oldPos[3]+1 || newp==oldPos[3]-1)
//				{
//					cin>>newp;
//				}
//				oldPos[3]=newp;
//				break;
//			}
//			case 49:
//			{
//				cout<<"Enter the figures position:"<<endl;
//				cout<<"X=";
//				break;
//			}
//			case 50:
//			{
//				cout<<"Enter the figures position:"<<endl;
//				cout<<"X=";
//				break;
//			}
//		}
		
	}
	
	return moves;
}
