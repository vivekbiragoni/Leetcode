
- **Problem:** Given a linked list of 0s, 1s, and 2s, sort it.

- **Approach:**
  1. Create three dummy nodes: `zero`, `one`, and `two`, each representing the start of a sublist for 0s, 1s, and 2s, respectively.
  2. Traverse the original list, segregating nodes into these three sublists based on their values.
  3. Combine the three sublists to form a single sorted list.
  4. Ensure to set the next pointer of the last node in each sublist to `nullptr` to avoid cyclic links.

- **Algorithm Steps:**
  - Traverse the original list:
    - If the node value is 0, append it to the `zero` sublist.
    - If the node value is 1, append it to the `one` sublist.
    - If the node value is 2, append it to the `two` sublist.
  - Combine the three sublists:
    - Attach the next of the `zero` sublist to the `one` sublist (if it exists). If not, attach it to the `two` sublist.
    - Attach the next of the `one` sublist to the `two` sublist.
  - Return the next of the `zero` dummy node, which will be the start of the sorted list.

- **Code:**
  ```cpp
  ListNode* sortList(ListNode* head) {
      ListNode* zero = new ListNode(0);
      ListNode* one = new ListNode(0);
      ListNode* two = new ListNode(0);
      ListNode* zeroHead = zero;
      ListNode* oneHead = one;
      ListNode* twoHead = two;

      ListNode* current = head;
      while (current) {
          if (current->val == 0) {
              zero->next = current;
              zero = zero->next;
          } else if (current->val == 1) {
              one->next = current;
              one = one->next;
          } else {
              two->next = current;
              two = two->next;
          }
          current = current->next;
      }

      // Combine the three lists
      zero->next = oneHead->next ? oneHead->next : twoHead->next;
      one->next = twoHead->next;

      // Set the end of the list to nullptr to avoid cycles
      two->next = nullptr;

      // Return the sorted list
      return zeroHead->next;
  }
  ```

- **Complexity Analysis:**
  - Time Complexity: O(n), where n is the number of nodes in the linked list.
  - Space Complexity: O(1), as we are using only a constant amount of extra space for pointers and dummy nodes.

These notes provide a concise understanding of the problem, the approach, and the code implementation.
