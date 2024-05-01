//{ Driver Code Starts
/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

class Node {
    char data;
    Node next;
    
    public Node(char data){
        this.data = data;
        next = null;
    }
}

class GFG {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
		    int n = sc.nextInt();
		    Node head = null, tail = null;
		    
		    char head_c = sc.next().charAt(0);
		    head = new Node(head_c);
		    tail = head;
		    
		    while(n-- > 1){
		        tail.next = new Node(sc.next().charAt(0));
		        tail = tail.next;
		    }
		    
		    Solution obj = new Solution();
		    //show(head);
		    show(obj.arrangeCV(head));
		    
		}
	}
	
	public static void po(Object o){
	    System.out.println(o);
	}
	
	public static void show(Node head){
        while(head != null){
            System.out.print(head.data+" ");
            head = head.next;
        }
        System.out.println();
    }
}

// } Driver Code Ends


/*
Structure of node class is:
class Node {
    char data;
    Node next;
    
    public Node(char data){
        this.data = data;
        next = null;
    }
}
*/
class Solution {
    public Node arrangeCV(Node head){
        //write code here and return the head of changed linked list
        
        Node vowHead = null; // Initialize a pointer to the head of vowel nodes
        Node consHead = null; // Initialize a pointer to the head of consonant nodes
        Node vowTail = null; // Initialize a pointer to the tail of vowel nodes
        Node consTail = null; // Initialize a pointer to the tail of consonant nodes
        
        Node current = head; // Initialize a pointer to traverse the original linked list
        
        while(current != null) { // Iterate through the original linked list
            if(isVowel(current.data)) { // Check if the current node contains a vowel
                if(vowHead == null) { // If it's the first vowel node encountered
                    vowHead = current; // Set the head of vowel nodes
                    vowTail = current; // Set the tail of vowel nodes
                } else {
                    vowTail.next = current; // Append the current node to the tail of vowel nodes
                    vowTail = vowTail.next; // Update the tail of vowel nodes
                }
            } else { // If it's a consonant
                if(consHead == null) { // If it's the first consonant node encountered
                    consHead = current; // Set the head of consonant nodes
                    consTail = current; // Set the tail of consonant nodes
                } else {
                    consTail.next = current; // Append the current node to the tail of consonant nodes
                    consTail = consTail.next; // Update the tail of consonant nodes
                }
            }
            current = current.next; // Move to the next node
        }
        
        if(vowHead != null) { // If there are vowel nodes
            head = vowHead; // Set the head of the modified linked list to the head of vowel nodes
            vowTail.next = consHead; // Connect the tail of vowel nodes to the head of consonant nodes
        } else { // If there are no vowel nodes
            head = consHead; // Set the head of the modified linked list to the head of consonant nodes
        }
        
        if(consTail != null) { // If there are consonant nodes
            consTail.next = null; // Set the next of the tail of consonant nodes to null to mark the end of the list
        }
        
        return head; // Return the head of the modified linked list
    }
    
    private boolean isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
}