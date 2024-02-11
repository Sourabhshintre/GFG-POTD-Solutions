//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
import java.lang.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            int n = Integer.parseInt(in.readLine());
            
            Solution ob = new Solution();
            ArrayList<Integer> ans = ob.recamanSequence(n);
            for(int i = 0;i < n;i++)
                System.out.print(ans.get(i)+" ");
            System.out.println();
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    static ArrayList<Integer> recamanSequence(int n){
        
        ArrayList<Integer> ans = new ArrayList<>();
        int val = check(ans,n-1);
        return ans;
    }
    public static int check(ArrayList<Integer> ans,int i){
        
        if(i==0){
            ans.add(0);
            return 0;
        }
        
        int val = check(ans,i-1);
        int curr = 0;
        
        if(val-i>=0 && !ans.contains(val-i)){
            curr = val-i;
            ans.add(val-i);
        }else{
            curr = val+i;
            ans.add(val+i);
        }
        return curr;
    }
}