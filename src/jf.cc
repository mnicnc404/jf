#include <iostream>
#include <fstream>
#include <iomanip>
#include <exception>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

int main(int argc, const char* argv[]) {

    if (argc < 2) {
        std::cerr << "usage: jf <path(s)-to-json-file-to-be-prettified>\n";
        return -1;
    }

    const int n = argc - 1;
    for (int i = 1; i < argc; i++) {
        std::cout << "[" << i << "/" << n << "] " << argv[i] << "\r";
        try {
            std::ifstream input(argv[i]);
            json j;
            input >> j;

            std::ofstream o(argv[i]);
            o << j.dump(4) << std::endl;
        } catch (std::exception &e) {
            std::cerr << std::endl << "something wrong handling " << argv[i] << ": " << e.what();
            std::cerr << "; ignoring.." << std::endl;
        }
    }
    std::cout << std::endl;
}
