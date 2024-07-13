#include <iostream>
#include <memory>
#include <cstdlib> // For rand()

class Alertador
{
    public:
    Alertador() {
        std::cout << "CONSTRUCTOR alertador \n";
    }
    ~Alertador() {
        std::cout << "DESTRUCTOR alertador \n";
    }
};

int funcionVariasSalidas()
{
    std::unique_ptr<Alertador> instancia { new Alertador };
    int r = rand();

    if (r < RAND_MAX / 2)
    {
        std::cout << "Flujo de ejecucion 1 \n";
        return 42;
    }
    else
    {
        std::cout << "Flujo de ejecucion 2 \n";
        return 24;
    }
}

void anotherFunction(std::shared_ptr<Alertador> arg)
{
    // something
}

int main() {
    // This calles constructor and destructor
    //Alertador instancia;

    // This calls only constructor and destructors
    //Alertador * instancia = new Alertador;
    //delete instancia;

    // unique pointer
    //std::unique_ptr<Alertador> instancia { new Alertador };

    // The unique pointer is created and destroied for each iteration
    //for (int i = 0; i < 10; ++i)
    //{
    //    funcionVariasSalidas();
    //}

    // Combining unique pointers with traditional pointers.
    //std::unique_ptr<Alertador> instancia { new Alertador };
    //Alertador * punteroTradicional = instancia.get();

    // Passing a unique pointer to a function: shared pointer. Shared pointer    
    //std::shared_ptr<Alertador> instancia { new Alertador };
    // make_shared is more efficient than new
    std::shared_ptr<Alertador> instancia = std::make_shared<Alertador>();
    anotherFunction(instancia);

    // Here the three pointers point at te same resource
    std::cout << "Ambito externo \n";
    //std::shared_ptr<Alertador> instancia { new Alertador };
    {
        std::cout << "Ambito 1 \n";
        std::shared_ptr<Alertador> ptr2 = instancia; //copy
        {
            std::cout << "Ambito 2 \n";
        std::shared_ptr<Alertador> ptr3 = instancia; //copy
        }
    }

    // To manualy free up the memory resources, instead of waiting for the end of the main program.
    instancia.reset();    
    std::cout << "Terminado \n";


    return 0;
}