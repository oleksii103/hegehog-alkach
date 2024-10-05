#include <iostream>

using namespace std;

template <typename T>
class linkedList {
private:
    struct Node {
        T elem;
        Node* next;

        Node(T value, Node* nextNode = nullptr) : elem(value), next(nextNode) {}
    };

    Node* first;

    bool checkIndex(int index) {
        return index >= 0;
    }

public:
    linkedList() {
        first = nullptr;
    }

    void add(T value, int index) {
        if (checkIndex(index)) {
            if (index == 0) {
                first = new Node(value, first);
            }
            else {
                Node* temp = first;
                int currentIndex = 0;

                while (temp != nullptr && currentIndex < index - 1) {
                    temp = temp->next;
                    currentIndex++;
                }

                if (temp != nullptr) {
                    temp->next = new Node(value, temp->next);
                }
                else {
                    cout << "Індекс за межами списку" << endl;
                }
            }
        }
        else {
            cout << "incorrect" << endl;
        }
    }

    void showList() {
        Node* curr = first;
        while (curr != nullptr) {
            cout << curr->elem << endl;
            curr = curr->next;
        }
    }

    ~linkedList() {
        Node* curr = first;
        while (curr != nullptr) {
            Node* toDelete = curr;
            curr = curr->next;
            delete toDelete;
        }
    }
};

int main() {
    setlocale(LC_ALL, "ukr");
    linkedList<int> list1;
    list1.add(1, 0);
    list1.add(6, 1);
    list1.add(3, 1);
    list1.add(5, 2);

    list1.showList();

    return 0;
}
