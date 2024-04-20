//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        
        int pt1 = 0, pt2 = 0;
        vector<int> ans;
        while(pt1<n && pt2<m){
            if(arr1[pt1]==arr2[pt2]){
                ans.push_back(arr1[pt1]);
                pt1++;
                while(pt1<n && arr1[pt1]==arr1[pt1-1]){
                    pt1++;
                }
                pt2++;
                while(pt2<m && arr2[pt2]==arr2[pt2-1]){
                    pt2++;
                }
            }
            else if(arr1[pt1]>arr2[pt2]){
                ans.push_back(arr2[pt2]);
                pt2++;
                while(pt2<m && arr2[pt2]==arr2[pt2-1]){
                    pt2++;
                }
            }
            else{
                ans.push_back(arr1[pt1]);
                pt1++;
                while(pt1<n && arr1[pt1]==arr1[pt1-1]){
                    pt1++;
                }
            }
        }
        while(pt1<n){
            ans.push_back(arr1[pt1]);
            pt1++;
            while(pt1<n && arr1[pt1]==arr1[pt1-1]){
                pt1++;
            }
        }
        while(pt2<m){
            ans.push_back(arr2[pt2]);
            pt2++;
            while(pt2<m && arr2[pt2]==arr2[pt2-1]){
                pt2++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends