/*
https://practice.geeksforgeeks.org/batch/dsa-4/track/DSASP-LinkedList/problem/delete-without-head-pointer

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;



class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
       // main logic 
       del->data = del->next->data;
       Node *temp = del->next;
       del->next = temp->next;
       delete temp;
    }

};

*/