#include <vector>
#include <initializer_list>
#include <algorithm>
#include <string>

class Block : public std::vector<std::string>
{
public:
    Block(int size) : std::vector<std::string>(size) {}
    
    std::string& operator[](std::size_t pos) override;
    const std::string& operator[](std::size_t pos) const override;

    std::string& at(std::size_t pos) override;
    const std::string& at(std::size_t pos) const override;

    
};

