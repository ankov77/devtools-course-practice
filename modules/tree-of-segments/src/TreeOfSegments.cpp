// Copyright 2018 Kovshov Andrey

#ifndef MODULES_TREE_OF_SEGMENTS_SRC_TREEOFSEGMENTS_CPP_
#define MODULES_TREE_OF_SEGMENTS_SRC_TREEOFSEGMENTS_CPP_

#include <algorithm>
#include <stdexcept>
#include "include/TreeOfSegments.h"

template<class T>
void TreeOfSegmets<T>::build(T* a, int vert, int lbord, int rbord) {
    if (lbord == rbord) {
        arr[vert] = a[lbord];
    } else {
        int middle = (lbord + rbord) / 2;
        build(a, vert * 2 + 1, lbord, middle);
        build(a, vert * 2 + 2, middle + 1, rbord);
        arr[vert] = arr[vert * 2 + 1] + arr[vert * 2 + 2];
    }
}

template<class T>
T TreeOfSegmets<T>::sum(int vert, int lbord, int rbord, int left, int right) {
    if (left > right)
        return 0;
    if (lbord == left && rbord == right)
        return arr[vert];
    int middle = (lbord + rbord) / 2;
    T res = sum(vert * 2 + 1, lbord, middle, left, std::min(middle, right))
    + sum(vert * 2 + 2, middle + 1, rbord, std::max(left, middle+1), right);
    return res;
}

template<class T>
void TreeOfSegmets<T>::update(int vert, int lbord, int rbord, int pos, T val) {
    if (lbord == rbord) {
         arr[vert] = val;
    } else {
        int middle = (lbord + rbord) / 2;
        if (pos <= middle)
            update(vert * 2 + 1, lbord, middle, pos, val);
        else
            update(vert * 2 + 2, middle + 1, rbord, pos, val);
        arr[vert] = arr[vert * 2 + 1] + arr[vert * 2 + 2];
    }
}

template<class T>
TreeOfSegmets<T>::TreeOfSegmets(int size, T * a) {
    if (size <= 0)
        throw std::invalid_argument("Negative_size");
    if (size > MAXSIZE)
        throw std::invalid_argument("Too_big_size");
    n = size;
    arr = new T[4 * n];
    for (int i = 0; i < 4 * n; ++i)
        arr[i] = 0;
    build(a, 0, 0, n - 1);
}

template<class T>
TreeOfSegmets<T>::TreeOfSegmets(const TreeOfSegmets<T>& st) {
    n = st.n;
    arr = new T[4 * n];
    for (int i = 0; i < 4 * n; ++i)
        arr[i] = st.arr[i];
}

template<class T>
TreeOfSegmets<T>::~TreeOfSegmets() {
    delete[] arr;
}

template<class T>
T TreeOfSegmets<T>::sum(int left, int right) {
    if (left < 0)
        throw std::invalid_argument("Negative_left");
    if (right >= n)
        throw std::invalid_argument("Too_big_right");
    if (left > right)
        throw std::invalid_argument("Right is less then left");
    return sum(0, 0, n - 1, left, right);
}

template<class T>
void TreeOfSegmets<T>::update(int pos, T val) {
    if (pos < 0)
        throw std::invalid_argument("Negative_vertex");
    if (pos >= n)
        throw std::invalid_argument("Too_big_vertex");
    update(0, 0, n - 1, pos, val);
}

template<class T>
bool TreeOfSegmets<T>::operator==(const TreeOfSegmets<T>& st) const {
    if (n != st.n)
        return false;
    for (int i = 0; i < 4*n; ++i) {
        if (arr[i] != st.arr[i])
            return false;
    }
    return true;
}

template<class T>
TreeOfSegmets<T> & TreeOfSegmets<T>::operator=(const TreeOfSegmets<T> & st) {
    if (*this == st)
        return *this;
    delete[] arr;
    n = st.n;
    arr = new T[4 * n];
    for (int i = 0; i < 4 * n; ++i)
        arr[i] = st.arr[i];
    return *this;
}

#endif  // MODULES_TREE_OF_SEGMENTS_SRC_TREEOFSEGMENTS_CPP_
