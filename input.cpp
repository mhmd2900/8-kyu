// #include <iostream>
// #include <string>
// #include <cstdlib> // random
// #include <ctime>  // random
// #include <limits>   // inpit number
// using namespace std ;

// using std::cin;
// using std::cout;
// using std::numeric_limits;
// using std::streamsize;



void reset_screen ()
{
system ("cls");
system ( "color 0F") ;
}

                                                                              //////////////     input random
                                                                              int random ( int from , int to )
                                                                              {
                                                                                return rand()%( to - from + 1)+from ;
                                                                              }





                                                                              //////////////    input number
                                                                                int number ( string message , short from , short to )
                                                                                {
                                                                                cout << message ;
                                                                                int num ;
                                                                                while ( true )
                                                                                {
                                                                                if ( cin >> num && num >= from && num <= to)
                                                                                return num ;
                                                                                  
                                                                                cout << " wrong input , repeat ";
                                                                                cin.clear();
                                                                                cin.ignore( numeric_limits<streamsize>::max() , '\n');
                                                                                }
                                                                                }


                                                                                ///////////////////////////    input string
                                                                                string word ( string message )
                                                                                {
                                                                                cout << message ;
                                                                                string pass ; 
                                                                                while ( true )
                                                                                {     
                                                                                
                                                                                if (getline(cin, pass) && !pass.empty())  // getline succeded + not empty
                                                                                return pass;
                                                                                
                                                                                //← getline succeded + empty    OR    FAILED (eof, failbit) + empty 
                                                                                cin.clear();
                                                                                cout << " input can not be empty !  ,  and EOF is not allowed \n";
                                                                                }
                                                                                }
                                                                              
                                                                              
                                                                              ///////////////////    input string ( charchters )
                                                                              string read ( string message )
                                                                              {  
                                                                                  cout << message ;
                                                                                  string password ;
                                                                                  char ch ;
                                                                                  while (true)
                                                                                  {
                                                                                      while ( cin.get(ch) )
                                                                                      {
                                                                                      if ( ch == '\r')
                                                                                      continue ;
                                                                                      if ( ch == '\n')
                                                                                      break ;
                                                                                      password += ch ;
                                                                                      }
                                                                              
                                                                                      if (! password.empty())
                                                                                      return password ;
                                                                              
                                                                                      else 
                                                                                      {
                                                                                      cout << " empty password , not acceted , repeat \n" ;
                                                                                      cin.clear();
                                                                                      }
                                                                                  }
                                                                              }

///////////////  want to repeat
bool want_to_repeat ()
{
cout << " repeat ?   [y/n] \n";
char ch ;
while ( true )
{
if ( cin>>ch && ( ch =='y' || ch == 'Y'))
return true ;
else if ( ch =='n' || ch == 'N')
return false ;
cout << " plz only enter y or n , thank you   \n" ;
cin.clear();
// cout << " input can not be empty !  ,  and EOF is not allowed \n"; // should only if user invalid input
// commented as during 2nd recall of this function
// there is no way to diff. between user invalid input or remaining \n ( both not meet the condition )
}
}
