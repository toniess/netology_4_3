#include <iostream>

class smart_array {
    int* ptr;
    size_t size;
    size_t copacity;

public:
    smart_array(const size_t copacity) : copacity(copacity), size(0)
    {
        ptr = new int[copacity];
    }

    smart_array(const smart_array& sa) : smart_array(sa.copacity)
    {
        for (size_t i = 0; i < sa.size; ++i)
        {
            add_element(sa.ptr[i]);
        }
    }

    smart_array& operator=(const smart_array& sa)
    {
        if(this != &sa)
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
        return *this;
    }


    void add_element(const int el)
    {
        check_out_of_range(size);
        ptr[size++] = el;
    }

    int get_element(const size_t index)
    {
        check_out_of_range(index);
        return ptr[index];
    }

    ~smart_array()
    {
        delete [] ptr;
    }

private:
    void check_out_of_range(const size_t index) {
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

    smart_array new_array(arr);
    new_array.add_element(44);
    new_array.add_element(34);
    arr = arr;
    for(int i = 0; i < 3; ++i)
        std::cout << new_array.get_element(i) << " ";
    std::cout << std::endl;
}
