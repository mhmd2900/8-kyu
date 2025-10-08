#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std ;


enum game { paper = 1 , stone = 2 , scissor = 3 , invalid = 4};


                                                                                int user_choice ( string message )
                                                                                {
                                                                                int num ;
                                                                                cout << message ;
                                                                                while (true)
                                                                                {
                                                                                if (cin >> num && num >=1 && num <=3  )
                                                                                return num;
                                                                                else
                                                                                {
                                                                                cout << " wrong input , retry \n" ;
                                                                                cin.clear();
                                                                                cin.ignore(100 , '\n');
                                                                                }
                                                                                }
                                                                                }


                                                                                int read_repeat_game ( string message )
                                                                                {
                                                                                int num ;
                                                                                cout << message ;
                                                                                while (true)
                                                                                {
                                                                                if (cin >> num && num >=1 && num <=10  )
                                                                                return num;
                                                                                else
                                                                                {
                                                                                cout << " wrong input , retry \n" ;
                                                                                cin.clear();
                                                                                cin.ignore(100 , '\n');
                                                                                }
                                                                                }
                                                                                }



                                                                            int comp_random_choice ( int from , int to )
                                                                            {
                                                                            return rand()%( to - from + 1)+ from ;
                                                                            }



                                                                            game options ( int input )
                                                                            {
                                                                            switch (input)
                                                                            {
                                                                            case 1 :
                                                                            return game::paper ;
                                                                            case 2 :
                                                                            return game::stone ;
                                                                            case 3 :
                                                                            return game::scissor ;
                                                                            default :
                                                                            return game::invalid ;
                                                                            }
                                                                            }

string convert_num_to_option ( int num)
{
if ( num == 1 )
return "paper" ;

else if ( num == 2 )
return "stone" ;

else if ( num == 3)
return "scissor" ;

else
return "invali" ;
}





void compare_options_print_round ( int& win1 , int& win2 , int& draw , int& i )
{
    
    cout << " \n " ;
game gm = options (user_choice ( " make your choice  \t  \t  [1] paper    [2] stone     [3] scissors \n " )) ;
game gmm = options (comp_random_choice ( 1 , 3 )) ;


 cout << " ----------- ROUND [" << i << "]------------ \n "  ; 


cout <<  " you choose       :  " << convert_num_to_option (gm) << endl;
cout <<  " computer  choose  :  " << convert_num_to_option ( gmm) << endl  ;


if ( gm == game::paper && gmm == game::stone )
{
++win1  ;
cout << " winner            :  you  \n " ;
system ("color 2F");
cout << "\a";
}
else if ( gm == game::paper && gmm == game::scissor )
{
++win2  ;
cout << " winner            :  computer  \n " ;
system ("color 4F");
} 
else if ( gm == game::stone && gmm == game::paper )
{
++win2  ;
cout << " winner            :  computer  \n " ;
system ("color 4F");
}  
else if ( gm == game::stone && gmm == game::scissor )
{
++win1  ;
cout << " winner             :  you  \n " ;
system ("color 2F");
cout << "\a";
}
else if ( gm == game::scissor && gmm == game::paper )
{
++win1  ;
cout << " winner             :  you  \n " ;
system ("color 2F");
cout << "\a";
}
else if ( gm == game::scissor && gmm == game::stone )
{
++win2  ;
cout << " winner            :  computer  \n " ;
system ("color 4F");
}

else if ( gm == gmm )
{
++draw  ;
cout << " winner            :  no winner \n " ;
system ("color E0");
}
cout << " -------------------------------- \n "  ; 

}







void end_game_stats ( int win1 , int win2 , int draw , int count )
{
for ( int i = 1 ; i <= count ; i ++ )
{
compare_options_print_round( win1 , win2 , draw , i ) ;
}
cout << "                                 ____________________________________________________________ \n " ;
cout << "                                                   +++ GAME OVER +++                          \n " ;
cout << "                                 _____________________________________________________________ \n " ;
cout << "                                 __________________ [ GAME RESULTS ]__________________________ \n " ;
cout << "                                 _____________________________________________________________ \n " ;
cout << "                                 game rounds   : " << count << endl ;
cout << "                                  you win       : " << win1 << endl ;
cout << "                                  comp win      : " << win2 << endl ;
cout << "                                  draw          : " << draw << endl ;
cout << "                                  final result  : " ;
if ( win1 > win2 )
{
cout << " you win \n " ;
system ("color 2F");
cout << "\a";
}
else if ( win1 < win2 )
{
cout << " computer win \n " ;
system ("color 4F");
}
else
{
cout << " no winner \n " ;
system ("color E0");
}
cout << "                                 ____________________________________________________________ \n " ;
}




bool repeat ()
{
char ch ;
 cout << " do you want to repeat the game [ y / n ] ? \n";
 cin >> ch ;

 while ( true )
 {
 if ( ch == 'y' || ch == 'Y' )
return true ;

else if ( ch == 'n' || ch == 'N' )
return false ;

else
{
     cout << " only choose  [ y / n ] ? \n";
 cin >> ch ;
}
 }
}









void repeat_choice ( int win1 , int win2 , int draw )
{
    int count ;
    do 
    {
     count = read_repeat_game ( " how many times would you play from 1 to 10  ? \n") ;
     end_game_stats ( win1 , win2 , draw , count ) ;
    } while ( repeat ());
}






int main ()
{
srand((unsigned)time(NULL)) ;

int win1 = 0 , win2 = 0 , draw = 0 ;
repeat_choice ( win1 , win2 , draw ) ;

return 0 ;
}
