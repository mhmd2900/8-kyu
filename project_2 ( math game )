#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std ;

enum enquestion_level { easy = 1 , med = 2 , hard = 3 , mix = 4 };
enum enoperator { add = 1 , sub = 2 , mult = 3 , divi = 4 , all = 5 };
enum enpass_fail { pass = 1 , fail = 2 , draw = 3 } ;

string level_to_word (enquestion_level enenquestion_level )
{
string word[4] = { "easy" , "med" , "hard" , "mix"};
return word [ enenquestion_level - 1 ];
}

string operator_to_word (enoperator enenoperator )
{
switch ( enenoperator )
{
case enoperator::add :
return "+" ;
case enoperator::sub :
return "-" ;
case enoperator::mult:
return "*" ;
case enoperator::divi :
return "/" ;
// case enoperator::mix :
// return ;
default :
return "all" ;
}
}

struct stgamestats 
{
enpass_fail enpasser ;
int questions_number ;
enquestion_level enenquestion_level ;
enoperator enenoperator ;
int correct_number = 0 ;
int wrong_number = 0  ;
};

struct sttwo_numbers 
{
int num1 = 0 ;
int num2  = 0 ;
int ans = 0 ;
int yans = 0 ;
char op = 'a' ;
};

                                                                                int number ( string message )
                                                                                {
                                                                                int num ;
                                                                                cout << message ;
                                                                                while ( true )
                                                                                {
                                                                                if ( cin >> num )
                                                                                return num ;
                                                                                else 
                                                                                {
                                                                                cout << " wrong input , repeat ";
                                                                                cin.clear();
                                                                                cin.ignore(100 , '\n');
                                                                                }
                                                                                }
                                                                                }

                                                                                int random ( int from , int to )
                                                                                {
                                                                                return rand()%( to - from + 1 ) + from ;
                                                                                }

                                                                                int random2 ()
                                                                                {
                                                                                    int t = 0 ;
                                                                                 while ( true )
                                                                                 {
                                                                                    t = rand()%9 + 40 ;
                                                                                    if ( t == 42 || t == 43 || t == 45 || t == 47)
                                                                                    return t ;
                                                                                 }
                                                                                }

bool want_to_repeat ( )
{
cout << endl ;
char ch ;
cout << " Do you want to repeat , if yes press [y] , if no press [n] \n";
while ( true )
{
if ( cin >> ch && ( ch == 'y' || ch == 'Y'))
return true ;
else if ( ch == 'n' || ch == 'N')
{
system ("cls");
system ( "color 0F") ;
return false ;
}

else
{
cout << " wrong choice , plz choose y or n \n " ;
cin.clear();
cin.ignore(100,'\n');
}
}
}


void choose_level ( sttwo_numbers& ststtwo_numbers , stgamestats ststgamestats)   
{
if (ststgamestats.enenquestion_level == enquestion_level::easy )
{
ststtwo_numbers.num1 = random ( 1 , 9);
ststtwo_numbers.num2 = random ( 1 , 9);
}
else if (ststgamestats.enenquestion_level == enquestion_level::med)
{
ststtwo_numbers.num1 = random ( 11 , 99);
ststtwo_numbers.num2 = random ( 11 , 99);
}
else if (ststgamestats.enenquestion_level == enquestion_level::hard )
{
ststtwo_numbers.num1 = random ( 111 , 222);
ststtwo_numbers.num2 = random ( 111 , 222 );
}
else if (ststgamestats.enenquestion_level == enquestion_level::mix )
{
ststtwo_numbers.num1 = random ( 1 , 222);
ststtwo_numbers.num2 = random ( 1 , 222);
}
}                                                                             

void choose_operator ( sttwo_numbers& ststtwo_numbers , stgamestats ststgamestats)
{
if      (ststgamestats.enenoperator == enoperator::add)
ststtwo_numbers.op = '+';
else if (ststgamestats.enenoperator == enoperator::sub)
ststtwo_numbers.op = '-';
else if (ststgamestats.enenoperator == enoperator::mult)
ststtwo_numbers.op = '*';
else if (ststgamestats.enenoperator == enoperator::divi)
ststtwo_numbers.op = '/';
else if (ststgamestats.enenoperator == enoperator::all)
ststtwo_numbers.op = char ( random2()) ;

}

void show_equation (sttwo_numbers&  ststtwo_numbers)
{

cout << ststtwo_numbers.num1 << endl ;
cout << ststtwo_numbers.op  << endl ; 
cout << ststtwo_numbers.num2 << endl  ;
cout << "_______    \n " ;
ststtwo_numbers.yans = number ( " ??      ") ;

}

void comp_answer ( sttwo_numbers& ststtwo_numbers)
{
if         (ststtwo_numbers.op == '+' )
ststtwo_numbers.ans = ststtwo_numbers.num1 + ststtwo_numbers.num2 ;
else if    (ststtwo_numbers.op == '-' )
ststtwo_numbers.ans = ststtwo_numbers.num1 - ststtwo_numbers.num2 ;
else if    (ststtwo_numbers.op == '*' )
ststtwo_numbers.ans = ststtwo_numbers.num1 * ststtwo_numbers.num2 ;
else if    (ststtwo_numbers.op == '/' )
ststtwo_numbers.ans = ststtwo_numbers.num1 / ststtwo_numbers.num2 ;
}

void compare ( sttwo_numbers ststtwo_numbers , stgamestats& ststgamestats )
{
if ( ststtwo_numbers.yans == ststtwo_numbers.ans )
{
cout << " \n correct answer \n" ;
system ( " color 2F");
ststgamestats.correct_number ++ ;
}
else 
{
cout << " \n wrong answer \n the correct answer is " << ststtwo_numbers.ans << endl ; 
system ( " color 4F");
}
}

void each_round ( int count , stgamestats& ststgamestats)
{

sttwo_numbers ststtwo_numbers ;

cout << "  \n ============================== \n       Question [" << count << "/"<< ststgamestats.questions_number << "]" << endl ;

choose_level    ( ststtwo_numbers , ststgamestats) ;
choose_operator ( ststtwo_numbers , ststgamestats) ;
show_equation   ( ststtwo_numbers) ;
comp_answer     ( ststtwo_numbers) ;
compare         ( ststtwo_numbers , ststgamestats) ;


}

void who_pass ( stgamestats& ststgamestats )
{
if      ( ststgamestats.correct_number > ststgamestats.wrong_number)
ststgamestats.enpasser = enpass_fail::pass ;
else if ( ststgamestats.correct_number < ststgamestats.wrong_number)
ststgamestats.enpasser = enpass_fail::fail ;
else
ststgamestats.enpasser = enpass_fail::draw ;
}

void final_result ( stgamestats ststgamestats )
{
cout << "_________________________________________________________________ \n";
cout << " final result is ";
if      ( ststgamestats.enpasser == enpass_fail::pass)
{
cout << " PASS  :-)   \n ________________________________________ \n ";
system (" color 2F") ;
}

else if ( ststgamestats.enpasser == enpass_fail::fail)
{
cout << " FAIL  :-(   \n ________________________________________ \n " ;
system ( " color 4F");
}

else 
{
" DRAW \n ________________________________________________________________ \n " ;
system ("color 6 F");
}
}

void stats ( stgamestats ststgamestats )
{
cout << " \n number of questions   : " << ststgamestats.questions_number ;
cout << " \n question level        : " << level_to_word   (ststgamestats.enenquestion_level) ;
cout << " \n operative type        : " << operator_to_word(ststgamestats.enenoperator);
cout << " \n correct answers       : " << ststgamestats.correct_number ;
cout << " \n wrong answers         : " << ststgamestats.wrong_number ;
}

void game_brief ()
{
stgamestats  ststgamestats ;
ststgamestats.questions_number   = number (" \n how many questions do you want to answer ? \n") ;
ststgamestats.enenquestion_level = enquestion_level (number (" choose question level    [1]easy  [2]med  [3]hard  [4]mix  \n") ) ;
ststgamestats.enenoperator       = enoperator       (number (" choose operator  [1]add  [2]sub  [3]mult  [4]divi   [5]all  \n") ) ;

for ( int i = 1 ; i <= ststgamestats.questions_number ; i ++ )
each_round (i , ststgamestats);

who_pass(ststgamestats) ;
final_result (ststgamestats) ;
stats ( ststgamestats) ;

}

void game_start()
{
do
{
system ("cls");
system ( "color 0F") ;
game_brief();
} while ( want_to_repeat());
}


int main ()
{
srand ( (unsigned)time(NULL));
game_start ( ) ;

return 0 ;
}

int main ()
