//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    vector<string> ans;
    void func(string s, int ind, string tempS) {
        if(ind == s.length()) {
            if(tempS != "") ans.push_back(tempS);
            return;
        }
        
        func(s, ind+1, tempS);
        func(s, ind+1, tempS+s[ind]);
    }
	public:
    vector<string> AllPossibleStrings(string s) {
        func(s, 0, "");
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends