#include <bits/stdc++.h> 
void InsertInSortedOrder(stack<int> &sorted_stack, int element){
	if(sorted_stack.empty() || element>sorted_stack.top()){
		sorted_stack.push(element);
		return;
	}

	int top_element = sorted_stack.top();
	sorted_stack.pop();
	InsertInSortedOrder(sorted_stack, element);
	sorted_stack.push(top_element);


}

void sortStack(stack<int> &stack)
{
	if(stack.empty()) return;

	int top_element = stack.top();
	stack.pop();
	sortStack(stack);
	InsertInSortedOrder(stack, top_element); 
}
