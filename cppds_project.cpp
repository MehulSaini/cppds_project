#include <iostream>
#include <string>
#include <list>
using namespace std;

// Define a structure for a node in the linked list
struct Node {
    string data;
    Node* next;
};

// Function to insert a node at the end of the linked list
void insert(Node*& head, string value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to sort the linked list in alphabetical order
void sortLinkedList(Node*& head) {
    list<string> sortedList;

    Node* current = head;
    while (current) {
        sortedList.push_back(current->data);
        current = current->next;
    }

    sortedList.sort();

    current = head;
    for (const string& s : sortedList) {
        current->data = s;
        current = current->next;
    }
}

// Function to report repeated words in the linked list
void reportRepeatedWords(Node* head) {
    if (!head) {
        cout << "No words in the list." << endl;
        return;
    }

    list<string> uniqueWords;
    list<string> repeatedWords;

    Node* current = head;
    while (current) {
        if (uniqueWords.empty() || uniqueWords.back() != current->data) {
            uniqueWords.push_back(current->data);
        } else {
            repeatedWords.push_back(current->data);
        }
        current = current->next;
    }

    cout << "Repeated words: ";
    for (const string& word : repeatedWords) {
        cout << word << " ";
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n;
    cout << "Enter the number of words: ";
    cin >> n;

    cout << "Enter " << n << " words:" << endl;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        insert(head, word);
    }

    sortLinkedList(head);
    cout << "Sorted list of words:" << endl;

    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    reportRepeatedWords(head);

    // Clean up memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

//Mehul Saini 22070123065
