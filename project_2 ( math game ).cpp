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

struct stgamestats 
{
enpassfail enpasser ;
int questions_number = 0 ;
enquestion enenquestion ;
enoperator enenoperator ;
int correct_number = 0 ;
int wrong_number = 0  ;
};

struct sttwo_numbers 
{
int num1 = 0 ;
int num2  = 0 ;
int comp_ans = 0 ;
int user_ans = 0 ;
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

void choose_nums ( sttwo_numbers& ststtwo_numbers , stgamestats ststgamestats)   
{
if (ststgamestats.enenquestion == enquestion::easy )
{
ststtwo_numbers.num1 = random ( 1 , 9);
ststtwo_numbers.num2 = random ( 1 , 9);
}
else if (ststgamestats.enenquestion == enquestion::med)
{
ststtwo_numbers.num1 = random ( 11 , 99);
ststtwo_numbers.num2 = random ( 11 , 99);
}
else if (ststgamestats.enenquestion == enquestion::hard )
{
ststtwo_numbers.num1 = random ( 111 , 222);
ststtwo_numbers.num2 = random ( 111 , 222 );
}
else if (ststgamestats.enenquestion == enquestion::mix )
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
ststtwo_numbers.op = char ( random_op()) ;
}

void user_answer (sttwo_numbers&  ststtwo_numbers)
{

cout << ststtwo_numbers.num1 << endl ;
cout << ststtwo_numbers.op  << endl ; 
cout << ststtwo_numbers.num2 << endl  ;
cout << "_______ \n " ;
ststtwo_numbers.user_ans = number ( "") ;

}

void comp_answer ( sttwo_numbers& ststtwo_numbers)
{
if         (ststtwo_numbers.op == '+' )
ststtwo_numbers.comp_ans = ststtwo_numbers.num1 + ststtwo_numbers.num2 ;
else if    (ststtwo_numbers.op == '-' )
ststtwo_numbers.comp_ans = ststtwo_numbers.num1 - ststtwo_numbers.num2 ;
else if    (ststtwo_numbers.op == '*' )
ststtwo_numbers.comp_ans = ststtwo_numbers.num1 * ststtwo_numbers.num2 ;
else if    (ststtwo_numbers.op == '/' )
ststtwo_numbers.comp_ans = ststtwo_numbers.num1 / ststtwo_numbers.num2 ;
}

void correct_wrong ( sttwo_numbers ststtwo_numbers , stgamestats& ststgamestats )
{
if ( ststtwo_numbers.user_ans == ststtwo_numbers.comp_ans )
{
cout << " \n correct answer \n" ;
system ( " color 2F");
ststgamestats.correct_number ++ ;
}
else 
{
cout << " \n wrong answer \n the correct answer is " << ststtwo_numbers.comp_ans << endl ; 
system ( " color 4F");
ststgamestats.wrong_number ++ ;
}
}

void round ( int count , stgamestats& ststgamestats)
{
sttwo_numbers ststtwo_numbers ;

cout << "  \n ============================== \n       Question [" << count << "/"<< ststgamestats.questions_number << "]" << endl ;

choose_nums     ( ststtwo_numbers , ststgamestats) ;
choose_operator ( ststtwo_numbers , ststgamestats) ;
user_answer     ( ststtwo_numbers) ;
comp_answer     ( ststtwo_numbers) ;
correct_wrong   ( ststtwo_numbers , ststgamestats) ;
}

void pass_or_fail ( stgamestats& ststgamestats )
{
if      ( ststgamestats.correct_number > ststgamestats.wrong_number)
ststgamestats.enpasser = enpassfail::pass ;
else if ( ststgamestats.correct_number < ststgamestats.wrong_number)
ststgamestats.enpasser = enpassfail::fail ;
else
ststgamestats.enpasser = enpassfail::draw ;
}

void print__pass_or_fail ( stgamestats ststgamestats )
{
cout << "_________________________________________________________________\n";
cout << " final result is ";
if      ( ststgamestats.enpasser == enpassfail::pass)
{
cout << " PASS  :-)   \n_________________________________________________________________\n ";
system (" color 2F") ;
}

else if ( ststgamestats.enpasser == enpassfail::fail)
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

void stats ( stgamestats ststgamestats )
{
cout << " \n number of questions   : " << ststgamestats.questions_number ;
cout << " \n question level        : " << level_to_word   (ststgamestats.enenquestion) ;
cout << " \n operative type        : " << operator_to_word(ststgamestats.enenoperator);
cout << " \n correct answers       : " << ststgamestats.correct_number ;
cout << " \n wrong answers         : " << ststgamestats.wrong_number ;
}

void game ()
{
stgamestats  ststgamestats ;
ststgamestats.questions_number   = number (" \n how many questions do you want to answer ? \n") ;
ststgamestats.enenquestion = enquestion (number (" choose question level    [1]easy  [2]med  [3]hard  [4]mix  \n") ) ;
ststgamestats.enenoperator       = enoperator       (number (" choose operator  [1]add  [2]sub  [3]mult  [4]divi   [5]all  \n") ) ;

for ( int i = 1 ; i <= ststgamestats.questions_number ; i ++ )
round (i , ststgamestats);

pass_or_fail(ststgamestats) ;
print__pass_or_fail (ststgamestats) ;
stats ( ststgamestats) ;

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
