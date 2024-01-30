//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*; 
class GFG{
    public static void main(String args[]) throws IOException 
    { 
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0){
            String input_line[] = read.readLine().trim().split("\\s+");
            int n1 = Integer.parseInt(input_line[0]);
            int n2 = Integer.parseInt(input_line[1]);
            int n3 = Integer.parseInt(input_line[2]);
            input_line = read.readLine().trim().split("\\s+");
            String A = input_line[0];
            String B = input_line[1];
            String C = input_line[2];
            Solution obj = new Solution();
            System.out.println(obj.LCSof3(A, B, C, n1, n2, n3));
        }
    } 
} 
// } Driver Code Ends


class Solution 
{ 
    int LCSof3(String A, String B, String C, int n1, int n2, int n3) 
    { 
        int array[][][]=new int[n1+1][n2+1][n3+1];
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                for(int k=1;k<=n3;k++)
                {
                    if(A.charAt(i-1)==B.charAt(j-1) && A.charAt(i-1)==C.charAt(k-1))
                    array[i][j][k]=1+array[i-1][j-1][k-1];
                    else
                    array[i][j][k]=(int)Math.max(Math.max(array[i-1][j][k],array[i][j-1][k]),array[i][j][k-1]);
                }
            }
        }
        return array[n1][n2][n3];
        
    }
}