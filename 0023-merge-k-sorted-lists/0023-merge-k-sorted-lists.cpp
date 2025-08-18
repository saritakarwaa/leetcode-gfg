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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>l;
        for(auto list:lists){
            while(list){
                l.push_back(list->val);
                list=list->next;
            }
        }
        sort(l.begin(),l.end());
        ListNode *newhead=new ListNode(0);
        ListNode *temp=newhead;
        for(int val:l){
            temp->next=new ListNode(val);
            temp=temp->next;
        }   
        return newhead->next;
    }
};