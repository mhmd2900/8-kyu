                                                                              //////////////     input random
                                                                              int random ( int from , int to )
                                                                              {
                                                                                return rand()%( to - from + 1)+from ;
                                                                              }





                                                                              //////////////    input number
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

