//o(n),o(1)

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        ListNode* endTrack = head; //last node
        int len = 0; //total length
        while(endTrack->next)
        {
            len++;
            endTrack = endTrack->next;
        }
        len++;
        k = k%len;
        if (k==0) return head;
        //number of steps from before = len-k+1
        int steps = len-k; //nodes before the new head
        ListNode* temp = head; //stops before the new head
        while(steps>1)
        {
            steps--;
            temp = temp->next;
        }
        endTrack->next = head; //connect the initial part behind
        head = temp->next; //new head
        temp->next = nullptr; //break the link before new head 
        return head;
    }
};
