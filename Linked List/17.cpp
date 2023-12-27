/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/

int cnt(Node *s, Node *f){
    f = f->next;
    int count = 1;
    while(s != f){
        count++;
        f= f->next;
    }
    return count;
}

int lengthOfLoop(Node *head) {
  // Write your code here
  Node *s = head;
  Node *f = head;
  while (f != NULL && f->next != NULL){
      s = s->next;
      f = f->next->next;
      if(s==f) return cnt(s,f);
  }
  return 0;
  
}
