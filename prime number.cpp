#include<iostream>
#include<vector>
using namespace std ;

int main ()
{
vector<int>vnum  ;
int x ;

    for ( int i = 2 ; i < 100 ; ++ i)   // i  value
    {
            for ( x = 1 ; x <= vnum.size() ; x ++ )   // x  index   // x =0  NOT with  %

                if ( i % vnum.at(x-1) == 0 ) // break in middle of loop   // x-1 = vnum.at(0)
                break ;

                if ( x == vnum.size()+1 ) // excute after end of loop 
                vnum.push_back(i) ;
    }                 
        
for ( auto p : vnum)
cout << p << endl ;

/// =================================================================
    // for      have   count   ,  value 
    // array    have   count   ,  index  ,  value
    // we will mark some values to discard
    // we will link the value either to array index (j-1 ) or array count 
    

    int arr[100] = {0} ;  // default value  0

for ( int i = 2 ; i < 100 ; ++ i) 
{
    for ( int j = i*i ; j < 100     ;  j+= i )
     arr [j -1 ] = 1 ;     // discard by making value 1  // link for value  to arr index
}


    
for ( int a = 1 ; a < 100 ; a ++ )
{
 if ( arr[a-1] == 0 )  // check arr value ( index - 1 )
 cout << a  << "\t" ;  // output  index
}

return 0 ;
}
