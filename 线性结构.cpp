#include <iostream>
template <typename T>  
class Array 
{  
private:  
    T* data;  
    size_t size;  
    size_t capacity;
public:  
    Array(size_t size = 0) :size(size),capacity(size) // ���캯�� 
    {  
        data = size ? new T[capacity] : nullptr;  
    }  
    ~Array() // ��������
    {  
        delete[] data;  
    }  
    Array(const Array& other) : size(other.size), capacity(other.capacity) //���ƹ���
    {  
        data = new T[capacity];  
        for (size_t i = 0; i < size; ++i) 
        {  
            data[i] = other.data[i];  
        }  
    }  
    size_t getSize() const // ��ȡ���鳤��  
    {  
        return size;  
    }  
    T& operator[](size_t index) // [] ���������
    {  
        if (index >= size) 
        {  
            throw std::out_of_range("Index out of range");  
        }  
        return data[index];  
    }  
    T& operator*() // * ��������أ�������Ԫ������  
    {  
        return data[0];  
    }  
    T* operator+(size_t index) // + ��������أ�����ƫ�ƺ�ĵ�ַ  
    {  
        if (index >= size) 
        {  
            throw std::out_of_range("Index out of range");  
        }  
        return &data[index];  
    }  
    Array& operator=(const Array& other) //��ֵ�����=
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
    bool operator==(const Array& other) const //������ع�==
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
    if (size == capacity)//��Ҫ����ʱ����Ϊԭ���鳤�ȵ�2�������������������·����ڴ�ռ� 
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
    data[size] = value;//�����пռ����Ԫ��    
    ++size;    
    return size; //�����µ����鳤��  
}
};  
int main() 
{  
    Array<int> a(5); //����һ����СΪ5����������  
    a[2] = 10;       //���õ�����Ԫ��Ϊ10  
    std::cout << "a[2] = " << a[2] << std::endl; //���������Ԫ�ص�ֵ��ӦΪ10  
    std::cout << "*(a+1) = " << *a + 1 << std::endl; //����ڶ���Ԫ�ص�ֵ��ӦΪ11������a[0]Ϊ1��  
    std::cout << "a.getSize() = " << a.getSize() << std::endl; //������鳤�ȣ�ӦΪ5  
    Array<int> b(5);  
    a = b; //��ֵ����  
    if (a == b) 
    { //�Ƚ��������Ƿ����  
        std::cout << "�������" << std::endl;  
    } else 
    {  
        std::cout << "���߲����" << std::endl;  
    }
    a.pushBack(6);//����pushback
    std::cout << "pushback��" <<a.getSize() << std::endl;
    std::cout << "��ʱ����ӵ�Ԫ��" << a[a.getSize()] << std::endl;
    a.pushBack(6);//�ٴν���
    std::cout << "�ٴ�pushback��" <<a.getSize() << std::endl;
    std::cout << "��ʱ����ӵ�Ԫ��" << a[a.getSize()] << std::endl;

    return 0;  
}