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
 ListNode* reverseLL(ListNode* head)
 {
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    ListNode* Newhead=reverseLL(head->next);
    ListNode* front=head->next;
    front->next=head;
    head->next=NULL;
    return Newhead;
 }
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
    {
        return true;
    }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            
        }
        ListNode* Newhead=reverseLL(slow->next);
        ListNode* first=head;
        ListNode* second=Newhead;
        while(second!=NULL)
        {
            if(first->val!=second->val)
            {
                reverseLL(Newhead);
                return false;
            }
            first=first->next;
            second=second->next;

        }
        reverseLL(Newhead);
        return true;
    }
};