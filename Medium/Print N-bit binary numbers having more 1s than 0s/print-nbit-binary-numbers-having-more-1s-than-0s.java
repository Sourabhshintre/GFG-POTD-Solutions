//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(read.readLine());
            Solution ob = new Solution();
            ArrayList<String> result = ob.NBitBinary(n);
            for(String value  : result){
                System.out.print(value + " ");
            }
            System.out.println();
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
     ArrayList<String> NBitBinary(int N) {
        // code here
        ArrayList<String> sol = new ArrayList<>();
        StringBuilder builder = new StringBuilder(N);
        builder.append('1');
        solve(N-1, 0, 0, builder, sol);
        return sol;
    }
    
    private void solve(int n, int ones, int zeros, 
                    StringBuilder builder, List<String> list){
        if(n == 0){
            list.add(builder.toString());
            return;
        }
        
        builder.append('1');
        solve(n-1, ones+1, zeros, builder, list);
        builder.deleteCharAt(builder.length()-1);
        
        if(ones >= zeros){
            builder.append('0');
            solve(n-1, ones, zeros+1, builder, list);
            builder.deleteCharAt(builder.length()-1);
        }
    }
}