#include "_libs.hpp"

template< class NODETYPE > class List; // forward declaration
template<class NODETYPE>
class ListNode
{
	friend class List< NODETYPE >; // make List a friend
public:
	ListNode(const NODETYPE& newData); // copy constructor
	NODETYPE getData() const; // return data in the node
private:
	NODETYPE data; // data
	ListNode< NODETYPE >* nextPtr; // next node in the list
};template< class NODETYPE >
class List
{
public:
	List(); // constructor
	~List(); // destructor
	void insertAtFront(const NODETYPE& newData);
	void insertAtBack(const NODETYPE& newData);
	bool removeFromFront(NODETYPE& removedData);
	bool removeFromBack(NODETYPE& removedData);
	bool isEmpty() const;
	void print() const;
private:
	ListNode< NODETYPE >* firstPtr; // pointer to first node
	ListNode< NODETYPE >* lastPtr; // pointer to last node
	// Utility function to allocate a new node
	ListNode< NODETYPE >* getNewNode(const NODETYPE& newData);
};