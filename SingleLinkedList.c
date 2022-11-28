#include <stdio.h>
#include <stdlib.h>
#define Node struct node
#define Mall(size) malloc(sizeof(size))

struct node{
  int data;
  Node *link;
};
Node* add_last(Node *ptr, int data){
  Node *temp = Mall(Node);
  temp-> data = data;
  temp->link = NULL;

  ptr->link = temp;
  return temp;
}
Node* add_first(Node* head,int d){
  Node *ptr = Mall(Node);
  ptr->data = d;
  ptr->link = NULL;

  ptr->link = head;
  head = ptr;
  return head;
}
void print_data(Node *head)
{
  if(head == NULL)
       printf("Linked list is empty");
  Node *ptr = NULL;
  ptr = head;
  while (ptr != NULL){
    printf("%d\n",ptr->data);
    ptr = ptr->link;
  }
}
Node* del_first(Node *head){
  if(head == NULL)
        printf("List is already empty!");
  else{
    Node *temp = head;
    head = head -> link;
    temp = NULL;
  }
  return head;
}
void del_last(Node* head){
  if(head == NULL)
        printf("List is already empty!");
  else if( head ->link == NULL)
  {
    free(head);
    head = NULL;
  } 
  else{
    Node *temp = head;
    // Node *temp2 = head;
    while (temp->link->link != NULL)
    {
      // temp2 = temp;
      temp =  temp->link;
    }
    // temp2 -> link = NULL;
    free(temp->link);
    temp->link = NULL;
  } 
  // return head;
}
Node* reverse_node(Node* head){
  Node *prev = NULL;
  Node *next = NULL; 
  while (head != NULL)
  {
    next = head->link;
    head->link = prev;
    prev = head;
    head = next;
  }
  head = prev;
  return head;
}
int main(){
  Node *head = Mall(Node);
  head->data = 45;
  head->link = NULL;
  
  Node *ptr = head;

  ptr = add_last(ptr,67);
  ptr = add_last(ptr,4);
  head = add_first(head,34);
  // head = reverse_node(head); // reverse_node Node of the list
  // head = del_first(head); //delate first Node of the list
  // del_last(head); // delate last Node of the lists
  ptr = head;
  print_data(ptr);
  return 0;
}
