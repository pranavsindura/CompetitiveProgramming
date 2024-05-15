#include <assert.h>
#include <iostream>
#include <vector>
using namespace std;

class Heap {
  vector<int> heap;

  int compare_and_swap_with_children(int node, int max_len) {
    int left = 2 * (node + 1) - 1;
    int right = 2 * (node + 1);
    int largest = node;

    if (left < max_len && heap[left] > heap[largest]) {
      largest = left;
    }

    if (right < max_len && heap[right] > heap[largest]) {
      largest = right;
    }

    if (largest != node) {
      swap(heap[largest], heap[node]);
      return largest;
    }

    return -1;
  }

public:
  void insert(int x) {
    heap.push_back(x);
    // need to compare and swap from bottom to top
    int k = heap.size() - 1;
    while (true) {
      int parent = (k + 1) / 2 - 1;
      if (parent < 0) {
        break;
      }
      k = compare_and_swap_with_children(parent, heap.size());
      if (k != -1) {
        k = parent;
      } else {
        break;
      }
    }
  }

  int pop() {
    int top = heap.front();
    swap(heap.front(), heap.back());
    heap.pop_back();
    int k = 0;
    while (true) {
      k = compare_and_swap_with_children(k, heap.size());
      if (k == -1) {
        break;
      }
    }

    return top;
  }

  int top() { return heap.front(); }

  bool isEmpty() { return heap.empty(); }
};

int main() {
  /*
    1 x - Push
    2 - Pop
    3 - Top
    4 - Exit
  */
  Heap h;
  int t;
  while (true) {
    cin >> t;
    switch (t) {
    case 1: {
      int x;
      cin >> x;
      h.insert(x);
      break;
    }
    case 2: {
      if (h.isEmpty()) {
        cout << "Heap is empty!" << endl;
        break;
      }
      int top = h.pop();
      cout << "Popped " << top << endl;
      break;
    }
    case 3: {
      if (h.isEmpty()) {
        cout << "Heap is empty!" << endl;
        break;
      }
      int top = h.top();
      cout << "Top is " << top << endl;
      break;
    }
    case 4:
      return 0;
    default:
      break;
    }
  }
}

/*
1 23
1 21
1 -14
1 324
3
2
2
3
1 2
1 90
1 229
2
2
2
2
2
4
*/
