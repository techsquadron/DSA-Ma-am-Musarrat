#include <iostream>
using namespace std;

struct node {
    int info;
    node *link;
};

node *start = NULL;

void create_list(int data){
    struct node* q, *tmp;
    tmp = new (struct node);
    tmp->info = data;
    tmp->link = NULL;

    if (start == NULL){
        start = tmp;
    }

    else{
        q = start;
        while (q->link != NULL){
            q = q->link;
        }
        q->link = tmp;
    }
}

void del(int data){
    struct node* tmp, *q;
    if (start->info == data){
        tmp = start;
        start = start->link;
        delete (tmp);
        return;
    }
    q = start;
    while (q->link->link != NULL){
        if (q->link->info == data){
            tmp = q->link;
            q->link = tmp->link;
            delete(tmp);
            return;
        }
        q = q->link;
    }
    if (q->link->info == data){
        tmp = q->link;
        delete(tmp);
        q->link = NULL;
        return;
    }
    cout << "Element " << data << " not found" << endl;
}

void display() {
    struct node* q;
    if (start == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    q = start;
    cout << "List is:" << endl;
    while (q != NULL) {
        cout << q->info << " ->  ";
        q = q->link;
    }
    cout << "NULL" << endl;
}

void customSwap(node **a, node **b) {
    node *tmp = *a;
    *a = *b;
    *b = tmp;
}

void siftDown(node **arr, int rootIdx, int end) {
    int root = rootIdx;
    while ((root * 2 + 1) <= end) {
        int child = root * 2 + 1;
        int customSwapIdx = root;
        if (arr[customSwapIdx]->info < arr[child]->info) {
            customSwapIdx = child;
        }
        if (child + 1 <= end && arr[customSwapIdx]->info < arr[child + 1]->info) {
            customSwapIdx = child + 1;
        }
        if (customSwapIdx != root) {
            customSwap(&arr[root], &arr[customSwapIdx]);
            root = customSwapIdx;
        } else {
            return;
        }
    }
}

node** listToArray(node *startNode, int length) {
    node **arr = new node*[length];
    node *current = startNode;
    for (int i = 0; i < length; ++i) {
        arr[i] = current;
        current = current->link;
    }
    return arr;
}

void smoothSort(node **startNode) {
    int length = 0;
    node *current = *startNode;
    while (current != NULL) {
        length++;
        current = current->link;
    }

    node **arr = listToArray(*startNode, length);

    for (int rootIdx = (length - 2) / 2; rootIdx >= 0; --rootIdx) {
        siftDown(arr, rootIdx, length - 1);
    }

    for (int end = length - 1; end > 0; end--) {
        customSwap(&arr[end], &arr[0]);
        siftDown(arr, 0, end - 1);
    }

    *startNode = arr[0];
    for (int i = 0; i < length - 1; i++) {
        arr[i]->link = arr[i + 1];
    }
    arr[length - 1]->link = NULL;

    delete[] arr;
}

int main() {
    int choice, n, m, i;

    while (1) {
        cout << "1. Create List" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Smooth Sort" << endl;
        cout << "4. Display" << endl;
        cout << "5. Quit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "How many nodes you want to add? ";
                cin >> n;
                for (i = 0; i < n; i++) {
                    cout << "Enter the element " << i << " :";
                    cin >> m;
                    create_list(m);
                }
                break;
            }
            case 2: {
                if (start == NULL) {
                    cout << "List is empty" << endl;
                    continue;
                }
                cout << "Enter the element for deletion: ";
                cin >> m;
                del(m);
                break;
            }
            case 3:
                smoothSort(&start);
                cout << "Sorted List" << endl;
                break;
            case 4:
                display();
                break;
            case 5:
                exit(1);
            default:
                cout << "Wrong choice" << endl;
        }
    }
    return 0;
}
