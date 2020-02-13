/* -- DList.h ------------------------------------------------------------------

    定义用于处理列表的DList数据类型
    基本操作包括：
        构造函数
        析构函数
        复制构造函数
        赋值运算符
        +empty：检查列表是否为空
        +insert：插入一项
        +erase：删除一项
        +display：打印输出列表
        +<<:输出操作符

    author：       wind
    cdate：        2020-02-09
------------------------------------------------------------------------------*/

#include <iostream>

using namespace std;

#ifndef DLIST
#define DLIST

typedef int ElementType;

class List
{
    public:
    /* 函数成员 */
        /* 类构造函数 */
        List(int maxSize = 1024);
        /* ---------------------------------------------------------------------

        创建一个List对象

        前置条件：maxSize是一个正整数，默认值为1024
        后置条件：创造一个空的List对象；myCapacity == maxSize(默认1024)；myArray指向容量为myCapacity的动态数组；    mySize为0
        ----------------------------------------------------------------------*/

        /* 复制构造函数 */
        List(const List & origList);
        /* ---------------------------------------------------------------------

        创建一个List对象的一个复制

        前置条件：需要origList的一份复制； origList是一个常引用形参
        后置条件：创建了origList的一份复制
        ----------------------------------------------------------------------*/

        /* 赋值运算符 */
        const List & operator=(const List & rightHandSize);
        /* ---------------------------------------------------------------------

        将List对象的一份复制赋给当前对象

        前置条件：无
        后置条件：rughtHandSize的一份复制被赋给当前对象，返回当前列表的一个常引用
        ----------------------------------------------------------------------*/

        /* empty操作 */
        bool empty() const;
        /* -------------------------------------------------------------------
        
        检查列表是否为空

        前置条件：无
        后置条件：如果列表为空，返回true，否则返回false
        ----------------------------------------------------------------------*/

        /* 插入操作 */
        void insert(ElementType item, int pos);
        /* --------------------------------------------------------------------

        在列表中给定位置插入一个值

        前置条件：item是将被插入的值；数组中有足够空间（mySize < CAPACITY）；并且插入位置满足0 <= pos <= mySize
        后置条件：item被插入到列表中由pos限定的位置
        --------------------------------------------------------------------- */

        /* 删除操作 */
        void erase(int pos);
        /* -------------------------------------------------------------------
        
        删除列表给定位置的值

        前置条件：列表非空并且给定位置满足0 < pos < mySize
        后置条件：由pos限定的位置处的元素被删除
        --------------------------------------------------------------------- */

        /* 输出操作 */
        void display(ostream & out) const;
        /* -------------------------------------------------------------------

        显示一个列表

        前置调价：ostream out已经被打开
        后置条件：这个List对象所表示的列表被插入到out中
        --------------------------------------------------------------------- */

    private:
    /* 数据成员 */
        int mySize;                         //列表的当前大小
        int myCapacity;                     //数组的容量
        ElementType * myArray;      //存储列表元素的数组
};  // --- List类声明结束

// ------ 输出操作符的原型
std::ostream & operator<< (std::ostream & out, const List & aList);

#endif