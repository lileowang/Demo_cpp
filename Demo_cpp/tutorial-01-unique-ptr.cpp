// CppConsole01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory> // unique_ptr

using namespace std;

class A
{
public:
    A(int val)
    {
        m_val = val;
        cout << "In A's constructor." << endl;
    }

    ~A()
    {
        cout << "In A's destructor" << endl;
    }

    int GetVal()
    {
        return m_val;
    }

private:
    int m_val;
};

int main()
{
    bool bRet = true;

    if (bRet)
    {
        //A* p = new A(3);
        unique_ptr<A> p = make_unique<A>(3);

        if (p)
        {
            cout << "val = " << p->GetVal() << endl;
        }
        else
        {
            cout << "p is empty" << endl;
        }

        cout << "p will be out of scope." << endl;
    }

    cout << "p is out of scope." << endl;

    return 0;
}

