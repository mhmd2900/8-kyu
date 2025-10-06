
                                                                                    ////////////////////                    make array 
                                                                                    void make_array ( int arr[] , int size)
                                                                                    {
                                                                                    for ( int i = 0 ; i < size ; i ++ )
                                                                                    arr[i] = random ( 0 , 100 ) ;
                                                                                    }
                                                                                    



                                                                                    /////////////////////                  swap array elements
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



///////////////////////             print array
void print ( int arr[] , int size )
{
for ( int i= 0 ; i < size ; i ++ )
 cout << arr[i] << " \t" ;
 cout << endl ;
}
