#include<iostream>
#include<string>                                       //better to include string           // better not use namespace
#include<cctype>


bool is_uppercase ( const std::string &s )  //bool return //good funct name //const as not editable //& avoid string many copies 
{
for (size_t i = 0 ; i< s.size() ; i++ )  //size_t compare to unsigned s.size  //s.size standard than size(s) //i !=0 not safe
      if ( islower(s[i]))  // != 1 is wrong
      return false ;   // no needed { } to close for
return true ;
}

bool is_upper ( const std::string &s ) 
{
for ( auto i : s)     // range-based for loop , direct iteration with ch not indices 
      if ( islower(i)) 
      return false ;  
return true ;
}




int main ()
{
std::cout << is_uppercase ("ACSKLDFJSGSKLD JSKLDFJ") << std::endl;
std::cout << is_upper ("ACSKLDFJSGSKLD JSKLDFJ") << std::endl;
return 0 ;
}
