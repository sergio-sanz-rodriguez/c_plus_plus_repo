#include <iostream>
#include <string>

class Entity
{
    private:
    std::string m_Name;
    mutable int m_DebugCount = 0;
    public:
    // By returning a reference, you avoid making a copy of the m_Name string. If the string is large or if this function is called frequently, this can save significant memory and processing time.
    const std::string& GetName() const
    {
        m_DebugCount++;
        return m_Name;
    }

};

int main()
{
    const Entity e;
    e.GetName();

    int x = 8;
    //you pass the variable not by reference (&) but by value (=). If you do so, you have to declare the function with mutable
    auto f = [=]() mutable
    {
        x++; // this x is a copy; without mutable this gives an error as variable x is read-only. With mutable you make this copy of x also writable.
        std::cout << x << std::endl;
    };
    
    // x is still 8
    f();
    std::cout << x << std::endl;

    return 0;

}