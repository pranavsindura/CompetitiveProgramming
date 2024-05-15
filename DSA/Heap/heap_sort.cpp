#include <iostream>
#include <vector>
using namespace std;

int compare_and_swap_node_with_children(vector<int> &arr, int node,
                                        int max_len) {
  int left_child = 2 * (node + 1) - 1;
  int right_child = 2 * (node + 1) + 1 - 1;
  int largest = node;
  if (left_child < max_len && arr[left_child] > arr[largest]) {
    largest = left_child;
  }

  if (right_child < max_len && arr[right_child] > arr[largest]) {
    largest = right_child;
  }

  if (largest != node) {
    swap(arr[largest], arr[node]);
    return largest;
  }

  return -1;
}

void heap_sort(vector<int> &arr) {
  // convert the array into a max heap
  int n = arr.size();
  // swap from bottom to top, each node
  for (int i = n - 1; i >= 0; i--) {
    compare_and_swap_node_with_children(arr, i, n);
  }

  // now pop from heap and keep at the end
  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]); // put largest element at the end of current heap
    // swap starting from the top, but only if swap occurs
    // then swap in the swapped subtree, until swaps can be made
    int k = 0;
    while (true) {
      k = compare_and_swap_node_with_children(arr, k, i);
      if (k == -1) {
        break;
      }
    }
  }
}

int main() {
  vector<int> arr = {23, 21, -14, 324, 2, 90, 229};
  heap_sort(arr);
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
