### Notes on Removing Nth Node from the End of a Linked List

#### Problem Statement
Given a singly-linked list, remove the nth node from the end of the list and return the modified list.

#### Approach
1. **Count Nodes**: Traverse the list once to count the total number of nodes.
2. **Calculate Node Position**: Determine the position of the node to be deleted from the start using `count - n`.
3. **Handle Head Node Deletion**:
   - If the node to be deleted is the head node (i.e., `node_pos == 0`), or if the list has only one node (i.e., `cont == node_pos`), delete the head node and return the next node.
4. **Traverse to (n-1)th Node**: Traverse to the node just before the one to be deleted (`node_pos - 1`).
5. **Delete the Nth Node from the End**: Adjust the `next` pointer of the previous node to skip the node to be deleted, and then delete that node.

#### Implementation
```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *temp = head;
    int cont = 0;
    
    // Count total nodes
    while(temp) {
        cont++;
        temp = temp->next;
    }

    int node_pos = cont - n;

    // Handle head node deletion or single node list
    if(node_pos == 0 || cont == node_pos) {
        ListNode *newNode = head->next;
        delete head;
        return newNode;
    }

    // Traverse to (n-1)th node
    temp = head;
    for(int i = 0; i < node_pos - 1; ++i) {
        temp = temp->next;
    }

    // Delete the nth node from the end
    ListNode* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
    
    return head;
}
```

#### Time Complexity
- The algorithm traverses the list twice, resulting in a time complexity of O(n), where n is the number of nodes in the list.
- The space complexity is O(1) as no extra space is used other than a few pointers.
