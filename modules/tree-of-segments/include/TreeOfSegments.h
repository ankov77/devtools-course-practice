 // Copyright 2018 Kovshov Andrey

#ifndef MODULES_TREE_OF_SEGMENTS_H_
#define MODULES_TREE_OF_SEGMENTS_H_

#define MAXSIZE 300000

template<class T>
class TreeOfSegmets {
protected:
    int n;
    T* arr;
    void build(T* a, int vert, int left, int right);
    T sum(int vert, int lbord, int rbord, int left, int right);
    void update(int vert, int lbord, int rbord, int pos, T val);
public:
    TreeOfSegmets(int size, T* a);
    TreeOfSegmets(const TreeOfSegmets<T>& st);
    ~TreeOfSegmets();
    T sum(int left, int right);
    void update(int pos, T val);
    bool operator==(const TreeOfSegmets<T>& st) const;
    TreeOfSegmets<T>& operator=(const TreeOfSegmets<T>& st);
};

#include "src/TreeOfSegments.cpp"

#endif  // MODULES_TREE_OF_SEGMENTS_H_

