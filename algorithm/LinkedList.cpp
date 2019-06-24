#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

void printList(Node *n) {
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << "\n";
}

void push(Node **head_ref, int new_data) {
    Node *new_node = new Node;
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insertAfter(Node *prev, int new_data) {
    if (prev == NULL) return;

    Node *new_node = new Node;
    new_node->data = new_data;
    new_node->next = prev->next;
    prev->next = new_node;
}

void append(Node **head_ref, int new_data) {
    Node *new_node = new Node;
    Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

void deleteNodeByKey(Node **head_ref, int key) {
    Node *tmp = *head_ref;

    if (tmp != NULL && tmp->data == key) {
        *head_ref = tmp->next;
        return;
    }

    Node *prev;
    while (tmp != NULL && tmp->data != key) {
        prev = tmp;
        tmp = tmp->next;
    }

    if (tmp == NULL) return;

    prev->next = tmp->next;
}

void deleteNodeByPosition(Node **head_ref, int pos) {
    if (*head_ref == NULL) return;

    Node *tmp = *head_ref;

    if (pos == 0) {
        *head_ref = tmp->next;
        return;
    }

    for (int i = 1; tmp != NULL && i < pos; i++) {
        tmp = tmp->next;
    }

    if (tmp == NULL) return;
    if (tmp->next == NULL) return;

    Node *nxt = tmp->next->next;
    tmp->next = nxt;
}

int getCount(Node *head) {
    int count = 0;
    Node *cur = head;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;
}

int getCountRecursive(Node *head) {
    if (head == NULL) return 0;
    return 1 + getCountRecursive(head->next);
}

bool search(Node *head, int key) {
    Node *cur = head;
    while (cur != NULL) {
        if (cur->data == key) return true;
        cur = cur->next;
    }
    return false;
}

bool searchRecursive(Node *head, int key) {
    if (head == NULL) return false;
    if (head->data == key) return true;
    return search(head->next, key);
}

int getNth(Node *head, int index) {
    Node *cur = head;
    int count = 0;
    while (cur != NULL) {
        if (count == index) return cur->data;
        count++;
        cur = cur->next;
    }
    assert(0);
}

int getNthRecursive(Node *head, int index) {
    if (index == 0) return head->data;
    return getNthRecursive(head->next, index - 1);
}

bool detectLoopByHash(Node *node) {
    unordered_set <Node *> s;
    while (node != NULL) {
        if (s.find(node) != s.end()) return true;
        s.insert(node);
        node = node->next;
    }
    return false;
}

bool detectLoopByFloyd(Node *node) {
    Node *slow = node, *fast = node;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

bool detectLoopByMarking(Node *head) {
    Node *tmp = new Node;
    while (head != NULL) {
        if (head->next == NULL) return false;
        if (head->next == tmp) return true;
        Node *nxt = head->next;
        head->next = tmp;
        head = nxt;
    }
    return false;
}

int countLoopNodes(Node *node) {
    Node *slow = node, *fast = node;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            int count = 1;
            while (slow->next != fast) {
                count++;
                slow = slow->next;
            }
            return count;
        }
    }
    return 0;
}

void loopTest() {
    Node *head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
    head->next->next->next->next = head;

    if (detectLoopByHash(head)) {
        cout << "loop found by Hash\n";
    }

    if (detectLoopByFloyd(head)) {
        cout << "loop found by Floyd's Algorithm\n";
        cout << "loop count = " << countLoopNodes(head) << "\n";
    }

    if (detectLoopByMarking(head)) {
        cout << "loop found by Marking\n";
    }
}

int main() {
    Node *head = NULL;
    append(&head, 6);
    push(&head, 7);
    push(&head, 1);
    append(&head, 4);
    insertAfter(head->next, 8);
    printList(head);

    cout << "count = " << getCount(head) << '\n';
    cout << "count = " << getCountRecursive(head) << '\n';

    cout << "4 is " << (search(head, 4) ? "" : "not ") << "present" << '\n';
    cout << "5 is " << (searchRecursive(head, 5) ? "" : "not ") << "present" << '\n';

    deleteNodeByKey(&head, 8);
    printList(head);

    deleteNodeByPosition(&head, 1);
    printList(head);

    cout << getNth(head, 1) << "\n";
    cout << getNthRecursive(head, 1) << "\n";

    loopTest();

    return 0;
}