#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
    float x, y, z;

    //Vertex(float x, float y, float z)
    //    : x(x), y(y), z(z) {}

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

int main()
{
    std::vector<Vertex> vertices;
    vertices.push_back({1, 2, 3});
    vertices.push_back({4, 5, 6});    
    
    for (int i = 0; i < vertices.size(); i++)
        std::cout << vertices[i] << std::endl;
    
    vertices.erase(vertices.begin());
    for (Vertex& v : vertices)
        std::cout << v << std::endl;

}
