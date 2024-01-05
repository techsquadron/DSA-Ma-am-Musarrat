#include <graphics.h>
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

struct node {
    char info;
    node *link;
} *start = NULL;

void intro(){
    cout << "Intro of Smooth Sort:\n" <<
    "Smooth Sort is an adaptive sorting algorithm developed by Edsger Dijkstra. " <<
    "It is a variation of heap sort that combines the advantages of both heap sort and insertion sort. " <<
    "Unlike standard heap sort, it attempts to take advantage of existing order in the elements. " <<
    "The algorithm classifies the input into a sequence of sorted 'sub-heaps', leading to reduced sorting time for partially sorted data.\n";
}

void advDisadv(){
    cout << "Advantages of Smooth Sort:\n" <<
    "1. Adaptive: Efficient for data that is already partially sorted.\n" <<
    "2. In-place: Requires no extra space for sorting.\n" <<
    "3. Not prone to worst-case scenarios like quicksort.\n" <<
    "4. Can be faster than traditional heap sort in practical scenarios.\n" <<
    "5. Maintains a relatively balanced heap, minimizing heap operations.\n\n" <<
    "Disadvantages of Smooth Sort:\n" <<
    "1. Complex implementation compared to other sorting algorithms.\n" <<
    "2. Not as fast as quicksort on average.\n" <<
    "3. Less effective on completely random data sets.\n" <<
    "4. Can be slower than other O(n log n) algorithms for certain data patterns.\n" <<
    "5. The advantage of being adaptive is not significant for small arrays.\n";
}

void Quiz() {
    const int NUM_QUESTIONS = 20;
    string questions[NUM_QUESTIONS] = {
        "Question 1: What is the main characteristic of Smooth Sort? (A) Adaptive (B) Non-Adaptive (C) Slow (D) Unstable",
        "Question 2: What is Smooth Sort primarily known for? (A) Speed (B) Memory efficiency (C) Adaptive sorting (D) Parallel processing",
        "Question 3: Who developed Smooth Sort? (A) Donald Knuth (B) Edsger Dijkstra (C) John von Neumann (D) Alan Turing",
        "Question 4: What is the worst-case time complexity of Smooth Sort? (A) O(n) (B) O(n log n) (C) O(n^2) (D) O(log n)",
        "Question 5: Smooth Sort is particularly efficient when dealing with: (A) Large datasets (B) Partially sorted data (C) Reverse ordered data (D) Small datasets",
        "Question 6: In the provided code, what data structure is primarily used? (A) Array (B) Linked list (C) Binary tree (D) Stack",
        "Question 7: What is the role of the `createList` function in the code? (A) Sorts the list (B) Searches for an element (C) Inserts a new element (D) Deletes an element",
        "Question 8: The `heapify` function in the code is used for: (A) Finding the maximum element (B) Heapifying a subtree (C) Splitting the list (D) Merging two lists",
        "Question 9: What does the `customSwap` function do in the code? (A) Swaps two elements in an array (B) Swaps two nodes in a linked list (C) Changes the value of a node (D) Reverses the linked list",
        "Question 10: In the `Sort` function, what is the purpose of the for loop that starts with `for (int rootIdx = (length - 2) / 2; rootIdx >= 0; --rootIdx)`? (A) To create a max heap (B) To sort the linked list (C) To reverse the linked list (D) To find the middle of the list",
        "Question 11: What does 'in-place' sorting mean in the context of Smooth Sort? (A) Uses additional memory (B) Does not use additional memory (C) Sorts remotely (D) Requires a helper array",
        "Question 12: Which of these is a disadvantage of Smooth Sort? (A) Fast (B) Memory Efficient (C) Complex implementation (D) Stable",
        "Question 13: In the provided code, what is the purpose of the 'Sort' function? (A) Inserting an element (B) Deleting an element (C) Sorting the list (D) Creating a list",
        "Question 14: How is a 'heap' primarily used in Smooth Sort? (A) For memory allocation (B) As a data structure (C) For parallel computation (D) For network management",
        "Question 15: What type of sorting algorithm is Smooth Sort? (A) Adaptive (B) Non-Adaptive (C) Bubble Sort (D) Quick Sort",
        "Question 16: Which other sorting algorithm is Smooth Sort most similar to? (A) Merge Sort (B) Quick Sort (C) Heap Sort (D) Bubble Sort",
        "Question 17: What is a key advantage of Smooth Sort over Quick Sort? (A) Uses less memory (B) Better worst-case performance (C) Faster average performance (D) Easier to implement",
        "Question 18: In the context of sorting algorithms, what does 'adaptive' mean? (A) Uses more memory (B) Adjusts to the initial order of elements (C) Requires additional sorting passes (D) Only sorts integers",
        "Question 19: What is a primary use case for Smooth Sort? (A) Sorting linked lists (B) Sorting very large arrays (C) Database record sorting (D) Real-time data processing",
        "Question 20: What is the time complexity of Smooth Sort in the best case scenario? (A) O(n log n) (B) O(n^2) (C) O(n) (D) O(log n)"
    };

    char answers[NUM_QUESTIONS] = {'A', 'C', 'B', 'B', 'B', 'B', 'C', 'B', 'B', 'A', 'B', 'C', 'C', 'B', 'A', 'C', 'B', 'B', 'A', 'C'};
    char userAnswer;
    int score = 0;

    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        cout << questions[i] << endl;
        cout << "Answer: ";
        cin >> userAnswer;

        if (toupper(userAnswer) == answers[i]) {
            score++;
            cout << "Correct!\n";
        } else {
            cout << "Incorrect. The correct answer was " << answers[i] << ".\n";
        }
    }

    cout << "Quiz completed. Your score: " << score << "/" << NUM_QUESTIONS << endl;
}

void createList(char data) {
    node *q, *tmp;
    tmp = new node;
    tmp->info = data;
    tmp->link = NULL;

    if (start == NULL) {
        start = tmp;
    } else {
        q = start;
        while (q->link != NULL) {
            q = q->link;
        }
        q->link = tmp;
    }
}

void del(char data) {
    node *tmp, *q;
    if (start == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    if (start->info == data) {
        tmp = start;
        start = start->link;
        delete tmp;
        return;
    }
    q = start;
    while (q->link != NULL) {
        if (q->link->info == data) {
            tmp = q->link;
            q->link = tmp->link;
            delete tmp;
            return;
        }
        q = q->link;
    }
    cout << "Element " << data << " not found" << endl;
}

void customSwap(node **a, node **b) {
    node *tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(node **arr, int rootIdx, int end) {
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

void Sort(node **startNode) {
    int length = 0;
    node *current = *startNode;
    while (current != NULL) {
        length++;
        current = current->link;
    }

    node **arr = listToArray(*startNode, length);

    for (int rootIdx = (length - 2) / 2; rootIdx >= 0; --rootIdx) {
        heapify(arr, rootIdx, length - 1);
    }

    for (int end = length - 1; end > 0; end--) {
        customSwap(&arr[end], &arr[0]);
        heapify(arr, 0, end - 1);
    }

    *startNode = arr[0];
    for (int i = 0; i < length - 1; i++) {
        arr[i]->link = arr[i + 1];
    }
    arr[length - 1]->link = NULL;

    delete[] arr;
}

void display(node *start) {
    int x = 150, y = 10, gap = 50;
    node *p = start;

    while (p != NULL) {
        char charStr[2] = {p->info, '\0'};
        setcolor(WHITE);
        circle(x, y, 20);
        setfillstyle(SOLID_FILL, WHITE);
        floodfill(x, y, WHITE);
        setcolor(BLACK);
        outtextxy(x - 7, y - 7, charStr);
        if (p->link != NULL) {
            line(x + 20, y, x + gap - 20, y);
        }
        x = x + gap;
        p = p->link;
    }
}

void hold() {
    while (!kbhit()) {
        delay(500);
    }
}

void insertElement() {
    char element;
    cout << "Enter the element to insert: ";
    cin >> element;
    createList(element);
}

void deleteElement() {
    char element;
    cout << "Enter the element to delete: ";
    cin >> element;
    del(element);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    setbkcolor(WHITE);
    cleardevice();

    setcolor(BLACK);
    rectangle(50, 350, 150, 390);
    outtextxy(60, 360, "Intro");
    rectangle(160, 350, 260, 390);
    outtextxy(170, 360, "Adv/Disadv");
    rectangle(270, 350, 370, 390);
    outtextxy(280, 360, "Quiz");
    rectangle(380, 350, 480, 390);
    outtextxy(390, 360, "Insert");
    rectangle(50, 400, 150, 440);
    outtextxy(60, 410, "Delete");
    rectangle(160, 400, 260, 440);
    outtextxy(170, 410, "Sort");
    rectangle(270, 400, 370, 440);
    outtextxy(280, 410, "Exit");

    int x, y;
    bool exit = false;
    while (!exit) {
	    if (ismouseclick(WM_LBUTTONDOWN)) {
	        getmouseclick(WM_LBUTTONDOWN, x, y);
	
	        if (x > 50 && x < 150 && y > 350 && y < 390) {
	            intro();
	        } else if (x > 160 && x < 260 && y > 350 && y < 390) {
	            advDisadv();
	        } else if (x > 270 && x < 370 && y > 350 && y < 390) {
	            Quiz();
	        } else if (x > 380 && x < 480 && y > 350 && y < 390) {
	            clearmouseclick(WM_LBUTTONDOWN);
	            insertElement();
	            cleardevice();
	            setcolor(BLACK);
	            rectangle(380, 350, 480, 390);
    			outtextxy(390, 360, "Insert");
    			rectangle(50, 400, 150, 440);
    			outtextxy(60, 410, "Delete");
    			rectangle(160, 400, 260, 440);
    			outtextxy(170, 410, "Sort");
    			rectangle(270, 400, 370, 440);
    			outtextxy(280, 410, "Exit");
	            display(start);
	        } else if (x > 50 && x < 150 && y > 400 && y < 440) {
	            clearmouseclick(WM_LBUTTONDOWN);
	            deleteElement();
	            cleardevice();
	            setcolor(BLACK);
	            rectangle(380, 350, 480, 390);
    			outtextxy(390, 360, "Insert");
    			rectangle(50, 400, 150, 440);
    			outtextxy(60, 410, "Delete");
    			rectangle(160, 400, 260, 440);
    			outtextxy(170, 410, "Sort");
    			rectangle(270, 400, 370, 440);
    			outtextxy(280, 410, "Exit");
	            display(start);
	        } else if (x > 160 && x < 260 && y > 400 && y < 440) {
	            clearmouseclick(WM_LBUTTONDOWN);
	            cleardevice();
	            Sort(&start);
	            setcolor(BLACK);
	            rectangle(380, 350, 480, 390);
    			outtextxy(390, 360, "Insert");
    			rectangle(50, 400, 150, 440);
    			outtextxy(60, 410, "Delete");
    			rectangle(160, 400, 260, 440);
    			outtextxy(170, 410, "Sort");
    			rectangle(270, 400, 370, 440);
    			outtextxy(280, 410, "Exit");
	            display(start);
	        } else if (x > 270 && x < 370 && y > 400 && y < 440) {
	            exit = true;
	        }
	    }
	}
    closegraph();
    return 0;
}