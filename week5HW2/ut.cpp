#include <cstdlib>
#include <gtest/gtest.h>
    int mul( int a , int b ) {
    return a * b ;
}
TEST( multest , HandleNoneZeroInput ) {
    ASSERT_EQ( 21 , mul( 3 , 7 ) ) ;
    ASSERT_EQ( -24 , mul( -6 , 4 ) ) ;
} 
int main( int argc ,char **argv ){
    testing :: InitGoogleTest( &argc , argv ) ;
    return RUN_ALL_TESTS( ) ;
}