#include <iostream>

class smart_array {
    int* ptr;
    size_t size;
    size_t copacity;

public:
    smart_array(size_t copacity) : copacity(copacity), size(0)
    {
        ptr = new int[copacity];
    }


    void operator=(smart_array& sa)
    {
        delete [] this->ptr;
        this->copacity = sa.copacity;
        size = 0;
        this->ptr = new int[copacity];
        for (size_t i = 0; i < sa.size; ++i)
        {
            add_element(sa.ptr[i]);
        }
    }


    void add_element(int el)
    {
        check_out_of_range(size);
        ptr[size++] = el;
    }

    int get_element(size_t index)
    {
        check_out_of_range(index);
        return ptr[index];
    }

    ~smart_array()
    {
        delete [] ptr;
    }

private:
    void check_out_of_range(size_t index) {
        if(index >= copacity)
        {
            throw std::exception();
        }
    }

};

int main()
{
    smart_array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    smart_array new_array(2);
    new_array.add_element(44);
    new_array.add_element(34);

    arr = new_array;
    for(int i = 0; i < 2; ++i)
        std::cout << arr.get_element(i) << " ";
    std::cout << std::endl;
}
