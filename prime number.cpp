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

/// another way

    int arr[100] = {0} ;

for ( int i = 2 ; i < 100 ; ++ i) 
{
    for ( int j = i*i ; j < 100     ;  j+= i )
     arr [j -1 ] = 1 ;

}

for ( int a = 0 ; a < 100 ; a ++ )
{
 if ( arr[a-1] == 0 )
 cout << a  << "\t" ;
}

return 0 ;
}
