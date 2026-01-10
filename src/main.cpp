#include<iostream>
#include<algorithm>

// hello anyone looking to add a dog breed to this program, i left this as a reference.
// please always name classes like this: fooBar
// and integers like this: is_foo_bar
// sizes: 1 - small; 2 small-medium; 3 - medium; 4 medium - large; 5 large; 
// coats: 1 - double; 2 short; 3 long; 4 curly; 5 rough; 6 fleece
// intelligence: 1 - not_very; 2 - average; 3 - smart; 4 - very_smart

class goldenRetriever {
    public:
        int coat_type = 1; // 1 = double coat
        std::string colors[5] = {"cream", "gold", "dark gold", "dark red"};
        int size = 4;
        int intelligence = 4;
};

class borderCollie {
    public:
        int coat_type = 5;
        std::string colors = "multicolor";
        int size = 3;
        int intelligence = 4;
};

class frenchBulldog {
    public:
        int coat_type = 2;
        std::string colors[5] = {"white", "brindle", "multicolor", "fawn", "tan"};
        int size = 2;
        int intelligence = 3;
};

class dachshund {
    public:
        int coat_type = 2;
        std::string colors[6] = {"black", "brown", "chocolate", "cream", "tan", "red"};
        int size = 1;
        int intelligence = 2;
};

class poodle {
    public:
        int coat_type = 4;
        std::string colors[10] = {"black", "white", "apricot", "cream", "multicolor", "silver", "brown", "red", "grey", "blue"};
        int size = 2;
        int intelligence = 4;
};

class mini_labradoodle {
    public:
        int coat_type = 6;
        std::string colors[7] = {"cream", "gold", "apricot", "red", "black", "silver", "multicolor"};
        int size = 1;
        int intelligence = 4;
};

class labrador {
    public:
        int coat_type = 1;
        std::string colors[5] = {"black", "chocolate", "brown", "yellow", "cream"};
        int size = 3;
        int intelligence = 4;
};

std::string input_color;
int input_size;
std::string raw_size;
std::string raw_intel;
std::string coat_raw;
int input_coat_type;
int input_intel;

int is_golden_retriever_color;
int is_golden_retriever_size;
int is_golden_retriever_coat;
int is_golden_retriever_intel;
int is_golden_retriever;
int is_border_collie_color;
int is_border_collie_size;
int is_border_collie_coat;
int is_border_collie_intel;
int is_border_collie;
int is_bulldog_color;
int is_bulldog_size;
int is_bulldog_coat;
int is_bulldog_intel;
int is_bulldog;
int is_dachshund_color;
int is_dachshund_size;
int is_dachshund_coat;
int is_dachshund_intel;
int is_dachshund;
int is_poodle_color;
int is_poodle_size;
int is_poodle_coat;
int is_poodle_intel;
int is_poodle;
int is_mlabradoodle_color;
int is_mlabradoodle_size;
int is_mlabradoodle_coat;
int is_mlabradoodle_intel;
int is_mlabradoodle;
int is_labrador_color;
int is_labrador_size;
int is_labrador_coat;
int is_labrador_intel;
int is_labrador;
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
    } else if (to_lower == "fleece") {
        input_coat_type = 6;
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
    dachshund d;
    auto dit = std::find(d.colors, d.colors + 6, color);
    if (dit != d.colors + 6) {
        is_dachshund_color = 1;
    } else {
        is_dachshund_color = 0;
    }
    poodle p;
    auto pit = std::find(p.colors, p.colors + 10, color);
    if (pit != p.colors + 10) {
        is_poodle_color = 1;
    } else {
        is_poodle_color = 0;
    }
    mini_labradoodle ml;
    auto mlit = std::find(ml.colors, ml.colors + 7, color);
    if (mlit != ml.colors + 7) {
        is_mlabradoodle_color = 1;
    } else {
        is_mlabradoodle_color = 0;
    }
    labrador l;
    auto lit = std::find(l.colors, l.colors + 5, color);
    if (lit != l.colors + 5) {
        is_labrador_color = 1;
    } else {
        is_labrador_color = 0;
    }
}

void compare_size(int size) {
    goldenRetriever gl;
    borderCollie bl;
    if (size == 4) {
        is_golden_retriever_size = 1;
    } else if (size == 3) {
        is_border_collie_size = 1;
        is_labrador_size = 1;
    } else if (size == 2) {
        is_bulldog_size = 1;
        is_poodle_size = 1;
    } else if (size == 1) {
        is_dachshund_size = 1;
        is_mlabradoodle_size = 1;
    } else {
        throw std::runtime_error("your dog is currently not in our db :( please open a ticket in the github repo, error in compare_size");
    }
}

void compare_coat(int coat) {
    goldenRetriever gl;
    borderCollie bl;
    if (coat == 1) {
        is_golden_retriever_coat = 1;
        is_labrador_coat = 1;
    } else if (coat == 5) {
        is_border_collie_coat = 1;
    } else if (coat == 2) {
        is_bulldog_coat = 1;
        is_dachshund_coat = 1;
    } else if (coat == 4) {
        is_poodle_coat = 1;
    } else if (coat == 6) {
        is_mlabradoodle_coat = 1;
    } else {
        throw std::runtime_error("your dog is currently not in our db :( please open a ticket in the github repo, error in compare_coat");
    }
} 

void intelligence(std::string intel){
    std::transform(intel.begin(), intel.end(), intel.begin(), ::tolower);
     if (intel == "not_very") {
        input_intel = 1;
    } else if (intel == "average") {
        input_intel = 2;
    } else if (intel == "smart") {
        input_intel = 3;
    } else if (intel == "very_smart") {
        input_intel = 4;
    } else {
        throw std::runtime_error("intelligence level not found");
    }
}

void compare_intelligence(int intel) {
    goldenRetriever gl;
    borderCollie bl;
    dachshund d;
    poodle p;
    switch(intel) {
        case 1:
            break;
        case 2:
            is_dachshund_intel = 1;
            break;
        case 3:
            is_bulldog_intel = 1;
            break;
        case 4:
            is_golden_retriever_intel = 1;
            is_border_collie_intel = 1;
            is_poodle_intel = 1;
            is_mlabradoodle_intel = 1;
            is_labrador_intel = 1;
            break;
        default:
            throw std::runtime_error("your dog is currently not in our db :( please open a ticket in the github repo, error in compare_intelligence");

    }
}

void compare_final() {
    goldenRetriever gl;
    borderCollie bl;
    if (is_golden_retriever_coat == 1 and is_golden_retriever_color == 1 and is_golden_retriever_size == 1 and is_golden_retriever_intel == 1) {
        is_golden_retriever = 1;
        std::cout << "Is your dog a golden retriever?" << std::endl;
    } else if (is_border_collie_coat == 1 and is_border_collie_color == 1 and is_border_collie_size == 1 and is_border_collie_intel == 1) {
        is_border_collie = 1;
        std::cout << "Is your dog a border collie?" << std::endl;
    } else if (is_bulldog_coat == 1 and is_bulldog_color == 1 and is_bulldog_size == 1 and is_bulldog_intel == 1) {
        is_bulldog = 1;
        std::cout << "Is your dog a french bulldog?" << std::endl;
    } else if (is_dachshund_coat == 1 and is_dachshund_color == 1 and is_dachshund_size == 1 and is_dachshund_intel == 1) {
        is_dachshund = 1;
        std::cout << "Is your dog a dachshund?" << std::endl;
    } else if (is_poodle_coat == 1 and is_poodle_color == 1 and is_poodle_size == 1 and is_poodle_intel == 1) {
        is_poodle = 1;
        std::cout << "Is your dog a poodle?" << std::endl;
    } else if (is_mlabradoodle_coat == 1 and is_mlabradoodle_color == 1 and is_mlabradoodle_size == 1 and is_mlabradoodle_intel == 1) {
        is_mlabradoodle = 1;
        std::cout << "Is your dog a small labradoodle?" << std::endl;
    } else if (is_labrador_coat == 1 and is_labrador_color == 1 and is_labrador_size == 1 and is_labrador_intel == 1) {
        is_labrador = 1;
        std::cout << "Is your dog a labrador retriever?" << std::endl;
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
    std::cout << "what type of coat does your dog have? short, long, curly, double, fleece, rough: ";
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
    // std::cout << input_size; // for debug
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
    std::cout << "how intelligent would you describe your dog? not_very, average, smart, very_smart: ";
    std::cin >> raw_intel;
    try {
        intelligence(raw_intel);
    } catch(std::exception& intel_error) {
        std::cout << "error: " << intel_error.what() << std::endl;
        return 1;
    }
    try {
        compare_intelligence(input_intel);
    } catch(std::exception& intel_compare_error) {
        std::cout << "error: " << intel_compare_error.what() << std::endl;
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