#include <iostream>

template< class NODETYPE > class List; // forward declaration

template<class NODETYPE>
class ListNode
{
    friend class List< NODETYPE >; // make List a friend
public:
    ListNode(const NODETYPE& newData) : data(newData), nextPtr(nullptr) {} // constructor
    NODETYPE getData() const { return data; } // return data in the node
private:
    NODETYPE data; // data
    ListNode< NODETYPE >* nextPtr; // next node in the list
};

template< class NODETYPE >
class List
{
public:
    List() : firstPtr(nullptr), lastPtr(nullptr) {} // constructor

    ~List()
    {
        if (!isEmpty())
        {
            ListNode<NODETYPE>* current = firstPtr;
            ListNode<NODETYPE>* temp;
            while (current != nullptr)
            {
                temp = current;
                current = current->nextPtr;
                delete temp;
            }
        }
    }
    void insertAtFront(const NODETYPE& newData)
    {
        ListNode<NODETYPE>* newNode = getNewNode(newData);
        if (isEmpty())
        {
            firstPtr = lastPtr = newNode;
        }
        else
        {
            newNode->nextPtr = firstPtr;
            firstPtr = newNode;
        }
    }
    void insertAtBack(const NODETYPE& newData)
    {
        ListNode<NODETYPE>* newNode = getNewNode(newData);
        if (isEmpty())
        {
            firstPtr = lastPtr = newNode;
        }
        else
        {
            lastPtr->nextPtr = newNode;
            lastPtr = newNode;
        }
    }
    bool removeFromFront(NODETYPE& removedData)
    {
        if (isEmpty())
        {
            return false;
        }
        else
        {
            ListNode<NODETYPE>* temp = firstPtr;
            removedData = firstPtr->data;

            if (firstPtr == lastPtr) // only one node
            {
                firstPtr = lastPtr = nullptr;
            }
            else
            {
                firstPtr = firstPtr->nextPtr;
            }

            delete temp;
            return true;
        }
    }
    bool removeFromBack(NODETYPE& removedData)
    {
        if (isEmpty())
        {
            return false;
        }
        else
        {
            ListNode<NODETYPE>* temp = lastPtr;
            removedData = lastPtr->data;

            if (firstPtr == lastPtr) // only one node
            {
                firstPtr = lastPtr = nullptr;
            }
            else
            {
                ListNode<NODETYPE>* current = firstPtr;
                while (current->nextPtr != lastPtr)
                {
                    current = current->nextPtr;
                }
                lastPtr = current;
                current->nextPtr = nullptr;
            }

            delete temp;
            return true;
        }
    }
    bool isEmpty() const
    {
        return (firstPtr == lastPtr == nullptr);
    }
    void print() const
    {
        for (ListNode<NODETYPE>* pCur = firstPtr; pCur != nullptr; pCur = pCur->nextPtr)  cout << pCur->getData() << endl;
    }

private:
    ListNode< NODETYPE >* firstPtr; // pointer to first node
    ListNode< NODETYPE >* lastPtr;  // pointer to last node

    // Utility function to allocate a new node
    ListNode< NODETYPE >* getNewNode(const NODETYPE& newData) { return new ListNode<NODETYPE>(newData); }
};
