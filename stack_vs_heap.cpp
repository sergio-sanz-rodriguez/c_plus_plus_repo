#include <iostream>
#include <string>

struct Vector3
{
    float x, y, z;

    Vector3(): x(10), y(11), z(12) {}
};

int main()
{
    // value, array and vector are allocated next to each other.
    // Stack pointer basically moves when allocating memory.
    // Stack is literally fast, you only need one instruction (move)
    // When the scope comes to an end, everthing on the stack is removed!
    // Stack has limited space: 1-2 MB
    int value = 5; //stack
    int array[5];
    std::string word{"hello world"};
    for (int i = 0; i < 5; ++ i)
    {
        array[i] = i;
    }
    Vector3 vector;

    // On stack you need to manually free memory, unless you use smart pointers
    // new keyword calls malloc, and that is a whole thing compared to just move instruction
    // Reasons to allocate on the heap:
    // - Variable size at runtime, when you do not know the size of the data beforehand
    // - Longer lifetime than the scope of your function
    // - Your need more data, e.g. 50 MB, you have to allocate on the heap.

    int* hvalue = new int; //new keword is the way to allocate memory on the heap
    *hvalue = 5;
    int* harray = new int[5];
    for (int i = 0; i < 5; ++ i)
    {
        array[i] = i;
    }
    Vector3* hvector = new Vector3();

    delete hvalue;
    delete harray;
    delete hvector;







}
