/*
2. ADD TWO NUMBERS [MEDIUM]

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example
----------------------
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]

*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int m = 0, n = 0;
        ListNode *a = l1, *b = l2;
        while(l1!=NULL){
            m++;
            l1 = l1->next;
        }
        while(l2!=NULL){
            n++;
            l2 = l2->next;
        }
        if(m<n){
            ListNode* temp = a;
            a = b;
            b = temp;
            m = m+n;
            n = m-n;
            m = m-n;
        }
        int c = 0;
        l1 = a;
        ListNode* prev;
        while(b!=NULL){
            if((a->val+b->val+c)>=10){
                a->val = (a->val+b->val +c)%10;
                c = 1;
            }else{
                a->val = (a->val+b->val+c)%10;
                c = 0;
            }
            prev = a;
            a = a->next;
            b = b->next;
            
        }
        while(a!=NULL){
            if(a->val+c>=10){
                a->val = (a->val+c)%10;
                c = 1;
            }else{
                a->val = (a->val+c)%10;
                c = 0;
            }
            prev = a;
            a = a->next;
        }
        if(c==1){
            ListNode* x = new ListNode(1);
            prev->next = x;
        }
        return l1;
    }
};
