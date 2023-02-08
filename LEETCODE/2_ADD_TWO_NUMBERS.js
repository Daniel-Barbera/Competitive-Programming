/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    solutionList = new SolutionList(0);
    iterator = solutionList;
    carry = 0; aux = 0;

    while (l1 || l2 || carry) {
        firstNum = l1?.val ?? 0;
        secondNum = l2?.val ?? 0; 
        aux = firstNum + secondNum + carry; 
        carry = aux / 10 >> 0
        iterator.val = aux % 10;
        l1 = l1?.next; l2 = l2?.next;
        if (carry !== 0 || l1 || l2) {
            iterator.next = new SolutionList(carry);
            iterator = iterator.next;
        }
    }
    return solutionList;
};

class SolutionList {
  constructor(val=0, next=undefined) {
      this.val = val ?? 0;
      this.next = next ?? null; 
  }
};