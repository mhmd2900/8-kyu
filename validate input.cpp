#include<iostream>
#include<string>
using namespace std ;


enum class operators { plus = '+' , minus = '-' };

                                                                                    float read_number ( string message )
                                                                                    { float f ;
                                                                                        cout << message ;
                                                                                        while ( true)
                                                                                        {
                                                                                            if ( cin >> f )
                                                                                            {
                                                                                            return f ; 
                                                                                            }

                                                                                            else 
                                                                                            {
                                                                                            cout << " invalid number ,, plz reenter \n " ;
                                                                                            cin.clear();
                                                                                            cin.ignore( 10000 , '\n');
                                                                                            }
                                                                                        }  
                                                                                    }




                                                                                bool read_operator ( operators& op)
                                                                                {
                                                                                    char ch = ' ';
                                                                                    cout << " plz enter operator either + or - \n " ;
                                                                                    cin >> ch ;
                                                                                     
                                                                                    switch ( ch )
                                                                                    {
                                                                                        case '+':
                                                                                        op = operators::plus ;
                                                                                        return true ;
                                                                                            
                                                                                        case '-':
                                                                                        op = operators::minus ;
                                                                                        return true ;

                                                                                        default :
                                                                                        return false ;
                                                                                       }
                                                                                }





                  void process_print ( float f1 , float f2 , operators op )
                  {
                    switch (op)
                        {
                        case operators::plus :
                        cout << f1 + f2 ;
                        break ;

                        case operators::minus :
                        cout << f1 - f2 ;
                        break ;

                        default :
                        cout << " Invalid \n" ;
                        }
                  }

int main ()
{
operators opp ;
 float f1 = read_number ( " plz enter 1st number \n ") ;
 float f2 = read_number ( " plz enter 2nd number \n ") ;

 while ( !read_operator(opp))
 {
 cout << " Invalid , repeat ";
 cin.clear();
 cin.ignore(10000, '\n');
 }



 process_print ( f1 , f2 , opp );

return 0 ;
}
