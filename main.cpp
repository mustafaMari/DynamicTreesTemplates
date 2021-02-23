#include <iostream>
#include "CNodeDynamic.h"
void v_tree_test_dynamic();
int main()
{
    v_tree_test_dynamic();
}

void v_tree_test_dynamic()
{
    CNodeDynamic<int> c_root;
    c_root.vAddNewChild();
    c_root.vAddNewChild();

    c_root.pcGetChild(0)->vSetValue(1);
    c_root.pcGetChild(1)->vSetValue(2);

    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->vAddNewChild();

    c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);

    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->vAddNewChild();

    c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    cout << "all below" << endl;
    c_root.vPrintAllBelow();

    c_root.~CNodeDynamic();
}