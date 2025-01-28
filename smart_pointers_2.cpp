#include <iostream>
#include <memory>
#include <cstdlib> // For rand()
#include <string>

class Entity
{
public:
    Entity()
    {
        std::cout << "Created Entity!" << std::endl;
    }

    ~Entity()
    {
        std::cout << "Destroyed Entity!" << std::endl;
    }
};

int main()
{
    {
        std::shared_ptr<Entity> e0;
        {
            //std::unique_ptr<Entity> entity = std::make_unique<Entity>();
            // you cannot copy
            //std::unique_ptr<Entity> e0 = entity;

            // shared pointer
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
            e0 = sharedEntity;
        }
        // Here e0 does not die
    }
    // Here dies

     

    return 1;
}
