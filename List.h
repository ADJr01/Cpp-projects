class ListIndexOverFlowed : public std::exception {
};
template<class T>
class List {
    /*
     * Basic Implementation of Linked List
     * Capable of doing basic operations like insertion,searching,overwriting,removing etc on the list.
     */
    struct Node {
        T item;
        Node *next;
    };
    int count;
    Node *Head;
    Node *Cursor;

public:

    List() {
        Head = new Node();     //Initializing The Root Node of the List
        Head->next = nullptr;
        count = -1;
    }

    //Capable of appending the List
    bool add(T item) {
        if (Head->next == nullptr) {
            Head->item = item;
            Head->next = new Node();
            Cursor = Head->next;
            Cursor->next = nullptr;
            count = 0;
            return true;
        } else {
            Cursor->item = item;
            Cursor->next = new Node();
            Cursor = Cursor->next;
            Cursor->next = nullptr; //Every Last Node has null to its next location
            count++;
            return true;

        }
    }


    /*
     * Just To Modify List
     * Takes Two parameter [item ,index]
     * T type of Item
     * in index
     */
    bool add(T item, int index) {
        try {
            if (index >= 0 && index < length()) {
                int i = 0;
                Node *temp = Head;
                while (i != index && temp->next != nullptr) {
                    temp = temp->next;
                    i++;
                }
                temp->item = item;
                return true;
            } else {
                throw ListIndexOverFlowed();
            }
        } catch (ListIndexOverFlowed &LIOF) {
            std::cerr << "List Index Out of Bound" << std::endl;
            return false;
        }


    }


    T getAt(int index) {
        try {
            if (index > count) {
                throw ListIndexOverFlowed();
            }
            Node *temp;
            temp = Head;
            int i = 0;
            while (i < index) {
                temp = temp->next;
                i++;
            }
            return temp->item;
        } catch (ListIndexOverFlowed &e) {
            std::cerr << "List Index Out of Bound" << std::endl;
        }
    }

    bool remove(int index = 0) {
        if (count == -1 || index > count || index < 0) {

            return false;
        }
        if (index == 0) {
            if (count == 0) {
                Head->item = '\0';
                count = -1;
                delete Head->next;
                Head->next = nullptr;
            } else {
                Node *temp = Head;
                Head = Head->next;
                delete temp;
                temp = nullptr;
                count--;
            }
        } else {
            Node *temp = Head;
            int i = 0;
            while (i != (index - 1)) {
                temp = temp->next;
                i++;
            }
            if (temp->next->next != nullptr) {
                temp->next = temp->next->next;
                count--;
            } else {
                temp->next = nullptr;
                count--;
            }
        }
        return true;

    }


    int length() const {
        return count + 1;
    }

    int *getAsArray() {
        int *ListArray = new int[length()];
        for (int i = 0; i < length(); i++) {
            ListArray[i] = getAt(i);
        }
        return ListArray;
    }

    int *getAsArray(int from, int upto) {
        if (from >= 0 && upto <= length() && upto > from) {
            int *ListArray = new int[upto];
            for (int i = from; i < upto; i++) {
                ListArray[i] = getAt(i);
            }
            return ListArray;
        }
    }


    ~List() {
        if (count > -1) {
            while (remove(0));
        }
        delete Head;
        Head = nullptr;
    }


};


template<class T>
class ArrayList {
    /*
     * ArrayList following the principles of LinkedList
     * Instead of keeping a single value we will keep  an array[small_size/medium_size/large_size]
     * We can do all operation expect deleting any item.
     */

    //Array List Node
    struct ArrayNode {
        T *Arr;
        ArrayNode *next;
    };

    int size;  //size of array to be intialized on every ArrayNode
    int count; //length of the list
    int AIC = 0; //AIC [ARRAY INDEX COUNT]
    ArrayNode *Head;
    ArrayNode *Cursor;

public:
    enum SIZE {
        tiny = 5,
        small = 10,
        medium = 50,
        large = 100,
    };

    ArrayList(int size = small) {
        this->size = size;
        count = -1;
        Head = new ArrayNode();
        Head->next = nullptr;
        Head->Arr = new T[this->size];
        Cursor = Head;
        AIC = 0;
    }

    //Capable of appending the List
    bool add(T item) {
        if (AIC < size) {
            Cursor->Arr[AIC] = item;
            count++;
            AIC++;
            return true;
        } else {
            AIC = 0;
            Cursor->next = new ArrayNode();
            Cursor = Cursor->next;
            Cursor->next = nullptr;
            Cursor->Arr = new T[this->size];
            Cursor->Arr[AIC] = item;
            count++;
            AIC++;
            return true;
        }


    }

    //Modify any existing item
    bool add(T item, int index) {
        if (index < 0 && index >= length()) {
            std::cerr << "Index out of Bound" << std::endl;
            return false;
        }
        if (index < this->size) {
            Head->Arr[index] = item;
        } else {

            ArrayNode *temp = Head;
            int upto = index / this->size;
            int toAdd = index % this->size;
            for (int i = 0; i < upto; i++) {
                temp = temp->next;
            }
            temp->Arr[toAdd] = item;

        }
        return true;

    }

    int length() {
        return count + 1;
    }


    T getAt(int index) {
        if (index < length()) {
            if (index < this->size) {
                return Head->Arr[index];
            } else {

                ArrayNode *temp = Head;
                int upto = index / this->size;
                int toAdd = index % this->size;
                for (int i = 0; i < upto; i++) {
                    temp = temp->next;
                }
                return temp->Arr[toAdd];

            }
        }
    }

    ~ArrayList() {
        ArrayNode *temp = Head;
        while (temp->next != nullptr) {
            delete[] temp->Arr;
            temp->Arr = nullptr;
            temp = temp->next;

        }
    }


};
