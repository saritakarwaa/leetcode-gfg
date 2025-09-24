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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        ListNode* curr1=list1;
        ListNode* curr2=list2;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(curr1!=NULL && curr2!=NULL){
            if(curr1->val<curr2->val){
                temp->next=curr1;
                temp=curr1;
                curr1=curr1->next;
            }
            else{
                temp->next=curr2;
                temp=curr2;
                curr2=curr2->next;
            }
        }
        if(curr1) temp->next=curr1;
        if(curr2) temp->next=curr2;
        return dummy->next;
    }
};