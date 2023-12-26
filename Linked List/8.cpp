// Function to delete the head of the doubly linked list
// The functionality of this has been explained in our previous
// article, please refer to it. 
Node* deleteHead(Node* head) {
    if (head == nullptr || head->next == nullptr) {
      // Return NULL if the list is empty or contains only one element
        return nullptr; 
    }

   // Store the current head as 'prev'
    Node* prev = head;      
     // Move 'head' to the next node
    head = head->next;    

 // Set 'back' pointer of the new head to nullptr
    head->back = nullptr;   

 // Set 'next' pointer of 'prev' to nullptr
    prev->next = nullptr;  

   // Return the new head
    return head;          
}

// Function to delete the tail of the doubly linked list
Node* deleteTail(Node* head) {
    if (head == nullptr || head->next == nullptr) {
     // If the list is empty or has only one node, return null
        return nullptr;  
    }
    
    Node* tail = head;
    while (tail->next != nullptr) {
     // Traverse to the last node (tail)
        tail = tail->next; 
    }
    
    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    
    // Free memory of the deleted node
    delete tail;  
    
    return head;
}
