#include <iostream>
#include <memory>

class Entity
{
public:
    Entity()
    {
        std::cout << "Entity created!" << std::endl;
    }
    ~Entity()
    {
        std::cout << "Entity destroyed!" << std::endl;
    }
    void print() const
    {
        std::cout << "Im an entity!" << std::endl;
    }
};

int main()
{
    {
        std::shared_ptr<Entity> a_ptr = std::make_unique<Entity>();
        std::shared_ptr<Entity> b_ptr = a_ptr;
        a_ptr->print();
        b_ptr->print();
    }

}