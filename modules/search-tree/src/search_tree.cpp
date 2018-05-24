// Copyright 2018 Gorelova Ksenia

#include "include/search_tree.h"

SearchTree::SearchTree(Tree * pRoot) {
    this->pRoot = pRoot;
}

void SearchTree::AddTree(int val, Tree** pRoot) {
    if (*pRoot == nullptr) {
        *pRoot = new Tree;
        (*pRoot)->value = val;
        (*pRoot)->left = (*pRoot)->right = nullptr;
        return;
    }
    if (val > (*pRoot)->value)
        AddTree(val, &(*pRoot)->right);
    else
        AddTree(val, &(*pRoot)->left);
}

Tree * SearchTree::SearchNode(Tree * pRoot, int key) {
    if (pRoot == nullptr)
        return nullptr;
    if (pRoot->value == key)
        return pRoot;
    if (key < pRoot->value)
        return SearchNode(pRoot->left, key);
    else
        return SearchNode(pRoot->right, key);
}

void SearchTree::DestroyBTree(Tree * pRoot) {
    if (pRoot != nullptr) {
        DestroyBTree(pRoot->left);
        DestroyBTree(pRoot->right);
        delete(pRoot);
    }
}

bool SearchTree::Insert(int val) {
    bool resultOfInsert = false;
    Tree* tmp = nullptr;
    tmp = new Tree;
    if (tmp != nullptr) resultOfInsert = true;
    delete tmp;

    AddTree(val, &pRoot);
    return resultOfInsert;
}

Tree* SearchTree::Search(int val) {
    return SearchNode(pRoot, val);
}

void SearchTree::Draw(std::ostringstream &os) {
    DrawTree(pRoot, 0, os);
}

//������ � �������
void SearchTree::DrawTree(Tree* pNode, int Level, std::ostringstream &os)
{
    if (pNode != nullptr)
    {
        DrawTree(pNode->right, Level + 1, os);
        for (int i = 0; i < 2 * Level; i++)
            os << " ";
        pNode->Print(os);
        os << std::endl;
        DrawTree(pNode->left, Level + 1, os);
    }
}
