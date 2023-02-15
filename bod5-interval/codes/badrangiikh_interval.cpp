#include<bits/stdc++.h>
using namespace std;

int w [ 1000005 ] , en [ 1000005 ] ;
pair < pair < int , int > , int > in [ 1000005 ] ;
int n ;

int part ( pair < pair < int , int > , int > arr [ ] , int low , int high ) {
    pair < pair < int , int > , int > pivot = arr [ high ] , temp ;
    int i = low - 1;
    for ( int j = low; j < high ; j ++ ) {
        if ( arr [ j ] . first . second <= pivot . first . second ) {
            i ++ ;
            temp = arr [ i ] ;
            arr [ i ] = arr [ j ] ;
            arr [ j ] = temp ;
        }
    }
    temp = arr [ i + 1 ] ;
    arr [ i + 1 ] = arr [ high ] ;
    arr [ high ] = temp ;
    return i + 1 ;
}

void quicksort ( pair < pair < int , int > , int > arr [ ] , int low , int high ) {
    if ( low < high ) {
        int pi = part ( arr, low , high ) ;
        quicksort ( arr , low , pi - 1 ) ;
        quicksort ( arr , pi + 1 , high ) ;
    }
}

int find_r ( int n , int x ) {
    int low = 0, high = n ;
    if ( x > en [ n ] ) return n ;
    while ( low <= high ) {
        int mid = low + ( high - low ) / 2 ;
        if ( en [ mid ] < x && en [ mid + 1 ] >= x ) {
            return mid ;
        }
        if ( en [ mid ] > x ) {
            high = mid - 1 ;
        }
        else {
            low = mid + 1;
        }
    }
}

int main ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        cin >> in [ i ] . first . first >> in [ i ] . first . second >> in [ i ] . second ;
    }
    quicksort ( in , 1 , n ) ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        int r = find_r ( i , in [ i ] . first . second ) ;
        w [ i ] = max ( w [ i - 1 ] , w [ r ] + in [ i ] . second ) ;
        if ( w [ r ] + in [ i ] . second > w [ i - 1 ] ) en [ i ] = in [ i ] . first . second ;
        else en [ i ] = en [ i - 1 ] ;
    }
    cout << w [ n ] ;
}
