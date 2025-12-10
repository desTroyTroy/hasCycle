// Description - create a method that takes a linked-list as an input,
// detects if a loop-back is present, and returns True or False.

#include <iostream>
#include <vector>

using namespace std;

//Definition of a Node with Value initialized to zero
struct ListNode {       
    int val;
    ListNode* next;
    ListNode(int x=0) : val(x), next(nullptr) {}
};

class Solution {
public:
    //Detects loop-back in input using Floyd's Tortoise and Hare algorithm
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;  //Slow node pointer
        ListNode* fast = head;  //Fast node pointer
        bool cycle = false;

        //Detects if list is empty, has only one item, or at end of list
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            //Breaks from while-loop if loop-back is detected
            //and sets return to True
            if (slow == fast) {
                cycle = true;
                break;
            }
        }
        return cycle;
    }
};

ListNode* buildNodes(vector<int>&);

// Main creates the sample input array, builds linked-list with array,
// inserts a loop-back in the linked-list, and calls hasCycle() on it,
// and prints to console True or False.
int main() {
    Solution sol;
    vector<int> arr = { 1, 2, 3, 4, 5 };
    ListNode* head = buildNodes(arr);
    head->next->next->next = head;  //Manually creates loop-back in linked list
    cout << sol.hasCycle(head) << endl;
}

//Builds the linked-list by calling ListNode on each item in array
ListNode* buildNodes(vector<int>& arr) {
    ListNode dummy;                 //Creates dummy node at head of list
    ListNode* current = &dummy;     //Creates pointer to dummy's location
    for (const auto& value : arr) {
        current->next = new ListNode(value);    //Link current node to new node
        current = current->next;                //Move "current" pointer forward
    }
    return dummy.next;              //Return head of linked-list
};