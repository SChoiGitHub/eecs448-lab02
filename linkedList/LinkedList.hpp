/**
*	@author 
*	@date 
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	return(m_size);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front; //First, look at the front
	
	if(temp == nullptr){
		//Empty lists have nothing to search for.
		return false;
	}else if(temp->getValue() == value){
		//The first value is the one we are looking for.
		return true;
	}
	
	while(temp->getNext() != nullptr){
		//If there are still other elements, go to the next.
		temp = temp->getNext();
		
		//If you can find the element, return true.
		if(temp->getValue() == value){
			return true;
		}

	}
	//return false, value not found;
	return false;
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	if(isEmpty()){
		m_front = new Node<T>(value);	
	}else{
		Node<T>* temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	if(m_front == nullptr){
		//We found no m_front. There is nothing to delete.
		return false;
	}
	
	Node<T>* temp = m_front; //First, look at the front
	
	//Get to the second-to-last node
	for(int x = 0; x < m_size-1; x++){
		temp = temp->getNext();
	}
	
	//Delete the last node
	delete temp->getNext();
	//Make the new last node point to a nullptr
	temp->setNext(nullptr);
	
	//decrement the size.
	m_size--;
	//return true;
	return true;
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
