#include <iostream>

// Option A
class Singleton
{
private:
    static Singleton* s_Instance;
public:
    static Singleton& Get() { return *s_Instance; }
};

Singleton* Singleton::s_Instance = nullptr;

// Option B
class Singleton
{
public:
    static Singleton& Get()
    {
        static Singleton instance; //Extendens its lifetime forever till the object gets destroyed.
        return instance;
    }

    void Hello() {}

};

void Function()
{
   static int i = 0;
   i++;
   std::cout << i << std::endl;
}

int main()
{   
    // This prints i five times with value 1 if that variable is not static
    // If it is static the context of this variable is preserved.
    // It is like declaring i as a global variable, outside Function(), but
    // in global variables you can modifiy the value anywhere in the code,
    // but with static local, you can only modify its value inside the function
    // where it was declared.
    Function();
    Function();
    Function();
    Function();
    Function();
}
