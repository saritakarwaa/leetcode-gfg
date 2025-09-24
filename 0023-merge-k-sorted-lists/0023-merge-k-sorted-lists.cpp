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
    ListNode* mergeTwoSortedLists(ListNode* l1,ListNode* l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val<=l2->val){
            l1->next=mergeTwoSortedLists(l1->next,l2);
            return l1;
        }
        else{
            l2->next=mergeTwoSortedLists(l1,l2->next);
            return l2;
        }
        return NULL;
    }
    ListNode* partitionAndMerge(int start,int end,vector<ListNode*>&lists){
        if(start>end) return NULL;
        if(start==end) return lists[start];
        int mid=start+(end-start)/2;
        ListNode* l1=partitionAndMerge(start,mid,lists);
        ListNode* l2=partitionAndMerge(mid+1,end,lists);
        return mergeTwoSortedLists(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // vector<int>l;
        // for(auto list:lists){
        //     while(list){
        //         l.push_back(list->val);
        //         list=list->next;
        //     }
        // }
        // sort(l.begin(),l.end());
        // ListNode *newhead=new ListNode(0);
        // ListNode *temp=newhead;
        // for(int val:l){
        //     temp->next=new ListNode(val);
        //     temp=temp->next;
        // }   
        // return newhead->next;
        if(lists.size()==0) return NULL;
        return partitionAndMerge(0,lists.size()-1,lists);
    }
};