#include<iostream>
#include<string>          //better to include string           // better not use namespace
#include<cctype>
#include<algorithm>      // for 3rd function



bool is_uppercase ( const std::string &s )  //bool return //good funct name //const as not editable //& avoid string many copies 
{
for (size_t i = 0 ; i< s.size() ; i++ )//index-based loop  //size_t compare to unsigned s.size  //s.size standard than size(s) //i !=0 not safe
      if ( islower(s[i]))  //islower is bool    //!= 1 is wrong practice
      return false ;   // no needed { } to close for
return true ;
}



bool is_upper ( const std::string &s ) 
{
for ( auto i : s)     //range-based for loop , direct iteration with charach not indices , better
      if ( islower(i)) 
      return false ;  
return true ;
}




bool is_up ( const std::string &s ) 
{
return std::none_of(s.begin() , s.end() , islower ) ;  //algorithm  //best practice
}




int main ()
{
std::cout << is_uppercase ("ACSKLDFJSGSKLD JSKLDFJ") << std::endl;
std::cout << is_upper ("ACSKLDFJSGSKLD JSKLDFJ") << std::endl;
std::cout << is_up ("ACSKLDFJSGSKLD JSKLDFJ") << std::endl;
return 0 ;
}
