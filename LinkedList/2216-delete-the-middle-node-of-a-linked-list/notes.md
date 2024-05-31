### Notes on Deleting the Middle Node of a Linked List

#### Problem Statement
Given a singly-linked list, delete the middle node of the list. If there are two middle nodes, delete the second one.

#### Approach
1. **Initialize Pointers**: Start with three pointers, `slow`, `prev`, and `fast`, all initially pointing to the head of the list.
2. **Move Pointers**: Use the slow and fast pointers to find the middle node of the list. The slow pointer moves one step at a time, while the fast pointer moves two steps at a time. The prev pointer keeps track of the node before the slow pointer.
3. **Delete Middle Node**: Once the fast pointer reaches the end of the list, the slow pointer will be at the middle node. Delete this node by adjusting pointers accordingly.
4. **Handle Edge Cases**: Check if there is only one middle node or if there are two middle nodes to ensure correct deletion.

#### Implementation
```cpp
ListNode* deleteMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* prev = NULL;
    ListNode* fast = head;
    
    // Find the middle node
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Delete the middle node
    if (prev == NULL) {
        head = slow->next;
    } else {
        prev->next = slow->next;
    }
    delete slow;
    
    return head;
}
```

#### Time Complexity
- The algorithm traverses the list once, resulting in a time complexity of O(n), where n is the number of nodes in the list.

#### Space Complexity
- The space complexity is O(1) as only a few pointers are used.
