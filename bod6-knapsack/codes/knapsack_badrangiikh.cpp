#include <bits/stdc++.h>
using namespace std;

int n , w ;
pair < int , int > item [ 1000005 ] ;
int dp [ 1005 ] [ 1005 ] ;

int main ( ) {
    cin >> n >> w ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> item [ i ] . first >> item [ i ] . second ;
    }
    for ( int i = 1 ; i <= n ; i ++ ) {
        for ( int j = 0 ; j <= w ; j ++ ) {
            if ( j == 0 ) {
                dp [ i ] [ j ] = 0 ;
                continue ;
            }
            if ( item [ i ] . second > j ) {
                dp [ i ] [ j ] = dp [ i - 1 ] [ j ] ;
            }
            else {
                dp [ i ] [ j ] = max ( dp [ i - 1 ] [ j ] , dp [ i - 1 ] [ j - item [ i ] . second ] + item [ i ] . first ) ;
            }
        }
    }
    cout << dp [ n ] [ w ] ;
}
