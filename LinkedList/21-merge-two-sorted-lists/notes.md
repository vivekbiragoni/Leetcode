
### Short Notes

- **Initial Checks**:
  - If `list1` is `NULL`, return `list2`.
  - If `list2` is `NULL`, return `list1`.

- **Initialization**:
  - `third` and `last` point to the first node of the merged list.
  - `first` and `second` traverse the remaining nodes of `list1` and `list2`.

- **Merging Process**:
  - Compare `first->val` and `second->val`.
  - Link the smaller node to `last->next`.
  - Update `last` to the newly added node.
  - Move the corresponding pointer (`first` or `second`) to the next node.

- **Attach Remaining Nodes**:
  - If `first` is not `NULL`, link remaining `first` nodes to `last->next`.
  - Else, link remaining `second` nodes to `last->next`.

- **Return**:
  - Return `third` which points to the head of the merged list.
