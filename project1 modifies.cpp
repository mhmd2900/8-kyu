#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


enum enchoices { paper = 1 , stone = 2 , scissor = 3 , invalid };
enum enplayers { pl1 , comp , draw } ;
string choice_to_word (enchoices enenchoices )
{
    string word [3] = { "paper" , "stone" , "scissor"};
    return word[enenchoices-1];
} 
string choice_to_player (enplayers enenplayers )
{
    switch ( enenplayers )
    {
    case enplayers::pl1 :
    return "pl1 is the one " ;
    case enplayers::comp :
    return "comp is the one " ;
    case enplayers::draw :
    return "no one wins " ;
   
    default :
    return "invalid" ;
    }
} 

struct stround 
{
enchoices pl1_choose ;
enchoices comp_choose ;
enplayers winner ;
} ;

struct st_gamestats 
{
int count = 0 ;
int pl1_win = 0 ;
int comp_win = 0 ;
int draw_win = 0 ;
enplayers final_winner ;
} ;

                                                                               int input_number ( string message )
                                                                                {
                                                                                int num ;
                                                                                cout << message ;
                                                                                while (true)
                                                                                {
                                                                                if (cin >> num && num >=1 && num <=10  )
                                                                                return num;
                                                                                else
                                                                                {
                                                                                cout << " wrong input , retry from 1 to 10 \n" ;
                                                                                cin.clear();
                                                                                cin.ignore(100 , '\n');
                                                                                }
                                                                                }
                                                                                }

                                                                               int input_choice ( string message )
                                                                                {
                                                                                int num ;
                                                                                cout << message ;
                                                                                while (true)
                                                                                {
                                                                                if (cin >> num && num >=1 && num <=3  )
                                                                                return num;
                                                                                else
                                                                                {
                                                                                cout << " wrong input , retry from 1 to 3  \n" ;
                                                                                cin.clear();
                                                                                cin.ignore(100 , '\n');
                                                                                }
                                                                                }
                                                                                }

                                                                               int input_random ( int from , int to )
                                                                            {
                                                                            return rand()%( to - from + 1)+ from ;
                                                                            }

void game_over ()
{
cout << "                                 ____________________________________________________________ \n " ;
cout << "                                                   +++ GAME OVER +++                          \n " ;
cout << "                                 _____________________________________________________________ \n " ;
cout << "                                 __________________ [ GAME RESULTS ]__________________________ \n " ;
cout << "                                 _____________________________________________________________ \n " ;
}

bool want_to_repeat ()
{
 char ch ;
 cout << " \n do you want to repeat the game [ y / n ] ? \n";
 while ( true )
 {

    if ( cin >> ch && ( ch == 'y' || ch == 'Y' ))
    return true ;

    else if ( ch == 'n' || ch == 'N' )
    return false ;

    else
    {
    cout << " only choose  [ y / n ] ? \n";
    cin.clear();
    cin.ignore ( 100 , '\n');
    }
 }
}

void color_rule ( stround ststround , st_gamestats& stst_gamestats)
{
if ( ststround.winner == pl1 )
{
system ("color 2F");
stst_gamestats.pl1_win ++ ;
}
else if ( ststround.winner == comp )
{
system ("color 4F");
stst_gamestats.comp_win ++ ;
}
else if ( ststround.winner == draw )
{
system ("color 6F");
stst_gamestats.draw_win ++ ;
}
}


void winning_rule ( stround& ststround )
{
if ( ststround.pl1_choose == ststround.comp_choose )
ststround.winner = enplayers::draw ;
else 
{
ststround.winner =  ( ststround.pl1_choose == enchoices::paper   && ststround.comp_choose == enchoices::stone   ) ||
                    ( ststround.pl1_choose == enchoices::stone   && ststround.comp_choose == enchoices::scissor ) ||
                    ( ststround.pl1_choose == enchoices::scissor && ststround.comp_choose == enchoices::paper   )
 ?enplayers::pl1 : enplayers::comp  ;
}
cout << " \n round winner is " << choice_to_player(ststround.winner) ;
}


void each_round ( st_gamestats& stst_gamestats )
{
stround ststround ;
ststround.pl1_choose = (enchoices)input_choice ( " \n write your choice \n");
ststround.comp_choose = (enchoices)input_random ( 1 , 3 );
cout << " pl1 choose "      << choice_to_word( ststround.pl1_choose) ;
cout << " \n comp  choose " <<  choice_to_word(ststround.comp_choose ) ;
winning_rule(ststround) ;
color_rule(ststround , stst_gamestats) ;
}


void all_rounds ()
{

st_gamestats stst_gamestats ;

stst_gamestats.count = input_number(" how many rounds ? \n ") ;
for ( int i = 0 ; i < stst_gamestats.count ; i ++ )
each_round(stst_gamestats ) ;

game_over();

cout <<" \n number of rounds " <<stst_gamestats.count;
cout <<" \n player 1 wins  " <<stst_gamestats.pl1_win;
cout <<" \n computer wins  " <<stst_gamestats.comp_win;
cout <<" \n no winner times " <<stst_gamestats.draw_win;
if ( stst_gamestats.pl1_win > stst_gamestats.comp_win)
stst_gamestats.final_winner   = enplayers::pl1 ;
else if ( stst_gamestats.pl1_win < stst_gamestats.comp_win)
stst_gamestats.final_winner   = enplayers::comp ;
else
stst_gamestats.final_winner  = enplayers::draw ;
cout << " \n final winner is " << choice_to_player(stst_gamestats.final_winner ) ;

}


void game_start ()
{
do 
{
system("cls") ;
system ( "color 0F") ;
all_rounds () ;
} while (want_to_repeat()) ;
}


int main()
{
srand((unsigned)time(NULL));
game_start();
return 0;
}



