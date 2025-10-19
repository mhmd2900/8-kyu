                                                                              //////////////     input random
                                                                              int random ( int from , int to )
                                                                              {
                                                                                return rand()%( to - from + 1)+from ;
                                                                              }





                                                                              //////////////    input number
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

