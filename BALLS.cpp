
#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;

    public:
    Node():value(0), left(NULL), right(NULL)
    {
    }

    Node(int valuep, Node *leftp, Node *rightp):value(valuep), left(leftp), right(rightp){
    }
};

Node* init(int n){
    Node* head = new Node(0, NULL, NULL);
    Node* cur, *prev;
    prev = head;
    for (int i = 1; i <=n; i++){
        cur = new Node(i, prev, NULL);
        prev->right = cur;
        prev = cur;
    }
    cur = head;
    head = head->right;
    delete cur;
    return head;
}

void destroy(Node *head){
    Node *cur;
    while(head != NULL){
        cur = head;
        delete cur;
        head = head->right;
    }
}

Node* findval(Node* head, int val){
    while(head != NULL){
        if(head->value == val) return head;
        else head = head->right;
    }
    return head;
}

Node* operateA(Node* head, int val1, int val2){
    //create dummy nodes
    Node* newhead = new Node(-1, NULL, head);
    head->left = newhead;
    while(head->right != NULL) head=head->right;
    Node* newtail = new Node(-2, head, NULL);
    head->right = newtail;
    //remove node1
    Node * node1 = findval(newhead, val1);
    (node1->left)->right = node1->right;
    (node1->right)->left = node1->left;
    //insert before node2
    Node * node2 = findval(newhead, val2);
    node1->left = node2->left;
    node1->right = node2;
    (node2->left)->right = node1;
    node2->left = node1;

    //delete dummy node
    head = newhead->right;
    head->left=NULL;
    delete newhead;
    (newtail->left)->right = NULL;
    delete newtail;
    return head;
}

Node* operateB(Node* head, int val1, int val2){
    //create dummy nodes
    Node* newhead = new Node(-1, NULL, head);
    head->left = newhead;
    while(head->right != NULL) head=head->right;
    Node* newtail = new Node(-2, head, NULL);
    head->right = newtail;
    //remove node1
    Node * node1 = findval(newhead, val1);
    (node1->left)->right = node1->right;
    (node1->right)->left = node1->left;
    //insert after node2
    Node * node2 = findval(newhead, val2);
    node1->right = node2->right;
    node1->left = node2;
    (node2->right)->left = node1;
    node2->right = node1;

    //delete dummy node
    head = newhead->right;
    head->left=NULL;
    delete newhead;
    (newtail->left)->right = NULL;
    delete newtail;
    return head;
}
void print(Node *head){
    while(head != NULL){
        cout << head->value << " ";
        head = head->right;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    Node* head = init(n);
    char op;
    int a, b;
    for(int i = 0; i<m; i++){
        cin >> op >> a >> b;
        if(op == 'A')  head = operateA(head, a, b);
        else if(op == 'B') head = operateB(head, a, b);
    }
    print(head);
    cout << endl;
    destroy(head);
}
