#include <bits/stdc++.h>
using namespace std;

int n , x1 , x2 ;
int a [ 100005 ] ;
int dp [ 100005 ] ;

int main ( ) {

    cin >> n ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> a [ i ] ;
    }
    dp [ 1 ] = 0 ;
    dp [ 2 ] = 0 ;
    dp [ 3 ] = 0 ;
    if ( a [ 1 ] + a [ 2 ] < a [ 3 ] + a [ 4 ] )
        dp [ 4 ] = 1 ;
    else
        dp [ 4 ] = 0 ;
    if ( a [ 1 ] + a [ 2 ] < a [ 3 ] + a [ 4 ] + a [ 5 ] && a [ 3 ] + a [ 4 ] + a [ 5 ] <= 21 )
        dp [ 5 ] = 1 ;
    else
        dp [ 5 ] = 0 ;
    dp [ 6 ] = max ( dp [ 4 ] , dp [ 5 ] ) ;
    dp [ 7 ] = dp [ 6 ] ;
    if ( a [ 5 ] + a [ 6 ] < a [ 7 ] + a [ 8 ] )
        dp [ 8 ] = max ( dp [ 4 ] + 1 , dp [ 5 ] ) ;
    else
        dp [ 8 ] = dp [ 7 ] ;
    for ( int i = 9  ; i <= n ; i ++ ) {
        if ( a [ i - 3 ] + a [ i - 2 ] < a [ i - 1 ] + a [ i ] )
            x1 = dp [ i - 4 ] + 1 ;
        else
            x1 = dp [ i - 4 ] ;
        if ( a [ i - 4 ] + a [ i - 3 ] < a [ i - 2 ] + a [ i - 1 ] + a [ i ] && a [ i - 2 ] + a [ i - 1 ] + a [ i ] <= 21 )
            x2 = dp [ i - 5 ] + 1 ;
        else
            x2 = dp [ i - 5 ] ;
        dp [ i ] = max ( x1 , x2 ) ;
    }
    for ( int i = 0 ; i <= 3 ; i ++ ) {
        cout << dp [ n - i ] << endl ;
    }
    cout << max ( max ( dp [ n ] , dp [ n - 1 ] ) , max ( dp [ n - 2 ] , dp [ n - 3 ] ) ) ;
}
