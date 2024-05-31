### Notes on the Odd-Even Linked List Rearrangement Logic

#### Problem Statement
Rearrange a singly linked list such that all nodes at odd positions are listed before nodes at even positions, preserving the original relative order of nodes in each group.

#### Key Concepts

1. **Linked List**: A data structure consisting of nodes, each containing data and a pointer to the next node.
2. **Odd and Even Position Nodes**: Nodes at positions 1, 3, 5, ... are considered odd-position nodes, and nodes at positions 2, 4, 6, ... are considered even-position nodes.

#### Steps to Rearrange the List

1. **Initialization**:
   - `odd`: Points to the first node (head).
   - `even`: Points to the second node (head->next).
   - `evenHead`: Stores the head of the even list to later connect it to the end of the odd list.

2. **Rearranging Nodes**:
   - Use two pointers, `odd` and `even`, to traverse the list.
   - Skip nodes in the even positions when moving the `odd` pointer and vice versa.

3. **Loop Condition**:
   - Continue the loop while both `odd` and `even` pointers and their next pointers are not `NULL`.
   - This ensures valid access to the `next` node without null pointer dereferencing.

4. **Inside the Loop**:
   - Update `odd->next` to skip the current even node and point to the next odd node.
   - Move the `odd` pointer to this new odd node.
   - Update `even->next` to skip the current odd node and point to the next even node.
   - Move the `even` pointer to this new even node.

5. **Connecting Lists**:
   - After rearranging, connect the last node in the odd list to the head of the even list (`evenHead`).

#### Code Implementation

Here's the implementation of the logic:

```cpp
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr; // Return if the list is empty
        if (!head->next) return head; // Return if the list has only one node

        ListNode* odd = head; // Initialize odd pointer
        ListNode* even = head->next; // Initialize even pointer
        ListNode* evenHead = even; // Store the head of the even list

        // Loop to rearrange nodes
        while (odd != nullptr && odd->next != nullptr && even != nullptr && even->next != nullptr) {
            odd->next = even->next; // Skip the current even node
            odd = odd->next; // Move odd pointer
            even->next = odd->next; // Skip the current odd node
            even = even->next; // Move even pointer
        }

        odd->next = evenHead; // Connect the end of the odd list to the head of the even list
        return head; // Return the head of the modified list
    }
};
```

#### Detailed Explanation:

1. **Initialization**:
   - `ListNode* odd = head;`: Start with the head as the first odd node.
   - `ListNode* even = head->next;`: The second node is the first even node.
   - `ListNode* evenHead = even;`: Save the starting point of the even nodes.

2. **Loop to Rearrange Nodes**:
   - **Condition**: `while (odd != nullptr && odd->next != nullptr && even != nullptr && even->next != nullptr)`
     - Ensure there are more nodes to process.
   - **Odd Node Handling**:
     - `odd->next = even->next;`: Link the current odd node to the next odd node.
     - `odd = odd->next;`: Move the odd pointer forward.
   - **Even Node Handling**:
     - `even->next = odd->next;`: Link the current even node to the next even node.
     - `even = even->next;`: Move the even pointer forward.

3. **Connecting Lists**:
   - After the loop, `odd->next = evenHead;` connects the last odd node to the first even node.

#### Summary
- This algorithm effectively rearranges nodes in a single traversal of the list.
- The time complexity is O(n), where n is the number of nodes in the list.
- The space complexity is O(1), as no additional space is used except for a few pointers.

This method ensures that all nodes at odd positions are followed by nodes at even positions, maintaining their original relative order.
