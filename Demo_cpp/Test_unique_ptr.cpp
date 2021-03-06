// Author:  Li Leo Wang
// Date:    2019-07-17
// Description:
//  - Test pass unique pointer by value and by reference
//

#include "stdafx.h"
#include <iostream>
#include <memory> // unique_ptr

using namespace std;

unique_ptr<double> Pass_by_value(unique_ptr<double> p)
{
    unique_ptr<double> q = make_unique<double>(*p);

    if (q.get())
    {
        cout << "q = " << *q.get() << endl;
    }
    else
    {
        cout << "q is empty" << endl;
    }

    return q;
}

void Pass_by_reference(unique_ptr<double> & p)
{
    unique_ptr<double> q = make_unique<double>(*p.get());

    if (q.get())
    {
        cout << "q = " << *q.get() << endl;
    }
    else
    {
        cout << "q is empty" << endl;
    }

    cout << "release q." << endl;
    q.release();

    if (q.get())
    {
        cout << "q = " << *q.get() << endl;
    }
    else
    {
        cout << "q is empty" << endl;
    }

    //cout << "release p." << endl;
    //p.release();
    //if (p.get())
    //{
    //    cout << "p = " << *p.get() << endl;
    //}
    //else
    //{
    //    cout << "p is empty" << endl;
    //}
}

int main()
{
    unique_ptr<double> p = unique_ptr<double>(new double(2));

    if (p.get())
    {
        cout << "p = " << *p.get() << endl;
    }
    else
    {
        cout << "p is empty" << endl;
    }

    cout << "---------------------------------" << endl;
    cout << "p is passed to Pass_by_value()." << endl;
    p = Pass_by_value(move(p));
    cout << "---------------------------------" << endl;

    cout << "---------------------------------" << endl;
    cout << "p is passed to Pass_by_reference()." << endl;
    Pass_by_reference(p);
    cout << "---------------------------------" << endl;

    cout << "Check p in main function." << endl;
    if (p.get())
    {
        cout << "p = " << *p.get() << endl;
    }
    else
    {
        cout << "p is empty" << endl;
    }

    printf("end\n");
    getchar();
    return 0;
}

