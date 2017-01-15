/*
 * heap is a specialized treebased data structure that satisfies the
 * heap structure. If A is a parent node of B then the key (the value)
 * of node A is ordered with respect to the key of node B with the same
 * ordering applying across the heap.
 *
 * this program is compiled with '-std=c++11' option.
 */

#ifndef HEAP_H
#define HEAP_H

#include <algorithm>

#define DEFAULT_MAX_HEAP_SIZE 100

template <typename T>
class Element {
public:
    Element ()
     : m_key(0)
     , m_value()
    {}
    Element (int key, T value)
     : m_key(key)
     , m_value(value)
    {}

    const Element<T> & operator= (const Element<T> & rhs) {
        this->m_key = rhs.m_key;
        this->m_value = rhs.m_value;
        return *this;
    }
    bool operator< (const Element<T> & rhs) {
        return this->m_key < rhs.m_key;
    }

    void SetKey (int key) { m_key = key; }
    int GetKey () { return m_key; }
    const T & GetValue () { return m_value; }

private:
    int m_key;
    T m_value;
};

template <typename T>
class Heap {
public:
    Heap (int capacity = DEFAULT_MAX_HEAP_SIZE);
    ~Heap ();

    bool Insert (Element<T> && e);
    Element<T> * Delete ();

private:
    void Heapify (int parent);
    void HeapDecreaseKey (int i, int key);

    Element<T> * m_elements;
    int m_capacity;
    int m_size;
};

template <typename T>
Heap<T>::Heap (int capacity) {
    m_elements = new Element<T>[capacity+1];
    m_capacity = capacity;
    m_size = 0;
}

template <typename T>
Heap<T>::~Heap () {
    delete[] m_elements;
}

template <typename T>
bool Heap<T>::Insert (Element<T> && e) {
    if (m_size == m_capacity)
        return false;
    m_size++;
    m_elements[m_size] = e;
    HeapDecreaseKey(m_size, e.GetKey());
    return true;
}

template <typename T>
Element<T> * Heap<T>::Delete () {
    if (!m_size)
        return 0;
    Element<T> * min = new Element<T>();

    // should consider heap underflow
    *min = m_elements[1];
    m_elements[1] = m_elements[m_size];
    m_size--;
    Heapify(1);
    return min;
}

template <typename T>
void Heap<T>::HeapDecreaseKey (int i, int key) {
    m_elements[i].SetKey(key);
    // compares to parent
    while (i > 1 && m_elements[i/2].GetKey() > m_elements[i].GetKey()) {
        std::swap(m_elements[i], m_elements[i/2]);
        i = i / 2;
    }
}

template <typename T>
void Heap<T>::Heapify (int parent) {
    int leftChild, rightChild;
    int smallest;

    leftChild = parent * 2;
    rightChild = leftChild + 1;

    smallest = parent;
    if (leftChild <= m_size && m_elements[leftChild] < m_elements[parent])
        smallest = leftChild;
    if (rightChild <= m_size && m_elements[rightChild] < m_elements[smallest])
        smallest = rightChild;
    if (smallest != parent) {
        std::swap(m_elements[parent], m_elements[smallest]);
        Heapify(smallest);
    }
}

#endif
