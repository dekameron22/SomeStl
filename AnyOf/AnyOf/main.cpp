//
//  main.cpp
//  AnyOf
//
//  Created by Артем Ткачук on 17.07.13.
//  Copyright (c) 2013 Артем Ткачук. All rights reserved.
//

#include <iostream>

using std::cout;

template <class T>
class Node
{
public:
    T value;
    Node *next;
};

template <class T>
class InputIterator
{
private:
    Node<T> *iterator;
    
public:
    InputIterator() : iterator(nullptr){};
    InputIterator(const InputIterator& myInputIterator) : iterator(myInputIterator.iterator){};
    
    InputIterator & operator++()
    {
        iterator = iterator->next;
        return *this;
    }
    
    T & operator*()
    {
        return iterator->value;
    }
    
    bool operator == (InputIterator & CompareInputOperator)
    {
        return iterator == CompareInputOperator.iterator;
    }
    
    bool operator != (InputIterator & CompareInputOperator)
    {
        return iterator != CompareInputOperator.iterator;
    }
    
    T & operator = (InputIterator const& myInputIterator) const
    {
        iterator = myInputIterator.iterator;
        return this;
    }
};

template <class T>
class OutputIterator
{
private:
    Node<T> *iterator;
    
public:
    OutputIterator(T* x) : iterator(x){};
    OutputIterator(const OutputIterator& myOutputIterator) : iterator(myOutputIterator.iterator){};
    
    T & operator = (OutputIterator const& myInputIterator) const
    {
        iterator = myInputIterator.iterator;
        return this;
    }
    
    OutputIterator & operator++()
    {
        iterator->next;
        return *this;
    }
};

template <class T>
class MyVector
{
private:
    
    
public:
    
};


template <class T>
struct DivisibleBy
{
    const T d;
    DivisibleBy(T n) : d(n) {}
    bool operator()(T n) const { return n % d == 0; }
};


template <typename II, typename UP>
bool anyOf(II first, II last, UP predicate)
{
    II current = first;
    while (current != last)
    {
        if (predicate(*current))
        {
            return true;
        }
        ++current;
    }
    
    return false;
}

int main(int argc, const char * argv[])
{

    cout << any_of(first, last, DivisibleBy<int>(4));
    
    return 0;
}

























