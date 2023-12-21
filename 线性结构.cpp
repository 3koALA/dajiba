#include <iostream>
template <typename T>  
class Array 
{  
private:  
    T* data;  
    size_t size;  
    size_t capacity;
public:  
    Array(size_t size = 0) :size(size),capacity(size) // 构造函数 
    {  
        data = size ? new T[capacity] : nullptr;  
    }  
    ~Array() // 析构函数
    {  
        delete[] data;  
    }  
    Array(const Array& other) : size(other.size), capacity(other.capacity) //复制构造
    {  
        data = new T[capacity];  
        for (size_t i = 0; i < size; ++i) 
        {  
            data[i] = other.data[i];  
        }  
    }  
    size_t getSize() const // 获取数组长度  
    {  
        return size;  
    }  
    T& operator[](size_t index) // [] 运算符重载
    {  
        if (index >= size) 
        {  
            throw std::out_of_range("Index out of range");  
        }  
        return data[index];  
    }  
    T& operator*() // * 运算符重载，返回首元素引用  
    {  
        return data[0];  
    }  
    T* operator+(size_t index) // + 运算符重载，返回偏移后的地址  
    {  
        if (index >= size) 
        {  
            throw std::out_of_range("Index out of range");  
        }  
        return &data[index];  
    }  
    Array& operator=(const Array& other) //赋值运算符=
    {  
    if (this != &other) {  
        delete[] data;  
        size = other.size;
        capacity = other.capacity;  
        data = new T[capacity];  
        for (size_t i = 0; i < size; ++i) 
        {  
            data[i] = other.data[i];  
        }  
    }  
    return *this;  
    }
    bool operator==(const Array& other) const //运算符重构==
    {  
    if (size != other.size) 
    {  
        return false;  
    }  
    for (size_t i = 0; i < size; ++i) 
    {  
        if (data[i] != other.data[i]) 
        {  
            return false;  
        }  
    }  
    return true;  
    }
    size_t pushBack(const T& value)   
{     
    if (size == capacity)//需要扩容时，变为原数组长度的2倍，并根据新容量重新分配内存空间 
    {  
        capacity *= 2;    
        T* newData = new T[capacity];    
        for (size_t i = 0; i < size; ++i)   
        {    
            newData[i] = data[i];    
        }    
        delete[] data;    
        data = newData;    
    }
    data[size] = value;//在已有空间添加元素    
    ++size;    
    return size; //返回新的数组长度  
}
};  
int main() 
{  
    Array<int> a(5); //创建一个大小为5的整数数组  
    a[2] = 10;       //设置第三个元素为10  
    std::cout << "a[2] = " << a[2] << std::endl; //输出第三个元素的值，应为10  
    std::cout << "*(a+1) = " << *a + 1 << std::endl; //输出第二个元素的值，应为11（假设a[0]为1）  
    std::cout << "a.getSize() = " << a.getSize() << std::endl; //输出数组长度，应为5  
    Array<int> b(5);  
    a = b; //赋值操作  
    if (a == b) 
    { //比较两个类是否相等  
        std::cout << "两者相等" << std::endl;  
    } else 
    {  
        std::cout << "两者不相等" << std::endl;  
    }
    a.pushBack(6);//进行pushback
    std::cout << "pushback后" <<a.getSize() << std::endl;
    std::cout << "此时新添加的元素" << a[a.getSize()] << std::endl;
    a.pushBack(6);//再次进行
    std::cout << "再次pushback后" <<a.getSize() << std::endl;
    std::cout << "此时新添加的元素" << a[a.getSize()] << std::endl;

    return 0;  
}