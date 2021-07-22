Using Map
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        unordered_map<ListNode*,int> mp;
        ListNode* a=A;
        ListNode* b=B;
        while(a!=NULL){
            mp[a]++;
            a=a->next;
        }
        while(b!=NULL){
            if(mp.find(b)!=mp.end()){
                return b;
            }
            b=b->next;
        }
        return NULL;
        
    }
};


Using TWO POINTERS
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode* a=headA;
        ListNode* b=headB;
        while(a!=b){
            a = a == NULL ? headB: a->next;
            b = b == NULL ? headA: b->next;
        }
        return a;
    }
};