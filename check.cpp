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


////////////// check distinct number ( copy repeated number only in 1st appearance )
bool check ( int number , int arr [] , int index)
{
  int c = 0 ;
for ( int i = index -1 ; i >= 0 ; i --)
{
if ( number == arr[i])
c ++ ;
}
if ( c > 1)
return false ;
else
return true ;
}
