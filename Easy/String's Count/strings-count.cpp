//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int countStr(long long int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout << countStr(n) << endl;
    }
return 0;
}
// } Driver Code Ends


long long int countStr(long long int n){
    //Atmost  1 b, 2 c
    /*
        tuple = {a, b, c}, here a, b, c are respective count of a,b,c
            c1 = {n, 0, 0}, 
            c2 = {n-1, 1, 0}, 
            c3 = {n-1, 0, 1}, 
            c4 = {n-2, 1, 1}, 
            c5 = {n-2, 0, 2}, 
            c6 = {n-3, 1, 2}
    */
    
    long long c1, c2, c3, c4, c5, c6;
    c1 = 1;
    c2 = n;
    c3 = n;
    c4 = n*(n-1)/2 * 2;
    c5 = n*(n-1)/2 ;
    c6 = n*(n-1)*(n-2)/6 * 3;
    return c1 + c2 + c3 + c4 + c5 + c6;
}