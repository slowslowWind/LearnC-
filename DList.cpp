/* --DList.cpp -----------------------------------------------------------------

这个文件中给出了List成员函数的实现

author:     wind
cdate:      2020-02-12
---------------------------------------------------------------------------- */

#include <cassert>
#include <new>

using namespace std;

#include "DList.h"

// --- 类构造函数的定义
List::List(int maxSize)
: mySize(0), myCapacity(maxSize)
{
    myArray = new(nothrow) ElementType[maxSize];
    assert(myArray != 0);
}

// --- 类析构函数的定义
List::~List()
{
    delete [] myArray;
}

// --- 复制构造函数的定义
List::List(const List & origList)
: mySize(origList.mySize), myCapacity(origList.myCapacity)
{
    myArray = new(nothrow) ElementType[myCapacity];

    if (myArray != 0)                   //检查是否有可用内存
    // --- 将origList的元素复制到这个新数组中
        for(int i = 0; i < mySize; i++)
            myArray[i] = origList.myArray[i];
    else
    {
        cerr << "*** Inadequate memory to allocate storage for list ***\n";
        exit(1);
    }
}

// --- 赋值运算符的定义
const List & List::operator=(const List & rightHandSize)
{
    if (this != &rightHandSize)         // 确认不是自我赋值
    {
        // --- 如果需要，分配一个新数组
        if (myCapacity != rightHandSize.myCapacity)
        {
            delete [] myArray;
            myCapacity = rightHandSize.myCapacity;
            myArray = new(nothrow) ElementType[myCapacity];

            if (myArray == 0)       // 检查是否有可用内存
            {
                cerr << "*Inadequate memery to allocate stack ***\n";
                exit(1);
            }
        }
        // --- 将rightHandSize的列表元素复制到这个新数组中
        mySize = rightHandSize.mySize;
        for(int i = 0; i < mySize; i++)
            myArray[i] = rightHandSize.myArray[i];
    }
    return *this;
}

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
    if (mySize == myCapacity)
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