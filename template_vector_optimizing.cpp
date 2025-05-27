#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
    float x, y, z;

    Vertex(float x, float y, float z)
        : x(x), y(y), z(z) {}

    //Vertex(const Vertex& other)
    //    : x(other.x), y(other.y), z(other.z)
    //{
    //    std::cout << "Copied!" << std::endl;
    //}
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;
}   

/*
Key Concepts Involved:
Temporary objects: Vertex(1, 2, 3) creates a temporary (rvalue) object.

Copying: Since the Vertex struct has a user-defined copy constructor and no move constructor, the temporary must be copied.

Vector reallocation: std::vector manages its own dynamic array. When it needs more capacity, it reallocates and copies existing elements into the new memory.
*/
int main()
{
    // Six copies
    /*
    1. First push_back(Vertex(1, 2, 3))
        A temporary Vertex is created → no "Copied!" yet.
        The temporary is copied into the vector → prints "Copied!" (1st copy).
    
    2. Second push_back(Vertex(4, 5, 6))
        Temporary Vertex is created.
        The vector currently has capacity for only 1 element. It needs to reallocate.
        It:
            Allocates a new array with larger capacity (typically doubled, from 1 to 2).
            Copies the existing element (1st Vertex) to the new memory → prints "Copied!" (2nd copy).
            Copies the temporary into the new memory → prints "Copied!" (3rd copy).
    3. Third push_back(Vertex(7, 8, 9))
        Temporary Vertex is created.
        Again, vector needs to reallocate (capacity 2 → 4).
        It:
            Copies both existing elements to the new memory → prints "Copied!" (4th and 5th copies).
            Copies the temporary → prints "Copied!" (6th copy).    
    */

    std::vector<Vertex> vertices;
    vertices.push_back(Vertex(1, 2, 3));
    vertices.push_back(Vertex(4, 5, 6));  
    vertices.push_back(Vertex(7, 8, 9));    

    // Three copies
    std::vector<Vertex> vertices2;
    vertices2.reserve(3);
    vertices2.push_back(Vertex(1, 2, 3));
    vertices2.push_back(Vertex(4, 5, 6));  
    vertices2.push_back(Vertex(7, 8, 9));    

    // No copies
    std::vector<Vertex> vertices3;
    //vertices3.reserve(3);
    vertices3.emplace_back(1, 2, 3);
    vertices3.emplace_back(4, 5, 6);
    vertices3.emplace_back(7, 8, 9);
    
}
