/*
 * dynamic array is an array that resize its capacity when its size reaches to
 * its capacity. It takes constant access time to the element stored in the array.
 * Appending a new element to a dynamic array is often constant time. However,
 * can take O(n).
 */

#ifndef _DYNAMIC_ARRAY_H_
#define _DYNAMIC_ARRAY_H_

const int DEFAULT_CAPACITY = 2;
const int GROWING_FACTOR = 2;

class DynamicArray {
public:
    DynamicArray (int capacity = DEFAULT_CAPACITY);
    ~DynamicArray () { delete[] m_arr;}

    int Get (int index);
    void Set (int index, int value);
    void PushBack (int value);
    void Remove (int index);

    int Size () const { return m_size; }
    int Capacity () const { return m_capacity; }

private:
    void IncreaseCapacity ();

    int * m_arr;
    int   m_size;
    int   m_capacity;
};

#endif
