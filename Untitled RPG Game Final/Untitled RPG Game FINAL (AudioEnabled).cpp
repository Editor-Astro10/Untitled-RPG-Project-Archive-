//********************************************************************
//
// Orlando Gomez, Mikel Cookston, Wincielee Caro
// COSC 1436
// Programming Lab 8
// March 26th 2020
// Instructor: Korinne Caruso
//
//********************************************************************


#include <iostream >
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

using namespace std;
// A lot of these variables are vital to this game working properly, having them global ensures that the values assigned to them in functions
// stay assigned throughout the game and any changes made to them are applied as well.
char YorN;
void BattleFailed(); // You die at the boss battle
void DifficultyChoice(); // You choose difficulty
void GameComplete(); // You Wind the boss battle
char Difficulty;
string DifficultyOut;
void NameChoice(); // You give yourself a name
float DifficultyIn;
string Name;
void Race(); // You choose a race
bool SpecialItem = false;
void DecisionLog(); // What you chose is saved to file
void AdventureStart(); // Main adventure starts
string RaceChosen;
float HP;
int Something;
float CurrentHP;
int EventNumber;
int Gameover(); // You die anywhere in the game
void MainMenu(); // The Main Menu hub like function
int StatMenu(); // Allows you to choose your stats
int StatCheck(); // checks HP and displays stats in case you are dead or alive
int CHR;
int LCK;
int PER;
int STR;
int END;
int INTE;
int Munny;
int AGI;
int REvent(int CurrentHP, int CHR, int LCK, int AGI, int INTE, int PER, int STR, int LostLimb);
int LostLimb;


int main()
{

int LostLimb = 1; // 1 = No, 2 = Yes




    (CurrentHP, CHR, LCK, AGI, INTE, PER, STR, LostLimb);


MainMenu();

}



//********************************************************************
//
// Main Menu Function
//
// This is a hub of the program at the beginning of it
// it takes the user through the list of items like name, race, stats, etc
// when all lines are executed it moves on
//
// Return Value
// ------------
// int Y,N for choice
//
// Function Parameters
// ----------------
// Decision Choice Char - If user wants to start
// Name String Name user desires
// Race chosen String Race Chosen of player
//
// Local Variables
// ---------------
// MenuChoice User enters if they want to start the game
//
//*******************************************************************
void MainMenu()
{

char MenuChoice;
system ("CLS");
cout << " ______________________________________________________________________________________________________________________________________________________________________________________" << endl;
cout << " |                                                                                                                                                                                    |" << endl;
cout << " | 888     888 888b    888 88888888888 8888888 88888888888 888      8888888888 8888888b.       8888888b.  8888888b.   .d8888b.        .d8888b.         d8888 888b     d888 8888888888 |" << endl;
cout << " | 888     888 8888b   888     888       888       888     888      888        888   Y88b      888   Y88b 888   Y88b d88P  Y88b      d88P  Y88b       d88888 8888b   d8888 888        | " << endl;
cout << " | 888     888 88888b  888     888       888       888     888      888        888    888      888    888 888    888 888    888      888    888      d88P888 88888b.d88888 888        | " << endl;
cout << " | 888     888 888Y88b 888     888       888       888     888      8888888    888    888      888   d88P 888   d88P 888             888            d88P 888 888Y88888P888 8888888    | " << endl;
cout << " | 888     888 888 Y88b888     888       888       888     888      888        888    888      8888888P   8888888P   888  88888      888  88888    d88P  888 888 Y888P 888 888        | " << endl;
cout << " | 888     888 888  Y88888     888       888       888     888      888        888    888      888 T88b   888        888    888      888    888   d88P   888 888  Y8P  888 888        | " << endl;
cout << " | Y88b. .d88P 888   Y8888     888       888       888     888      888        888  .d88P      888  T88b  888        Y88b  d88P      Y88b  d88P  d8888888888 888       888 888        |" << endl;
cout << " |   Y88888P   888    Y888     888     8888888     888     88888888 8888888888 8888888P        888   T88b 888         Y8888P88        Y8888P88  d88P     888 888       888 8888888888 | " << endl;
cout << " |____________________________________________________________________________________________________________________________________________________________________________________|" << endl;
cout << "\n\n";


PlaySound("Duck.wav", NULL, SND_FILENAME|SND_ASYNC); //2 Versions of Game, one with audio and the other without

cout << " Welcome to Untitled RPG Game \n";
cout << " SYSTEM: Are You ready to Begin Y or N? ";
cin >> MenuChoice; // User enters if they want to begin or now

if (MenuChoice == 'Y' || MenuChoice == 'y')
  {
      cout << " Good, let's begin... \n";
      cout << " How much do you want to be punished? \n";
      DifficultyChoice(); // Choose Difficulty
      cout << " <<< SYSTEM >>> You are now on Difficulty " << DifficultyOut << endl;
      cout << " <<< SYSTEM >>> Difficulty Scale is now at " << DifficultyIn << endl;
      cout << " So Kid, what is your name? ";
      NameChoice(); // Choose a name
      cout << " Ah, so you are " << Name << ", well you ain't look like much kid... \n";
      cout << " Not until you choose a Race that is... \n";
      Race(); // Choose a race
      cout << " Ah, so you want to be a " << RaceChosen << " very well then... \n";
      cout << " <<< SYSTEM >>> You are now " << RaceChosen << endl;
      cout << " Now... Lets see what your stats are for your character huh " << endl;
      //REvent(CurrentHP, CHR, LCK, AGI, INTE, PER, STR, LostLimb);
      StatMenu(); // Makees stats
      cout << " Now then... Chosen one... \n";
      cout << " It is time to go rescue the princess for the 999th time in 12 years... \n";
      cout << " Let your adventure begin... \n";
      AdventureStart(); // Starts the adventure







  }

if (MenuChoice == 'N' || MenuChoice == 'n')
    {
      cout << " Well then... \n";
      return;

    }
}


//----------------------------------------------------------------

//********************************************************************
//
// Difficulty Choice Function
//
// This function allows the user to select the difficulty
// They want to play in
//
// Return Value
// ------------
// Char E M H I for difficulty selection
//
// Function Parameters
// ----------------
// Difficulty  String   Name of difficulty
// DifficultyOut String Name Assigned to difficulty
// DifficultyIn float Multiplier assigned to damage
// Local Variables
// ---------------
// All Variables in the function are global to ensure they are passed properly
//
//*******************************************************************
void DifficultyChoice()
{

        cout << " CHOOSE YOUR DIFFICULTY \n\n";
        cout << " [E] EASY \n\n";
        cout << " [M] MEDIUM \n\n";
        cout << " [H] HARD \n\n";
        cout << " [I] IMPOSSIBLE \n\n";
        cout << " I want to play on... ";
        cin >> Difficulty;
        cout << "\n";

             if (Difficulty == 'E' || Difficulty == 'e')
             {

                DifficultyOut = "Easy";
                DifficultyIn = 1;
            cout << " Wanna Relax aye? \n";
             }



             if (Difficulty == 'M' || Difficulty == 'm')
             {
                DifficultyOut = "Medium";
                DifficultyIn = 1.25;
            cout << " Daring today are we? \n";

             }


             if (Difficulty == 'H' || Difficulty == 'h')
             {
                DifficultyOut = "Hard";
                DifficultyIn = 1.75;
            cout << " Hurt Me Plenty... \n";
             }


             if (Difficulty == 'I' || Difficulty == 'i')
             {
                DifficultyOut = "Impossible";
                DifficultyIn = 2;
            cout << " You face opponents who have never known defeat, who laugh in alien tongues at your efforts to survive. This is suicide \n\n";
             }


}

//----------------------------------------------------
// this sets the name of the chosen one...
//********************************************************************
//
// Name Function
//
// this sets the name of the user
//
// Return Value
// ------------
//  Name - Name is returned to the function that called it and will set the string to the Name Variable
//
// Function Parameters
// ----------------
// The Function does not need anything to run
//
// Local Variables
// ---------------
// All Variables are Global
//
//*******************************************************************
void NameChoice()
{
    cout << " My Name is... ";
    cin >> Name;
}


//-----------------------------------------
//********************************************************************
// RaceChoice
// This sets the Race of the player
//
// Return Value
// ------------
// This function takes the input of the user and assigns it to the global variable
//
// Function Parameters
// ----------------
// The function does not need anything to run
//
// Local Variables
// ---------------
// All Variables are Global to ensure proper functionality
//
//*******************************************************************
void Race()
{
        char RaceSelection;

         cout << " SYSTEM: Now Choose your Race: \n\n"
                << " You Can Choose from \n\n"
                << " [H] Human \n"
                << " [O] Orcs \n"
                << " [K] Kajiit \n"
                << " [F] Fairy \n"
                << " [C] Celestial \n"
                << " [G] Goblin \n\n";
                cout << " I will be... ";
                cin >> RaceSelection;

                 switch(RaceSelection)
                {
                 case 'H': cout << " Human Aye? \n\n";
                  RaceChosen = "Human";
                  break;

                  case 'h': cout << " Human Aye? \n\n";
                  RaceChosen = "Human";
                  break;

                 case 'O':cout << " WHAT ARE YOU DOING IN MY SWAMP? \n\n";
                    RaceChosen = "Orc";
                  break;


                  case 'o':cout << " WHAT ARE YOU DOING IN MY SWAMP? \n\n";
                    RaceChosen = "Orc";
                  break;

                 case 'K':cout << " Elon did it? \n\n";
                    RaceChosen = "Kajiit";
                  break;


                 case 'k':cout << " Elon did it? \n\n";
                    RaceChosen = "Kajiit";
                  break;

                      case 'F':cout << " Hey Listen! \n\n";
                      RaceChosen = "Fairy";
                               break;

                      case 'f':cout << " Hey Listen! \n\n";
                      RaceChosen = "Fairy";
                    break;

                 case 'C':cout << " You Are God \n\n";
                 RaceChosen = "Celestial";

                  break;

                        case 'c':cout << " You Are God \n\n";
                 RaceChosen = "Celestial";

                  break;
                 case 'G':cout << " Precious... \n\n";
                 RaceChosen = "Goblin";

                           case 'g':cout << " Precious... \n\n";
                 RaceChosen = "Goblin";

                 break;
                }
}
//----------------------------------------------------------------------
//********************************************************************
//
// File Function
//
// This outputs all stats, HP and money to the files
//
// Return Value
// ------------
// Return is not needed as no input is needed
//
// Function Parameters
// ----------------
// Function Requires
// Name String Value
// CHR Int Value
// LCK Int Value
// PER Int Value
// STR Int Value
// END Int Value
// INTE int Value
// AGI int value
// RaceChosen Char Value
// Difficulty String Value
//
// Local Variables
// ---------------
//
//
//*******************************************************************
// This function serves to save the choices here to file, it's not a save system, is just to see what you did.

void DecisionLog()
{
    ofstream myfile;
    myfile.open(" Decision Log in Menu.txt");
    myfile << " Adventurer " << Name << " Chose the race of " << RaceChosen << " They did their adventure on difficulty " << Difficulty << endl;
    myfile << " The final stats of " << Name << " were\n" << endl;
    myfile << " CHR: " << CHR << endl;
    myfile << " LCK: " << LCK << endl;
    myfile << " PER: " << PER << endl;
    myfile << " STR: " << STR << endl;
    myfile << " END: " << END << endl;
    myfile << " INT: " << INTE << endl;
    myfile << " AGI: " << AGI << endl;

}


//********************************************************************
//
// Adventure Begin Function
//
// This is the story of the game
// Return Value
// ------------
//
//
// Function Parameters
// ----------------
// CurrentHP int    Value CurrentHP of the character
// CHR       int          Value Charisma Stat
// STR      int          Value Strength Stat
// INTE     int         Value Intelligence Stat
// PER      int          Value Perception Stat
// AGI      int          Value Agility Stat
// LCK      int          Value Luck Stat
// Munny    int        Value Money Stat
// Difficulty int       Difficulty Multiplier Stat
//
// Local Variables
// ---------------
// Choice 1 int Choice for Event 1
// Choice 2 int Choice For Event 1
// Choice4 int Choice 4 for event 1-4
// Choice 5 int Choice 5 for Event 1
// Choice Revive int Choice to Revive or not in event 2
// ChoiceFight int Choose to fight or run
// EnemyAttack Float Value enemy does to CurrentHP
// int Choice 6 int Event 4 Decision
// BHP int Bounty Hunter HP
// BHPA int Bounty Hunter Attack
// ParryChance int Number that chooses if you parry properly
// Damagetaken float the value of damage the Bounty Hunter does to CurrentHP
// Choice12 int 12th choice in the storyline
// BigBoiHP int HP of a Large Boss in CH 8
// BigBoiDmg int Damage Value of Large Boss in CH8
// DamageDealt float DamageDealt by Large boss by BigBoiDMG * .75
// ChoiceRelic If player has the relic and decides the ending of the game
// Enemy Attack float Attack Value of the Enemy times difficulty multiplier
// BossHP float the HP of the Boss
//*******************************************************************
void AdventureStart()
{

   int RNG();
   int REvent();
   int Choice1;
   int Choice2;


    cout << " Press Enter to Advance the Speech " << endl;
    cout << " You Are Starting with " << HP << " Health Points " << endl;
    //cout << " This is the random event generator test for the Untitled RPG Game we are in development of... " << endl;
    getch();
    	system ("CLS");

//------------------------------------------------------------
    cout << " Chapter 1: Humble Beginnings " << endl;
     getch();
    cout << " You awaken in a cave and look around... " << endl;
    getch();
    cout << " You notice that it is dark, cold, but the entrance is a few meters away " << endl;
    getch();
    cout << " You approach the exit and look out into the landscape... " << endl;
    getch();
    cout << " The landscape is vast, open and green with a town nearby " << endl;
    getch();
    cout << " You notice a path leading to the main road from the cave you are in and you walk to the main road on the path... " << endl;
    getch();
    cout << " You approach a small, homely, village " << endl;
    getch();
    cout << " You say to yourself that this village looks comfortable, and a likely place to search for clues... " << endl;
    getch();
    cout << " You approach the town and reach the town square... " << endl;
    getch();
    cout << " You see what looks like a bar or a tavern of sorts, it looks kinda packed... " << endl;
    getch();
    cout << " You say to yourself: This looks like a good place to search for information " << endl;
    getch();
    cout << " You walk into the tavern and take a seat at a random table to go over your quest... " << endl;
    getch();
    cout << " You know that you need to save the Princess from a Dragon in a large mountain like formation, but you don't know where it is and need to search for clues " << endl;
    getch();
    cout << " Someone approaches you and asks if you are around here? " << endl;
    getch();
    cout << " SYSTEM: What do you say?: " << endl;
    cout << " Oh No I'm not, can you tell me something about the area? [1] " << endl;
    cout << " Yeah, I live nearby actually [2] " << endl;
    cin >> Choice1;
        if (Choice1 == 1)
        {
            cout << " You explain that you just got here and that you have no clue where you are actually " << endl;
                getch();
            cout << " Huh, the figure says, well them welcome to the town of Ravenholm, the last place for people to be " << endl;
                getch();
            cout << " Why is that? you ask " << endl;
            cout << " The figure says, well there isn't a town with a tavern for another few miles they say and laugh " << endl;
                getch();
            cout << " Well that's fair you say " << endl;
        }

        if (Choice1 == 2)
        {
             cout << " You say that yes, you are from around here and live down the road " << endl;
                 getch();
             cout << " The figure says that you are full of it, you don't have that smell of someone who lives here... " << endl;
                 getch();
             cout << " Sorry you respond " << endl;
                 getch();
        }

         cout << " The figure is silent for a moment... but then asks: So what is your quest or what are you doing here? " << endl;
             getch();
         cout << " You tell the mysterious man about your quest, a noble quest at that " << endl;
             getch();
         cout << " The man says: Ahh in these days I can believe a quest like  yours, although I don't know of a princess you are talking of, I do know where this mountain of yours is..." << endl;
             getch();
         cout << " the man pulls out a map and points to where we are, and then points to a large mountain in the distance... " << endl;
             getch();
             cout << " The man tells you that from Ravelholm to the Great Mountain known as: Mount Doom, is a long, long journey... " << endl;
             getch();
             cout << " It is full of danger, random events, and creatures that can have your for lunch... you best be ready he says... " << endl;
            getch();
            cout << " Here noble adventurer, take this " << endl;
            getch();
            cout << " SYSTEM: GAINED 100 GOLD " << endl;
            Munny = Munny + 100;
            cout << " SYSTEM: You now have 100 Gold " << endl;
            getch();
            cout << " So, Noble Hero, are you ready for your quest, or do you want to increase your stats by buying stat upgrades?   " << endl;
            cout << " SYSTEM: What will you do? " << endl;
            cout << " Buy a stat boosting item [1] " << endl;
            cout << " Go forth on your quest [2] " << endl;
            int Choice3;
            cin >> Choice3;
            if (Choice3 == 1)
            {
                cout << " So, hero. The Mysterious figure says... " << endl;
                cout << " Do you want to purchase a stat boost for 30 gold, ONE TIME OPPORTUNITY KID! " << endl;
                cout << " SYSTEM; (Y) for Yes, (N) for no. " << endl;
                char Choice4;
                cin >> Choice4;

                if (Choice4 == 'Y' || Choice4 == 'y')
                {
                    cout << " Alrighty kid, one overall stat booster for 30 Gold coming right up " << endl;
                                getch();
                    cout << " You spent 30 Gold for + 5 to all stats... " << endl;
                    Munny = Munny - 30;
                    cout << " You now have " << Munny << " Gold left " << endl;
                    cout << " SYSTEM: ALL STATS INCREASED BY 5 " << endl;
                        CHR = CHR + 5;
                        STR = STR + 5;
                        INTE = INTE + 5;
                        PER = PER + 5;
                        AGI = AGI + 5;
                        LCK = LCK + 5;
                }

                if(Choice4 == 'N' || Choice4 == 'n')
                {
                    cout << " Well Suit yourself kid.... " << endl;
                }


             if(Choice3 == 2)
            {
                cout << " You sure? " << endl;
                cout << " Well then, off you go... " << endl;
                    getch();
            }
            }
            cout << " You leave the tavern but before you exit the town the mysterious man walks catches up to you and says " << endl;
                        getch();
            cout << " By the way, Names Andrew, what's yours? " << endl;
                        getch();
            cout <<" " << Name << " You say " << endl;
                        getch();
            cout << " Well " << Name << " Glad to have met ya, good luck on your quest and perhaps we shall meet again huh? " << endl;
                        getch();

                        if(RaceChosen == "Kajiit")
                        {
                            cout << " The mysterious stranger pats you on the head... " << endl;
                            getch();
                        }
            cout << " Before you can say anything, you blink and he's gone... " << endl;
                        getch();
            cout << " SYSTEM: The hell was that? " << endl;
                        getch();
            cout << " You mutter to yourself, the hell was that? " << endl;
                        getch();
    RNG();
    REvent();
    StatCheck();
//------------------------------------------------------------
    cout << " Chapter 2: Bloody Mess " << endl;
    getch();
     cout << " After somehow surviving your first encounter you come across a fork in the road... " << endl;
     getch();
     cout << " there's someone laying in a pool of blood grasping for life, do you help them or pretend like you do not notice..." << endl;
     cout << " SYSTEM: What do you do? " << endl;
     cout << " Do you save them? (Y) or (N) " << endl;
     char Choice5;
     cin >> Choice5;
     if (Choice5 == 'Y' || Choice5 == 'y')
     {
        cout << " You approach the person and they are barley alive " << endl;
                      getch();
        cout << " The ask: P-P-Please, help me, put me out of my misery... " << endl;
                      getch();
        cout << " You say, but what happened to you? " << endl;
                      getch();
        cout << " They struggle to say: Creature... Creature... cut me open... it hurts a lot... please put me down... use what you find to help with your adventure... " << endl;
        cout << " SYSTEM: What do you do, Do you put them down [1] or do you try to revive them [2] " << endl;
        int ChoiceRevive;
        cin >> ChoiceRevive;
            if(ChoiceRevive == 1)
            {
                cout << " You tell the poor soul that you will complete their final wish and to please close their eyes... " << endl;
                          getch();
                cout << " You equip your sword and prepare to take the final swing ... " << endl;
                if(STR >= 8)
                    {
                        cout << " You take a large swing of your sword to the poor guy as the lets out a final gasp of air and dies... " << endl;
                                  getch();
                        cout << " You lay the guy down comfortably and remain silent for a bit " << endl;
                               getch();

                    }

                      if(STR < 8)
                    {
                        cout << " You take a swing but your mighty sword gets stuck in the poor guy, he looks like he is in immense pain more than before " << endl;
                                  getch();
                        cout << " The guy gasps: PLEASE KILL ME, KILL ME!! " << endl;
                                  getch();
                        cout << " You swing again and put the poor soul down finally... " << endl;
                               getch();
                        cout << " You lay the guy down comfortably and remain silent for a bit " << endl;
                                getch();
                    }

            }

            if(ChoiceRevive == 2)
            {
                    cout << " You attempt to use what medical knowledge you have to heal the poor guy... " << endl;
                                        getch();
                    cout << " The guy gasps saying: Please... Stop... Just Kill me... " << endl;
                    getch();
                    if (INTE >= 15)
                    {
                        cout << " You do the best you can but your attempt at revival is a loss... " << endl;
                        getch();
                    }

                       if (INTE < 15)
                    {
                        cout << " You do the best you can but your attempt at revival is a loss... " << endl;
                                            getch();
                        cout << " It is so bad that the guy has regained the ability to scream and he does so... " << endl;
                                            getch();
                        cout << " He screams: PLEASE FOR THE LOVE OF GOT KILL ME ALREADY THERE'S NO HOPE FOR ME... " << endl;
                                            getch();
                        cout << " Then his lights go out... " << endl;
                                            getch();
                    }
            }
     }


                       cout << " You search the guy for anything useful ... " << endl;
                           getch();
                    cout << " You find a sheet of paper that has the title of Local Hazards... " << endl;
                           getch();
                    cout << " The sheet says, DANGER: GIANT MANTIS COMMON IN THE REMNANT REGION " << endl;
                           getch();
                    cout << " Then you see another page and look at it... " << endl;
                           getch();
                    cout << " The other side of the sheet say WANTED: LARGE DRAGON ON MOUNT.DOOM " << endl;
                    getch();
                    cout << " You say to yourself: Mount Doom huh so that must be the large mountain off in the distance... " << endl;
                           getch();
                    cout << " something else catches your eye on the paper... it says REWARD 10 MILLION GOLD " << endl;
                           getch();
                    cout << " SYSTEM AND PLAYER: HOLY CRAP 10 MILLION GOLD FOR THE DRAGON! " << endl;
                    getch();
                    cout << " The paper says: Bring proof of murder to the town of Alfheim to the Bounty Center to claim reward... " << endl;
                 cout << " \n";
                 getch();

     if (Choice5 == 'N' || Choice5 == 'n')
     {
         cout << " You choose to wander along as if you do not see them, you hear their final grasp of life escape them as they die... " << endl;
         cout << " SYSTEM: You Coward..." << endl;
         getch();
     }
    RNG();
    REvent();
    StatCheck();
//------------------------------------------------------
    cout << " Chapter 3: Mantis issue " << endl;
    getch();
     cout << " You continue along your path and encounter something moving in the distance... " << endl;
     cout << " There is a large mantis creature blocking your path... " << endl;
     cout << " There is no escape, you must fight... " << endl;
     float EnemyHP = 50;
      PlaySound("BATTLECRAB", NULL, SND_FILENAME|SND_ASYNC);
      do
      {
          cout << " What do you do? [1] " << endl;
          cout << " Attempt to run or fight? [2] " << endl;
          int choiceFight;
          float EnemyAttack = 3;
          cin >> choiceFight;

          if(choiceFight = 1 || 2)
          {
              cout << " Even if you wanted to run, you can't " << endl;
              cout << " You take a swing at the mantis " << endl;
              cout << " You do " << STR * .75 << " Damage to the lad " << endl;
              EnemyHP = EnemyHP - STR * .75;
              cout << " Enemy HP is now at " << EnemyHP;
              if(EnemyHP > 0)
              {
              cout << " The enemy strikes back at you " << endl;
              cout << " You take " << EnemyAttack * DifficultyIn << " HP points of damage... " << endl;
              CurrentHP = CurrentHP - EnemyAttack * DifficultyIn;
              cout << " Your HP is now " << CurrentHP;
              if(CurrentHP < 0)
              {
                  Gameover();
              }
              }
          }

       }   while( EnemyHP > 0 );



       cout << " You defeat the wild beast and are able to tread on " << endl;
      PlaySound(NULL, NULL, 0);
       cout << " After the encounter you gain + 10 HP and +1 to STR " << endl;
       CurrentHP = CurrentHP + 10;
       STR = STR + 1;


    RNG();
    REvent();
    StatCheck();
//------------------------------------------------------------
        cout << " Chapter 4: Mysterious Upgrade " << endl;
        cout << " After your encounter with the large mantis " << endl;
        cout << " The sun is beginning to set over the horizon and you need to find some sort of shelter quickly..." << endl;
        getch();
        cout << " You continue down the path, a thought goes through your head..." << endl;
        getch();
        cout << " TO YOURSELF: Is this quest really worth it? I could die out here, nothings worth more than my own life..." << endl;
        cout << " Should I actually continue this quest and risk my life or just go home and forget about it entirely?" << endl;
        cout << " 1: Continue with your quest" << endl;
        cout << " 2: Go home while you still can" << endl;
        int Choice6;
        cin >> Choice6;
        switch (Choice6)
        {
        case 1:
            {
            cout << " You continue with your journey, moving swiftly down the path to cover more ground before the sun sets" << endl;
            getch();
            break;
            }
        case 2:
            {
            cout << " SYSTEM: COWARD!!" << endl;
            getch();
            Gameover();
            break;
            }
        }
        cout << " After running for what felt like an eternity, in the near distance you begin to see street lights and what appears to be houses or shops" << endl;
        getch();
        cout << " As you get closer, you hear people chatting and see people walking around the village..." << endl;
        getch();
        cout << " You go to the nearest person and ask them where you can stay for the night" << endl;
        getch();
        cout << " They point you to the local lodge, you thank them and head over to the building..." << endl;
        getch();
        cout << " You enter the building and walk up to the clerk" << endl;
        getch();
        cout << " CLERK: Welcome to Redwater Den, would you like to purchase a room for the night?" << endl;
        getch();
        cout << " YOU: Yes please, how much for a standard room?" << endl;
        getch();
        cout << " CLERK: It will be 25 gold..." << endl;
        getch();
        cout << " 1. Accept the fee and go to your room" << endl;
        cout << " 2. [INTE] Attempt to barter a better price" << endl;
        int Choice7;
        cin >> Choice7;
        if (Choice7 == 1)
        {
            cout << " You get your key and go up to your room, immediately falling asleep after the exhausting day you just had..." << endl;
            Munny = Munny - 25;
            cout << "You now have " << Munny << " gold" << endl;
            getch();
        }
        else if (Choice7 == 2 && INTE > 10)
        {
            cout << " You decide to try and negotiate a lower price, offering to only pay 15 gold" << endl;
            getch();
            cout << " The clerk accepts this offer and lets you be on your way..." << endl;
            Munny = Munny - 15;
            getch();
            cout << " You get your key and go up to your room, immediately falling asleep after the exhausting day you just had..." << endl;
            getch();
        }
        else if (Choice7 == 2 && INTE <= 10)
        {
            cout << " You decide to try and negotiate a lower price, offering to only pay 15 gold" << endl;
            getch();
            cout << " The clerk snaps at you and denies your offer..." << endl;
            Munny = Munny - 25;
            getch();
            cout << " You get your key and go up to your room, immediately falling asleep after the exhausting day you just had..." << endl;
        }
        cout << " In the morning, you feel refreshed and ready to tackle whatever the world can throw at you" << endl;
        getch();
        cout << " YOU GAIN +10 HP and + 1 CHR" << endl;
        CurrentHP = CurrentHP + 10;
        CHR = CHR + 1;
        cout << " Your HP is now " << CurrentHP << endl;
        cout << " Your CHR is now " << CHR << endl;
        getch();
        cout << " You exit the Redwater Den and go to the tavern next door..." << endl;
        getch();
        cout << " Right before you enter the tavern, a mysterious man stops you and asks your reasoning as to why you are there" << endl;
        getch();
        cout << " You tell the mysterious man about the quest you are on to save the princess..." << endl;
        getch();
        cout << " The mysterious man gets a curious look on his face and invites you over to his place" << endl;
        getch();
        cout << " Do you accept his offer?" << endl;
        cout << " 1. Yes" << endl;
        cout << " 2. Nah" << endl;
        int Choice8;
        cin >> Choice8;
        if (Choice8 == 1)
        {
            cout << " You accept his offer and follow him to his house..." << endl;
            getch();
        }
        else if (Choice8 == 2)
        {
            cout << " You decline his offer but you get the feeling you should go with him..." << endl;
            cout << " You accept his offer anyways and follow him to his house..." << endl;
            getch();
        }
        cout << " When you enter the mysterious mans house, it is covered from floor to ceiling in old books, tools, and you see a statue in the corner of the room..." << endl;
        getch();
        cout << " MYSTERIOUS MAN: " << Name << ", I have brought you here to tell you that you were chosen by fate to complete this quest..." << endl;
        getch();
        cout << " He walks over to the statue in the corner of the room and explains what the statue is..." << endl;
        getch();
        cout << " He explains that the statue is an ancient magical being that can improve three stats of your choosing..." << endl;
        getch();
        cout << " You place your hand on the glowing symbol in the center and feel a rush of power..." << endl;
        getch();
        cout << " SYSTEM: You can choose to upgrade three stats of your choice, each one increasing by 5" << endl;
        getch();
        cout << " SYSTEM: Which stats will you upgrade?\n" << endl;
        cout << " 1. CHR" << endl;
        cout << " 2. LCK" << endl;
        cout << " 3. PER" << endl;
        cout << " 4. STR" << endl;
        cout << " 5. END" << endl;
        cout << " 6. INTE" << endl;
        cout << " 7. AGI" << endl;
        int Choice9;
        int Counter = 3;
        for (Counter = Counter; Counter > 0; Counter--)
        {
            cin >> Choice9;
            if (Choice9 == 1)
            {
                CHR = CHR + 5;
                cout << " Your new CHR stat is " << CHR << endl;
            }
            else if (Choice9 == 2)
            {
                LCK = LCK + 5;
                cout << " Your new LCK stat is " << LCK << endl;
            }
            else if (Choice9 == 3)
            {
                PER = PER + 5;
                cout << " Your new PER stat is " << PER << endl;
            }
            else if (Choice9 == 4)
            {
                STR = STR + 5;
                cout << " Your new STR stat is " << STR << endl;
            }
            else if (Choice9 == 5)
            {
                END = END + 5;
                cout << " Your new END stat is " << END << endl;
            }
            else if (Choice9 == 6)
            {
                INTE = INTE + 5;
                cout << " Your new INTE stat is " << INTE << endl;
            }
            else if (Choice9 == 7)
            {
                AGI = AGI + 5;
                cout << " Your new AGI stat is " << AGI << endl;
            }
        }
        cout << " You are hit with a wave of power like no other" << endl;
        getch();
        cout << " The man is sitting in a chair nearby, reading a book..." << endl;
        getch();
        cout << " You ask him why he is letting you do this, he says again that you were chosen by fate to be the one to complete this quest..." << endl;
        getch();
        cout << " He talks a bit more and informs you that you must hurry before the princess is killed..." << endl;
        getch();
        cout << " The man gives you some food for your travels and you continue on your way, leaving the village and its people behind..." << endl;
        getch();
    RNG();
    REvent();
    StatCheck();
//------------------------------------------------------------
        cout << " Chapter 5: The Bounty Hunter " << endl;
            float BHP = 50;
            float BHPA = 30;
            int Chance;
            int ParryChance;
            float damagetaken;
            damagetaken = BHPA;
        cout << " You are walking away from the village " << endl;
            getch();
        cout << " The sun is bright overhead but the temperature is comfortable " << endl;
            getch();
        cout << " You continue along for a long, long while " << endl;
            getch();
        cout << " You come across a shifty looking figure in the distance... " << endl;
            getch();
        cout << " Do you approach (1) it or hide and wait for it to leave (2)? " << endl;
        cout << " I want to... ";
        int Choice10;
        cin >> Choice10;
            if ( Choice10  == 1)
                {
                cout << " You approach the man in what now is heavy armor " << endl;
                   getch();
                cout << " I... Know... Your... Quest... He says as he deploys his sword and yells... THAT BOUNTY IS MINE!! " << endl;
                PlaySound("BountyHunterBattle.wav", NULL, SND_FILENAME|SND_ASYNC);

                do
                {
                    cout << " SYSTEM: You must defeat your enemy at all costs " << endl;
                    cout << " Do you attack (1) or Parry (2) " << endl;
                    float DamageDone;
                    float DefenseBH;
                    cin >> DefenseBH;
                        if(DefenseBH ==1)
                        {
                            cout << " You make a well swung swish at your enemy... " << endl;
                              getch();
                            cout << " The attack did " << STR * 1.25 << " units of damage to your foe! " << endl;
                              getch();
                            DamageDone =  STR * 1.25;
                            BHP = BHP - DamageDone;
                            cout << " The bounty hunter has " << BHP << " left " << endl;
                            cout << " The Bounty Hunter makes a well thwack on you with his sword... " << endl;
                              getch();
                            cout << " The impact did " << damagetaken << " Units of damage to you! " << endl;
                              CurrentHP = CurrentHP - damagetaken;
                              getch();
                              cout << " Your current HP is " << CurrentHP << endl;

                              if (CurrentHP > 0)
                              {

                              }

                              if (CurrentHP <= 0)
                              {
                                  Gameover();
                              }

                        }
                        if (DefenseBH == 2)
                        {
                            cout << " You Attempt to block with your weapon and quickly strike as he recoils " << endl;
                             int RandomEvent;
                            srand (time(NULL));
                            Chance = rand() % 10 + 1;
                            ParryChance = Chance;
                            if ( ParryChance == 2 || ParryChance == 4 || ParryChance == 6 || ParryChance == 8|| ParryChance == 10)
                            {
                                cout << " You rotate your sword quickly to block the enemies attack " <<endl;
                                     getch();
                                cout << " Their sword bounces off of your sword and you make a quick slash on them " << endl;
                                     getch();
                                cout << " The attack did " << STR * 1.25 << " units of damage to your foe! " << endl;
                                    DamageDone =  STR * 1.25;
                                    BHP = BHP - DamageDone;
                                cout << " The bounty hunter has " << BHP << " left " << endl;
                                    getch();

                            }
                        else
                            {
                                cout << " You attempt to rotate your sword to parry but you were too slow and the enemy got a hit on you! " << endl;
                                cout << " The impact did " << BHPA << " Units of damage to you! " << endl;
                                CurrentHP = CurrentHP - BHPA;
                                getch();
                                cout << " Your current HP is " << CurrentHP << endl;

                            }


                        }
                } while(BHP > 0);


                cout << " You lower your sword as the knight falls to his knees after taking one last hit on you... " << endl;
                          getch();
                cout << " He says: That... Bounty... Was... Was... " << endl;
                          getch();
                cout << " I was supposed to be the chosen one from Ravenholm to save the princess from Mount.Doom... The Knight says... " << endl;
                          getch();
                cout << " He collapses... dying... " << endl;
                PlaySound("victory.wav", NULL, SND_FILENAME|SND_ASYNC);
                getch();
                cout << " You search his body and take his armor adding +5 to STR and find 150 gold " << endl;
                STR = STR + 5;
                Munny = Munny + 150;
                getch();
                cout << " You also find a World Map, you find the town you were just at and locate the next one... " << endl;
                getch();
                cout << " You say: Well the next town is... Arroyo... " << endl;
                getch();
                }

                if ( Choice10 == 2)
                {
                    cout << " You hide from the being and they vanish... " << endl;
                    getch();
                    cout << " You continue on your quest and find the map the Bounty Hunter was using... " << endl;
                    getch();
                }







    RNG();
    REvent();
    StatCheck();
//-------------------------------------------------------
        cout << " Chapter 6 Mysterious Shop " << endl;
         getch();
        cout << " The town of Arroyo according to the map is a few miles away " << endl;
        getch();
        cout << " You take out one of the snacks the mysterious man from  the last village gave you and eat it to get some energy..." << endl;
        getch();
        cout << " You pick up the pace a little bit to try and save some time" << endl;
        getch();
        cout << " After a while of running, you take a short break under a tree to cool down and check out that map one more time..." << endl;
        getch();
        cout << " You begin studying the map and notice a scratched out section just up ahead and get curious" << endl;
        getch();
        cout << " Do you go see if that area has anything important[1] or ignore it and continue[2]?" << endl;
        int Choice11;
        cin >> Choice11;
        if (Choice11 == 1)
        {
            cout << " You go a little farther ahead and find a small trail leading off of your current one..." << endl;
            getch();
            cout << " You find a small run down building and approach it" << endl;
            getch();
            cout << " There is a horrible smell coming from inside, making you cover your nose as best you can" << endl;
            getch();
            cout << " You get right up to one of the windows and peek in, you see nothing but old and moldy furniture..." << endl;
            getch();
            cout << " You decide to enter the building and take a look at whats left" << endl;
            getch();
            cout << " While exploring, you trip on a board that was sticking up, taking 3 damage..." << endl;
            getch();
            CurrentHP = CurrentHP - 3;
            cout << " Your new HP is " << CurrentHP << endl;
            getch();
            if (CurrentHP <= 0)
            {
                Gameover();
            }
            else
            {

            }
            cout << " You get up and decide to stop exploring the building" << endl;
            getch();
            cout << " You leave and get back on your path" << endl;
            getch();
        }
        if (Choice11 == 2)
        {
            cout << " You tell yourself its most likely nothing important since its scratched out and continue" << endl;
            getch();
        }
        cout << " After another long time of walking, You finally begin to see signs of civilization..." << endl;
        getch();
        cout << " Since its a little after mid day, the sun is beaming almost directly down onto you, but there is a nice cool breeze" << endl;
        getch();
        cout << " You are on top of a hill looking into a valley, you can see the town of Arroyo at the bottom, but it is still a ways away" << endl;
        getch();
        cout << " You make your way down the hill to the bottom..." << endl;
        getch();
        cout << " When you get to the bottom, you notice something off about the road ahead" << endl;
        getch();
        cout << " You notice a bunch of footsteps and you begin to feel like your not alone..." << endl;
        getch();
        cout << " You start to pay more attention to your surroundings and catch someone watching you..." << endl;
        getch();
        cout << " You start to yell at them but someone approaches from behind, they call you by your name..." << endl;
        getch();
        cout << " " << Name << ", right? We have been tracking you down for a while now..." << endl;
        getch();
        cout << " We are merchants from the town up ahead and wanted to catch you before you got there" << endl;
        getch();
        cout << " We specialize in wearable armor and accessories, would you like to take a look?" << endl;
        getch();
        cout << " You say sure why not and take a look" << endl;
        getch();
        cout << "\n\n SHOP" << endl;
        cout << " 1. Glasses = 35 gold / PER + 3" << endl;
        cout << " 2. Combat Boots = 60 gold / AGI + 5 STR + 5" << endl;
        cout << " 3. Bandage = 15 gold / HP + 5" << endl;
        cout << " 4. Dapper looking suit = 100 gold / CHR + 15 INTE + 20" << endl;
        cout << " 5. Ancient artifact with strange letters on it = 150 gold / UNKNOWN EFFECT" << endl;
        cout << " 6. Leave Shop" << endl;
        int Choice12;
        cin >> Choice12;
        if (Choice12 != 6)
        {
            if (Choice12 == 1 && Munny > 35)
            {

                cout << " You can see a bit better now..." << endl;
                PER = PER + 3;
                Munny = Munny - 35;
                getch();
                cout << " Your new PER level is " << PER << endl;
                cout << " You now have " << Munny << " gold" << endl;
                getch();
            }


            if (Choice12 == 2 && Munny > 60)
            {
                cout << " These boots are very well made and sturdy" << endl;
                AGI = AGI + 5;
                STR = STR + 5;
                cout << " You now have " << AGI << " AGI, and " << STR << " STR" << endl;
                getch();
            }


            if (Choice12 == 3 && Munny > 15)
            {
                cout << " These bandages are pretty effective" << endl;
                CurrentHP = CurrentHP + 5;
                cout << " You now have " << CurrentHP << " HP" << endl;
                getch();
            }


            if (Choice12 == 4 && Munny > 100)
            {
                cout << " You instantly feel much more professional" << endl;
                CHR = CHR + 15;
                INTE = INTE + 20;
                cout << " You now have " << CHR << " CHR, and " << INTE << " INTE" << endl;
                getch();
            }


            if  (Choice12 == 5 && Munny > 150)
            {
                cout << " The artifact vibrates slightly and glows when you pick it up..." << endl;
                SpecialItem = true;
                getch();
            }
        }
    cout << " The merchants thank you for looking and shake your hand..." << endl;
    getch();
    cout << " You blink and the two men vanish without a trace, even the feet print vanish..." << endl;
    getch();
    cout << " You continue down the path and soon find yourself in Arroyo..." << endl;
    getch();

    RNG();
    REvent();
    StatCheck();

//--------------------------------------------------------------------------------------------------
        cout << " Chapter 7: Arroyo " << endl;
         getch();

        cout << "You make it to Arroyo but something looks off about the place... " << endl;
        getch();
        cout << " It's too quiet, more so as it is night... " << endl;
        getch();
        cout << " It is also too dark, except for one building that looks like a Bar and Hotel mix... " << endl;
        getch();
        cout << " You decide to approach the only active building in the entire town and find the bartender... " << endl;
        getch();
        cout << " AH WHO GOES THERE! he yells startled... " << endl;
        getch();
        if ( CHR > 15 )
        {
            cout << " Hey there you say as you hold your hands up " << endl;
            getch();
            cout << " oh, it's a traveler he says... thought you were gonna finish me off here... " << endl;
            cout << " Finish you off? " << endl;
         }

         if ( CHR < 15 )
         {
             cout << " You yell back in fear and fall backwards " << endl;
             getch();
             cout << " The you took 5 damage... " << endl;
             CurrentHP = CurrentHP - 5;
             getch();
             cout << " You get up and compose yourself and the bartender does the same " << endl;
             getch();
             cout << " JESUS MATE! he yells, YOU JUST ABOUT SCARED THE HELL OUT OF ME! " << endl;
             getch();
             cout << " You just about did the same to me: you say back as you approach him... " << endl;
             getch();
             cout << " Thought you were gonna finish me off here, sorry mate he says... " << endl;
             getch();
             cout << " Finish you off? You respond with" << endl;
         }

        cout << " Well you see... a dragon ravaged this place a few hours ago and this is the one place that was unharmed..." << endl;
        getch();
        cout << " Almost everyone was either burned alive or fled the city in search of safety... " << endl;
        getch();
        cout << " I was just about to wrap up shop and leave town when you showed up... I assume you are here to buy a room? " << endl;
               getch();
                cout << " Yeah, I want a room for the night " << endl;
                       getch();
                cout << " Okay, that will be 20 Gold please... " << endl;
                       getch();
                Munny = Munny - 20;
                cout << " You head up to your room but then the bartender calls you and asks Hey kid, what's a person like you doing in a place like this? " << endl;
                       getch();
                cout << " You respond telling him of your noble quest " << endl;
                       getch();
                cout << " So you're the chosen one huh? Been hearing whispers about a lad like you... I wish I could do more to help you but, " << endl;
                       getch();
                cout << " Good luck with your quest... " << endl;
                       getch();
                cout << " Thanks sir, and good luck with whatever you will be doing next... you both nod at each other and you head up to your room to sleep " << endl;
                       getch();
                cout << " SYSTEM: YOU GAIN + 50 HP AND +1 TO CHR in your sleep " << endl;
                CurrentHP = CurrentHP + 50;
                CHR = CHR + 1;
                       getch();
                cout << " You awake and find a new sword with a bow and a note on it and a fancy Knight's shield " << endl;
                       getch();
                cout << " You read the note and it says: Good Luck " << Name << " Everyone is hoping for you " << endl;
                       getch();
                cout << " The sword adds + 10 to STR and the shields adds +5 to END and + 30 HP " << endl;
                STR = STR + 10;
                CurrentHP = CurrentHP + 30;
                END = END + 5;
                       getch();
                cout << " Thanks... you whisper to yourself " << endl;
                       getch();
                cout << " You walk down the stairs and notice the bartender has already left, you decide to do the same... " << endl;
                       getch();
                cout << " You walk out and see Mount.Doom in the distance, it's starting to glow red " << endl;
                cout << " SYSTEM: HEY YOU ARE RUNNING OUT OF TIME!" << endl;
                       getch();
                cout << " You Draw your sword, deploy your shield and take a direct route to the now glowing mountain... " << endl;
                       getch();
                cout << " But you feel like you are being watched... " << endl;

    RNG();
    REvent();
    StatCheck();

//----------------------------------------------------------------------------------------
   cout << " Chapter 8: Creature " << endl;
         getch();

       int bigboiHP = 140;
       int bigboiDamg = 40;
       float DamageDealt;
        cout << " As you leave Arroyo, you begin to remember how far you have come thus far..." << endl;
        getch();
        cout << " Just a couple days ago, you were a nobody fighting for survival..." << endl;
        getch();
        cout << " You remember you had second guessed even going on this quest, but are thankful you did" << endl;
        getch();
        cout << " After a few minutes of thinking to yourself, you hear the snap of a stick off to your side and quickly turn to see what it was..." << endl;
        getch();
        cout << " You slow down a bit and quiet your footsteps to hear your surroundings a bit better" << endl;
        getch();
        cout << " You tell yourself it was all in your head and that your just being paranoid..." << endl;
        getch();
        cout << " As you go back to your normal pace and forget about it, something strikes you from behind causing you to lose your balance..." << endl;
        PlaySound("CreatureBattle", NULL, SND_FILENAME|SND_ASYNC);
        getch();
        if (AGI >= 12)
        {
            cout << " You catch yourself before falling to the ground and turn to see what it was" << endl;
            getch();
        }
        else if (AGI < 12)
        {
            cout << " Before you realize it you hit the ground with full force, losing 8 HP" << endl;
            CurrentHP = CurrentHP - 8;
            getch();
            if (CurrentHP <= 0)
            {
                Gameover();
            }
            cout << " You get up quickly and turn to see what knocked you down" << endl;
            getch();
        }
        cout << " When you turn around, you are shocked to see a massive humanoid creature that must have been at least 7 feet tall standing in front of you" << endl;
        getch();
        cout << " The giant of a man doesn't hesitate to attack and begins charging..." << endl;
        getch();
        cout << " Do you attempt to dodge his attack[1] or try to block it?[2]?" << endl;
        int Choice13;
        cin >> Choice13;
        if (Choice13 == 1)
        {
            if (AGI >= 16)
            {
                cout << " As he approaches you jump out of the way, dodging his attack..." << endl;
                getch();
                cout << " His sword is so large and heavy, it gets stuck in the ground allowing you to get a free hit in" << endl;
                getch();
                cout << " You strike him in the back, dealing " << STR * 2 << " damage" << endl;
                DamageDealt = STR * 2;
                bigboiHP = bigboiHP - DamageDealt;
                getch();
                cout << " The warrior now has " << bigboiHP << "HP" << endl;
            }
            if (AGI < 16 )
            {
                cout << " You don't jump out of the way in time, getting hit as you attempt your escape, taking " << bigboiDamg << " damage..." << endl;
                CurrentHP = CurrentHP - bigboiDamg;
                getch();
                cout << " You now have " << CurrentHP << " HP" << endl;
                getch();
                if (CurrentHP <= 0)
                {
                    Gameover();
                }
            }

        }
        if (Choice13 == 2)
        {
            if (STR >= 20)
            {
                cout << " As he swings at you, you lift your shield and successfully block his attack" << endl;
                getch();
                cout << " You swing back, dealing " << STR << " damage" << endl;
                bigboiHP = bigboiHP - STR;
                getch();
                cout << " He now has " << bigboiHP << " HP" << endl;
                getch();
             }
            if (STR < 20)
            {
                cout << " You try to block his attack but the strength of the swing is too great, breaking your guard and dealing " << bigboiDamg * 2 << " damage" << endl;
                getch();
            }
        }
        do {
            cout << " The warrior takes another swing at you, do you try to parry it? Y/N" << endl;
            cin >> YorN;
            if (YorN == 'Y' || YorN == 'y')
            {
                cout << " As the sword is about to hit, you swing your shield to try and parry the incoming attack... " << endl;
                getch();
                    int RandomEvent;
                    srand (time(NULL));
                    Chance = rand() % 10 + 1;
                    ParryChance = Chance;
                    if ( ParryChance == 2 || ParryChance == 4 || ParryChance == 6 || ParryChance == 8 || ParryChance == 10)
                            {
                                cout << " The sword is deflected and knocks them off balance, you see an opening and take your chance to attack " << endl;
                                     getch();
                                cout << " Your attack does " << STR << " damage to the warrior " << endl;
                                    DamageDealt =  STR;
                                    bigboiHP = bigboiHP - DamageDealt;
                                    getch();
                                cout << " The warrior now has " << bigboiHP << " HP left " << endl;
                                    getch();
                                cout << " They swing back and strike you, dealing " << bigboiDamg << " damage" << endl;
                                getch();
                                CurrentHP = CurrentHP - bigboiDamg;
                                cout << " You now have " << CurrentHP << " HP" << endl;
                                getch();
                                if (CurrentHP <= 0)
                                {
                                    Gameover();
                                }
                            }

                            else
                            {
                                cout << " As the sword closes in, you attempt your parry but miss and the sword hits you... " << endl;
                                getch();
                                cout << " The attack does " << bigboiDamg * 1.75 << " damage to you " << endl;
                                CurrentHP = CurrentHP - bigboiDamg * 1.75;
                                getch();
                                cout << " Your current HP is " << CurrentHP << endl;
                                getch();
                                if (CurrentHP <= 0)
                                {
                                    Gameover();
                                }

                            }


            }
            if (YorN == 'N' || YorN == 'n')
            {
                cout << " You don't want to risk missing a parry and take the hit, receiving " << bigboiDamg << " damage" << endl;
                getch();
            }
            cout << " You swing back and deal " << STR << " damage" << endl;
            bigboiHP = bigboiHP - STR;
            getch();
            cout << " He now has " << bigboiHP << " HP" << endl;
            getch();

        }
        while (bigboiHP > 0);

        cout << " The giant of a man falls to the ground and produces a large cloud of dust as he hits the ground..." << endl;
        getch();
        cout << " When the cloud disappears, the man is gone besides a letter..." << endl;
        getch();
        cout << " You pick up the letter and it reads, TARGET " << Name << " MUST BE STOPPED, INTERCEPT AND ELEMINATE..." << endl;
        getch();
        cout << " You put the letter in your bag and continue on the trail in a hurry to try to catch back up on time lost..." << endl;
        getch();
        cout << " You get close to MOUNT.DOOM and get an uneasy feeling, this place is massive and has an intimidating look to it..." << endl;
        getch();
        cout << " Well, you say, I've come this far and cant go back now... " << endl;
        getch();
        cout << " You enter the lair and grip your sword tight..." << endl;
        getch();



//--------------------------------------------------------------------------------
        cout << " Chapter 9: The end of the Line Part 1 " << endl;

        cout << " You are outside the dragons chamber now, it is very hot in here... " << endl;
         char ChoiceRelic;

        if(SpecialItem == true)

            {
                cout << " You walk into the chamber and the unknown artifact starts to glow... " << endl;
                  getch();
                cout << " WHO DARES ENTER MY LAIR AND DISTRURB THE RITURAL a booming voice declares " << endl;
                   PlaySound("BattleDragon1.wav", NULL, SND_FILENAME|SND_ASYNC);
                  getch();
                cout << " PREPARE TO DI-... the dragon turns around to see you, with a glowing block in your hand... " << endl;
                  getch();
                cout << " Is that... Is that... Is that the- " << endl;
                  getch();
                cout << " Before the dragon can finish its sentence... you pull forth the relic cube, " << endl;
                cout << " Do you use the Relic? (Y/N)" << endl;

                cin >> ChoiceRelic;
                if(ChoiceRelic == 'Y'|| 'y')
                {
                    getch();
                 cout << " The cube glows a intense bright yellow and lightning emerges from the relic and shocks the dragon " << endl;
                 getch();
                 cout << " The dragon falls to it's knees and exclaims: What... What have you done... " << endl;
                 getch();
                 cout << " The ground starts shaking as the room begins to crumble " << endl;
                 getch();
                 cout << " If you kill me... YOU ARE GOING DOWN WITH ME " << endl;
                 getch();
                 PlaySound(NULL, NULL, 0);
                 cout << " A bright white light emits from the cube as everything goes silent... " << endl;
                 getch();
                 cout << " You wake up in a field at the base of where the mountain *was* " << endl;
                 getch();
                 cout << " The skies are dark but there are no signs of the Dragon, or the princess... " << endl;
                 getch();
                 cout << " You see a concrete box with an opening in it in the distance... " << endl;
                 getch();
                 cout << " You stumble to the box and look inside it... " << endl;
                 getch();
                 cout << " You find the princess inside the concrete box, knocked out but still alive " << endl;
                 getch();
                 cout << " SYSTEM: You did it mate, you saved the princess from total death " << endl;
                 getch();
                 cout << " If this game gets a Part 2 you may be able to reap the benefits of that 10 Million Gold bounty " << endl;
                GameComplete();
                }

                if(ChoiceRelic == 'N'|| 'n')
                {
                    cout << " The relic is shaking and glowing even brighter but you refuse to use it... " << endl;
                    getch();
                    cout << " The dragon, knowing the full extent of your relic is charging up a extreme attack... " << endl;
                    getch();
                    cout << " The dragon's tail is glowing a bright blue and the ground is shaking..." << endl;
                    getch();
                    cout << " SYSTEM: Hey buddy, you see that dragon over there... YOU HAD YOUR PRIME CHANCE TO KILL IT AND YOU DIDN'T, NOW WE GONNA DIE! System Yells" << endl;
                    getch();
                    cout << " SYSTEM: Do you dodge the attack (1) , or accept your fate? (2) " << endl;
                    int Fate;
                    cin >> Fate;
                        if(Fate == 1 )
                        {
                            cout << " You prepare to dodge the attack " << endl;
                            if(AGI == 99)
                            {
                                cout << " You somehow dodge the attack, but the dragon isn't having it... " << endl;
                                getch();
                                cout << " The dragon uses it's charged tail to swing at you... you can't dodge it... it hits you... " << endl;
                                getch();
                                cout << " It strikes you and things fade to black moments after as the impact has caused your limbs to separate and your head to disconnect... " << endl;
                                BattleFailed();
                            }
                        }
                        if( Fate == 2)
                        {
                            cout << " The words of system resonate inside of you, you know you messed up, and now you are paying for it... " << endl;
                            getch();
                            cout << " The Dragon Opens it's mouth... " << endl;
                            getch();
                            cout << " It fires a brilliant blue beam of energy at you, accepting your fate you embrace the beam as every atom in your body is torn apart... " << endl;
                            getch();
                            cout << " The dragon uses Ultra Beam for 10 Million Damage Points..." << endl;
                            CurrentHP = CurrentHP - 10000000;
                            cout << " Your HP is now... " << CurrentHP;
                            getch();
                            BattleFailed();
                        }



                }
         if(SpecialItem == false)
         {
             cout << " You enter the chamber and see a massive, red, dragon... " << endl;
             getch();
             cout << " A voice booms WHO DARES ENTER MY LAIR AND DISTRURB THE RITURAL " <<endl;
             getch();
             cout << " Ahh, it's the chosen one again... " << endl;
             getch();
             cout << " You're here for the princess huh, well, you're gonna have to fight me first... " << endl;
         }

//----------------------------------------------------------------------------------------
         StatCheck();
            cout << " Chapter 10: End of the Line Part 2  " << endl;
            getch();
            cout << " You draw your sword in anticipation of the final fight you will face..." << endl;
            getch();
            cout << " You think you can win against ME, while i'm doing my ritual!? " << endl;
            getch();
            cout << " You... " <<endl;
            getch();
            cout << " Thought... " << endl;
            getch();
            cout << " Wrong... " << endl;
            getch();
            PlaySound("DragonBattle2.wav", NULL, SND_FILENAME|SND_ASYNC);
            cout << " The room turns bright as the battlefield is perfectly illuminated " << endl;
        float EnemyAttack = 12;
          float BossHP = 264;
          int choiceFight;
        do {
          cout << " What do you do? [1] " << endl;
          cout << " Attempt to run or fight? [2] " << endl;


          cin >> choiceFight;



          if(choiceFight == 1 ||choiceFight == 2)
          {
              cout << " Even if you wanted to run, you can't " << endl;
              cout << " You swing for the great dragon with lots of purpose in your eyes " << endl;
              cout << " You do " << STR * .75 << " Damage to the lad " << endl;
              BossHP = BossHP - STR * .75;
              cout << " Enemy HP is now at " << BossHP;
              if(BossHP > 0)
              {
              cout << " The enemy strikes back at you " << endl;
              cout << " You take " << EnemyAttack * DifficultyIn << " HP points of damage... " << endl;
              CurrentHP = CurrentHP - EnemyAttack * DifficultyIn;
              cout << " Your HP is now " << CurrentHP;
              if(CurrentHP < 0)
              {
                  Gameover();
              }
              }
          }

       }   while( BossHP > 0 );



       cout << " You have defeated the dragon that has haunted the lands and are able to tread on " << endl;
       cout << " The dragon falls to the ground and you approach its head before making the final blow...  " << endl;
            getch();
            cout << " The dragon struggles and says... I am forever... I will return... and when I do... you... will... suffer...  " << endl;
            getch();
            cout << " In a stern tone you state that: When you return, I will be right back to kill you, and to stop you from destroying the world " << endl;
            getch();
            cout << " You take your sword, and stab the dragon in the head where he lies as he stops moving " << endl;
            getch();
            cout << " The ground starts shaking as the entire mountain crumbles and collapses around you and over you..." << endl;
            getch();
            cout << " You wake up in a field at the base of where the mountain *was* " << endl;
            getch();
            cout << " The skies are dark but there are no signs of the Dragon, or the princess... " << endl;
            getch();
            cout << " You see a concrete box with an opening in it in the distance... " << endl;
            getch();
            cout << " You stumble to the box and look inside it... " << endl;
            getch();
            cout << " You find the princess inside the concrete box, knocked out but still alive " << endl;
            getch();
            cout << " SYSTEM: You did it mate, you saved the princess from total death " << endl;
            getch();
            cout << " If this game gets a Part 2 you may be able to reap the benefits of that 10 Million Gold bounty " << endl;
            GameComplete();

PlaySound(NULL, NULL, 0);






            }

}

//--------------------------------------
//********************************************************************
//
// Random Number Generator Function
//
// This function pulls a random number from a set range
// and applies it to RandomEvent then to EventNumber;
//
// Return Value
// ------------
// There is no input and no return value as this is a background function
//
// Function Parameters
// ----------------
// Local Variables
// ---------------
// RandomEvent int Event Chosen
//
//
//*******************************************************************

void RNG()
{
 int RandomEvent;
 srand (time(NULL));
 RandomEvent = rand() % 100 + 1;
 EventNumber = RandomEvent;
}

//-------------------------
//********************************************************************
//
// Stats Menu Function
//
// This function allows the user to set the stats of their characters
//
// Return Value
// ------------
// CHR int CHR Stat
// :CL Int LCK Stat
// PER int PER stat
// STR int STR stat
// End int END stat
// ITNE int INTE stat
// AGI int AGI stat
//
// Function Parameters
//
// ----------------
// Local Variables
// ---------------
// RULETOTAL int determines if the stats are valid
// RandomEvent int Event Chosen
//
//
//*******************************************************************
int StatMenu()

{

    int RULETOTAL;
    cout << " SYSTEM: Hello there Mate... " << endl;
    cout << " Here you will make the stats for your character... " << endl;
    cout << " We are gonna do this Fallout style, you can make a max of 40 points and put any stat at any range of 0 - 20 " << endl;
    cout << " So let's get this done... " << endl;
    cout << " Enter for CHR or Charisma ";
    cin >> CHR;
    cout << " Total is " << CHR << " Out of 40 " << endl;
    cout << " Enter for LCK or Luck ";
    cin >> LCK;
    cout << " Total is " << CHR + LCK << " Out of 40 " << endl;
    cout << " Enter for PER or Perception ";
    cin >> PER;
     cout << " Total is " << CHR + LCK + PER << " Out of 40 " << endl;
    cout << " Enter for STR or Strength ";
    cin >> STR;
    cout << " Total is " << CHR + LCK + PER + STR << " Out of 40 " << endl;
    cout << " Enter for END or Endurance ";
    cin >> END;
    cout << " Total is " << CHR + LCK + PER + STR + END << " Out of 40 " << endl;
    cout << " Enter for INTE or Intelligence ";
    cin >> INTE;
    cout << " Total is " << CHR + LCK + PER + STR + END + INTE << " Out of 40 " << endl;
    cout << " Enter for AGI or Agility ";
    cin >> AGI;
    cout << " Total is " << CHR + LCK + PER + STR + END + INTE + AGI << " Out of 40 " << endl;


     RULETOTAL = CHR + LCK + PER + STR + END + INTE + AGI;
     HP = STR * 2 * END;
     CurrentHP = HP;
    if (RULETOTAL > 40)
    {
        cout << " Hey Fam, your total is over 25, you can't do that... " << endl;
        cout << " Try Again kid... " << endl;
        StatMenu();
    }

    if (RULETOTAL <= 40)
    {
        cout << " Ah you're good... " << endl;
        cout << " Your Health is also " << HP << " Now " << endl;
    }
}
//********************************************************************
//
// Random Event Function
//
// this is the in between of each chapter, a random event occurs
//
// Return Value
// ------------
//
//
// Function Parameters
// ----------------
// DifficultyIn float Value Damage Multiplier via difficulty
// Name string Value Name of user when called
// CHR int Value Charisma Stat
// INTE int Value Intellect Stat
// LCK int Value Luck Stat
// PER int Value Perception Stat
// STR int Value Strength Stat
// AGI int Value Agility Stat
// END int Value Endurance Stat
// CurrentHP int Value HP of user so can be calculated properly in case of damage
//
//
// Local Variables
// ---------------
//
// Option3 int Option for Event 3
// Choice7 int Choice for Event 7
// DamageTaken float Damage taken throughout the events
// Choice 16 int choice for event 16
// Event 18 int choice for event 18
// Event 19 int choice for event 19
// Number  int  Number that is assigned for a D20 Event
// Rolled  int  Number that determines your fate in a D20 Event
// Choice 20 int Choice for Event 20
// Choice 21 int Choice for Event 21
// Choice 25 int Choice for Event 25

//
//*******************************************************************




// These are all the random events
void REvent()
{


{
   //cout << " DEBUG PLEASE ENTER EVENT NUMBER " << endl;
   //cin >> EventNumber;

    if (EventNumber == 1)
    {
    cout << " You spot a Tardis in the distance, but when you look at it, it vanishes... " << endl;
           getch();
    }

if (EventNumber == 2)
    {
    cout << " You spot a crashed shuttle in the distance, it's too dangerous to go take a look " << endl;
    getch();
    cout << " The shuttle looks to be of a Shuttle of the USS Enterprise from the future..." << endl;
    getch();
    }

if (EventNumber == 3)
        {
            int option3;
             cout << " You Spot 3 Cows talking about Calculus or Trigonometry...  " << endl;
             cout << " What will you do to them? " << endl;
             getch();
             cout << " Will you kill them (1), or perhaps tell them a tale? (2) " << endl;
                 getch();
             cin >> option3;

             switch(option3)
             {
                 case 1: cout << " You decide to kill them..." << endl;
                     getch();
                        cout << " You lose 5 points to INTE..." << endl;
                        INTE = INTE - 5;
                    getch();
                 break;

                 case 2: cout << " You decide to tell them a story of your many adventures " << endl;
                     getch();
                        cout << " Your Intellect Raises to 10 " << endl;
                        INTE = INTE + !0;
                            getch();
                break;
             }
        }

if (EventNumber == 4)
        {
            cout << " You spot a skeleton on the ground wearing a blue suit..." << endl;
            getch();
            cout << " The suit appears to have the number '101' on it... " << endl;
            getch();
        }


if (EventNumber == 5)

        {
          cout << " You spot a skeleton on the ground wearing a blue suit..." << endl;
          getch();
          cout << " The suit appears to have the number '111' on it... " << endl;
          getch();
        }

        if (EventNumber == 6)
        {
          cout << " You spot a skeleton on the ground wearing a blue suit..." << endl;
          getch();
          cout << " The suit appears to have the number '98 on it... " << endl;
          getch();
        }

else if ( EventNumber == 7)
        {
            int choice7;
            int TEST;
            cout << " A wizard blocks the path, it asks What Is the Airspeed Velocity of an Unladen Swallow? " << endl;
            getch();
            cout << " What will you respond with? " << endl;
            cout << " (1) I don't know that! " << endl;
            cout << " (2) Roughly 11 Meters Per Second or 24 Miles an hour" << endl;
            cout << " (3) What do you mean? African or European Swallow" << endl;
            cin >> choice7;

            switch(choice7)
             {
                 case 1: cout << " You say you do not know... " << endl;
                        getch();
                        cout << " You are Killed as a bolt of lightning comes down from the heavens and strikes you where you stood" << endl;
                        cout << " You are dealt 99999 damage..." << endl;
                        getch();
                        CurrentHP = HP - 999999;
                        cout << " YOU ARE DEAD " << endl;
                      PlaySound("DarkSoulsDead.wav", NULL, SND_FILENAME|SND_ASYNC);
                        Gameover();

                 break;

                 case 2: cout << " You answer with; roughly 11 meters per second, or 24 miles an hour  " << endl;
                        getch();
                        cout << " The Wizard says; Very Good you may pass " << endl;
                        getch();
                        cout << " You Pass and keep your bacon intact... for now... " << endl;
                        getch();
                break;

                case 3: cout << " You ask: What do you mean? African or European swallow " << endl;
                        getch();
                        cout << " The Wizard says: I don't know that!" << endl;
                        getch();
                        cout << " The Wizard is Killed as a bolt of lightning comes down from the heavens and strikes them where they stood " << endl;
                        getch();
                        cout << " You are allowed to pass " << endl;
                             getch();
               break;

             }
        }
if ( EventNumber == 8)
                {
                    cout << " You find a holy hand grenade sitting there on the ground " << endl;
                    getch();
                    cout << " You Gain 1 Holy Hand Grenade! " << endl;
                    getch();
                }


if ( EventNumber == 9)
            {
                cout << " Your Health is " << CurrentHP << endl;
                cout << " You see a GREAT DRAGON APPROACH IN THE DISTANCE " << endl;
                getch();
                cout << " Little does our hero know... it is the end boss dragon " << endl;
                getch();
                cout << " The Dragon Exclaims: TIME TO DIE! " << endl;
                getch();
                cout << " The Dragon does 100,000 damage, you are cooked and killed " << endl;
          PlaySound("DarkSoulsDead.wav", NULL, SND_FILENAME|SND_ASYNC);
                CurrentHP = HP - 999999;
                getch();
                Gameover();




            }

if (EventNumber == 10)
            {
                cout << " You spot a man in what looks like very Powerful Armor at a camp of sorts" << endl;
                getch();
                cout << " He talks to you knowing that you are not a part of their camp... " << endl;
          PlaySound("AssForDinner.wav", NULL, SND_FILENAME|SND_ASYNC);
                getch();

                if ( STR > 8)
                {
                 cout << " You tell him you are one of their members and prove it by punching a hole in the nearest tree " << endl;
           PlaySound("FineJob.wav", NULL, SND_FILENAME|SND_ASYNC);
                getch();
                 cout << " The man says: Outstanding. Proceed on the double to the hangar where you will stand guard duty. You will do a fine job. Do you understand? " << endl;
                 getch();
                 cout << " You walk away towards the hangar then you make like a tree and get the hell out " << endl;
                      getch();
                }
                if ( STR < 8)
                 {
                    cout << " The man says: Well I'll be damned. I had you escorted off this base and here you are again. I don't think you're a civilian after all. More than likely you're a spy! Sound the alarm and execute this maggot! " << endl;
           PlaySound("Damn.wav", NULL, SND_FILENAME|SND_ASYNC);
                    getch();
                    cout << " Your head is blown clean off for 9999 damage, you die " << endl;
                    CurrentHP = HP - 999999;
             PlaySound("DarkSoulsDead.wav", NULL, SND_FILENAME|SND_ASYNC);
                    getch();
                    Gameover();

                 }

                }

if (EventNumber == 11)
            {
                cout << " You Encounter a group of Orcs beating a Human, by the time you arrived her head was pudding "  << endl;
                getch();
            }


if (EventNumber == 12)
{
    float DamageTaken;
    DamageTaken = 5;

    cout << " You encounter a goose, it chases you down... " << endl;
 PlaySound("Honk", NULL, SND_FILENAME|SND_ASYNC);
    getch();
    cout << " You Cannot Out Run it and it pecks you... a lot... " << endl;
    getch();

    CurrentHP = CurrentHP - DamageTaken * DifficultyIn;
    cout << " Your Health is now " << CurrentHP;
    getch();
}

if (EventNumber == 13)
{
    float DamageTaken;
    DamageTaken = 10;
    cout << " Remember that goose you encountered? " << endl;
    getch();
PlaySound("Honk", NULL, SND_FILENAME|SND_ASYNC);
    getch();
    cout << " It wasn't finished and it brought friends " << endl;
    getch();
    cout << " You hadn't learned your lesson and got pecked into oblivion... " << endl;
     CurrentHP = CurrentHP - DamageTaken * DifficultyIn;
    cout << " Your Health is now " << CurrentHP;
    getch();
}

if (EventNumber == 14 )
{
    cout << " You spot a pack of wandering Rats... " << endl;
    getch();
}

if (EventNumber == 15)
{
    cout << " You spot a pack of wandering chickens " << endl;
    getch();
}


if (EventNumber == 16)

    {
       int Choice16;
     cout << " You spot a lone chicken... " << endl;
     getch();
     cout << " What do you do to the chicken? " << endl;
     getch();
     cout << " Do you attack it? (1) " << endl;
     cout << " Or do you leave it alone? (2) " << endl;
     cin >> Choice16;

     if (Choice16 == 1)
     {
       cout << " You Attack the Chicken... it explodes... " << endl;
       getch();
       cout << " You hear a rumbling in the distance and you see a horde of chickens " << endl;
       getch();
       cout << " They are coming in hot and fast, you have little time to react as they impact you and start attacking you violently " << endl;
       getch();
       cout << " You are impailed straight through the brain and die of 9999 damage... " << endl;
       getch();
        CurrentHP = CurrentHP - 99999;
       cout << " You Are DEAD " << endl;
 PlaySound("DarkSoulsDead.wav", NULL, SND_FILENAME|SND_ASYNC);
       getch();
       Gameover();
     }

     if (Choice16 == 2)
     {
        cout << " You Leave it alone... it leaves you alone... but it's staring at you..." << endl;
            getch();

     }



    }
if (EventNumber == 17)
        {
            cout << " You spot a random dog... it runs off " << endl;
                getch();

        }

if (EventNumber == 18)
    {
        int Event18;
       cout << " You See a Golden Object in the ground... what do you do? " << endl;
        getch();
        cout << " Do you Pick it up? (1) " << endl;
            getch();

        cout << " Or do you leave it there? (2) " << endl;
        cin >> Event18;

        if(Event18 == 1)
        {
            cout << " You pick it up... BUT IT'S ARMED " << endl;
             getch();
            cout << " Everything turns to white as the grenade undergoes a nuclear detonation " << endl;
                getch();
            cout << " You are killed for 999999 damage... " << endl;
            CurrentHP = CurrentHP - 99999;
             getch();
 PlaySound("DarkSoulsDead.wav", NULL, SND_FILENAME|SND_ASYNC);
             getch();
             Gameover();

        }

         if(Event18 == 2)
        {
            cout << " You leave it alone and walk off " << endl;
             getch();
            cout << " After an hour of walking you hear a distant detonation... " << endl;
             getch();
        }
    }
if (EventNumber == 19)
    {
    int Event19;
    int Number;
    int Rolled;
    cout << " You find a D20 Die... what do you do? " << endl;
    getch();
    cout << " Do you pick it up and roll it (1)" << endl;
    getch();
    cout << " Or do you leave it alone? (2)" << endl;
    cin >> Event19;
        if (Event19 == 1)
        {
            cout << " You pick it up and throw it making a roll... " << endl;
            getch();
            srand (time(NULL));
            Number = rand() % 20 + 1;
            Rolled = Number;

            if (Rolled < 11 )
            {
                cout << " You Rolled High... you're lucky... " << endl;
                cout << " You gained 2 Levels in Luck and Charisma " << endl;
                getch();
                CHR + 2;
                LCK + 2;
            }
        }
         if (Rolled > 11 )
            {
                cout << " You Rolled Low...welp... " << endl;
                cout << " You lost 4 Levels in Luck and Charisma " << endl;
                getch();
                CHR + 4;
                LCK + 4;
            }

    }

if (EventNumber == 20)
    {
        int Choice20;
        cout << " You encounter a pack of wild mantis " << endl;
        getch();
        cout << " They look mad... " << endl;
        getch();
        cout << " You Realize you must defend yourself " << endl;
        getch();
PlaySound("Mantis.wav", NULL, SND_FILENAME|SND_ASYNC);
        cout << " SYSTEM: QUEUE BATTLE MUSIC " << endl;
        getch();
        cout << " How do you proceed? " << endl;
        cout << " Do you Defend Yourself (1) " << endl;
        cout << " Or do you run? (2) " << endl;
        cin >> Choice20;

        if (Choice20 == 1)
        {
            cout << " You choose to fight these horrid insects " << endl;
            cout << " You Draw your sword to swing " << endl;
            getch();
            if (END && STR > 11)
            {
              cout << " You swing with absolute power and grace, cutting manti and killing them left, right, center until they are all gone..." << endl;
              getch();
              cout << " You win the battle and can continue on " << endl;
              getch();
              cout << " <<SYSTEM>> GAINED +3 TO STR and END " << endl;
              getch();
              END + 3;
              STR + 3;
            }
            if (END && STR < 11)
            {
                cout << " You attempt to swing and wipe out your Manti foes, and you land a hit but it bounces off the Mantis leg " << endl;
                getch();
                cout << " You've made it madder and it swings fiercely at you... you are cut in half... you die..." << endl;
        PlaySound("DarkSoulsDead.wav", NULL, SND_FILENAME|SND_ASYNC);
                getch();
                CurrentHP = CurrentHP - 99999;
                Gameover();
            }


        }
        if (Choice20 == 2)
        {
            cout << " You decide to book it, running as fast as you can in a random direction, but boy those mantis are fast... " << endl;
            getch();
            if (END && PER > 11)
            {
                cout << " You run as fast as you can and make some sharp turns and manuvers, you make a clean escape... " << endl;
                getch();
            }

             if (END && PER < 11)
            {
                cout << " You run as fast as you can but not fast enough " << endl;
                      getch();
                cout << " You trip on a rock and the mantis get to you " << endl;
                      getch();
                cout << " You look in pure horror and shock as your insides become outside as you are torn open and killed for 999999 HP " <<  endl;
                      getch();
       PlaySound("DarkSoulsDead.wav", NULL, SND_FILENAME|SND_ASYNC);
                getch();
                CurrentHP = CurrentHP - 99999;
                Gameover();

            }

        }

    }
if (EventNumber == 21)
        {
            int Choice21;
            cout << " You find a chest sitting there... what do you do? " << endl;
            getch();
            cout << " Do you approach it and open it? (1) " << endl;
            getch();
            cout << " Do leave it alone? (2) " << endl;
            getch();
            cin >> Choice21;

            if ( Choice21 == 1)
            {
                cout << " You approach the chest and open it up... " << endl;
                if(LCK > 6)
                {
                    cout << " You got lucky... you get +1 to all stats " << endl;
                    cout << " SYSTEM: ALL STATS +1 " << endl;
                    getch();
                    CHR + 1;
                    LCK + 1;
                    PER + 1;
                    STR + 1;
                    END + 1;
                }

                if(LCK < 6)
                {
                    cout << " You got unlucky... -2 to all stats... " << endl;
                    cout << " SYSTEM: ALL STATS -2 " << endl;
                    getch();
                    CHR - 2;
                    LCK - 2;
                    PER - 2;
                    STR - 2;
                    END - 2;
                }
                }


              if ( Choice21 == 2)
            {
                cout << " You leave the thing alone, with it's contents un-touched..." << endl;
                getch();
            }
        }

 if (EventNumber == 22)
        {
            int Choice21;
            cout << " You find a chest sitting there... what do you do? " << endl;
            getch();
            cout << " Do you approach it and open it? (1) " << endl;
            getch();
            cout << " Do leave it alone? (2) " << endl;
            getch();
            cin >> Choice21;

            if ( Choice21 == 1)
            {
                cout << " You approach the chest and open it up... " << endl;
                if(LCK > 6)
                {
                    cout << " You got lucky... you get +1 to all stats " << endl;
                    cout << " SYSTEM: ALL STATS +1 " << endl;
                    getch();
                    CHR + 1;
                    LCK + 1;
                    PER + 1;
                    STR + 1;
                    END + 1;
                }

                if(LCK < 6)
                {
                    cout << " You got unlucky... " << endl;
                    getch();
                    cout << " TWAS A SPANISH MIMIC" <<  endl;
                    PlaySound("Spanish.wav", NULL, SND_FILENAME|SND_ASYNC);
                    getch();
                    cout << " The Mimic Bites your head clean off, but you don't have time to notice as the mimic bites down and everything instantly turns to black... " << endl;
                    CurrentHP = CurrentHP - 99999;
                    PlaySound("DarkSoulsDead.wav", NULL, SND_FILENAME|SND_ASYNC);
                    getch();
                    cout << " YOU ARE DEAD " << endl;
                    getch();
                    Gameover();
                }



              if ( Choice21 == 2)
            {
                cout << " You leave the thing alone, with it's contents un-touched..." << endl;
                getch();
            }
        }


        }


  if (EventNumber == 23)
  {
    float DamageTaken;
    DamageTaken = 10;
      cout << " You see a falling UFO speed by over head... then you hear a bang as it crashes..." << endl;
      getch();
       getch();
        getch();
      cout << " some time later you encounter a crashed UFO and lose 5 HP to Radiation damage... " << endl;
      CurrentHP = CurrentHP - 5;
      cout << " Your HP is now " << CurrentHP;
      getch();

  }

    if (EventNumber == 24)
    {
        cout << " You encounter a rock with a arrow through it... " << endl;
    }

if (EventNumber == 25)
        {
    int Choice25;
    cout << " You encounter a guy with a bomb strapped to his chest... what do you do? " << endl;
    getch();
    cout << " Do you attempt to disarm the bomb? (1) " << endl;
    getch();
    cout << " Or do you chicken out and run away (2) " << endl;
    getch();
    cin >> Choice25;

    if (Choice25 == 1)
    {
        cout << " You try to be a hero and save the guy, you get a sharp knife that was conveniently dropped next to you... " << endl;
        cout << " You start making sense of the bomb and go for a cut... " << endl;
        getch();

            if ( INTE && PER > 10 )
            {
                cout << " You cut the right wires and the bomb makes a beeping sound... then falls off... " << endl;
                getch();
                cout << " The man thanks you for saving his life and you gain +3 to INT and PER " << endl;
                getch();
                cout << " SYSTEM +3 TO INTE AND PER " << endl;
                getch();
                INTE + 3;
                PER + 3;
            }
                if (INTE && PER < 15 )
            {
                cout << " You cut the wrong wires and the bomb makes a beeping sound... " << endl;
                getch();
                cout << " The Man Yells: WHAT HAVE YOU DONE!!! " << endl;
                getch();
                cout << " The bomb explodes killing you and that poor guy..." << endl;
                getch();
                CurrentHP = CurrentHP - 99999;
                PlaySound("DarkSoulsDead.wav", NULL, SND_FILENAME|SND_ASYNC);
                getch();
                cout << " YOU ARE DEAD... " << endl;
                Gameover();


    }

    if (Choice25 == 2)
    {
        cout << " You book it from the man as he yells begging you to come back... then you hear and explosion... " << endl;
        cout << " SYSTEM: ... YOU COWARD... " << endl;
    }

        }

    }

if (EventNumber == 26)
        {
            float DamageTaken;
            DamageTaken = 10;
            cout << " A Flash of light is seen as a man in heavy armor appears... he spots you and approaches you... " << endl;
            getch();
            if (CHR > 10)
            {
                cout << " The man says: Hello there good sir, allow me to heal you... " << endl;
                   getch();
                cout << " You are healed for 10 Points... " << endl;
                   getch();
                CurrentHP = CurrentHP + 10;
                cout << " You now have " << CurrentHP << endl;
                getch();

            }
            if (CHR < 10)
            {
                                CurrentHP = CurrentHP - DamageTaken * DifficultyIn;
                cout << " The man robs you of your pride by stabbing you with a chair... " << endl;
                cout << " You lost 3 Points of Charisma " << endl;
                getch();
                CHR = CHR - 3;
                cout << " You Lost " <<  DamageTaken << " Points of HP " << endl;
                cout << " You now have " << CHR << " Charisma Points " << endl;
                cout << " You now have " << CurrentHP << " HP Points... " << endl;
                getch();
                if (CurrentHP <= 0)
                {
                cout << " YOU DIED " << endl;
                    getch();
                Gameover();
                }
                else
                {
                    //main();
            }
            }



        }

if (EventNumber == 27)
    {
    cout << " You spot a wild Refrigerator chilling out by itself..." << endl;
    getch();
    cout << " You approach it and open it " << endl;
    getch();
    cout << " You find a Fedora and a Skeleton, you equip the fedora " << endl;
    getch();
    cout << " You get +5 to Charisma " << endl;
    CHR = CHR + 5;
    getch();
    cout << " Your Charisma is now " << CHR << endl;
    getch();
    }

if (EventNumber == 28)
    {
            cout << " You encounter a pack of crabs... " << endl;
            getch();
            cout << " They turn their claws sideways gangsta style and get into formation... " << endl;
            getch();
            cout << " They back away from you and leave you be... " << endl;
            getch();
    }

if (EventNumber == 29)
   {
         float DamageTaken;
         DamageTaken = 15;
         cout << " You encounter a pack giant of crabs... " << endl;
         getch();
         cout << " They turn their claws sideways gangsta style and get into formation... " << endl;
         getch();
         PlaySound("CRAB.wav", NULL, SND_FILENAME|SND_ASYNC);
         cout << " They start shouting: NOW YOU F*CKED UP " << endl;
         getch();

         PlaySound("BATTLECRAB", NULL, SND_FILENAME|SND_ASYNC);
         cout << " There's nowhere to run, you must defend yourself " << endl;
         getch();
         if ( STR >= 10 )
         {
            cout << " You pull out your sword and fight the crabs " << endl;
            getch();
            cout << " You slice and dice the crabs into bit and pieces and make it out the winner in the event " << endl;
            getch();
            cout << " You gained +5 to STR " << endl;
            STR = STR + 5;
            CurrentHP = CurrentHP + 10;
            getch();
         }

                  if ( STR < 10 )
         {
             CurrentHP = CurrentHP - DamageTaken * DifficultyIn;
            cout << " You pull out your sword and fight the crabs " << endl;
            getch();
            cout << " But the squad is too powerful and you get mugged, beat, and sliced by them cretin " << endl;
            getch();
            cout << " They wander off seeing you on the ground... " << endl;
            getch();
            cout << " After the whole Ordeal you took " << DamageTaken *2  << " Points of Damage " << endl;
            getch();
            PlaySound(NULL, NULL, 0);

            if ( CurrentHP <= 0)
            {
                 Gameover();
            }

            if ( CurrentHP > 0)
            {
                 cout << " You some how survived " << endl;
                 getch();
            }
         }


   }
if (EventNumber == 30)
        {
              cout <<   "You Encounter a Can of Beans... That's it... it didn't even do anything when you ate it..." << endl;
              getch();

        }


if (EventNumber == 31)
        {
              cout <<   "You Encounter a Can of Beans... When you open it to eat it, it's a LOAF OF BEANS " << endl;
              getch();
              cout << " You gained +20 HP " << endl;
              CurrentHP = CurrentHP + 20;
              getch();
              cout << " Your HP is now " << CurrentHP << endl;
              getch();
        }

 }

 if (EventNumber == 32)
   {
       cout << " You are struck by lightning " << endl;
       getch();
       cout << " You gain +3 to ALL stats and + 10 HP " << endl;
       CurrentHP = CurrentHP + 10;
       getch();
       cout << " Your HP is now " << CurrentHP << endl;
       getch();
       CHR = CHR + 3;
       STR = STR + 3;
       INTE = INTE + 3;
       PER = PER + 3;
       AGI = AGI + 3;
       LCK = LCK + 3;

       cout << " \nYour new stats are " << endl;
       cout << " Charisma " << CHR;
         cout << " Strength " << STR;
           cout <<  " Intellect " << INTE;
             cout <<  " Perception " << PER;
               cout <<  " Agility " << AGI;
                 cout << " Luck " << LCK;
                 getch();
   }

    if (EventNumber == 33)
    {
      cout << " You are struck by lightning " << endl;
      getch();
      cout << " You are Killed " << endl;
      getch();
      Gameover();
    }

      if (EventNumber == 34)
      {
           cout << " You are struck by lightning " << endl;
           getch();
           cout << " It Does 30 Damage to you " << endl;
           getch();
           CurrentHP = CurrentHP - 30;
           cout << " Your HP is now " << CurrentHP;
           getch();

           if ( CurrentHP > 0)
           {
               cout << " Congrats you survived... " << endl;
           }

           if(CurrentHP <= 0)
           {
            cout << " Congrats you are now a Fried " << RaceChosen;
            Gameover();
           }
      }


 if (EventNumber == 35)
   {
       cout << " You are struck by lightning " << endl;
       getch();
       cout << " You gain +5 to ALL stats and + 30 HP " << endl;
              getch();
       CurrentHP = CurrentHP + 10;
       cout << " Your HP is now " << CurrentHP << endl;
              getch();
       CHR = CHR + 5;
       STR = STR + 5;
       INTE = INTE + 5;
       PER = PER + 5;
       AGI = AGI + 5;
       LCK = LCK + 5;

       cout << " Your new stats are " << endl;
              getch();
       cout << " Charisma " << CHR;
              getch();
         cout << " Strength " << STR;
                getch();
           cout <<  " Intellect " << INTE;
                  getch();
             cout <<  " Perception " << PER;
                    getch();
               cout <<  " Agility " << AGI;
                      getch();
                 cout << " Luck " << LCK;
                        getch();
   }
   if ( EventNumber == 36)
   {
       cout << " You are struck by lightning... YOU BECOME SUPERCHARGED AND LIGHTNING PUNCH THE NEAREST LIZARD INTO OBRIT " << endl;
       getch();
       cout << " but 5 seconds later you die of cardiac arrest... " << endl;
        getch();
       Gameover();
   }

   if ( EventNumber == 37)
   {
       cout << " You encounter a tiny wizard lizard... " << endl;
       getch();
       cout << " You got Car Insurance, gain +1 to INTE " << endl;
       INTE = INTE + 1;
       getch();
       cout << " Your Intellect is now " << INTE << endl;
       getch();
   }

    if ( EventNumber == 38)
   {
       cout << " You encounter the brother of tiny wizard lizard " << endl;
       getch();
       cout << " the thing says: LET ME INCREASE YOUR HP YOU MERE MORTAL! " << endl;
       getch();
       cout << " You gain + 50 Health " << endl;
       CurrentHP = CurrentHP + 50;
       getch();
       cout << " Your current HP is now " << CurrentHP << endl;
       getch();
   }


    if ( EventNumber == 39)
    {
        cout << " You see someone walking in the distance twoards you... " << endl;
        getch();
        cout << " No way, you say to yourself... " << endl;
        getch();
        cout << " This person is... THE PRINCESS YOU'RE TRYING TO SAVE " << endl;
        getch();
        cout << " She approaches you and says: Wow, my hero... you took to long ya loser... " << endl;
        getch();
        cout << " SYSTEM: Well that's unexpected, but you lose... " << endl;
        getch();
        Gameover();
    }
    if(EventNumber == 40)
    {
        float DamageTaken;
        DamageTaken = 1;
        cout << " You encounter a tiny crab... " << endl;
             getch();
        cout << " SYSTEM: Not this again... " << endl;
             getch();
        cout << " You utter to your self: Not This again... " << endl;
             getch();
        cout << " The crab cuts you with it's pincer... and runs off... " << endl;
             getch();
        CurrentHP = CurrentHP - DamageTaken * DifficultyIn;
        cout << " Your HP is now " << CurrentHP << endl;
             getch();
    }

        if(EventNumber == 41)
    {

        cout << " You encounter a tiny crab... " << endl;
             getch();
        cout << " SYSTEM: Not this again... " << endl;
             getch();
        cout << " You utter to your self: Not This again... " << endl;
             getch();
        cout << " The crab hisses at you and runs off... " << endl;
             getch();
    }


    if(EventNumber == 42)
    {

        cout << " You encounter a tiny crab... " << endl;
        getch();
        cout << " SYSTEM: Not this again... " << endl;
             getch();
        cout << " You utter to your self: Not This again... " << endl;
             getch();
        cout << " The crab jumps on you and becomes a part of your armor... " << endl;
             getch();
        cout << " You gain +1 to STR and -1 to CHR " << endl;
             getch();
        CHR = CHR - 1;
        STR = STR + 1;
        cout << " Your new STR and CHR stats are " << CHR << " and " << STR << endl;
        getch();
    }

    if(EventNumber == 43)
    {
        cout << " You randomly take 10 damage... " << endl;
        CurrentHP = CurrentHP - 10;
        cout << " Your new HP is " << CurrentHP << endl;
            getch();
    }


    if (EventNumber == 44)
    {
            getch();
    cout << " Your heart starts to hurt, you think this is it, nothing happens after... " << endl;
    getch();
    }

    if (EventNumber == 45)
    {
    cout << " Your heart starts to hurt, you think this is it, nothing happens after... " << endl;
    getch();
    if (CurrentHP >= 10)
        {
         cout << " Nothing happens... yet again... " << endl;
         getch();
        }
    if (CurrentHP < 10)
     {
      cout << " Your HP Is low... your heart decides to finish you off " << endl;
      getch();
      Gameover();
     }
    }
    if(EventNumber == 46)
    {
      cout << " Your lungs start to hurt... you think this is it... again... nothing happens after... again... " << endl;
      getch();
    }

    if(EventNumber == 47)
    {
      cout << " Your lungs start to hurt... you think this is it... again... nothing happens after... again... " << endl;
      getch();

    if (CurrentHP >= 10)
        {

         cout << " Nothing happens... yet again... " << endl;
         getch();
        }
    if (CurrentHP < 10)
     {
      cout << " Your HP Is low... your Lungs decide to finish you off " << endl;
      getch();
      Gameover();
     }
    }


    if(EventNumber == 48)
    {
        cout << " You feel a sudden wave of anxiety " << endl;
        getch();
    }


  if(EventNumber == 49)
    {
        cout << " You feel a sudden wave of fear " << endl;
        getch();
    }

if(EventNumber == 50)
    {
     cout << " SYSTEM: wait, i'm a random event? " << endl;
     getch();
     cout << " SYSTEM: Finally someone sees me as a actual character for once! " << endl;
     getch();
     cout << " I am honored.. " << endl;
     getch();
    }


if (EventNumber == 51)
        {
        cout << " You Feel A Sudden Wave Of Excitement" << endl;
        getch();
            //main();
        }
else if (EventNumber == 52)
        {
              cout << " You Feel A Sudden Wave Of Sadness\n " << endl;
              getch();
              if (CHR < 3)
              {
                  cout << "\nYou commit suicide" << endl;
                  getch();
                  Gameover();
              }
        }
else if (EventNumber == 53)
        {
              float DamageTaken;
              DamageTaken = 10;
             cout << " You Encounter A Highly Explosive Wizard " << endl;
             getch();
             if (LCK < 4)
             {
                 cout << " The Wizard Yells EXPLOSION, Blowing Up Everything In A 50 Foot Radius Killing You Both" << endl;
                 getch();
                 Gameover();
             }
             else
             {
                 cout << " She hits you with her staff and runs off... " << endl;
                CurrentHP = CurrentHP - DamageTaken * DifficultyIn;
                getch();
                cout << " Your HP is now " << CurrentHP;
                getch();

                 //main();
             }
        }
else if (EventNumber == 54)
        {
        cout << " You See A Water Goddess In The Distance\n" << endl;
        getch();

        if (CHR < 4 && LCK < 4 && INTE < 4 && STR < 4 && PER < 4)
            {
            cout << " She Catches You Staring At Her And Proceeds To Drag You To The Lake, Drowning You" << endl;
            getch();
            Gameover();
            }
        else
            {
            cout << " She Runs Away As Soon As She Spots You" <<endl;
            getch();
            //main();
            }
        }

else if (EventNumber == 55)
        {
       cout << " You Encounter An Ancient Machine Known As A Guardian" << endl;
       getch();
       if (LCK < 5 && AGI < 5 && PER < 5)
            {
           cout << " The Guardian Detects You And Stabs You From The Top Of Your Skull Downwards" << endl;
           getch();
           Gameover();
            }
       else
            {
           cout << "The Guardian Is In A Dormant State, Allowing You To Pass By Unharmed" << endl;
           getch();
           //main();
            }
        }

else if (EventNumber == 56)
        {

        cout << "A Long, Tall, White, Malnourished Humanoid Creature Approaches You" << endl;
        getch();
        cout << "Do You Look At It? Y or N" << endl;
        cin >> YorN;
        if (YorN == 'Y' || YorN == 'y')
        {
            cout << "The Creature Begins Screaming And Chases You With A Seemingly Endless Amount Of Stamina" <<
            "\n It Eventually Catches You, Killing You Instantly" << endl;
            getch();
            Gameover();
        }
        else
        {
            cout << "You Walk Away From The Creature" << endl;
            getch();
            //main();
        }
        }
else if (EventNumber == 57)
        {
            cout << "You Encounter A Floating Ball Of Water... After a Couple Of Seconds It Disappears" << endl;
            getch();
            //main();
        }

else if (EventNumber == 58)
        {
            cout << "You Encounter A Circular Rock With A Hole In The Middle... Do You Walk Into It? Y Or N" << endl;
            cin >> YorN;
            if (YorN == 'Y' || YorN == 'y')
            {
                cout << " The Player enters the portal... " << endl;
                getch();
                cout << " SYSTEM: WAIT WAIT WAI- " << endl;
                getch();
                MainMenu();
            }
            else
            {
                cout << "The Rock Tells You It Can Take You Into Time But You Walk Away..." << endl;
                getch();
                //main();
            }
        }
else if (EventNumber == 59)
        {
            cout << "You Get A Splinter" << endl;
            getch();
            CurrentHP = CurrentHP - 1;
            cout << " You lose 1 HP, your HP is now " << CurrentHP << endl;
            getch();
            //main();
        }


else if (EventNumber == 60)
        {
            cout << "You Get Dysentery... You Take 10 Damage" << endl;
            CurrentHP = CurrentHP - 10;
            getch();
            if (CurrentHP <= 0)
            {
                cout << " You die of Dysentery... " << endl;
                getch();
                Gameover();
            }
            else
            {
                //main();
            }

        }



     if (EventNumber == 61)
        {
            cout << "You Walk On A Spike... You Take 30 Damage" << endl;
            CurrentHP = CurrentHP - 30;
            cout << " Your HP is now " << CurrentHP << endl;
            getch();
            if (CurrentHP <= 0)
            {
                Gameover();
            }
            else
            {
              //REvent(CurrentHP, CHR, LCK, AGI, INTE, PER, STR);
            }
        }



        if (EventNumber == 62)
        {
            cout << "You Trip On A Massive, Extremely Sharp Rock" << endl;
            getch();
            if (LCK <= 4)
            {
                cout << "You Hit Your Head On The Rock... You Die Instantly" << endl;
                getch();
                Gameover();
            }
            else if (LCK >= 12)
            {
                cout << "Because Of Your Insane Reflexes, You Catch Yourself Just In Time To Not Take Any Damage" << endl;
                getch();
               // REvent(CurrentHP, CHR, LCK, AGI, INTE, PER, STR);
            }
            else
            {
                cout << "You Hit Your Head On The Rock, Dealing 90 Damage" << endl;
                getch();
                CurrentHP = CurrentHP - 75;
                cout << " Your HP is now " << CurrentHP << endl;
                getch();
                if (CurrentHP <= 0)
                {
                    Gameover();
                }
                else
                {
                    CurrentHP = CurrentHP;
                //    REvent(CurrentHP, CHR, LCK, AGI, INTE, PER, STR);
                }
            }

        }



        if (EventNumber == 63)
        {
            cout << "You Hear Someone In The Distance Say Nice..." << endl;
            getch();
         //   REvent(CurrentHP, CHR, LCK, AGI, INTE, PER, STR);
        }



        if (EventNumber == 64)
        {
            cout << "You Hear Someone In The Distance Say Not Nice..." << endl;
            getch();
          //  REvent(CurrentHP, CHR, LCK, AGI, INTE, PER, STR);
        }



        if (EventNumber == 65)
        {
            cout << "Just To Your Side You Hear Someone Begin To Yell KAME-HAME-HAAA!!" << endl;
            getch();
            cout << "\nJust As You Turn To See Who It Is, Your Limbs Become Disconnected From The Rest Of Your Body..." << endl;
            cout << "\nYou Die Instantly..." << endl;
            getch();
            Gameover();
        }



        if (EventNumber == 66)
        {
            cout << "\nYou Encounter A Knight Who Just Happens To Be Passing By" << endl;
            getch();
            if (LCK <= 4)
            {
                cout << "\nThe Knight Doesn't Vibe With You And Kills You..." << endl;
                getch();
                Gameover();
            }
            else
            {
                cout << "The Knight Vibes With You And You Gain +5 To The LCK Stat..." << endl;
                LCK = LCK + 5;
                getch();
            //REvent(CurrentHP, CHR, LCK, AGI, INTE, PER, STR);
            }
        }



        if (EventNumber == 67)
        {
            cout << "You Trip On A Rock... You Take 5 damage" << endl;
            CurrentHP = CurrentHP - 5;
            cout << " Your HP is now " << CurrentHP << endl;
            getch();

            if (CurrentHP <= 0)
            {
                Gameover();
            }
            else
            {
          //      REvent(CurrentHP, CHR, LCK, AGI, INTE, PER, STR);
            }
        }



        if (EventNumber == 68)
        {
            cout << "You trip on a rock... You hit your head on a bigger rock and take 60 damage" << endl;
            getch();
            CurrentHP = CurrentHP - 60;
            cout << "Your HP is now " << CurrentHP << endl;
            getch();
            if (CurrentHP <= 0)
            {
                Gameover();
            }
            else
            {
            //   REvent(CurrentHP, CHR, LCK, AGI, INTE, PER, STR);
            }
        }



        if (EventNumber == 69)
        {
            cout << "You encounter a metal object in the shape of a W on the ground" << endl;
            getch();
            if (INTE >= 7)
            {
                cout << "You take the object and deploy it away from you... ENERGY SWORD GAINED" << endl;
                STR = STR + 10;
                getch();
                cout << " Your new sword adds 10 to strength! " << endl;
                cout << " Your new strength is " << STR << endl;
                getch();
                (CurrentHP, CHR, LCK, AGI, INTE, PER, STR);
            }
            if (INTE < 7)
            {
                cout << "You take the object and deploy it right into your chest, killing yourself with an energy sword..." << endl;
                getch();
                Gameover();
            }
        }



        if (EventNumber == 70)
        {
            cout << "You encounter a giant green pipe... You hear a distant voice shout It'sa Me, Mario!" << endl;
            getch();
           // REvent(CurrentHP, CHR, LCK, AGI, INTE, PER, STR);
        }



        if (EventNumber == 71)
        {
            cout << "You encounter a group of members from the BrotherHood of Steel... " << endl;
            getch();
            if (AGI < 5)
            {
                cout << "They spot you and begin shooting at you with their miniguns... \n" <<
                "Your AGI is too low to get away, causing you to be killed." << endl;
                getch();
                Gameover();
            }
            else if (AGI >=5 && AGI <= 10)
            {
                cout << "They spot you and begin shooting at you with their miniguns... \n" <<
                "You barely escape but lose 65 HP..." << endl;
                getch();
                cout << " Your HP is now " << CurrentHP << endl;
                getch();
                CurrentHP = CurrentHP - 65;
                if (CurrentHP <= 0)
                {
                    Gameover();
                }
                else
                {
                 (CurrentHP, CHR, LCK, AGI, INTE, PER, STR);
                }
            }
            else
            {
                cout << "\nBecause of your high AGI, you get away without being spotted" << endl;
                getch();
          //REvent(CurrentHP, CHR, LCK, AGI, INTE, PER, STR);
            }
        }

       if (EventNumber == 72)
        {
            cout << "You hear roaring in the distance... you never hear it again" << endl;
            getch();
            //REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);

        }



        if (EventNumber == 73)
        {
            cout << "You meet a cat..." << endl;
            getch();
            cout << "It meows and runs off" << endl;
            getch();
            //REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
        }



        if (EventNumber == 74)
        {
            cout << "You meet a cat..." << endl;
            getch();
            cout << "You gain +1 to CHR" << endl;
            CHR = CHR + 1;
            getch();
            cout << " Your CHR is now " << CHR << endl;
            getch();
           // REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
        }



        if (EventNumber == 75)
        {
            cout << "You meet a cat..." << endl;
            getch();
            cout << "It scratches you and runs off... You  take 10 damage" << endl;
            CurrentHP = CurrentHP - 10;
            getch();
            cout << "Your HP is now " << CurrentHP << endl;
            getch();
            if (CurrentHP <= 0)
            {
                Gameover();
            }
            else
            {
               // REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
            }

        }



        if (EventNumber == 76)
        {
            cout << "You encounter a balloon with a present tied to it..." << endl;
            getch();
            cout << "It begins to float away, do you shoot it down? Y or N" << endl;
            cin >> YorN;
            if (YorN == 'Y' || YorN == 'y')
            {
                cout << "You shoot the balloon down, it explodes... You take 20 damage" << endl;
                CurrentHP = CurrentHP - 20;
                getch();
                cout << "Your HP is now " << CurrentHP << endl;
                getch();
                if (CurrentHP <= 0)
                {
                    Gameover();
                }
                else
                {
                   // REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
                }
            }
            if (YorN == 'N' || YorN == 'n')
            {
                cout << "It floats away, you will never know what it contained..." << endl;
                getch();
               // REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
            }
        }



        if (EventNumber == 77)
        {
            cout << "You encounter a balloon with a present tied to it..." << endl;
            getch();
            cout << "It begins to float away, do you shoot it down? Y or N" << endl;
            cin >> YorN;
            if (YorN == 'Y' || YorN == 'y')
            {
                cout << "You shoot the balloon down, You gain +1 to LCK" << endl;
                LCK = LCK + 1;
                getch();
                cout << "Your LCK is now " << LCK << endl;
                getch();
               // REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
            }
            if (YorN == 'N' || YorN == 'n')
            {
                cout << "It floats away, you will never know what it contained..." << endl;
                getch();
               // REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
            }
        }



        if (EventNumber == 78)
        {
            cout << "You randomly take 10 damage..." << endl;
            getch();
            CurrentHP = CurrentHP - 10;
            cout << "Your HP is now " << CurrentHP << endl;
            getch();
            if (CurrentHP <= 0)
            {
                Gameover();
            }
            else
            {
              //  REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
            }
        }



        if (EventNumber == 79)
        {
            cout << "You randomly take 20 damage..." << endl;
            getch();
            CurrentHP = CurrentHP - 20;
            cout << "Your HP is now " << CurrentHP << endl;
            getch();
            if (CurrentHP <= 0)
            {
                Gameover();
            }
            else
            {
              //  REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
            }
        }



        if (EventNumber == 80)
        {
            cout << "You randomly take 50 damage..." << endl;
            getch();
            CurrentHP = CurrentHP - 50;
            cout << "Your HP is now " << CurrentHP << endl;
            getch();
            if (CurrentHP <=0)
            {
                Gameover();
            }
            else
            {
             //   REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
            }
        }



        if (EventNumber == 81)
        {
            cout << "You feel a pain in your chest..." << endl;
            getch();
            cout << "You have a heart attack..." << endl;
            getch();
            Gameover();
        }



        if (EventNumber == 82)
        {
            cout << "You gain 100 HP" << endl;
            CurrentHP = CurrentHP + 100;
            getch();
            cout << "Your HP is now " << CurrentHP << endl;
            getch();
            //REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
        }



        if (EventNumber == 83)
        {
            cout << "You gain 20 HP" << endl;
            CurrentHP = CurrentHP + 20;
            getch();
            cout << "Your HP is now " << CurrentHP << endl;
            getch();
          //  REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
        }



        if (EventNumber == 84)
        {
            cout << "You gain 30 HP" << endl;
            CurrentHP = CurrentHP + 30;
            getch();
            cout << "Your HP is now " << CurrentHP << endl;
            getch();
          //  REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
        }



        if (EventNumber == 85)
        {
            if (LostLimb == 2)
            {
                cout << "You regrow a lost limb..." << endl;
                LostLimb = 1;
                getch();
            //    REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
            }
            else
            {
                cout << "You are relieved when you see you have all your limbs still..." << endl;
                getch();
               // REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
            }

        }



        if (EventNumber == 86)
        {
            if (LostLimb == 1)
            {
                cout << "A random limb falls off your body..." << endl;
                LostLimb = 2;
                getch();
             //   REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
            }
            else
            {
                cout << "You really wish that limb wouldn't have fallen off earlier." << endl;
                getch();
              //  REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
            }
        }



        if (EventNumber == 87)
        {
            cout << "You hear boss music in the distance..." << endl;
            getch();
            cout <<  "It fades away" << endl;
            getch();
         //   REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
        }



        if (EventNumber == 88)
        {
            cout << "You hear boss music in the distance..." << endl;
            getch();
            cout << "It grows louder" << endl;
            getch();
          //  REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
        }



        if (EventNumber == 89)
        {
            cout << "You hear battle music..." << endl;
            getch();
            cout << "It grows near" << endl;
            getch();
        //    REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
        }




        if (EventNumber == 90)
        {
            cout << "You hear battle music..." << endl;
            getch();
            cout << "It fades away" << endl;
            getch();
        //    REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
        }



        if (EventNumber == 91)
        {
            cout << "A rock hits you on the head... You take 1 damage" << endl;
            getch();
            CurrentHP = CurrentHP - 1;
            cout << "Your HP is now " << CurrentHP << endl;
            getch();
            if (CurrentHP <= 0)
            {
                Gameover();
            }
            else
            {
           //     REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
            }
        }



        if (EventNumber == 92)
        {
            cout << "You kick a rock..." << endl;
            getch();
            cout << "You lose 1 AGI" << endl;
            getch();
            AGI = AGI - 1;
            cout << "Your AGI is now " << AGI << endl;
            getch();
           // REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
        }



        if (EventNumber == 93)
        {
            cout << "You kick a rock..." << endl;
            getch();
            cout << "It hits a tree and explodes..." << endl;
            getch();
            cout << "You gain 1 LCK..." << endl;
            getch();
            cout << "You lose 1 PER..." << endl;
            getch();
            LCK = LCK + 1;
            PER = PER - 1;
            cout << "Your LCK is now " << LCK << " and your PER is now " << PER << endl;
            getch();
          //  REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
        }



        if (EventNumber == 94)
        {
            cout << "+15 to STR" << endl;
            getch();
            STR = STR + 15;
            cout << "Your STR is now " << STR << endl;
            getch();
           // REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
        }



        if (EventNumber == 95)
        {
            cout << "-15 to STR" << endl;
            getch();
            STR = STR - 15;
            cout << "Your STR is now " << STR << endl;
            getch();
           // REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
        }



        if (EventNumber == 96)
        {
            cout << "A crab approaches you and mugs you..." << endl;
            getch();
            cout << "You lose 1 CHR" << endl;
            getch();
            CHR = CHR - 1;
            cout << "Your CHR is now " << CHR << endl;
            getch();
       //     REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
        }



        if (EventNumber == 97)
        {
            cout << "A thug approaches you..." << endl;
            getch();
            cout << "You get mugged and take 10 damage" << endl;
            getch();
            CurrentHP = CurrentHP - 10;
            cout << "Your HP is now " << CurrentHP << endl;
            if (CurrentHP <= 0)
            {
                Gameover();
            }
            else
            {
                //REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
            }
        }



        if (EventNumber ==  98)
        {
            int Punches = rand() % 10 + 1;
                cout << "You are approached by a boxer." << endl;
                getch();
                if (STR < 12)
                {
                    cout << "He hits you " << Punches << " Time(s), Dealing 5 damage each" << endl;
                    getch();
                    for (Punches = Punches; Punches > 0; Punches--)
                    {

                        CurrentHP = CurrentHP - 5;
                    }
                    cout << "Your HP is now " << CurrentHP << endl;
                    getch();
                    if (CurrentHP <= 0)
                        {
                            Gameover();
                        }
                        else
                        {
                          //  REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
                        }
                }
              else
                    {
                        cout << "He passes by leaving you unharmed" << endl;
                        getch();
                        //REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
                    }
        }



        if (EventNumber == 99)
        {
            cout << "Along your path you see a sign that says there is cake up ahead..." << endl;
            getch();
            cout << "Do you follow the sign to get the free cake? Y or N" << endl;
            cin >> YorN;
            if (YorN == 'Y' || YorN == 'y')
            {
                cout << "There is a door you enter that brings you into an odd, abandoned room with white panels everywhere." <<
                "\nYou walk behind one of the panels and see writing all over the walls stating The Cake Is A Lie..." << endl;
                getch();
                cout << "After a little bit you leave the room and continue on your journey." << endl;
                getch();
                //REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
            }
            if (YorN == 'N' || YorN == 'n')
            {
                cout << "You don't pay much attention to it and continue on your journey..." << endl;
                getch();
               // REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
            }




        }



        if (EventNumber == 100)
            {
                cout << "You encounter an oddly cube shaped set of rocks leading into a forest of oak trees..." << endl;
                getch();
                cout << "Do you enter the forest in hopes of finding a place to rest? Y or N" << endl;
                cin >> YorN;
                if (YorN == 'Y' || YorN == 'y')
                {
                    cout << "You enter the forest and you notice everything around you looks oddly uniform and symmetrically cube shaped..." << endl;
                    cout << "You spot a small shack between a couple trees that would be a good resting spot, do you approach it? Y or N" << endl;
                    cin >> YorN;
                    if (YorN == 'Y' || YorN == 'y')
                    {
                        cout << "As you approach the shack, from  behind you hear a faint foot step, then a loud hissing noise..." << endl;
                        cout << "As you whip around to see what it is, there is a large explosion and you are killed..." << endl;
                        getch();
                        Gameover();
                    }
                    else if (YorN == 'N' || YorN == 'n')
                    {
                        cout << "You exit the forest and continue on your quest..." << endl;
                        getch();
                       // REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
                    }
                }
                else if (YorN == 'N' || YorN == 'n')
                    {
                        cout << "You get an unsettling feeling about the forest and continue on your way..." << endl;
                        getch();
                        cout << "As you are passing by, a pleasantly relaxing song begins to play..." << endl;
                        getch();
                        //REvent(CurrentHP, CHR, LCK, AGI, INT, PER, STR, LostLimb);
                    }
            }
}

//********************************************************************
//
// Game Over function
//
// Once the user hits HP Zero they die and are sent here
//
// Return Value
// ------------
// This returns either The call to MainMenu();
// or exit(1) to end the program
//
// Function Parameters
// ----------------
// string Name value
//
// Local Variables
// ---------------
// char ChoiceGo
//
//
//*******************************************************************
 int Gameover()
{
    char ChoiceGO;
    cout << " SYSTEM: So the mighty hero " << Name << " has fallen in battle huh? " << endl;
    cout << " SYSTEM: So... Do you want to try again? " << endl;
    cout << " Yes (Y) " << endl;
    cout << " No (N) " << endl;
    cin >> ChoiceGO;

    if ( ChoiceGO == 'Y' || ChoiceGO == 'y')
    {
        MainMenu();
    }

     if ( ChoiceGO == 'N' || ChoiceGO == 'n')
    {
        cout << " Until next time... young lad... " << endl;
        DecisionLog();
        exit(1);
    }



}

//********************************************************************
//
// Status Check Function
//
// This displays all stats and ensures you are still alive
//
// Return Value
// ------------
// If HP > 0 then you are passed back to the story
// If HP < 0 then you are sent to GameOver();
//
// Function Parameters
// ----------------
// CurrentHP int    Value CurrentHP of the character
// CHR       int          Value Charisma Stat
// STR      int          Value Strength Stat
// INTE     int         Value Intelligence Stat
// PER      int          Value Perception Stat
// AGI      int          Value Agility Stat
// LCK      int          Value Luck Stat
// Munny    int        Value Money Stat
//
// Local Variables
// ---------------
//
//
//
//*******************************************************************
int StatCheck()
{
    system ("CLS");
    cout << " This is the Status Checkpoint " << endl;
    cout << " Your HP is " << CurrentHP << endl;
    getch();
         cout << " Charisma " << CHR << endl;
            getch();
         cout << " Strength " << STR << endl;
            getch();
           cout <<  " Intellect " << INTE << endl;
              getch();
             cout <<  " Perception " << PER << endl;
                getch();
               cout <<  " Agility " << AGI << endl;
                  getch();
                 cout << " Luck " << LCK << endl;
                    getch();
                    cout << " Money " << Munny << endl;

                    if(CurrentHP < 0)
                    {
                        Gameover();
                    }


}


//********************************************************************
//
// Game Complete function
//
// this if if the player beats the dragon by any means necessary in the last 2 chapters
//
// Return Value
// ------------
// FinalChoice == 1 int Return to menu
// FinalChoice == 2 int Exit game
//
// Function Parameters
// ----------------
// Local Variables
// ---------------
// RandomEvent int Event Chosen
//
//
//*******************************************************************
void GameComplete()
{
    cout << " And so " << Name << " Has defeated the dragon once and for all... " << endl;
         getch();
    cout << " And saved the princess from said dragon " << endl;
         getch();
    cout << " This is it... Game Over... YOU WIN " << endl;
         getch();

    cout << " Well... You win... Do you want to play again? (Y/N) " << endl;
    int FinalChoice;
    cin >> FinalChoice;

    if( FinalChoice == 'Y' || FinalChoice == 'y')
    {
        cout << " Well then, lets begin again " << endl;
        MainMenu();
    }

    if(FinalChoice == 'N'|| FinalChoice == 'n')
    {
        cout << " Well then... Thanks for playing and we hope to see you again " << endl;
        cout << " Adios " << Name << endl;
        DecisionLog();
         exit(1);
    }


}


//********************************************************************
//
// Battle Failed function
//
// this if if the player dies to the dragon in the last 2 chapters
//
// Return Value
// ------------
// DeathChoice == 1 int Return to menu
// DeathChoice == 2 int Exit game
//
// Function Parameters
// ----------------
// Name String Value Name of character
//
// Local Variables
// ---------------
// DeathChoice int Chooses to exit or restart
//
//
//*******************************************************************
void BattleFailed()
{
    cout << " SYSTEM: and so our hero " << Name << " Who fought valiantly in their quest to save the princess and slay the dragon... " << endl;
    getch();
    cout << " SYSTEM: Would come to fall in battle... their quest coming to a tragic end in the pursuit of accomplishing their one known task... " << endl;
    getch();
    cout << " Rest Easy " << Name << endl;
    cout << " Do you want to play again? " << endl;
    int DeathChoice;
    cin >> DeathChoice;

    if( DeathChoice == 'Y' || DeathChoice == 'y')
    {
        cout << " Well then, lets try again " << endl;
        MainMenu();
    }

    if(DeathChoice == 'N'|| DeathChoice == 'n')
    {
        cout << " Well then... Thanks for playing and we hope to see you again " << endl;
        cout << " Adios " << Name << endl;
        DecisionLog();
        exit(1);
    }
}



