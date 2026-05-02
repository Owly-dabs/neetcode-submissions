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
#include <unordered_map>
class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_map<int,int> myMap;

        while (head != nullptr) {
            if (myMap.find(head->val) != myMap.end()) return true;
            else {
                myMap[head->val] = head->val;
                head = head->next;
            }
        }

        return false;
        // Check if value of head is in myMap
        // If yes, return true 
        // Else store the value of head in myMap
        // go to next node
    }
};
