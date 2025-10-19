#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std ;

enum enquestion { easy = 1 , med = 2 , hard = 3 , mix = 4 };
enum enoperator { add = 1 , sub = 2 , mult = 3 , divi = 4 , all = 5 };
enum enpassfail { pass = 1 , fail = 2 , draw = 3 } ;

string level_to_word (enquestion enenquestion )
{
string word[4] = { "easy" , "med" , "hard" , "mix"};
return word [ enenquestion - 1 ];
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
default :
return "all" ;
}
}

struct st_round 
{
short num1 = 0 ;
short num2  = 0 ;
short comp_ans = 0 ;
short user_ans = 0 ;
string op ;
};

struct st_game 
{
enpassfail enpasser ;
short questions_number = 0 ;
enquestion enenquestion ;
enoperator enenoperator ;
short correct_number = 0 ;
short wrong_number = 0  ;
st_round stst_round[10] ;
};

                                                                                short number ( string message , short from , short to )
                                                                                {
                                                                                short num ;
                                                                                cout << message ;
                                                                                while ( true )
                                                                                {
                                                                                if ( cin >> num && num >= from && num <= to)
                                                                                return num ;
                                                                                else 
                                                                                {
                                                                                cout << " wrong input , repeat ";
                                                                                cin.clear();
                                                                                cin.ignore(100 , '\n');
                                                                                }
                                                                                }
                                                                                }

                                                                                short random ( short from , short to )
                                                                                {
                                                                                return rand()%( to - from + 1 ) + from ;
                                                                                }

void show_nums    ( st_round& stst_round , st_game stst_game)  // const st_game& stst_game 
{
if (stst_game.enenquestion == enquestion::easy )
{
stst_round.num1 = random ( 1 , 9);
stst_round.num2 = random ( 1 , 9);
}
else if (stst_game.enenquestion == enquestion::med)
{
stst_round.num1 = random ( 11 , 99);
stst_round.num2 = random ( 11 , 99);
}
else if (stst_game.enenquestion == enquestion::hard )
{
stst_round.num1 = random ( 111 , 170 ); // 170 power2 is just below the short variable maximum number ( 32,768 )
stst_round.num2 = random ( 111 , 170 );
}
else if (stst_game.enenquestion == enquestion::mix )
{
stst_round.num1 = random ( 1 , 170 );
stst_round.num2 = random ( 1 , 170 );
}
}                                                                             

void show_operator( st_round& stst_round , st_game stst_game)  // const st_game& stst_game 
{
if (stst_game.enenoperator == enoperator::all)
stst_round.op = operator_to_word (enoperator(random(1,4))) ;

else 
stst_round.op = operator_to_word(stst_game.enenoperator) ;
}

void user_answer    (st_round&  stst_round)
{

cout << stst_round.num1 << endl ;
cout << stst_round.op  << endl ; 
cout << stst_round.num2 << endl  ;
cout << "_______ \n " ;
stst_round.user_ans = number ("" , -4000 , 4000 ) ;

}

void comp_answer    ( st_round& stst_round)
{
if         (stst_round.op == "+" )
stst_round.comp_ans = stst_round.num1 + stst_round.num2 ;
else if    (stst_round.op == "-" )
stst_round.comp_ans = stst_round.num1 - stst_round.num2 ;
else if    (stst_round.op == "*" )
stst_round.comp_ans = stst_round.num1 * stst_round.num2 ;
else if    (stst_round.op == "/" && stst_round.num2 !=0 )
stst_round.comp_ans = stst_round.num1 / stst_round.num2 ;
else 
stst_round.comp_ans = 0 ;
}

void correct_wrong  ( st_round stst_round , st_game& stst_game ) // const st_round& stst_round 
{
if ( stst_round.user_ans == stst_round.comp_ans )
{
cout << " \n correct answer \n" ;
system ( " color 2F");
stst_game.correct_number ++ ;
}
else 
{
cout << " \n wrong answer \n the correct answer is " << stst_round.comp_ans << endl ; 
system ( " color 4F");
stst_game.wrong_number ++ ;
}
}

// Rule of thumb:
// ➤ If it’s a single int, char, bool, etc. — pass by value (copy is cheap).
// ➤ If it’s >1 primitive or a struct
            // ➤ If you’re modifying it     — pass by &.
            // ➤ If you’re not modifying it — pass by const&.

void round          ( short count , st_game& stst_game) 
{

cout << "  \n ============================== \n       Question [" << count << "/"<< stst_game.questions_number << "]" << endl ;

show_nums       ( stst_game.stst_round[count-1] , stst_game) ;
show_operator   ( stst_game.stst_round[count-1] , stst_game) ;
user_answer     ( stst_game.stst_round[count-1]) ;
comp_answer     ( stst_game.stst_round[count-1]) ;
correct_wrong   ( stst_game.stst_round[count-1] , stst_game) ;
}

void pass_or_fail           ( st_game& stst_game )
{
if      ( stst_game.correct_number > stst_game.wrong_number)
stst_game.enpasser = enpassfail::pass ;
else if ( stst_game.correct_number < stst_game.wrong_number)
stst_game.enpasser = enpassfail::fail ;
else
stst_game.enpasser = enpassfail::draw ;
}

void print__pass_or_fail    ( st_game stst_game )
{
cout << "_________________________________________________________________\n";
cout << " final result is ";
if      ( stst_game.enpasser == enpassfail::pass)
{
cout << " PASS  :-)   \n_________________________________________________________________\n ";
system (" color 2F") ;
}

else if ( stst_game.enpasser == enpassfail::fail)
{
cout << " FAIL  :-(   \n_________________________________________________________________\n " ;
system ( " color 4F");
}

else 
{
cout << " DRAW \n_________________________________________________________________\n " ;
system ("color 6F");
}
"_________________________________________________________________\n" ;
}

void stats                  ( st_game stst_game )
{
cout << " \n number of questions   : " << stst_game.questions_number ;
cout << " \n question level        : " << level_to_word   (stst_game.enenquestion) ;
cout << " \n operative type        : " << operator_to_word(stst_game.enenoperator);
cout << " \n correct answers       : " << stst_game.correct_number ;
cout << " \n wrong answers         : " << stst_game.wrong_number ;


cout << " \n \n --------- REVIEW TOUR ANSWERS --------- \n";
for ( short i = 1 ; i <= stst_game.questions_number ; i ++ )
cout << " question " << i << " :  you answered " << stst_game.stst_round[i-1].user_ans << " ,  correct answer is " << stst_game.stst_round[i-1].comp_ans << endl ;
}

void game                   ()                                          
{
st_game  stst_game ;
stst_game.questions_number   =                   number (" \n how many questions do you want to answer ? \n" , 1 , 10) ;
stst_game.enenquestion       = enquestion       (number (" choose question level    [1]easy  [2]med  [3]hard   [4]mix  \n" , 1 , 4 )) ;
stst_game.enenoperator       = enoperator       (number (" choose operator  [1]add  [2]sub  [3]mult  [4]divi   [5]all  \n" , 1 , 5 )) ;

for ( short i = 1 ; i <= stst_game.questions_number ; i ++ )
round (i , stst_game);

pass_or_fail(stst_game) ;
print__pass_or_fail (stst_game) ;
stats ( stst_game) ;
}

bool want_to_repeat                          ()
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

void restart                                 ()
{
do
{
system ("cls");
system ( "color 0F") ;
game();
} while ( want_to_repeat());
}


int main ()
{
srand((unsigned)time(NULL));
restart() ;

return 0 ;
}
