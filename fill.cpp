
                                                                                   //////////////////////////   make array one by one    ( random or user )
                                                                                    void add_array_element ( int arr[] , int &index )
                                                                                    {
                                                                                      arr[index] = read(" plz enter number \n");  
                                                                                      index ++ ;
                                                                                    } // index = 0 in  int main 



                                                                                    ///////////////////////       make array total         ( random or user )
                                                                                    void make_array ( int arr[] , int size)
                                                                                    {
                                                                                    for ( int i = 0 ; i < size ; i ++ )
                                                                                     arr[i] = read(" plz enter number \n");
                                                                                    }
                                                                                    



                                                                                    /////////////////////      make array from itself ( by swapping - irreversible )
                                                                                    void swap ( int& a , int& b )
                                                                                    {
                                                                                    int temp ;
                                                                                    temp = a ;
                                                                                    a = b ;
                                                                                    b = temp ;
                                                                                    }
                                                                                    
                                                                                    
                                                                                    
                                                                                    void swaps ( int arr[] , int size )
                                                                                    {
                                                                                    for ( int i = 0 ; i < size ; i ++)
                                                                                    swap (         arr[random(1 , size ) -1 ]      ,       arr[random(1  , size  )-1 ]         ) ;
                                                                                    }





                                                                                ////////////////////////    make string from itself  ( with known key - reversible )
                                                                                string crypt ( string password , int key )
                                                                                {
                                                                                for ( int i = 0 ; i < password.length() ; i ++ )
                                                                                password[i] = static_cast<char> (static_cast<unsigned char>(password[i]) + key) ;
                                                                                return password ;
                                                                                }
                                                                                // Yes, the conversion from int (or unsigned char) to char happens implicitly — 
                                                                                // but you should still write the explicit static_cast<char> for 3 critical reasons:
                                                                                // 🧭 Clarity & Intent — telling “I know this is a narrowing conversion, and I want it.”
                                                                                // ⚠️ Without cast, some compilers will warn you about implicit narrowing.
                                                                                // 🔍 Makes code more robust against future changes or stricter compiler settings.
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                /////////////////////////    make string from other string  ( with known key )
                                                                                string decrypt ( string password , int key )
                                                                                {
                                                                                string pass ;
                                                                                for ( int i = 0 ; i < password.length() ; i ++ )
                                                                                // for ( char& i : password )
                                                                                pass += static_cast<char>(static_cast<unsigned char>(password[i]) - key) ;
                                                                                return pass ;
                                                                                }





///////////////////////             print array
void print ( int arr[] , int size )
{
for ( int i= 0 ; i < size ; i ++ )
 cout << arr[i] << " \t" ;
 cout << endl ;
}
