/* --- 测试List的驱动程序 -----------------------------------------------------

author:  wind
cdate:   2020-02-08
-------------------------------------------------------------------------- */

#include <iostream>

using namespace std;

#include "list.h"

int main()
{
    // 测试类构造函数
    List intList;
    std::cout << "Constructing intList";

    //  测试empty()并输出空列表
    if (intList.empty())
        std::cout << "Empty List: \n"
             << intList << endl;
    // 测试insert()
    for (int i = 0; i < 9; i++)
    {
        std::cout << "Inserting " << i << " at postion " << i/2 << endl;
        intList.insert(i, i/2);         // -- 将i插入到位置i/2处
        // 测试输出
        std::cout << intList << endl;
    } 
    std::cout<< "list empty? " << (intList.empty() ? "yes" : "no") <<endl;

    std::cout<< "\n Try to insert at positon -1" << endl;
    intList.insert(0,-1);
    std::cout<< "\n Try to insert at positon 10" << endl;
    intList.insert(0,10);

    // 测试erase()
    int index;
    std::cout << endl;
    while (!intList.empty())
    {
        std::cout << "Give an index of a list element to remove: ";
        cin >> index;
        intList.erase(index);
        std::cout << intList << endl;
    }
    std::cout << intList <<endl;
    std::cout << "List is empty" << endl;

    std::cout << "\nInsert " << CAPACITY << " integers\n";
    for (int i = 0; i < CAPACITY; i++)
        intList.insert(i ,i);
    std::cout << "Attempting to insert one more integer:\n";
    intList.insert(-1 ,0);
}