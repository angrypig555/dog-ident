#include<iostream>

// sizes: 1 - small; 2 small-medium; 3 - medium; 4 medium - large; 5 large;

class goldenRetriever {
    public:
        int coat_type = 1; // 1 = double coat
        std::string colors[5] = {"cream", "gold", "dark gold", "dark red"};
        int size = 4;
};

int main() {
    std::cout << "dog-ident v1, for woof" << std::endl;
    return 0;
}