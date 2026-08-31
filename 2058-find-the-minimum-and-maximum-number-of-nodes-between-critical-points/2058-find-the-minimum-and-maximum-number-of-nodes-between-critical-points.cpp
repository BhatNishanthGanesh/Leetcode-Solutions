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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode*curr=head;
        ListNode*prev=nullptr;
        int mn=INT_MAX;
        int first=-1,a=INT_MAX,last=-1;
        for(int i=0;curr!=nullptr;i++){
            if(i>0 && curr->next!=nullptr){
                if((prev->val>curr->val && curr->val<curr->next->val)||(prev->val<curr->val && curr->val>curr->next->val)){
                    if(first==-1) first=i;
                    if(a==INT_MAX){
                        a=i;
                    }else{
                        mn=min(mn,i-a);
                        a=i;
                    }
                    last=i;
                }
            }
            prev=curr;
            curr=curr->next;
        }
        if(first==last && mn==INT_MAX) return {-1,-1};
        return {mn,last-first};
        
    }
};