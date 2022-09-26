/**
*  
* Solution to course project # 09
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Mincho Hristov
* @idnumber 62551
* @compiler gcc
*
* This is a simlified version of chess.It is played with 2 knights and 1 king .
* The goal of the game is to take the enemy king with the least amout of moves.
* You can change the size of the map to as much a you want but the minimal size is 5 or it will bug.
*
*
*/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>


using namespace std;


struct piece 
{
	char p;
	int x,y;
};


int game(const int &Y,const int &X);
void setPrime(vector<piece> &p, const char* c, const int &X, const int &Y);
void print(const vector<piece> &p, const int &Y,const int &X);

int main ()
{
	int choice, hight = 8, lenght = 8;
	int move = 0;
  	while (true)
    {
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
    	cout << "1. Start a new game" << endl;
    	cout << "2. Change the size of the desk" << endl;
		cout << "3. Exit" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
  		cout << "Enter what you want to do:";
    	cin >> choice;
    	cout<<endl;
    	while (choice < 1 || choice > 3)
		{
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
	  		cout << "You entered an invalid option.Enter again:";
	  		cin >> choice;
		}
    	switch (choice)
		{
		case 1:
	  	{
		    move = game (hight, lenght);
		    cout << "Congratulations you have won!!!";
		    cout << "Finished in :" << move;
		    break;
		}
		case 2:
	  	{
	    	cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
	    	cout << "Enter the new hight:";
	    	cin >> hight;
	    	cout << "Enter the new lenght:";
	    	cin >> lenght;
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
void print(const vector<piece> &p, const int &Y,const int &X)
{
	int i=0;
	cout<<"    ";
	while(i<Y)
		cout<<i++<<" ";
	i=0;
	cout<<endl;
	while(i<Y)
	{
		int j=0;
		while(j<X+2)
		{
			if(j == 0)
		  		cout<<i<<" "<<char (186)<<" ";
			else if(j == X+1)
		  		cout<<char (186)<<"\n";
			else if(i == p[0].y && j-1 == p[0].x)
			{
				cout<<p[0].p<<" ";
			}
			else if(i == p[1].y && j-1 == p[1].x)
			{
				cout<<p[1].p<<" ";
			}
			else if(i == p[2].y && j-1 == p[2].x)
			{
				cout<<p[2].p<<" ";
			}
			else if(i == p[3].y && j-1 == p[3].x)
			{
				cout<<p[3].p<<" ";
			}
			else 
			{
				cout<<"_ ";
			}
			j++;
		}
		i++;
	}
	
}
void setPrime(vector<piece> &p, const char* c, const int &X, const int &Y)
{
	piece tmp;
	srand (time (NULL));

	switch(*c)
	{
		case 'K':
		{
			tmp.x = rand()%(X);
    		tmp.y = rand()%(Y);
			tmp.p = 'K';
			break;
		}case '1':
		{
			tmp.x = rand()%(X);    
    		tmp.y = rand()%(Y);
    		while(tmp.x == p[0].x && tmp.y == p[0].y)
    		{
				tmp.x = rand()%(X);
    			tmp.y = rand()%(Y);
    		}
			tmp.p = '1';
			break;
		}case '2':
		{
			tmp.x = rand()%(X);
    		tmp.y = rand()%(Y);
    		while((tmp.x == p[0].x && tmp.y == p[0].y)
				|| (tmp.x == p[1].x && tmp.y == p[1].y))
				{
	    			tmp.x = rand()%(X);
    				tmp.y = rand()%(Y);
    			}
			tmp.p = '2';
			break;
		}case 'P':
		{
			tmp.x = rand()%(X);
			tmp.y = rand()%(Y);
    		while((tmp.x<=p[0].x+1 && tmp.x>=p[0].x-1 && tmp.y<=p[0].y+1 && tmp.y>=p[0].y-1)
    		     ||tmp.x == p[1].x || tmp.y == p[1].y
       		     ||tmp.x == p[2].x || tmp.y == p[2].y
				 )
				{
	    			tmp.x = rand()%(X);
    				tmp.y = rand()%(Y);
    			}
			tmp.p = 'P';
			break;
		}
	}
	p.push_back(tmp);
}


int game(const int &Y,const int &X)
{
	int moves=0;
	vector<piece> p;
	bool notMatted=true;
	
	setPrime(p,"K",X,Y);
	setPrime(p,"1",X,Y);
	setPrime(p,"2",X,Y);
	setPrime(p,"P",X,Y);


	bool **mat;
	mat=new bool*[Y];
	for(int i=0;i<Y;i++)
		mat[i]=new bool[X];	
	

	
	while(notMatted)
	{
		char fig;
		int x, y, i=0;
		print(p, Y, X);

		cout << "Enter the figure you want to move:";
      	cin >> fig;
      	while (fig != '1' && fig != '2' && fig != 'K' && fig != 'k')
		{
		  	cout << "Not a valid pawn.Chose a valid one:";
		  	cin >> fig;
		}
		switch((int)fig)
		{
			case'k':
			case'K':
			{
				cout<<"Enter the figures position.\nX=";
			    cin>>x;
			    cout<<"Y=";
			    cin>>y;
			    while(x<p[0].x-1 || x>p[0].x+1 || x<0 || x>=X || y<p[0].y-1 || y>p[0].y+1 || y<0 || y>=Y)
			    {
			    	cout <<"The king can't reach such a possition or it's out of bounds.\nX=";
					cin >> x;
			    	cout <<"Y=";
					cin >> y;
				}
				p[0].x=x;
				p[0].y=y;
				break;
			}
			case'1':
			case'2':
			{
				cout<<"Enter the figures position.\nX=";
			    cin>>x;
			    cout<<"\nY= ";
			    cin>>y;

				if(fig == '1')
				{
				    while((p[1].x!=x && p[1].y!=y) || (p[1].x==x && p[1].y ==y) || x<0 || x>=X || y<0 || y>=Y)
			    	{
			    		
			    		cout <<"The knight cant move to such a location or it's out of bounds.\nX= ";
						cin >> x;
						cout<<"Y= ";
						cin>>y;
					}
					p[1].x=x;
					p[1].y=y; 
				}else
				{
				    while((p[2].x!=x && p[2].y!=y) || (p[2].x==x && p[2].y ==y) || x<0 || x>=X || y<0 || y>=Y)
			    	{
			    		cout <<"The knight cant move to such a location or it's out of bounds.\nX= ";
						cin >> x;
						cout<<"Y= ";
						cin>>y;
					}
					p[2].x=x;
					p[2].y=y;
				}
				break;
			}
		}
		
		while(i<Y)
		{
			int j=0;
			while(j<X)
			{
				if (j == p[1].x || i == p[1].y || j == p[2].x || i == p[2].y 
				|| (j<=p[0].x+1 && j>=p[0].x-1 && i<=p[0].y+1 && i>=p[0].y-1))
					mat[i][j]=1;
				else 
					mat[i][j]=0;
				if((j==p[1].x && i==p[1].y && j!=p[2].x && i!=p[2].y) || (j==p[2].x && i==p[2].y && j!=p[1].x && i!=p[1].y))
					mat[i][j]=0;
				j++;
			}
			i++;
		}
		
		moves++;
		if((p[3].y-1 == -1 || (mat[p[3].y-1][p[3].x-1] && mat[p[3].y-1][p[3].x] && mat[p[3].y-1][p[3].x+1])) &&
		   (p[3].y+1 ==  Y || (mat[p[3].y+1][p[3].x-1] && mat[p[3].y+1][p[3].x] && mat[p[3].y+1][p[3].x+1])) &&
		   (p[3].x-1 ==  0 || mat[p[3].y][p[3].x-1]) &&
		   (p[3].x+1 == X+1 || mat[p[3].y][p[3].x+1]))
		   {
		   		notMatted=false;
		   		break;
		   }
			
			
		do{ 
			x=rand()%(3)-1;
     		y=rand()%(3)-1;
     		x+=p[3].x;
     		y+=p[3].y;
     		
			if (!(mat[y][x]) && x == p[1].x && y == p[1].y)
		    {
			  	p[1].x=-1;
			  	p[1].y=-1;
			  	break;
		  	}
			else if((!mat[y][x]) && x == p[2].x && y == p[2].y)
			{
			  	p[2].x=-1;
			  	p[2].y=-1;
			  	break;				
			}
		}while(mat[y][x] || !(x>=0 && x<X) || !(y>0 && y<Y)
		    || x<p[3].x-1 ||  x>p[3].x+1 || y<p[3].y-1 ||  y>p[3].y+1
			|| (x==p[3].x && y==p[3].y));
	  	p[3].x=x;
		p[3].y=y;
	}
	return moves;
}
