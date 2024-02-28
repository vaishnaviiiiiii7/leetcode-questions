/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}					
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    int length(ListNode *&head)
    {
        ListNode *temp = head;
        int count = 0;
        while(temp != 0)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    ListNode* reverseKGroup(ListNode* &head, int k) {
        
        //empty or single Node checks
        if(head == 0 or head->next == 0)
            return head;
        
        int len = length(head);
        if(k > len)
            return head;
        
        //reverse first k Nodes
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nextNode = NULL;
        int count = 0;
        
        while(count < k)
        {
nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        } 
      //recursive Call for remaining Nodes
        if(curr != 0)
        {
            head->next = reverseKGroup(curr,k);
        }
        
        //return head of modified linked list
        return prev;
    }
};
