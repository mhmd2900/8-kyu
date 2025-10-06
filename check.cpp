//////////////// check prime
bool check_prime ( int num )
{
     if ( num < 2 )
      return false ;   //  0 , 1     to avoid skipping into 3rd return
      
      for ( int x = 2 ; x <= num /2 ; x ++ ) // <=  to involve 4 and prevent its skipping to 3rd return
      if ( num % x == 0 )
      return false ;  

    return true ;  // 2 , 3         skip to it 
}
