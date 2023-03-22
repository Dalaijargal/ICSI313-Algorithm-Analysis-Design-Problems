#include <bits/stdc++.h>
using namespace std;

int n , m ;
int dp [ 10005 ] [ 1005 ] , c [ 1005 ] , p [ 1005 ] ;

int main ( ) {

    cin >> n >> m ;
    for ( int i = 1 ; i <= m ; i ++ ) {
        cin >> c [ i ] >> p [ i ] ;
    }
    memset ( dp , 0 , sizeof ( dp ) ) ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 1 ; j <= m ; j ++ ) {
            if ( i >= c [ j ] ) {
                dp [ i ] [ j ] = max ( dp [ i ] [ j - 1 ] , dp [ i - c [ j ] ] [ j ] + p [ j ] ) ; 
            }
            else {
                dp [ i ] [ j ] = dp [ i ] [ j - 1 ] ;
            }
        }
    }
    cout << dp [ n ] [ m ] ;
}
