#User function Template for python3

'''
class Node:
	def __init__(self, data):
		self.data = data
		self.next = None
		self.prev = None
'''

class Solution():
    def sortDoubly(self,head):
        tail = head
        while tail.next:
            tail=tail.next
        def merge(head,mid,tail):
            temp=[]
            i,j=head,mid.next
            while i!=mid.next and j!=tail.next:
                if i.data<j.data:
                    temp.append(i.data)
                    i = i.next
                else:
                    temp.append(j.data)
                    j=j.next
            if i!=mid.next:
                while i!=mid.next:
                    temp.append(i.data)
                    i = i.next
            if j!=tail.next:
                while j!=tail.next:
                    temp.append(j.data)
                    j=j.next
            k=head
            for i in temp:
                k.data=i
                k=k.next
        def mergesort(head,tail):
            if head!=tail:
                temp,mid=head,head
                while temp!=tail and temp.next!=tail:
                    temp=temp.next.next
                    mid=mid.next
                mergesort(head,mid)
                mergesort(mid.next,tail)
                merge(head,mid,tail)
        mergesort(head,tail)
        return head   


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import sys

sys.setrecursionlimit(1000000)


class Node:

    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


class DoublyLinkedList:

    def __init__(self):
        self.head = None
        self.tail = None

    def append(self, new_data):
        new_node = Node(new_data)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
            return
        new_node.prev = self.tail
        self.tail.next = new_node
        self.tail = new_node

    def printList(self, node):
        while (node.next is not None):
            node = node.next
        while node.prev is not None:
            node = node.prev
        while (node is not None):
            print(node.data, end=" ")
            node = node.next
        print()


def printList(node):
    temp = node

    while (node is not None):
        print(node.data, end=" ")
        temp = node
        node = node.next
    print()
    while (temp):
        print(temp.data, end=" ")
        temp = temp.prev


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        llist = DoublyLinkedList()
        for e in arr:
            llist.append(e)
        ob = Solution()
        llist.head = ob.sortDoubly(llist.head)
        printList(llist.head)
        print()

# } Driver Code Ends