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
// case enoperator::mix :
// return ;
default :
return "all" ;
}
}

struct st_round 
{
int num1 = 0 ;
int num2  = 0 ;
int comp_ans = 0 ;
int user_ans = 0 ;
char op = 'a' ;
};

struct st_game 
{
enpassfail enpasser ;
int questions_number = 0 ;
enquestion enenquestion ;
enoperator enenoperator ;
int correct_number = 0 ;
int wrong_number = 0  ;
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

                                                                                int random_op ()
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

void choose_nums ( st_round& stst_round , st_game stst_game)   
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
stst_round.num1 = random ( 111 , 222);
stst_round.num2 = random ( 111 , 222 );
}
else if (stst_game.enenquestion == enquestion::mix )
{
stst_round.num1 = random ( 1 , 222);
stst_round.num2 = random ( 1 , 222);
}
}                                                                             

void choose_operator ( st_round& stst_round , st_game stst_game)
{
if      (stst_game.enenoperator == enoperator::add)
stst_round.op = '+';
else if (stst_game.enenoperator == enoperator::sub)
stst_round.op = '-';
else if (stst_game.enenoperator == enoperator::mult)
stst_round.op = '*';
else if (stst_game.enenoperator == enoperator::divi)
stst_round.op = '/';
else if (stst_game.enenoperator == enoperator::all)
stst_round.op = char ( random_op()) ;
}

void user_answer (st_round&  stst_round)
{

cout << stst_round.num1 << endl ;
cout << stst_round.op  << endl ; 
cout << stst_round.num2 << endl  ;
cout << "_______ \n " ;
stst_round.user_ans = number ( "") ;

}

void comp_answer ( st_round& stst_round)
{
if         (stst_round.op == '+' )
stst_round.comp_ans = stst_round.num1 + stst_round.num2 ;
else if    (stst_round.op == '-' )
stst_round.comp_ans = stst_round.num1 - stst_round.num2 ;
else if    (stst_round.op == '*' )
stst_round.comp_ans = stst_round.num1 * stst_round.num2 ;
else if    (stst_round.op == '/' )
stst_round.comp_ans = stst_round.num1 / stst_round.num2 ;
}

void correct_wrong ( st_round stst_round , st_game& stst_game )
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

void round ( int count , st_game& stst_game)
{
st_round stst_round ;

cout << "  \n ============================== \n       Question [" << count << "/"<< stst_game.questions_number << "]" << endl ;

choose_nums     ( stst_round , stst_game) ;
choose_operator ( stst_round , stst_game) ;
user_answer     ( stst_round) ;
comp_answer     ( stst_round) ;
correct_wrong   ( stst_round , stst_game) ;
}

void pass_or_fail ( st_game& stst_game )
{
if      ( stst_game.correct_number > stst_game.wrong_number)
stst_game.enpasser = enpassfail::pass ;
else if ( stst_game.correct_number < stst_game.wrong_number)
stst_game.enpasser = enpassfail::fail ;
else
stst_game.enpasser = enpassfail::draw ;
}

void print__pass_or_fail ( st_game stst_game )
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
" DRAW \n_________________________________________________________________\n " ;
system ("color 6 F");
}
"_________________________________________________________________\n" ;
}

void stats ( st_game stst_game )
{
cout << " \n number of questions   : " << stst_game.questions_number ;
cout << " \n question level        : " << level_to_word   (stst_game.enenquestion) ;
cout << " \n operative type        : " << operator_to_word(stst_game.enenoperator);
cout << " \n correct answers       : " << stst_game.correct_number ;
cout << " \n wrong answers         : " << stst_game.wrong_number ;
}

void game ()                                          
{
st_game  stst_game ;
stst_game.questions_number   =                   number (" \n how many questions do you want to answer ? \n") ;
stst_game.enenquestion       = enquestion       (number (" choose question level    [1]easy  [2]med  [3]hard   [4]mix  \n") ) ;
stst_game.enenoperator       = enoperator       (number (" choose operator  [1]add  [2]sub  [3]mult  [4]divi   [5]all  \n") ) ;

for ( int i = 1 ; i <= stst_game.questions_number ; i ++ )
round (i , stst_game);

pass_or_fail(stst_game) ;
print__pass_or_fail (stst_game) ;
stats ( stst_game) ;
}

void restart()
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
srand ( (unsigned)time(NULL));
restart ( ) ;

return 0 ;
}
