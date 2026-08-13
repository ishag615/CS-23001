//
// File: stack.hpp
//
// Programmer:
// Date:        Spring 2024
//
//
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//
#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_

#include <new>
#include <cassert>


template<typename T> 
class Node {
    public:
    Node() : data(), next(0) {};
    Node (const T& val) : data(val), next(0) {};
    T data;
    Node<T> *next;
};


// CLASS INV:
//
template <typename T>
class stack {
public:
              stack     (): tos(0){};
              stack     (const stack<T>&);
              ~stack    ();
    void      swap      (stack<T>& rhs);
    stack<T>& operator= (stack<T> rhs) {swap(rhs); return *this; };
    
	bool      empty     () const {return tos == 0;};
	bool      full      () const ;
	T         top       () const {return tos-> data;};
	T         pop       () ;
	void      push      (const T&) ;

private:
	Node<T>   *tos;
};
//copy constructor
template<typename T>
stack<T>::stack(const stack<T>& actual){
    Node<T> *temp = actual.tos;
    Node<T> *bottom = 0;
    tos = 0;
    while (temp != 0){
        if (tos == 0){
            tos = new Node<T>(temp-> data);
            bottom = tos;
        }else{
            bottom->next = new Node <T>(temp->data);
            bottom = bottom->next;
        }
        temp = temp->next;
    }
}
//destructor
template <typename T>
stack<T>::~stack()
{
	Node<T> *temp = 0;
    while(tos != 0) {
        temp = tos;
        tos = tos -> next;
        delete temp;
    }
}
//const time swap
template <typename T>
void stack<T>::swap(stack<T>& rhs ){
    Node<T> *temp = tos;
    tos = rhs.tos = rhs.tos;
    rhs.tos       = temp;
}
//push
// REQUIRES: tos -> x1 -> x2 -> ... xn->0
// ENSURE: tos -> item -> x1 -> x2 -> ...xn->0
template <typename T>
void stack<T>::push(const T& item){
    assert(!full());
    Node<T> *temp = new Node<T>(item);
    temp->next = tos;
    tos = temp;
}

//pop
//REQUIRES: tos-> x1 -> x2 -> ...xn ->0 && tos!=0
// ENSURE:  tos-> x2 -> ...xn->0
template <typename T>
T stack<T>::pop(){
    assert(!empty());
    T result = tos->data;
    Node<T> *temp = tos;
    tos = tos->next;
    delete temp;
    return result;
}

//full
template <typename T>
bool stack<T>::full() const {
    Node<T> *temp = new(std::nothrow) Node<T>();
    if (temp == 0) //no memory remaining
        return true;
    delete temp;
    return false;
}



#endif
