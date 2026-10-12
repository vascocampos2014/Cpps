#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;
    data.datanbr = 42;
    data.datac = 'a';
    data.datad = 4.2;

    uintptr_t raw = Serializer::serialize(&data);
    Data* result = Serializer::deserialize(raw);

    std::cout << "Original address:     " << &data << std::endl;
    std::cout << "Serialized value:     " << raw << std::endl;
    std::cout << "Deserialized address: " << result << std::endl;

    if (result == &data)
        std::cout << "OK: pointers are equal" << std::endl;
    else
        std::cout << "KO: pointers are different" << std::endl;

    std::cout << "datanbr: " << result->datanbr << std::endl;
    std::cout << "datac:   " << result->datac << std::endl;
    std::cout << "datad:   " << result->datad << std::endl;
    return 0;
}
