/* --List.cpp -----------------------------------------------------------------

这个文件中给出了List成员函数的实现
---------------------------------------------------------------------------- */

#include <cassert>

using namespace std;

#include "List.h"

// --- 类构造函数的定义
List::List()
: mySize(0)
{}

// --- empty()的定义
bool List::empty() const
{
    return mySize == 0;
}

// --- display()的定义
void List::display(ostream & out) const
{
    for (int i = 0; i < mySize; i++)
        out << myArray[i] << " ";
}

// --- 输出操作符的定义
ostream & operator<< (ostream & out, const List & aList)
{
    aList.display(out);
    return out;
}

// --- insert()的定义
void List::insert(ElementType item, int pos)
{
    if (mySize == CAPACITY)
    {
        cerr << "*** NO space for list element -- terminating "
                "execution ***\n";
        exit(1);
    }
    if (pos < 0 || pos >mySize)
    {
        cerr << "*** Illegal location to insert -- " << pos
             << ". List unchanged. ***\n";
        return;
    }

    // 首先向右移动数组元素为item腾出空间

    for(int i = mySize; i > pos; i--)
        myArray[i] = myArray[i - 1];

    // 现在将item插入到位置pos处并递增列表大小
    myArray[pos] = item;
    mySize++;
}

// --- erase()的定义
void List::erase(int pos)
{
    if(mySize == 0)
    {
        cerr << "*** List is empty ***\n";
        return;
    }
    if(pos < 0 || pos >= mySize)
    {
        cerr << "Illegal location to delete --" << pos
             << ". Listunchanged. ***\n";
        return;
    }

    // 向左移动数组元素以消除间隔
    for(int i = pos; i< mySize; i++)
        myArray[i] = myArray[i + 1];

    // 递减列表大小
    mySize--;
}