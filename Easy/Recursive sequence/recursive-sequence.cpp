//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:

long long ans = 0;
    long long mod = 1e9+7;
    void solve(int n , int index,int val){
        long long sol=  1;
        
        // val is used to track how many elements are inculded in current multiplication.
        
        for(int i=0;i<val;i++){
            sol  =( sol * (index++))%mod;
            
            // index++ to update value to be multiplied
        }
        ans = (ans+sol)%mod;
        if(val==n)return ;
        
        // recursive call 
        // val++ is to incriment the size of next multiplication
        solve(n,index,val+1);
    }
    
    long long sequence(int n){
        solve(n,1,1);
        return ans%mod;
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends