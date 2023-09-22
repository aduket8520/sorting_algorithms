#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deck.h" // Include your deck.h header file

// Compare function for qsort
int compareCards(const void *a, const void *b)
{
  const deck_node_t **cardA = (const deck_node_t **)a;
  const deck_node_t **cardB = (const deck_node_t **)b;

  // First, compare kinds (SPADE < HEART < CLUB < DIAMOND)
  if ((*cardA)->card->kind < (*cardB)->card->kind)
  {
    return -1;
  }
  else if ((*cardA)->card->kind > (*cardB)->card->kind)
  {
    return 1;
  }

  // If kinds are the same, compare values (Ace < 2 < 3 < ... < King)
  return strcmp((*cardA)->card->value, (*cardB)->card->value);
}

// Swap two nodes in a doubly linked list
void swapNodes(deck_node_t **deck, deck_node_t *nodeA, deck_node_t *nodeB)
{
  if (nodeA == nodeB)
  {
    return; // Nothing to swap
  }

  if (nodeA->prev)
  {
    nodeA->prev->next = nodeB;
  }
  else
  {
    *deck = nodeB; // Update the head if nodeA was the head
  }

  if (nodeB->prev)
  {
    nodeB->prev->next = nodeA;
  }
  else
  {
    *deck = nodeA; // Update the head if nodeB was the head
  }

  deck_node_t *temp = nodeA->next;
  nodeA->next = nodeB->next;
  nodeB->next = temp;

  temp = nodeA->prev;
  nodeA->prev = nodeB->prev;
  nodeB->prev = temp;
}

// Sort the deck using qsort
void sort_deck(deck_node_t **deck)
{
  if (deck == NULL || *deck == NULL)
  {
    return; // Empty deck or NULL pointer, nothing to sort
  }

  // Create an array of pointers to card nodes
  deck_node_t *nodeArray[52];
  deck_node_t *current = *deck;
  size_t count = 0;
  while (current != NULL)
  {
    nodeArray[count] = current;
    current = current->next;
    count++;
  }

  // Sort the array of card nodes using qsort
  qsort(nodeArray, count, sizeof(deck_node_t *), compareCards);

  // Rearrange the linked list based on the sorted array
  for (size_t i = 1; i < count; i++)
  {
    swapNodes(deck, nodeArray[i - 1], nodeArray[i]);
  }
}
