#include <iostream>
#include <string>
#include <cstring>

struct Vector2
{
    float x, y;

};

class String
{
    private:
    char* m_Buffer;
    unsigned int m_Size;
public:
    String(const char* string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string, m_Size);
        m_Buffer[m_Size] = 0;
    }

    // Deep copy
    // ALLWAYS PASS OBJECTS BY CONST REFERENCE
    String(const String& other)
        : m_Size(other.m_Size)
    {
        std::cout << "Deep Copied 1!" << std::endl;
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    }

    // ✅ Copy Assignment Operator (deep copy)
    String& operator=(const String& other) {
        if (this == &other)
            return *this; // avoid self-assignment

        delete[] m_Buffer; // clean up existing
        std::cout << "Deep Copied 2!" << std::endl;    
        m_Size = other.m_Size;
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);

        return *this;
    }

    ~String()
    {
        delete[] m_Buffer;
    }

    char& operator[](unsigned int index)
    {
        return m_Buffer[index];
    }

    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Buffer;
    return stream;
}

void PrintString(const String& string)
{
    std::cout << string << std::endl;
}

int main()
{
    //int a = 2;
    //int b = a; // we are copying to be the content of a: two memory addresses.
    //b = 3; // b is another place in the memory
    //std::cout << a << std::endl;
    //std::cout << b << std::endl;

    // Copy
    //Vector2 a = {2, 3};
    //Vector2 b = a;
    //b.x = 5;

    // Pointer
    //Vector2* a = new Vector2();
    //Vector2* b = a;

    // This copy returns an error, as the private pointer member is copied.
    // When one class gets destroyed, the pointer also gets destroyed. Then
    // the second class attempts to access to a memory that has been freed up.
    String string = "Cherno";
    //String* string = new String("Cherno");
    String second = string;  //invokes String(const String& other)
    second[2] = 'a';

    String third = "Hello";
    third = second;

    std::cout << string << std::endl;
    std::cout << second << std::endl;

    PrintString(string);
    PrintString(second);

}