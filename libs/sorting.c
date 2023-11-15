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
  int idx;
  for (idx = 1; idx < length; idx++)
  {
    int idx_pre = idx - 1;
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
  int idx;

  for (idx = 1; idx < length; idx++)
  {
    int idx_pre = idx - 1;
    int current = ar[idx];

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
  int gap = 1;
  while (gap < length / 3)
  {
    gap = gap * 3 + 1;
  }

  while (gap > 0)
  {
    int idx;
    for (idx = gap; idx < length; idx++)
    {
      int idx_pre = idx - gap;
      int current = ar[idx];

      while (idx_pre >= 0 && ar[idx_pre] > current)
      {
        ar[idx_pre + gap] = ar[idx_pre];
        idx_pre -= gap;
      }
      ar[idx_pre + gap] = current;
    }
    gap /= 3;
  }
}

void shell_sort_desc(int ar[], int length)
{
  int gap = 1;
  while (gap < length / 3)
  {
    gap = gap * 3 + 1;
  }

  while (gap > 0)
  {
    int idx;
    for (idx = gap; idx < length; idx++)
    {
      int idx_pre = idx - gap;
      int current = ar[idx];

      while (idx_pre >= 0 && ar[idx_pre] < current)
      {
        ar[idx_pre + gap] = ar[idx_pre];
        idx_pre -= gap;
      }
      ar[idx_pre + gap] = current;
    }
    gap /= 3;
  }
}
#pragma endregion

#pragma region Merge Sort
/**
 * \brief (internal) Returns a ascendingly sorted segment of given array.
 *
 * \param ar Array to sort
 * \param l Segment start index (inclusive)
 * \param r Segment end index (inclusive)
 */
void __merge_sort_asc(int ar[], int l, int r)
{
  if (r == l)
  {
    return;
  }

  int mid = (l + r) >> 1;
  __merge_sort_asc(ar, l, mid);
  __merge_sort_asc(ar, mid + 1, r);
  int idx_l = l, idx_r = mid + 1, idx = 0;
  int temp_ar[r - l + 1];

  while (idx_l <= mid && idx_r <= r)
  {
    temp_ar[idx++] = ar[idx_l] < ar[idx_r] ? ar[idx_l++] : ar[idx_r++];
  }

  while (idx_l <= mid)
  {
    temp_ar[idx++] = ar[idx_l++];
  }

  while (idx_r <= r)
  {
    temp_ar[idx++] = ar[idx_r++];
  }

  int idx_temp;
  for (idx_temp = 0; idx_temp < r - l + 1; idx_temp++)
  {
    ar[l + idx_temp] = temp_ar[idx_temp];
  }
}

/**
 * \brief (internal) Returns a descendingly sorted segment of given array.
 *
 * \param ar Array to sort
 * \param l Segment start index (inclusive)
 * \param r Segment end index (inclusive)
 */
void __merge_sort_desc(int ar[], int l, int r)
{
  if (r == l)
  {
    return;
  }

  int mid = (l + r) >> 1;
  __merge_sort_desc(ar, l, mid);
  __merge_sort_desc(ar, mid + 1, r);
  int idx_l = l, idx_r = mid + 1, idx = 0;
  int temp_ar[r - l + 1];

  while (idx_l <= mid && idx_r <= r)
  {
    temp_ar[idx++] = ar[idx_l] > ar[idx_r] ? ar[idx_l++] : ar[idx_r++];
  }

  while (idx_l <= mid)
  {
    temp_ar[idx++] = ar[idx_l++];
  }

  while (idx_r <= r)
  {
    temp_ar[idx++] = ar[idx_r++];
  }

  int idx_temp;
  for (idx_temp = 0; idx_temp < r - l + 1; idx_temp++)
  {
    ar[l + idx_temp] = temp_ar[idx_temp];
  }
}

void merge_sort_asc(int ar[], int length)
{
  __merge_sort_asc(ar, 0, length - 1);
}

void merge_sort_desc(int ar[], int length)
{
  __merge_sort_desc(ar, 0, length - 1);
}
#pragma endregion

#pragma region Quick Sort
/**
 * \brief (internal) Quick sort partition function
 *
 * Find first element as piviot and move all elements smaller than it to its
 *  left hand side. Then return the new pivot position index.
 * \param ar Array to sort
 * \param l Left range of current segment
 * \param r Right range of current segment
 */
int __qs_partition_asc(int ar[], int l, int r)
{
  int idx_pivot = l;
  int idx = idx_pivot + 1;
  int i = idx;
  while (i <= r)
  {
    if (ar[i] < ar[idx_pivot])
    {
      swap_array_elements(ar, i, idx++);
    }
    i++;
  }
  swap_array_elements(ar, idx_pivot, idx - 1);
  return idx - 1;
}

/**
 * \brief (internal) Quick sort using ascending order
 *
 * \param ar Array to sort
 * \param l Left range of current segment
 * \param r Right range of current segment
 */
void __quick_sort_asc(int ar[], int l, int r)
{
  if (l < r)
  {
    int idx_partition = __qs_partition_asc(ar, l, r);
    __quick_sort_asc(ar, l, idx_partition - 1);
    __quick_sort_asc(ar, idx_partition + 1, r);
  }
}

/**
 * \brief (internal) Quick sort partition function
 *
 * Find first element as piviot and move all elements greater than it to its
 *  left hand side. Then return the new pivot position index.
 * \param ar Array to sort
 * \param l Left range of current segment
 * \param r Right range of current segment
 */
int __qs_partition_desc(int ar[], int l, int r)
{
  int idx_pivot = l;
  int idx = idx_pivot + 1;
  int i = idx;
  while (i <= r)
  {
    if (ar[i] > ar[idx_pivot])
    {
      swap_array_elements(ar, i, idx++);
    }
    i++;
  }
  swap_array_elements(ar, idx_pivot, idx - 1);
  return idx - 1;
}

/**
 * \brief (internal) Quick sort using descending order
 *
 * \param ar Array to sort
 * \param l Left range of current segment
 * \param r Right range of current segment
 */
void __quick_sort_desc(int ar[], int l, int r)
{
  if (l < r)
  {
    int idx_partition = __qs_partition_desc(ar, l, r);
    __quick_sort_desc(ar, l, idx_partition - 1);
    __quick_sort_desc(ar, idx_partition + 1, r);
  }
}

void quick_sort_asc(int ar[], int length)
{
  __quick_sort_asc(ar, 0, length - 1);
}

void quick_sort_desc(int ar[], int length)
{
  __quick_sort_desc(ar, 0, length - 1);
}
#pragma endregion