//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> subset_sums;

    void generateSubsetSums(vector<int>& arr, int n, int index, int current_sum) {
        // Base case: if we have considered all elements
        if (index == n) {
            subset_sums.push_back(current_sum);
            return;
        }
        
        // Include the current element in the sum
        generateSubsetSums(arr, n, index + 1, current_sum + arr[index]);
        
        // Exclude the current element from the sum
        generateSubsetSums(arr, n, index + 1, current_sum);
    }

    vector<int> subsetSums(vector<int> arr, int n) {
        subset_sums.clear(); // Clear the results from any previous runs
        generateSubsetSums(arr, n, 0, 0);
        return subset_sums;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends