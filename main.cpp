#include<iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>
#include <cstring> 
#include <string>
using namespace std;
// Hangman 
class Hangman{
int tries = 3;
string message = "You have 3 chances!";
public:

void hangmanmain()
{
    char letter;
    string month;
    string months[] = {
        "january", "february", "march", "april", "may", "june",
        "july", "august", "september", "october", "november", "december",
    };

    srand(time(NULL));
    int month_no = rand() % 12;
    month = months[month_no];

    string hide_month(month.length(), 'X');

    system("cls");

    while (tries != 0)
    {
        hang_man('n');
        cout << "\t\t\t\tLife: " << tries << endl;
        cout << "\t\t\t\t" << hide_month << endl;
        cout << "\t\t\t\tGuess a letter: ";
        cin >> letter;

        system("cls");

        if (checkGuess(letter, month, hide_month) == 0)
        {
            message = "Incorrect Letter";
            tries--;
        }
        else
        {
            message = "Nice! Correct Guess";
        }

        if (hide_month == month)
        {
            message = "You're Free!";
            hang_man('f');
            cout << "\t\t\t\tLife: " << tries << endl;
            cout << "\t\t\t\tThe month is: " << month;
            break;
        }
    }

    if (tries == 0)
    {
        message = "You're Hanged!";
        hang_man('h');
        cout << "\t\t\t\tLife: " << tries << endl;
        cout << "\t\t\t\tThe month is: " << month;
    }
    
}

int checkGuess(char guess, string real_month, string& hidden_month)  
{
    int matches = 0;
    int len = real_month.length();
    for (int i = 0; i < len; i++)
    {
        if (guess == hidden_month[i])
        {
            return 0;  
        }
        if (guess == real_month[i])
        {
            hidden_month[i] = guess;
            matches++;
        }
    }
    return matches;
}

void  hang_man(char state)
{
    string head_string = "|";
    string stage = "=";
    string liver = "|";
    if (state == 'f')
    {
        liver = "\\";
        head_string = " ";
    }
    else if (state == 'h')
    {
        stage = " ";
        liver = "/";
    }

    cout << "\t\t\t\t_________________" << endl;
    cout << "\t\t\t\t        " << head_string << "       |" << endl;
    cout << "\t\t\t\t        o       |" << endl;
    cout << "\t\t\t\t       / \\      |" << "\t      " << message << endl;
    cout << "\t\t\t\t        |       |" << "\t          /" << endl;
    cout << "\t\t\t\t       / \\      |               o  " << endl;
    cout << "\t\t\t\t    ==" << stage << stage << stage << stage << stage << stage << "==  |              / \\" << endl;
    cout << "\t\t\t\t    |        |  |               |" << endl;
    cout << "\t\t\t\t    |        |  |    _" << liver << "_       / \\" << endl;
    cout << "\t\t\t\t====================|===|===============" << endl;
}

};

//Guess no
int guess_no()
{
	srand(static_cast<unsigned int>(time(0)));
	
	int low= 1;
    int up= 100;
    int g;
    char ch='Y';
    
    do{
     int rand_no=low+rand()%(up-low+1);
     bool game= true;
     int chance=5;
     cout<<"\nGuess the Random number Between "<<low<<" and "<<up<<" :";

     
    while(game)
    { 
      if(chance>=1)
  {
     cin>>g;
    if(g<rand_no)
    {
    cout<<"\n Too Low";
    chance--;
    
    if (chance!=0) cout<<"\n"<<chance<<" chances are remaining!!!";
    else cout<<"\nYou are out of chances!";
    
    if (chance>0) cout<<"\n\n Guess the number above "<<g<<": ";
    }
    else if(g>rand_no)
    {
     cout<<"\n Too High";
	 chance--;	
    if (chance!=0) cout<<"\n"<<chance<<" chances are remaining!!!";
    else cout<<"\nYou are out of chances!";
    if (chance>0) cout<<"\n\n Guess the number below: "<<g<<":";
	 
	}
	else
	{
	 cout<<"\n Hooray! YOU WON.??";
	 game=false;
    }  
  }
  else{
  	cout<<"\n\n\nOops! YOU LOSE.?? \n Answer -> "<<rand_no;
  	game=false;
  }
}
   cout<<"\n\n\n Do you want to play again if YES then enter Y else Enter  N :";
   cin>>ch;
 }while(ch=='Y'|| ch=='y');
 
 return 0;
}


//stone-paper-scissors
void s_p_s()
{    
    char ch[3];
    int input;
	srand(static_cast<unsigned int>(time(0)));
	int low = 1;
	int up = 3;
    
    cout << "    ...WELCOME TO...";
    cout << "\n STONE-PAPER-SCISSOR ";
	cout << "\n       <-GAME->";
	cout << "\n\n ";
	cout << "\n GAME'S INSTRUCTIONS =>";
	cout << "\n * PRESS (1) for STONE.\n * PRESS (2) for PAPER.\n * PRESS (3) for SCISSOR.";
    
    do {	
        cout << "\n\n\n Enter 'S' to START the GAME OR 'EX' to EXIT: ";
        cin >> ch;

        if (strcmp(ch, "S") == 0 || strcmp(ch, "s") == 0)
        {
            bool game = true;
            while (game)
            {
                for (int i = 1; i < 4; i++)
                {
                    cout << "\n Choose Stone, Paper, Or Scissor: ";
                    cin >> input;

                    if (input == 1)
                    {
                        cout << R"(
    ___
---'   __)
      (_ )
      (__ )
      (_ )
---._ (_)

)";
                    }
                    else if (input == 2)
                    {
                        cout << R"(
    _
---'   ) __
          ___)
          ____)
         ____)
---._______)

)";
                    }
                    else if (input == 3)
                    {
                        cout << R"(    
    _
---'   ) _ _
       _  _ _ )
       ___ _ )
      (_ )
---._(__)
 
)";
                    }
                    else
                    {
                        cout << "\n\n INVALID INPUT...";
                        continue;
                    }

                    int rand_no = low + rand() % (up - low + 1);
                    if (rand_no == 1)
                    {
                        cout << R"(
    ___
---'   __)
      (_ )
      (__ )
      (_ )
---._ (_)

)";
                        if (input == 1)
                            cout << "\n TIE :|\n\n";
                        else if (input == 2)
                            cout << "\n YOU WON :)\n\n";
                        else if (input == 3)
                            cout << "\n YOU LOSE :(\n\n";
                    }
                    else if (rand_no == 2)
                    {
                        cout << R"(
    _
---'   ) __
          ___)
          ____)
         ____)
---._______)

)";
                        if (input == 2)
                            cout << "\n TIE :|\n\n";
                        else if (input == 3)
                            cout << "\n YOU WON :)\n\n";
                        else if (input == 1)
                            cout << "\n YOU LOSE :(\n\n";
                    }
                    else if (rand_no == 3)
                    {
                        cout << R"(    
    _
---'   ) _ _
       _  _ _ )
       ___ _ )
      (_ )
---._(__)
 
)";
                        if (input == 3)
                            cout << "\n TIE :|\n\n";
                        else if (input == 1)
                            cout << "\n YOU WON :)\n\n";
                        else if (input == 2)
                            cout << "\n YOU LOSE :(\n\n";
                    }
                }
                
                char c;
                cout << "\n\n Do you want to continue? Enter 'Y' to continue or 'Q' to go back to home: ";
                cin >> c;
                if (c == 'Y' || c == 'y')
                {
                    cout << "\n YES \n";
                }
                else if(c == 'Q' || c != 'Q' || c == 'q' || c != 'q')
                {   
                    cout<<"\n\n <- BACK TO HOME -> ";
                    game = false;
                }
            }
        }

    } while (strcmp(ch, "S") == 0 || strcmp(ch, "s") == 0);

    if (strcmp(ch, "EX") != 0 || strcmp(ch, "EX") == 0 && strcmp(ch, "ex") != 0 || strcmp(ch, "ex") == 0 )
    {
        cout << "\n THANK YOU...";
    }
}



main()
{  
    Hangman h;
    int ch;
    do{
    cout<<"\n. . . . MENU . . . .";
    cout<<"\n    . . GAMES. .    ";
    cout<<"\n 1]HANGMAN.";
    cout<<"\n 2]GUESS THE NUMBER.";
    cout<<"\n 3]STONE-PAPER-SCISSOR.";
    cout<<"\n 4]EXIT.";
    cout<<"\n\nEnter your choose to play games :";
    cin>>ch;
    if(ch>=1 && ch<=3)
    {
     switch(ch)
	 {
	 	case 1:
	 	// hangman game function.
	 	h.hangmanmain();
	 	break;
	 	
	 	case 2:
	 	//Guess the number function.
	 	guess_no();
	 	break;
	 	
	 	case 3:
	 	//Stone- paper-scissors function.
	 	s_p_s();
	 	break;
	 }	
	}
	else if(ch==4)
	cout<<"Thank you :) ...";
	else
	cout<<"\n <!!!> Invalid choose :( ... "<<endl<<endl<<endl;
    
}while(ch!=4);
}