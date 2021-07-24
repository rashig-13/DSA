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
        priority_queue<int,vector<int> , greater<int>> pq;
        for(ListNode* tmp: lists){
            while(tmp!=NULL){
                pq.push(tmp->val);
                tmp=tmp->next;
            }
        }
        ListNode* fake=new ListNode(-1);
        ListNode * tmp=fake;
        while(!pq.empty()){
            ListNode* node=new ListNode(pq.top());
            pq.pop();
            tmp->next=node;
            tmp=node;
        }
        return fake->next;
    }
};