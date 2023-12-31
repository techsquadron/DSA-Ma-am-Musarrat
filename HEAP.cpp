#include <iostream>
using namespace std;

struct Student {
    struct Student* left;
    int Student_Id;
    struct Student* right;
    struct Student* parent;
} *root = NULL;

// Queue structure
struct node {
    Student* t;
    node* link;
};
node* rear, *front;

// Swap function used at insertion
void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Enqueue a student pointer to the queue
void enqueue(Student* seat) {
    if (rear == NULL) {
        front = rear = new node;
        rear->t = seat;
        rear->link = NULL;
    } else {
        rear->link = new node;
        rear = rear->link;
        rear->t = seat;
        rear->link = NULL;
    }
}

// Dequeue a student pointer from the queue
Student* dequeue() {
    if (front == NULL) {
        cout << "Queue is empty" << endl;
        return NULL;
    }

    Student* seat = front->t;
    node* tempNode = front;
    front = front->link;

    if (front == NULL) {
        rear = NULL;
    }

    delete tempNode;
    return seat;
}

// Maintain the Min Heap property by swapping with parents if necessary
void heapifyUp(Student* node) {
    while (node->parent != NULL && node->Student_Id < node->parent->Student_Id) {
        Swap(node->Student_Id, node->parent->Student_Id);
        node = node->parent;
    }
}

// Insertion in heap with level order
void insert(int ID) {
    struct Student* tmp = new Student;
    tmp->Student_Id = ID;
    tmp->left = tmp->right = tmp->parent = NULL;

    if (root == NULL) {
        root = tmp;
        enqueue(root);
    } else {
        while (front != NULL) {
            struct Student* p = dequeue();

            if (p->left == NULL) {
                p->left = tmp;
                tmp->parent = p;
                heapifyUp(tmp);  // Corrected: Maintain Min Heap property after insertion
				enqueue(p->left);
                
                return;
            } else if (p->right == NULL) {
                p->right = tmp;
                tmp->parent = p;
                heapifyUp(tmp);  // Corrected: Maintain Min Heap property after insertion
                enqueue(p->right);
                return;
            } else {
                // Enqueue the left and right children for further insertion
                enqueue(p->left);
                enqueue(p->right);
            }
        }
    }
}

void printMinHeap(Student* root) {
    if (root != NULL) {
        cout << root->Student_Id << " ";
        printMinHeap(root->left);
        printMinHeap(root->right);
    }
}


int main() {
    // Example usage
    insert(101);
    insert(95);
    insert(75);
    insert(120);
    insert(85);
    insert(110);

    // Print the Min Heap
    cout << "Min Heap tree: ";
    printMinHeap(root);
    cout << endl;
    
    cout<<"min heap on root"<<endl;
    cout<<root->Student_Id<<endl;
    

    return 0;
}