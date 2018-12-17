#include <stdio.h>
#include "merge.h"

int findNext(Node *lists[], int index, int n, int adj)
{
  while (index >= 0 && index < n) {
    if (lists[index] != NULL)
      return index;
    index += adj;
  }
  return -1;
}

Node *merge(Node *lists[], int n)
{
  int last = 0;
  Node *lastPtr = NULL, *head = NULL;
  int adj = 1;			/* foreward */
  int current;
  
  while ((current = findNext(lists, last, n, adj)) != -1) {
    if (lastPtr == NULL) 
      head = lists[current];
    else
      lastPtr->next = lists[current];
  
    int next;
    while ((next = findNext(lists, current + adj, n, adj)) != -1) {
      Node *currentPtr = lists[current];
      lists[current] = currentPtr->next;
      currentPtr->next = lists[next];
      current = next;
    }
    last = current;
    lastPtr = lists[current];
    lists[current] = lastPtr->next;
    adj = -adj;
  }
  return head;
}
