#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head, *second = head;
        int i = 0;
        while (i < n) {
            first = first->next;
            i++;
        }
        while (first && first->next) {
            first = first->next;
            second = second->next;
        }
        if (!first) {
            return second->next;
        }
        second->next = second->next->next;
        return head;
    }
};