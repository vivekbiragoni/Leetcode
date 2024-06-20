
### 1. Implementing a Stack using Queues

**Single Queue Approach:**
- Use a single queue to simulate stack behavior by ensuring the most recently added element is always at the front of the queue.
- Every time you push a new element, you enqueue it to the queue and then dequeue all previous elements and enqueue them again.

**Two Queue Approach:**
- Use two queues to simulate stack behavior.
- Use one queue (`q1`) for pushing elements, and another queue (`q2`) for storing elements temporarily during pop operations.

### 2. Implementing a Queue using Stacks

**Two Stack Approach:**
- Use two stacks (`st1` and `st2`) to implement a queue.
- For enqueue operations, push elements onto `st1`.
- For dequeue operations, transfer elements from `st1` to `st2` only when `st2` is empty, then pop from `st2`.

### 3. Implementing a MinStack

**MinStack with Two Stacks:**
- Use one primary stack to store all elements.
- Use a secondary stack (`minStack`) to keep track of the minimum elements.
- On `push`, push the element onto the primary stack, and also push it onto the `minStack` if it's less than or equal to the current minimum.
- On `pop`, pop from both stacks if the top of the primary stack equals the top of the `minStack`.
- `top` and `getMin` operations retrieve the top element from the primary stack and `minStack`, respectively.

### Example Implementations

#### Stack using Single Queue
```cpp
class StackUsingQueue {
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        q.pop();
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
```

#### Queue using Two Stacks
```cpp
class QueueUsingStacks {
    stack<int> st1, st2;

public:
    void enqueue(int x) {
        st1.push(x);
    }

    int dequeue() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int val = st2.top();
        st2.pop();
        return val;
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }
};
```

#### MinStack
```cpp
class MinStack {
    stack<int> st;
    stack<int> minSt;

public:
    void push(int x) {
        st.push(x);
        if (minSt.empty() || x <= minSt.top()) {
            minSt.push(x);
        }
    }

    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};
```

### Summary of Variants

1. **Stack using Single Queue**: Reorders elements on each push to keep the most recent element at the front.
2. **Stack using Two Queues**: Transfers elements between two queues to maintain stack behavior.
3. **Queue using Two Stacks**: Uses one stack for enqueue operations and another for dequeue operations, transferring elements between them as necessary.
4. **MinStack using Two Stacks**: Uses a primary stack for all elements and a secondary stack to keep track of the current minimum element.

Each approach and variant has its own use cases and efficiency considerations, so the choice of implementation depends on the specific requirements and constraints of the problem you're solving.
