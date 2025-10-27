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

#include<chrono>
auto start = std::chrono::steady_clock::now();  // Start timer
auto end = std::chrono::steady_clock::now();    // Stop timer

// Calculate and print time in microseconds
auto us = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
std::cout << " \n \n Time: " << us << " µs\n";


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
                                                                                int num ;
                                                                                cout << message ;
                                                                                while ( true )
                                                                                {
                                                                                if ( cin >> num && num >= from && num <= to)
                                                                                return num ;
                                                                                else 
                                                                                {
                                                                                cout << " wrong input , repeat ";
                                                                                cin.clear();
                                                                                cin.ignore( numeric_limits<streamsize>::max() , '\n');
                                                                                  // must include<limits>
                                                                                  // must use namespace std
                                                                                }
                                                                                }
                                                                                }
                                                                              
                                                                              
                                                                              
                                                                              
                                                                              ///////////////////    input string ( charchters )
                                                                              
                                                                              string read ( string message )
                                                                              {
                                                                                  string password ;
                                                                                  char ch ;
                                                                                  cout << message ;
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



                                                                                }

