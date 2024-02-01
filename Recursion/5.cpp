// Reverse a given stack of 'N' integers using recursion. You are required to make changes in the input parameter itself.



// Note: You are not allowed to use any extra space other than the internal stack space used due to recursion.



// Example:
// Input: [1,2,3,4,5] 
// Output: [5,4,3,2,1]

#include <stack>

void insertAtBottom(std::stack<int> &stack, int item) {
    if (stack.empty()) {
        stack.push(item);
        return;
    }

    int temp = stack.top();
    stack.pop();
    insertAtBottom(stack, item);
    stack.push(temp);
}

void reverseStack(std::stack<int> &stack) {
    if (!stack.empty()) {
        int temp = stack.top();
        stack.pop();
        reverseStack(stack);
        insertAtBottom(stack, temp);
    }
}
