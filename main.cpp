#include<iostream>
#include<algorithm>

// sizes: 1 - small; 2 small-medium; 3 - medium; 4 medium - large; 5 large;
// coats: 1 - double; 2 short; 3 long; 4; curly

class goldenRetriever {
    public:
        int coat_type = 1; // 1 = double coat
        std::string colors[5] = {"cream", "gold", "dark gold", "dark red"};
        int size = 4;
};

std::string input_color;
int input_size;
std::string raw_size;
std::string coat_raw;
int input_coat_type;

// this function converts the coat type into the integer format
void coat(std::string to_lower) {
    std::transform(to_lower.begin(), to_lower.end(), to_lower.begin(), ::tolower);
    if (to_lower == "double") {
        input_coat_type = 1;
    } else if (to_lower == "short") {
        input_coat_type = 2;
    } else if (to_lower == "long") {
        input_coat_type = 3;
    } else if (to_lower == "curly") {
        input_coat_type = 4;
    } else {
        throw std::runtime_error("coat not found");
    }
}

void compare_color(std::string color) {
    
}

// this function converts the size into the integer format for easier comparison
void size(std::string size) {
    std::transform(size.begin(), size.end(), size.begin(), ::tolower);
    if (size == "small") {
        input_size = 1;
    } else if (size == "small-medium") {
        input_size = 2;
    } else if (size == "medium") {
        input_size = 3;
    } else if (size == "medium-large") {
        input_size = 4;
    } else if (size == "large") {
        input_size = 5;
    } else {
        throw std::runtime_error("size not found");
    }
}

void color(std::string lower) {
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
}

int main() {
    goldenRetriever glRet;
    std::cout << "dog-ident v1, for woof" << std::endl;
    std::cout << "what type of coat does your dog have? short, long, curly, double: ";
    std::cin >> coat_raw;
    try {
        coat(coat_raw);
    } catch (const std::exception& coat_error) {
        std::cout << "error: " << coat_error.what() << std::endl;
        return 1;
    }
    std::cout << "how large is your dog? small, small-medium, medium, medium-large, large: ";
    std::cin >> raw_size;
    try {
        size(raw_size);
    } catch (const std::exception& size_error) {
        std::cout << "error: " << size_error.what() << std::endl;
        return 1;
    }
    std::cout << input_size;
    std::cout << "what is the color of your dog? keep it 1 word only: ";
    std::cin >> input_color;
    color(input_color);
    return 0;
}