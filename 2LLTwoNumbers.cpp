#include <iostream>
using namespace std;


struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x) , next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x) , next(next) {}
};

class Solution {
public:

        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

       if(!l1 && !l2) {
        return nullptr;
       }

       ListNode* head = nullptr;
       ListNode* tail = nullptr;
       int carry=0;

       while(l1||l2||carry>0) {

        int val1 = (l1) ? l1 ->val:0;
        int val2 = (l2) ? l2->val: 0;

        int sum = val1 + val2+carry;

        carry = sum / 10;

        ListNode* currentNode = new ListNode(sum%10);

        if(!head) {
            head = currentNode;
        }else{
            tail -> next = currentNode;
        }
        tail = currentNode;

        if(l1) {
            l1 = l1 -> next;
        }
        if(l2) {
            l2 = l2 ->next;
        }
       }

       return head;
    }

};


    // Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Test case: 342 + 465 = 807
    int num1[] = {2, 4, 3};  // represents 342
    int num2[] = {5, 6, 4};  // represents 465

    ListNode* l1 = createList(num1, 3);
    ListNode* l2 = createList(num2, 3);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);  // Expected output: 7 -> 0 -> 8

    return 0;
}