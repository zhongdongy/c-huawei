#include <stdio.h>
#include "sorting.h"
#include "utils.h"

#pragma region Shared Functions
void swap_array_elements(int ar[], int a, int b)
{
  int temp = ar[a];
  ar[a] = ar[b];
  ar[b] = temp;
}

#pragma endregion

#pragma region Bubble Sort

void bubble_sort_asc(int ar[], int length)
{
  int idx;
  for (idx = length - 1; idx > 0; idx--)
  {
    int idx_b = 0;
    while (idx_b < idx)
    {
      if (ar[idx_b] > ar[idx_b + 1])
      {
        swap_array_elements(ar, idx_b, idx_b + 1);
      }

      idx_b++;
    }
  }
}

void bubble_sort_desc(int ar[], int length)
{
  int idx;
  for (idx = length - 1; idx > 0; idx--)
  {
    int idx_b = 0;
    while (idx_b < idx)
    {
      if (ar[idx_b] < ar[idx_b + 1])
      {
        swap_array_elements(ar, idx_b, idx_b + 1);
      }

      idx_b++;
    }
  }
}

#pragma endregion

#pragma region Heap Sort

/**
 * \brief (internal only) Move largest node of a sub tree to its root.
 *
 * \param ar Array form of a complete binary tree
 * \param length Boundary of the CBT array (extra elements not considered as
 *  part of the tree)
 * \param root A root node whose sub tree should be heapified.
 */
void __heapify_max(int ar[], int length, int root)
{
  int idx_left_child = 2 * root + 1;
  int idx_right_child = 2 * root + 2;

  int largest = root;
  if (idx_left_child < length && ar[idx_left_child] > ar[largest])
  {
    largest = idx_left_child;
  }
  if (idx_right_child < length && ar[idx_right_child] > ar[largest])
  {
    largest = idx_right_child;
  }
  if (largest != root)
  {
    swap_array_elements(ar, largest, root);
    __heapify_max(ar, length, largest);
  }
}
/**
 * \brief (internal only) Move smallest node of a sub tree to its root.
 *
 * \param ar Array form of a complete binary tree
 * \param length Boundary of the CBT array (extra elements not considered as
 *  part of the tree)
 * \param root A root node whose sub tree should be heapified.
 */
void __heapify_min(int ar[], int length, int root)
{
  int idx_left_child = 2 * root + 1;
  int idx_right_child = 2 * root + 2;

  int smallest = root;
  if (idx_left_child < length && ar[idx_left_child] < ar[smallest])
  {
    smallest = idx_left_child;
  }
  if (idx_right_child < length && ar[idx_right_child] < ar[smallest])
  {
    smallest = idx_right_child;
  }
  if (smallest != root)
  {
    swap_array_elements(ar, smallest, root);
    __heapify_min(ar, length, smallest);
  }
}

/**
 * \brief (internal only) Traverse tree nodes (w/ sub tree) to build a max heap
 *
 * \param ar Array form of a complete binary tree
 * \param length Boundary of the CBT array (all elements included)
 */
void __build_max_heap(int ar[], int length)
{
  int idx = length / 2;
  while (idx >= 0)
  {
    __heapify_max(ar, length, idx--);
  }
}

/**
 * \brief (internal only) Traverse tree nodes (w/ sub tree) to build a min heap
 *
 * \param ar Array form of a complete binary tree
 * \param length Boundary of the CBT array (all elements included)
 */
void __build_min_heap(int ar[], int length)
{
  int idx = length / 2;
  while (idx >= 0)
  {
    __heapify_min(ar, length, idx--);
  }
}

void heap_sort_asc(int ar[], int length)
{
  __build_max_heap(ar, length);

  int idx = length - 1;
  int len = length;
  while (idx > 0)
  {
    swap_array_elements(ar, 0, idx--);
    __heapify_max(ar, --len, 0);
  }
}

void heap_sort_desc(int ar[], int length)
{
  __build_min_heap(ar, length);

  int idx = length - 1;
  int len = length;
  while (idx > 0)
  {
    swap_array_elements(ar, 0, idx--);
    __heapify_min(ar, --len, 0);
  }
}

#pragma endregion

#pragma region Selection Sort
void selection_sort_asc(int ar[], int length)
{

  int min, idx_min;

  int idx;
  for (idx = 0; idx < length - 1; idx++)
  {
    min = ar[idx];
    idx_min = idx;

    int idx_next;
    for (idx_next = idx + 1; idx_next < length; idx_next++)
    {
      if (min > ar[idx_next])
      {
        min = ar[idx_next];
        idx_min = idx_next;
      }
    }
    swap_array_elements(ar, idx, idx_min);
  }
}
void selection_sort_desc(int ar[], int length)
{

  int max, idx_max;

  int idx;
  for (idx = 0; idx < length - 1; idx++)
  {
    max = ar[idx];
    idx_max = idx;

    int idx_next;
    for (idx_next = idx + 1; idx_next < length; idx_next++)
    {
      if (max < ar[idx_next])
      {
        max = ar[idx_next];
        idx_max = idx_next;
      }
    }
    swap_array_elements(ar, idx, idx_max);
  }
}
#pragma endregion

#pragma region Insertion Sort

void insertion_sort_asc(int ar[], int length)
{
  int idx_pre, idx_current;

  int idx;
  for (idx = 1; idx < length; idx++)
  {
    idx_pre = idx - 1;
    int current = ar[idx];

    while (idx_pre >= 0 && ar[idx_pre] > current)
    {
      ar[idx_pre + 1] = ar[idx_pre];
      idx_pre--;
    }
    ar[idx_pre + 1] = current;
  }
}

void insertion_sort_desc(int ar[], int length)
{
  int idx_pre, current;
  int idx;

  for (idx = 1; idx < length; idx++)
  {
    idx_pre = idx - 1;
    current = ar[idx];

    while (idx_pre >= 0 && ar[idx_pre] < current)
    {
      ar[idx_pre + 1] = ar[idx_pre];
      idx_pre--;
    }
    ar[idx_pre + 1] = current;
  }
}
#pragma endregion

#pragma region Shell Sort

void shell_sort_asc(int ar[], int length)
{
  
}
#pragma endregion