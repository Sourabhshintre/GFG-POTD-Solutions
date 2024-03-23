//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
       stack<int> insertAtBottom(stack<int> st,int ele){
    //base case
    if (st.empty()) 
    {
        //agar empty hai then push the ele and return the stack
        st.push(ele);
        return st; 
    }
    
    
    //ek case solve kro
    //phele top ele ko save kro
    //then top ele ko pop kro 
    //recursion lgao
    //bar bar recursion lgega hence stack at last empty mil jayega // hence base case achieved
    //uske bad ele push hoke ajayega
    //top ele ko push kro or return maro 
    //last mein stack with ele at bottom mil jayega
    //hence solved
    
    int top = st.top();
    st.pop();
    st = insertAtBottom( st, ele);
    st.push(top);
    return st;
    
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        cin>>x;
        stack<int> st;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            st.push(a);
        }
        Solution ob;
        stack<int> tmp=ob.insertAtBottom(st,x);
        vector<int> v;
        while(tmp.size()){
            v.push_back(tmp.top());tmp.pop();
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            if(i!=v.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends