#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};

// Helper function to reverse a portion of the list
struct ListNode* reverse(struct ListNode* start, struct ListNode* end) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = start;
    struct ListNode* next = NULL;

    while (curr != end) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    // Count total nodes
    struct ListNode* node = head;
    int count = 0;
    while (node) {
        count++;
        node = node->next;
    }

    // Create a dummy node
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    while (count >= k) {
        struct ListNode* start = prev->next;
        struct ListNode* end = start;
        for (int i = 0; i < k; i++) {
            end = end->next;
        }

        prev->next = reverse(start, end);
        start->next = end;
        prev = start;

        count -= k;
    }

    return dummy.next;
}

// Helper function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Helper function to print the list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Create the linked list: 1 -> 2 -> 3 -> 4 -> 5
    struct ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    int k = 3;
    struct ListNode* new_head = reverseKGroup(head, k);
    printList(new_head);

    return 0;
}