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
	int PosX[4];
	int PosY[4];
	int newp,newp1;
	int moves=0;
	char fig;
	bool matted=1;


	{		//Placement of pawns
		
		srand(time(NULL));
		PosX[0] = rand()%(X) + 1; //player king X	
		PosY[0] = rand()%(Y) + 0; //player king Y
		
		
		
		newp=rand()%(X) + 1;
		while(PosX[0]==newp )
		{
			newp=rand()%(X) + 1;     			//Knight2 X	
		}
		PosX[3]=newp;
		newp=rand()%(Y) + 0;
		while(PosY[0]==newp)
		{
			newp=rand()%(Y) + 0;     			//Knight2 Y
		}
		PosY[3]=newp;
		
		
		
		newp=rand()%(X) + 1;
		while(PosX[0]==newp || PosX[3]==newp)
		{
			newp=rand()%(X) + 1;     			//Knight1 X		
		}
		PosX[2]=newp;
		newp=rand()%(Y) + 0;
		while(PosY[0]==newp || PosY[3]==newp)
		{
			newp=rand()%(Y) + 0;     			//Knight1 Y
			
		}
		PosY[2] = newp;
		
		
		
		newp=rand()%(X) + 1;
		while(PosX[3]==newp || PosX[0]==newp || PosX[2]==newp || PosX[0]+1==newp || PosX[0]-1==newp)
		{
			newp=rand()%(X) + 1;     			//Enemy king X
		}
		PosX[1]=newp;
		newp=rand()%(Y) + 0;
		while(PosY[3]==newp || PosY[0]==newp || PosY[2]==newp|| PosY[0]+1==newp || PosY[0]-1==newp)
		{
			newp=rand()%(Y) + 0;     			//Enemy king Y
			
		}
		PosY[1] = newp;
	}
	

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
				else if(count1==PosY[0] && count2==PosX[0])
				{
					cout<<"K"<<" ";
				}
				else if(count1==PosY[1] && count2==PosX[1])
				{
					cout<<"E"<<" ";
				}
				else if(count1==PosY[2] && count2==PosX[2])
				{
					cout<<"1"<<" ";
				}
				else if(count1==PosY[3] && count2==PosX[3])
				{
					cout<<"2"<<" ";
				}
				else cout<<"_"<<" ";
				count2++;
			}
		count2=0;
		count1++;
		}
		count1=0;
		count2=0;
		cout<<"Enter the figure you want to move:";
		cin>>fig;
		while (fig!=75 && fig!=49 && fig!=50)
		{
			cout<<"Not a valid pawn.Chose a valid one:";
			cin>>fig;
		}
		switch (int(fig))
		{
			case 75:
			{
				cout<<"Enter the figures position:"<<endl;
				cout<<PosX[0]<<" "<<PosY[0]<<endl;
				cout<<"X=";
				cin>>newp;
				while(newp!=PosX[0]+1 && newp!=PosX[0]-1 && newp!=PosX[0])
				{
					cout<<"You entered an invalid possition.Enter again:";
					cin>>newp;
				}
				PosX[0]=newp;
				cout<<"Y=";
				cin>>newp;
				while(newp!=PosY[0]+1 && newp!=PosY[0]-1 && PosY[0])
				{
					cin>>newp;
				}
				PosY[0]=newp;
				moves++;
				break;
			}
			case 49:
			{
				cout<<"Enter the figures position:"<<endl;
				cout<<"X=";
				cin>>newp;
				cout<<"Y=";
				cin>>newp1;
				while((PosX[2]!=newp && PosY[2]!=newp1) || (PosX[2]==newp && PosY[2]==newp1))
				{
					cout<<"You entered an invalid possition.Enter again:";
					cout<<"X=";
					cin>>newp;
					cout<<"Y=";
					cin>>newp1;
				}
				PosX[2]=newp;
				PosY[2]=newp1;
				moves++;
				break;
			}
			case 50:
			{
				cout<<"Enter the figures position:"<<endl;
				cout<<"X=";
				cin>>newp;
				cout<<"Y=";
				cin>>newp1;
				while((PosX[3]!=newp && PosY[3]!=newp1) || (PosX[3]==newp && PosY[3]==newp1))
				{
					cout<<"You entered an invalid possition.Enter again:";
					cout<<"X=";
					cin>>newp;
					cout<<"Y=";
					cin>>newp1;
				}
				PosX[3]=newp;
				PosY[3]=newp1;
				moves++;
				break;
			}
		}
		
	}
	
	return moves;
}
