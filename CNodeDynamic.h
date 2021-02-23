//
// Created by Mufasa on 2/2/2021.
//

#ifndef LAB4_CNODEDYNAMIC_H
#define LAB4_CNODEDYNAMIC_H

#include <iostream>
#include <vector>
using namespace std;
template<typename T> class CNodeDynamic
{
public:
    CNodeDynamic()
    {
        i_val = 0; parent = NULL;
    };
    ~CNodeDynamic();
    void vSetValue(T iNewVal)
    {
        i_val = iNewVal;
    };
    int iGetChildrenNumber()
    {
        return v_children.size();
    };
    void vAddNewChild();
    CNodeDynamic* pcGetChild(int iChildOffset);
    void vPrint() {
        cout << " " << i_val;
    };
    void vPrintAllBelow();
    void vAddNewChild(CNodeDynamic<T>* newChild);
    void removeChild(CNodeDynamic<T>* oldChild);
private:
    vector<CNodeDynamic<T>*> v_children;
    T i_val;
    CNodeDynamic<T>* parent;
};
template <typename T>
CNodeDynamic<T> :: ~CNodeDynamic() {

}
template <typename T>
void CNodeDynamic<T>::vAddNewChild() {
    CNodeDynamic<T>* newChild = new CNodeDynamic();
    newChild->parent = this;
    v_children.push_back(newChild);
}
template <typename T>
CNodeDynamic<T>* CNodeDynamic<T>::pcGetChild(int iOffSet) {
    for (int i = 0; i < v_children.size(); i++)
    {
        if (i == iOffSet) return v_children[i];
    }
    return 0;

}
template <typename T>
void CNodeDynamic<T>::vPrintAllBelow() {
    vPrint();
    for (CNodeDynamic* child : v_children) child->vPrintAllBelow();
}
template <typename T>
void CNodeDynamic<T>::vAddNewChild(CNodeDynamic<T>* newChild) {
    newChild->parent = this;
    v_children.push_back(newChild);
}
template <typename T>
void CNodeDynamic<T>::removeChild(CNodeDynamic* childToDelete) {
    for (int i = 0; i < v_children.size(); i++)
    {
        if (v_children[i] == childToDelete)
        {
            delete v_children[i];
            v_children.erase(v_children.begin() + i);
            return;
        }
    }
}



#endif //LAB4_CNODEDYNAMIC_H
