#include <iostream>
#include <string>
#include <vector>

#include <loxo.hpp>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {

  for (int i = 0; i < nums.size(); i++) {
    for (int j = 1 + 1; j < nums.size(); j++) {
      if ((nums[i] + nums[j]) == target) {
        return {i, j};
      }
    }
  }
}
void twoSumTest() {
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  vector<int> ans = twoSum(nums, target);

  for (auto i : ans) {
    cout << i << '\n';
  }
}

// You are given two non-empty linked lists representing two non-negative
// integers. The digits are stored in reverse order and each of their nodes
// contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the
// number 0 itself.

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.

// 1
// ---
// 342
// 485
// ---
// 827

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
  //  ListNode(int v): val(v){}
  //  ListNode(int v, ListNode *l): val(v), next(l) {}
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// FUCKING DONE !!!!
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

  ListNode s(0);
  ListNode d(0);
  ListNode *r;
  r = &s;

  int rem = 0;
  int res = 0;

  while (true) {

    if (l1 == NULL && l2 == NULL) {
      if (rem > 0) {
        r->next = new ListNode(rem);
      }
      break;
    }

    if (l1 == NULL) {
      l1 = &d;
    }

    if (l2 == NULL) {
      l2 = &d;
    }

    res = l1->val + l2->val + rem;
    rem = res / 10;
    r->next = new ListNode(res % 10);

    l1 = l1->next;
    l2 = l2->next;
    r = r->next;
  }
  return s.next;
}

void addTwoNumbersTest() {
  // (2 -> 4 -> 3) + (5 -> 6 -> 4)
  ListNode l1(2);
  ListNode l2(4);
  ListNode l3(3);

  // l1.next = &l2;
  // l2.next = &l3;

  ListNode n1(5);
  ListNode n2(6);
  ListNode n3(4);

  // n1.next = &n2;
  // n2.next = &n3;

  ListNode *ln = addTwoNumbers(&n1, &n1);

  // ListNode *ln = &l1;

  while (ln != NULL) {
    cout << ln->val;
    ln = ln->next;
  }
}

int main() {

  int foo = 42;

  lxo::DBP(foo);
  lxo::DBP("Hello debug");

//  addTwoNumbersTest();

  return 0;
}
