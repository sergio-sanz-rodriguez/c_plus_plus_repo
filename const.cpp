#include <iostream>
#include <string>

class Entity
{
    private:    
    int m_X, m_Y;
    int *p_m_X;
    // you can use "mutable" if you need to modify the variable event though it is insieda a constant method.
    mutable int var;
    
    public:
    // With this you cannot modify class-member variables
    int GetX() const
    {
        // m_X = 2; // error
        var = 2;
        return m_X;
    }

    int GetX()
    {
        // m_X = 2; // error
        return m_X;
    }

    //we are returning a pointer that cannot be modified, the contents of the pointer cannot be modified, and the function promises not to modify the acutal entity class
    const int* const GetX_ptr() const
    {
        return p_m_X;
    }

    void SetX(int x)
    {
        m_X = x;
    }    
};

// To make this function work the function would use the const version of GetX()
void PrintEntity(const Entity & e)
{
    std::cout << e.GetX() << std::endl;
}

int main()
{
    // I am not goint to change this variable
    const int MAX_AGE = 90;

    // you cannot modify the content of that pointer
    const int* a = new int; // or int const* a = new int
    // *a = 2; -> here is an error

    // but I can change the pointer itselft
    a = (int*)&MAX_AGE;

    // Or the other way around. I can change the content of the pointer but cannot reasign the actual pointer itself to point to another address.
    int* const b = new int;
    *b = 2; // correct!
    //b = (int*)&MAX_AGE; //error
    
    //you cannot change the content of the pointer and cannot change the pointer's address.
    //const int* const c = new int;

    std::cout << *a << ", " << *b << std::endl;

}