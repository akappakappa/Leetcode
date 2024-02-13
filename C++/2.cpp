/**
 * @author github.com/akappakappa
 *
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode();
        ListNode *current = head;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int val1 = l1 == nullptr ? 0 : l1->val;
            int val2 = l2 == nullptr ? 0 : l2->val;

            int sum = (val1 + val2 + carry);
            current->next = new ListNode(sum % 10);
            carry = sum / 10;

            current = current->next;
            l1 = l1 == nullptr ? nullptr : l1->next;
            l2 = l2 == nullptr ? nullptr : l2->next;
        }
        ListNode *output = head->next;
        delete head;
        return output;
    }
};