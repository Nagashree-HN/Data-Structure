#include <iostream>
#include <string>
using namespace std;

// ===================== Node Definition =====================

struct node {
    int item;
    node *l, *r;
    node(int x) { item = x; l = 0; r = 0; }
};
typedef node* link;


// ===================== QUEUE (Linked List Version) =====================

template <class Item>
class QUEUE {
private:
    struct qnode {
        Item item;
        qnode* next;
        qnode(Item x) { item = x; next = 0; }
    };
    typedef qnode* linkq;

    linkq head, tail;

public:
    QUEUE(int) { head = 0; tail = 0; }

    int empty() const { return head == 0; }

    void put(Item x) {
        linkq t = tail;
        tail = new qnode(x);
        if (head == 0)
            head = tail;
        else
            t->next = tail;
    }

    Item get() {
        Item v = head->item;
        linkq t = head->next;
        delete head;
        head = t;
        return v;
    }
};


// ===================== Helper: Find Node by Item =====================
// Manual DFS search (recursively)

link findNode(link h, int x) {
    if (h == 0) return 0;
    if (h->item == x) return h;

    link left = findNode(h->l, x);
    if (left) return left;

    return findNode(h->r, x);
}


// ===================== Level Order Traversal Printing =====================

void printLevelOrder(link root) {
    if (root == 0) return;

    QUEUE<link> q(1000);
    q.put(root);

    while (!q.empty()) {
        link h = q.get();
        cout << h->item << " ";

        if (h->l != 0) q.put(h->l);
        if (h->r != 0) q.put(h->r);
    }
}


// ===================== Main Program =====================

int main() {
    link root = 0;

    string cmd;
    while (cin >> cmd) {

        if (cmd == "C") {                    // Create root
            int r;
            cin >> r;
            cout << "C " << r << endl;

            if (root != 0) {
                cout << "Error: Tree is not empty" << endl;
            } else {
                root = new node(r);
                cout << "Root node with item " << r << " has been created" << endl;
            }
        }

        else if (cmd == "L") {               // Add left child
            int p, l;
            cin >> p >> l;
            cout << "L " << p << " " << l << endl;

            link u = findNode(root, p);
            if (u == 0) {
                cout << "Error: Node " << p << " not found" << endl;
            }
            else if (u->l != 0) {
                cout << "Error: Left child already exists" << endl;
            }
            else {
                u->l = new node(l);
                cout << "Node with item " << l << " has been added" << endl;
            }
        }

        else if (cmd == "R") {               // Add right child
            int p, r;
            cin >> p >> r;
            cout << "R " << p << " " << r << endl;

            link u = findNode(root, p);
            if (u == 0) {
                cout << "Error: Node " << p << " not found" << endl;
            }
            else if (u->r != 0) {
                cout << "Error: Right child already exists" << endl;
            }
            else {
                u->r = new node(r);
                cout << "Node with item " << r << " has been added" << endl;
            }
        }

        else if (cmd == "P") {                // Print full tree
            cout << "P" << endl;
            cout << "level order traversal of the entire tree: ";
            printLevelOrder(root);
            cout << endl;
        }

        else if (cmd == "S") {                // Print subtree
            int p;
            cin >> p;
            cout << "S " << p << endl;

            link u = findNode(root, p);
            if (u == 0) {
                cout << "Error: Node " << p << " not found" << endl;
            } else {
                cout << "level order traversal of the asked subtree: ";
                printLevelOrder(u);
                cout << endl;
            }
        }
    }

    return 0;
}