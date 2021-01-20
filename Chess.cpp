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


using namespace std;

int random (int high, int low);
int game (int Y, int X);

int
main ()
{
  int choice, hight = 8, lenght = 8;
  int move = 0;

  while (true)
    {
      cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
	<< endl;
      cout << "1. Start a new game" << endl;
      cout << "2. Change the size of the desk" << endl;
      cout << "3. Exit" << endl;
      cout << "Enter what you want to do:";
      cin >> choice;
      while (choice < 1 || choice > 3)
	{
	  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
	    << endl;
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
	    cout <<
	      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<
	      endl;
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




int
game (int Y, int X)
{
  int count1 = 1, count2 = 0;
  int PosX[4];
  int PosY[4];
  int newp, newp1;
  int moves = 0;
  char fig;
  bool matted = 1;


  {				//Placement of pawns

    srand (time (NULL));
    PosX[0] = rand () % (X) + 1;	//player king X       
    PosY[0] = rand () % (Y) + 1;	//player king Y



    newp = rand () % (X) + 1;
    while (PosX[0] == newp)
      {
	newp = rand () % (X) + 1;	//Knight2 X     
      }
    PosX[3] = newp;
    newp = rand () % (Y) + 1;
    while (PosY[0] == newp)
      {
	newp = rand () % (Y) + 1;	//Knight2 Y
      }
    PosY[3] = newp;



    newp = rand () % (X) + 1;
    while (PosX[0] == newp || PosX[3] == newp)
      {
	newp = rand () % (X) + 1;	//Knight1 X             
      }
    PosX[2] = newp;
    newp = rand () % (Y) + 1;
    while (PosY[0] == newp || PosY[3] == newp)
      {
	newp = rand () % (Y) + 1;	//Knight1 Y

      }
    PosY[2] = newp;



    newp = rand () % (X) + 1;
    while (PosX[3] == newp || PosX[0] == newp || PosX[2] == newp
	   || PosX[0] + 1 == newp || PosX[0] - 1 == newp)
      {
	newp = rand () % (X) + 1;	//Enemy king X
      }
    PosX[1] = newp;
    newp = rand () % (Y) + 0;
    while (PosY[3] == newp || PosY[0] == newp || PosY[2] == newp
	   || PosY[0] + 1 == newp || PosY[0] - 1 == newp)
      {
	newp = rand () % (Y) + 1;	//Enemy king Y

      }
    PosY[1] = newp;
  }


  while (matted)
    {
      count1 = 1;
      count2 = 0;		//map drawing
      while (count1 <= Y)
	{
	  while (count2 < X + 2)
	    {
	      if (count2 == 0)
		{
		  cout << char (186) << " ";
		}
	      else if (count2 == X + 1)
		{
		  cout << char (186) << "\n";
		}
	      else if (count1 == PosY[0] && count2 == PosX[0])
		{
		  cout << "K" << " ";
		}
	      else if (count1 == PosY[1] && count2 == PosX[1])
		{
		  cout << "E" << " ";
		}
	      else if (count1 == PosY[2] && count2 == PosX[2])
		{
		  cout << "1" << " ";
		}
	      else if (count1 == PosY[3] && count2 == PosX[3])
		{
		  cout << "2" << " ";
		}
	      else
		cout << "_" << " ";
	      count2++;
	    }
	  count2 = 0;
	  count1++;
	}

      cout << "Enter the figure you want to move:";
      cin >> fig;
      while (fig != 75 && fig != 49 && fig != 50)
	{
	  cout << "Not a valid pawn.Chose a valid one:";
	  cin >> fig;
	}
      switch (int (fig))
	{
	case 75:
	  {
	    cout << "Enter the figures position:" << endl;
	    cout << "X=";
	    cin >> newp;
	    while (newp > 8 || newp < 1)
	      {
		cout <<
		  "You entered a value greater or lower than the boards range. Enter again:";
		cin >> newp;
	      }
	    while (newp > PosX[0] + 1 || newp < PosX[0] - 1)
	      {
		cout << "You entered an invalid possition.Enter again:";
		cin >> newp;
	      }
	    PosX[0] = newp;
	    cout << "Y=";
	    cin >> newp;
	    while (newp > 8 || newp < 1)
	      {
		cout <<
		  "You entered a value greater or lower than the boards range. Enter again:";
		cin >> newp;
	      }
	    while (newp > PosY[0] + 1 || newp < PosY[0] - 1)
	      {
		cout << "You entered an invalid possition.Enter again:";
		cin >> newp;
	      }
	    PosY[0] = newp;
	    moves++;
	    break;
	  }
	case 49:
	  {
	    cout << "Enter the figures position:" << endl;
	    cout << "X=";
	    cin >> newp;
	    cout << "Y=";
	    cin >> newp1;
	    while ((PosX[2] != newp && PosY[2] != newp1)
		   || (PosX[2] == newp && PosY[2] == newp1))
	      {
		cout << "You entered an invalid possition.Enter again:" <<
		  endl;
		cout << "X=";
		cin >> newp;
		cout << "Y=";
		cin >> newp1;
	      }
	    PosX[2] = newp;
	    PosY[2] = newp1;
	    moves++;
	    break;
	  }
	case 50:
	  {
	    cout << "Enter the figures position:" << endl;
	    cout << "X=";
	    cin >> newp;
	    cout << "Y=";
	    cin >> newp1;
	    while ((PosX[3] != newp && PosY[3] != newp1)
		   || (PosX[3] == newp && PosY[3] == newp1))
	      {
		cout << "You entered an invalid possition.Enter again:" <<
		  endl;
		cout << "X=";
		cin >> newp;
		cout << "Y=";
		cin >> newp1;
	      }
	    PosX[3] = newp;
	    PosY[3] = newp1;
	    moves++;
	    break;
	  }
	}
      if (((PosY[1] == 1 && PosY[1] == PosY[2]) && PosY[1] + 1 == PosY[3])
	  || ((PosY[1] == Y && PosY[1] == PosX[3]) && PosY[1] - 1 == PosY[2]))
	return moves;
      if (((PosY[1] == 1 && PosY[1] == PosY[3]) && PosY[1] + 1 == PosY[2])
	  || ((PosY[1] == Y && PosY[1] == PosX[2]) && PosY[1] - 1 == PosY[3]))
	return moves;
      if (((PosX[1] == 1 && PosX[1] == PosX[3]) && PosX[1] + 1 == PosX[2])
	  || ((PosX[1] == X && PosX[1] == PosX[2]) && PosX[1] - 1 == PosX[3]))
	return moves;
      if (((PosX[1] == 1 && PosX[1] == PosX[2]) && PosX[1] + 1 == PosX[3])
	  || ((PosX[1] == X && PosX[1] == PosX[3]) && PosX[1] - 1 == PosX[2]))
	return moves;

      if ((PosX[1] == 1 && PosY[1] == 1)
	  && (PosX[1] + 1 == PosX[2] || PosX[1] + 1 == PosX[3])
	  && (PosY[1] + 1 == PosY[2] || PosY[1] + 1 == PosY[3]))
	return moves;
      if ((PosX[1] == Y && PosY[1] == Y)
	  && (PosX[1] - 1 == PosX[2] || PosX[1] - 1 == PosX[3])
	  && (PosY[1] - 1 == PosY[2] || PosY[1] - 1 == PosY[3]))
	return moves;
      if ((PosX[1] == 1 && PosY[1] == Y)
	  && (PosX[1] - 1 == PosX[2] || PosX[1] - 1 == PosX[3])
	  && (PosY[1] + 1 == PosY[2] || PosY[1] + 1 == PosY[3]))
	return moves;
      if ((PosX[1] == Y && PosY[1] == 1)
	  && (PosX[1] + 1 == PosX[2] || PosX[1] + 1 == PosX[3])
	  && (PosY[1] - 1 == PosY[2] || PosY[1] - 1 == PosY[3]))
	return moves;

      if ((PosX[1] == 1 && PosY[1] == 1)
	  &&
	  (((PosX[1] + 1 == PosX[2] || PosX[1] + 1 == PosX[3])
	    && PosY[1] - 2 == PosY[0]) || ((PosY[1] + 1 == PosY[2]
					    || PosY[1] + 1 == PosY[3])
					   && PosX[1] - 2 == PosX[0])))
	return moves;
      if ((PosX[1] == Y && PosY[1] == Y)
	  &&
	  (((PosX[1] - 1 == PosX[2] || PosX[1] - 1 == PosX[3])
	    && PosY[1] + 2 == PosY[0]) || ((PosY[1] - 1 == PosY[2]
					    || PosY[1] - 1 == PosY[3])
					   && PosX[1] + 2 == PosX[0])))
	return moves;
      if ((PosX[1] == Y && PosY[1] == 1)
	  &&
	  (((PosX[1] - 1 == PosX[2] || PosX[1] - 1 == PosX[3])
	    && PosY[1] + 2 == PosY[0]) || ((PosY[1] + 1 == PosY[2]
					    || PosY[1] + 1 == PosY[3])
					   && PosX[1] - 2 == PosX[0])))
	return moves;
      if ((PosX[1] == 1 && PosY[1] == Y)
	  &&
	  (((PosX[1] + 1 == PosX[2] || PosX[1] + 1 == PosX[3])
	    && PosY[1] - 2 == PosY[0]) || ((PosY[1] - 1 == PosY[2]
					    || PosY[1] - 1 == PosY[3])
					   && PosX[1] + 2 == PosX[0])))
	return moves;

      if ((PosX[1] + 1 == PosX[2] || PosX[1] + 1 == PosX[3])
	  && (PosX[1] - 1 == PosX[2] || PosX[1] - 1 == PosX[3]))
	return moves;
      if ((PosY[1] + 1 == PosY[2] || PosY[1] + 1 == PosY[3])
	  && (PosY[1] - 1 == PosY[2] || PosY[1] - 1 == PosY[3]))
	return moves;


      newp = rand () % (PosX[1] + 1) + (PosX[1] - 1);
      newp1 = rand () % (PosY[1] + 1) + (PosY[1] - 1);
      while ((newp == PosX[2] || newp == PosX[3]
	      || (newp == PosX[0] + 1 || newp == PosY[0] - 1)) || (newp > X
								   || newp <
								   1))
	{
	  newp = rand () % (PosX[1] + 1) + (PosX[1] - 1);
	}
      while ((newp1 == PosY[2] || newp1 == PosY[3]
	      || (newp1 == PosY[0] + 1 || newp1 == PosY[0] - 1)) || (newp1 > Y
								     || newp1
								     < 1))
	{
	  newp1 = rand () % (PosY[1] + 1) + (PosY[1] - 1);
	}
      PosX[1] = newp;
      PosY[1] = newp1;
      cout << "X=" << PosX[1] << "\n" << "Y=" << PosY[1] << endl;
    }
}
