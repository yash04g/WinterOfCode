// https://leetcode.com/problems/intersection-of-two-linked-lists/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2){
        if(head1==NULL || head2==NULL) return NULL;
        ListNode* pa = head1;
        ListNode* pb = head2;
        ListNode* last1 = NULL;
        ListNode* last2 = NULL;
        while(pa->next!=NULL){
            pa = pa->next;
        }
        last1 = pa;
        while(pb->next!=NULL){
            pb = pb->next;
        }
        last2 = pb;
        if(last1!=last2) return NULL;
        pa = head1;
        pb = head2;
        while(pa!=pb){
            if(pa==NULL){
                pa = head2;
            }else{
                pa = pa->next;
            }
            if(pb==NULL){
                pb = head1;
            }else{
                pb = pb->next;
            }
        }
        return pa;
    }
};