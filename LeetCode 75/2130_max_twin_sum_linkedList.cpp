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
    int pairSum(ListNode* head) {
        ListNode* slow = head, * fast = head;

        // 1. finding mid
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow;

        // 2. Reverse second half
        ListNode* prev = NULL, *nextNode = NULL;

        while(mid != NULL){
            nextNode = mid->next;
            mid->next = prev;
            prev = mid;
            mid = nextNode;
        }

        // 3. Finding answers
        int result = 0;
        ListNode * curr = head;
        
        while(prev != NULL){
            result = max(result, curr->val + prev->val);
            prev = prev->next;
            curr = curr->next;
        }

        return result;
    }
};