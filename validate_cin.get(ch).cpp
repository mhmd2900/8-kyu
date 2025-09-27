#include <iostream>
#include <string>
#include <cmath>
using namespace std;


string read ( string message )
{
char ch ;
string password ;
cout << message ;

                                                          while ( true )
                                                          {
                                                            while (cin.get(ch))
                                                                  {
                                                                      if (ch == '\r')
                                                                          continue;
                                                                      if (ch == '\n')
                                                                          break; 

                                                                      password += ch; 
                                                                  }



                                                                  if (!password.empty())
                                                                  {
                                                                      return password;
                                                                  }


                                                                  
                                                                  else
                                                                  {
                                                                      cout << "Password cannot be empty. Try again.\n";
                                                                      cin.clear();
                                                                      // cin.ignore(100,'\n');
                                                                  }
                                                          }
                                                          }



int main ()
{
cout << read ( " enter password ");

 return 0 ;
}
