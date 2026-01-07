#include<iostream>
#include<algorithm>

// sizes: 1 - small; 2 small-medium; 3 - medium; 4 medium - large; 5 large; 
// coats: 1 - double; 2 short; 3 long; 4 curly; 5 rough

class goldenRetriever {
    public:
        int coat_type = 1; // 1 = double coat
        std::string colors[5] = {"cream", "gold", "dark gold", "dark red"};
        int size = 4;
};

class borderCollie {
    public:
        int coat_type = 5;
        std::string colors = "multicolor";
        int size = 3;
};

class frenchBulldog {
    public:
        int coat_type = 2;
        std::string colors[5] = {"white", "brindle", "multicolor", "fawn", "tan"};
        int size = 2;
};

std::string input_color;
int input_size;
std::string raw_size;
std::string coat_raw;
int input_coat_type;
int is_golden_retriever_color;
int is_border_collie_color;
int is_bulldog_color;
int is_golden_retriever_size;
int is_border_collie_size;
int is_bulldog_size;
int is_golden_retriever_coat;
int is_border_collie_coat;
int is_bulldog_coat;
int is_golden_retriever;
int is_border_collie;
int is_bulldog;
std::string yesno;
// int result_accuracy; unused for now

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
    } else if (to_lower == "rough") {
        input_coat_type = 5;
    } else {
        throw std::runtime_error("coat not found");
    }
    
}

void compare_color(std::string color) {
    goldenRetriever gl;
    auto it = std::find(gl.colors, gl.colors + 5, color);
    if (it != gl.colors + 5) {
        is_golden_retriever_color = 1;
    } else {
        is_golden_retriever_color = 0;
    }
    borderCollie bl;
    if (color == bl.colors) {
        is_border_collie_color = 1;
    } else {
        is_border_collie_color = 0;
    }
    frenchBulldog fb;
    auto fbit = std::find(fb.colors, fb.colors + 5, color);
    if (fbit != fb.colors + 5) {
        is_bulldog_color = 1;
    } else {
        is_bulldog_color = 0;
    }
}

void compare_size(int size) {
    goldenRetriever gl;
    borderCollie bl;
    if (size == 4) {
        is_golden_retriever_size = 1;
    } else if (size == 3) {
        is_border_collie_size = 1;
    } else if (size == 2) {
        is_bulldog_size = 1;
    } else {
        throw std::runtime_error("your dog is currently not in our db :( please open a ticket in the github repo, error in compare_size");
    }
}

void compare_coat(int coat) {
    goldenRetriever gl;
    borderCollie bl;
    if (coat == 1) {
        is_golden_retriever_coat = 1;
    } else if (coat == 5) {
        is_border_collie_coat = 1;
    } else if (coat == 2) {
        is_bulldog_coat = 1;
    } else {
        throw std::runtime_error("your dog is currently not in our db :( please open a ticket in the github repo, error in compare_coat");
    }
}

void compare_final() {
    goldenRetriever gl;
    borderCollie bl;
    if (is_golden_retriever_coat == 1 and is_golden_retriever_color == 1 and is_golden_retriever_size == 1) {
        is_golden_retriever = 1;
        std::cout << "Is your dog a golden retriever?" << std::endl;
    } else if (is_border_collie_coat == 1 and is_border_collie_color == 1 and is_border_collie_size == 1) {
        is_border_collie = 1;
        std::cout << "Is your dog a border collie?" << std::endl;
    } else if (is_bulldog_coat == 1 and is_bulldog_color == 1 and is_bulldog_size == 1) {
        is_bulldog = 1;
        std::cout << "Is your dog a french bulldog?" << std::endl;
    } else {
        throw std::runtime_error("your dog is currently not in our db :( please open a ticket in the github repo error in compare_final");
    }

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

void color(std::string &lower) {
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
}

void lower(std::string &lower) {
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
}

int main() {
    goldenRetriever glRet;
    std::cout << "dog-ident v1, for woof" << std::endl;
questions:
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
    std::cout << input_size; // for debug
    std::cout << "what is the color of your dog? keep it 1 word only, if it has multiple colors write multicolor: ";
    std::cin >> input_color;
    color(input_color);
    try {
        compare_color(input_color);
    } catch (const std::exception& color_cmp_error) {
        return 1; // todo: add the error handler
    }
    try {
        compare_size(input_size);
    } catch (const std::exception& size_cmp_error) {
        std::cout << "error: " << size_cmp_error.what() << std::endl;
        return 1;
    }
    try {
        compare_coat(input_coat_type);
    } catch (const std::exception& coat_error) {
        std::cout << "error: " << coat_error.what() << std::endl;
        return 1;
    }
    try {
        compare_final();
    } catch (const std::exception& compare_error) {
        std::cout << "error: " << compare_error.what() << std::endl;
        return 1;
    } 
    std::cin >> yesno;
    lower(yesno);
    if (yesno == "no") {
        goto questions;
    } else if (yesno == "yes") {
        std::cout << "yay!" << std::endl;
        std::cout << "if you have any dog breeds that you would like to get added, please open an issue in the repo" << std::endl;
        std::cout << "thank you for using dog-ident" << std::endl;
    }

    return 0;
}