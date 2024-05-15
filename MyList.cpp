//#include <iostream>
//using namespace std;
//
//template<typename T>
//class MyForList {
//private:
//	int size = 0;
//
//	class Node {
//	public:
//		T elem;
//		Node* next;
//		Node(const T& value) :elem(value), next(nullptr) {};
//	};
//	Node* head;
//public:
//	MyForList() :head(nullptr) {};
//	MyForList(const MyForList& otherlist) {
//		if (otherlist.empty())return;
//		Node* ocur = otherlist.head;
//		this->push_back(ocur->elem);
//		for (; ocur->next != nullptr;) {
//			ocur = ocur->next;
//			this->push_back(ocur->elem);
//		}
//		this->push_back(ocur->elem);
//	}
//	void push_front(const T& value) {
//		Node* newNode = new Node(value);
//		newNode->next = head;
//		head = newNode;
//		size--;
//	}
//	bool empty() const {
//		return head == nullptr;
//	}
//	void pop_front() {
//		if (empty()) throw out_of_range("Пусто, прямо как в твоей голове...");
//		Node* buf = this->head->next;
//		delete this->head;
//		this->head = buf;
//		size--;
//	}
//	void show() {
//		Node* cur = head;
//		if (empty()) throw out_of_range("Пусто, прямо как в твоей голове...");
//		for (; cur->next != nullptr;) {
//			cout << cur->elem << " ";
//			cur = cur->next;
//		}
//		cout << cur->elem << endl;
//	}
//	void push_back(const T& value) {
//		if (empty()) {
//			head = new Node(value);
//			return;
//		}
//		Node* cur = head;
//		for (; cur->next != nullptr;) {
//			cur = cur->next;
//		}
//		cur->next = newNode(value);
//		size++;
//	}
//	void pop_back() {
//		if (empty()) throw out_of_range("Пусто, прямо как в твоей голове...");
//		Node* cur = head;
//		for (; cur->next->next != nullptr;)cur = cur->next;
//		delete cur->next;
//		cur->next = nullptr;
//		size--;
//	}
//	/*void indInsert(int index) {
//		if (empty()) throw out_of_range("Пусто, прямо как в твоей голове...");
//		Node* cur = head;
//		for (; cur->next->next != nullptr;)cur = cur->next;
//	}*/
//	void insert_after(int index, const T& value) {
//		if (empty() || index < 0) throw out_of_range("Пусто, прямо как в твоей голове...");
//		Node* cur = head;
//		for (int i = 0; i < index; i++)
//		{
//			if (cur->next == nullptr)throw out_of_range("Пусто, прямо как в твоей голове...");
//			cur = cur->next;
//		}
//		Node* buf = cur->next;
//		cur->next = new Node(value);
//		cur->next->next = buf;
//	}
//	void emplace(int index, T& value) {
//		if (empty() || index < 0) throw out_of_range("Пусто, прямо как в твоей голове...");
//		Node* cur = head;
//		for (int i = 0; i < index; i++)
//		{
//			if (cur->next == nullptr)throw out_of_range("Пусто, прямо как в твоей голове...");
//		}
//		cur->elem = value;
//	}
//	void clear() {
//		if (empty())return;
//		Node* cur = head;
//		Node* buf = cur->next;
//		for (; cur->next != nullptr;) {
//			delete cur;
//			cur = buf;
//			buf = buf->next;
//		}
//		head = nullptr;
//	}
//	T& front() {
//		return head->elem;
//	}
//	bool operator ==(const MyForList& otherlist) {
//		Node* cur = this->head;
//		Node* ocur = otherlist->head;
//		for (; true;) {
//			if ((cur == nullptr && ocur != nullptr) ||
//				(cur != nullptr && ocur == nullptr)) return 0;
//			else if (cur == nullptr && ocur == nullptr)break;
//			else if (cur->elem != ocur->elem)return 0;
//
//			cur = cur->next;
//			ocur = ocur->next;
//		}
//		return true;
//	}
//	bool operator !=(const MyForList& otherlist) {
//		return !(*this == otherlist);
//	}
//
//	MyForList& operator =(const MyForList& otherlist) {
//		this->clear;
//		if (otherlist.empty()) {
//			Node* ocur = otherlist.head;
//			this->push_back(ocur->elem);
//			for (; ocur->next != nullptr;) {
//				ocur = ocur->next;
//				this->push_back(ocur->elem);
//			}
//			this->push_back(ocur->elem);
//		}
//		return *this;
//	}
//	class Iterator {
//	private:
//		Node* ptr;
//	public:
//		Iterator(Node* ptr) :ptr(ptr) {}
//		T& operator *() const {
//			return ptr->elem;
//		}
//		Iterator& operator++() {
//			ptr=ptr->next;
//			return *this;
//		}
//		Iterator& operator =(const Iterator& other) {
//			ptr = other.ptr;
//		}
//		bool operator ==(const Iterator& other) {
//			return this->ptr == other.ptr;
//		}
//		bool operator !=(const Iterator& other) {
//			return this->ptr != other.ptr;
//		}
//		~Iterator() {
//			delete ptr;
//		}
//	};
//	Iterator begin() {
//		return Iterator(head);
//	}
//	Iterator end() {
//		return Iterator(nullptr);
//	}
//
//	~MyForList() {
//		if (empty())return;
//		Node* cur = head;
//		Node* buf = cur->next;
//		for (; cur->next != nullptr;) {
//			delete cur;
//			cur = buf;
//			buf = buf->next;
//		}
//	}
//};
//int main()
//{
//	setlocale(LC_ALL, "rus");
//	MyForList<int> bigger;
//	MyForList<int> igger;
//	bigger.push_front(9);
//	bigger.push_front(52);
//	bigger.push_front(89);
//	bigger.push_front(14);
//	bigger.push_front(65);
//	bigger.show();
//	/*delete bigger;*/
//	/*igger = bigger;*/
//	bigger.show();
//	cout << endl;
//	/*igger.show();*/
//	for (auto el: bigger) {
//		cout << el << " ";
//	}
//}
#include <iostream>
#include <list>
#define random(min,max) min + rand() % (max - min + 1)
using namespace std;

template<typename T>
class MyList {
private:

    class Node {
    public:
        T elem;
        Node* next;
        Node* prev;

        Node(const T& value) : elem(value), next(nullptr), prev(nullptr) {};
    };

    Node* head;
    Node* tail;
    int size = 0;

public:
    MyList() : head(nullptr), tail(nullptr) {};

    MyList(const MyList& otherList) {
        if (otherList.empty()) return;
        this->size = otherList.size;
        Node* otherCur = otherList.head;
        this->push_back(otherCur->elem);

        while (otherCur->next != nullptr) {
            otherCur = otherCur->next;
            this->push_back(otherCur->elem);
        }
    }

    void push_front(const T& value) {
        Node* newNode = new Node(value);
        if (this->empty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void pop_front() {
        if (empty()) throw out_of_range("Forward list is empty");
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node* buf = head->next;
            delete head;
            head = buf;
            head->prev = nullptr;
        }
        size--;
    }


    bool empty() const {
        return head == nullptr;
    }

    void show() {
        if (empty()) return;
        Node* cur = head;
        while (cur->next != nullptr) {
            cout << cur->elem << " ";
            cur = cur->next;
        }
        cout << cur->elem << endl;
    }

    void insert_after(int index, const T& value) {

        if (empty() || index < 0 || index >= size) throw out_of_range("empty");
        Node* cur;
        find(cur, index);
        Node* buf = cur->next;
        cur->next = new Node(value);
        cur->next->next = buf;
        cur->next->prev = cur;
        buf->prev = cur->next;
        size++;

    }

    void emplace(int index, const T& value) {
        if (empty() || index < 0) throw out_of_range("empty");
        Node* cur = head;
        for (int i = 0; i < index; i++)
        {
            if (cur->next == nullptr) throw out_of_range("empty");
            cur = cur->next;
        }
        cur->elem = value;
    }

    void push_back(const T& value) {
        if (empty()) {
            head = new Node(value);
            tail = head;
            return;
        }
        tail->next = new Node(value);
        tail->next->prev = tail;
        tail = tail->next;
        size++;
    }

    void pop_back() {
        if (empty()) throw out_of_range("empty");
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
        size--;
    }

    T& front() {
        return head->elem;
    }

    T& back() {
        return tail->elem;
    }

    void clear() {
        Node* cur = head;
        while (cur->next != nullptr) {
            Node* buf = cur->next;
            delete cur;
            cur = buf;
        }
        delete cur;
        head = nullptr;
        size = 0;
    }

    ~MyList() {
        if (!empty()) {
            Node* cur = head;
            Node* buf;
            while (cur->next != nullptr) {
                buf = cur->next;
                delete cur;
                cur = buf;
            }
            delete cur;
        }
    }

    bool operator == (const MyList& otherList) {
        Node* cur1 = this->head;
        Node* cur2 = otherList.head;

        while (true) {
            if ((cur1 == nullptr && cur2 != nullptr) ||
                (cur1 != nullptr && cur2 == nullptr)) return false;
            else if (cur1 == nullptr && cur2 == nullptr) break;
            else if (cur1->elem != cur2->elem) return false;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return true;
    }

    bool operator != (const MyList& otherList) {
        return !(*this == otherList);
    }

    MyList& operator = (const MyList& otherList) {
        this->clear();
        this->size = otherList.size;
        if (!(otherList.empty())) {
            Node* otherCur = otherList.head;
            this->push_back(otherCur->elem);

            while (otherCur->next != nullptr) {
                otherCur = otherCur->next;
                this->push_back(otherCur->elem);
            }
        }
        return *this;
    }

    class Iterator {
    private:
        Node* ptr;
    public:
        Iterator(Node* ptr) : ptr(ptr) {}
        T operator *() const {
            return ptr->elem;
        }
        Iterator operator ++() {
            this->ptr = this->ptr->next;
            return *this;
        }
        bool operator ==(const Iterator otherIter) {
            return this->ptr == otherIter.ptr;
        }
        bool operator !=(const Iterator otherIter) {
            return !(*this == otherIter);
        }
        Node* getPtr() {
            return ptr;
        }
        Iterator& operator +(int num) {
            for (int i = 0; i < num; i++)
            {
                this->ptr = this->ptr->next;
            }
            return*this;
        }
        void setPtr(Node* ptr) {
            this->ptr = ptr;
        }

    };

    Iterator begin() {
        return Iterator(head);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

    Iterator erase(Iterator begin, Iterator end) {
        Node* start = begin.getPtr();
        Node* finish = end.getPtr();
        if (start == head && finish == nullptr) {
            this->clear();
            return Iterator(nullptr);
        }
        if (start == head && finish != nullptr) {
            finish->next->prev = nullptr;
            this->head = finish->next;
        }
        else if (start != head && finish == nullptr) {
            start->prev->next = nullptr;
            this->tail = start->prev;
        }
        else {
            start->prev->next = finish->next;
            finish->next->prev = start->prev;
        }

        for (; begin != end; this->size--) {
            Iterator buf = begin;
            begin++;
            delete buf.getPtr();
        }

    }

    Iterator erase(Iterator iter) {
        Node* cur = iter.getPtr();
        if (cur == head) {
            cur->next->prev = nullptr;
            head = cur->next;
        }
        else if (cur == tail) {
            cur->prev->next = nullptr;
            tail = cur->prev;
        }
        else {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
        }

        if (cur->next != nullptr) iter.setPtr(cur->next);
        else iter.setPtr(nullptr);
        delete cur;
        size--;
        return iter;
    }



    void erase(int index) {
        if (empty() || index < 0 || index >= size) throw out_of_range("empty");
        Node* cur;
        find(cur, index);
        if (cur == head) {
            cur->next->prev = nullptr;
            head = cur->next;
        }
        else if (cur == tail) {
            cur->prev->next = nullptr;
            tail = cur->prev;
        }
        else {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
        }
        delete cur;
        size--;
    }

private:
    void find(Node*& cur, int index) {
        if ((index + 1) < (size / 2)) {
            cur = head;
            for (int i = 0; i < index; i++) cur = cur->next;

        }
        else {
            cur = tail;
            for (int i = size - 1; i > index; i--) cur = cur->prev;
        }
    }

};

int main()
{

    MyList<int> test;

    test.push_front(1);
    test.push_front(3);
    test.push_front(4);
    test.push_back(543);
    test.push_back(31);
    test.push_back(41);
    test.push_back(34);

    for (auto el : test) {
        cout << el << " ";
    }
    auto it = test.begin();
    test.erase(it);
    cout << endl;
    for (auto el : test) {
        cout << el << " ";
    }


}