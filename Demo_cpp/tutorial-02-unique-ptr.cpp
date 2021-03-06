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
        unique_ptr<A> q;

        q = move(p);

        if (p)
        {
            cout << "val = " << p->GetVal() << endl;
        }
        else
        {
            cout << "p is empty" << endl;
        }

        if (q)
        {
            cout << "val = " << q->GetVal() << endl;
        }
        else
        {
            cout << "q is empty" << endl;
        }

        cout << "q will be out of scope." << endl;
    }

    cout << "q is out of scope." << endl;

    return 0;
}

