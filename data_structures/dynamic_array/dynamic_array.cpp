#include "dynamic_array.h"

DynamicArray::DynamicArray (int capacity)
 : m_capacity(capacity)
 , m_size(0)
{
    m_arr = new int[capacity];
}

int DynamicArray::Get (int index) {
     if (index < 0 || index > m_size)
         return -1;
     return m_arr[index];
}

void DynamicArray::Set (int index, int value) {
    if (index < 0 || index > m_size)
        return;
    m_arr[index] = value;
}

void DynamicArray::PushBack (int value) {
    if (m_size == m_capacity)
        IncreaseCapacity();
    m_arr[m_size++] = value;
}

void DynamicArray::Remove (int index) {
    if (index < 0 || index > m_size)
        return;
    for (int i = index; i < m_size - 1; i++)
        m_arr[i] = m_arr[i+1];
}

void DynamicArray::IncreaseCapacity () {
    int * newArr = new int[m_capacity * GROWING_FACTOR];
    for (int i = 0; i < m_capacity; i++)
        newArr[i] = m_arr[i];
    delete[] m_arr;
    m_arr = newArr;
    m_capacity = m_capacity * GROWING_FACTOR;
}
