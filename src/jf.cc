#include <iostream>
#include <fstream>
#include <iomanip>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

int main(int argc, const char* argv[]) {

    if (argc < 2) {
        std::cerr << "usage: jf <path(s)-to-json-file-to-be-prettified>\n";
        return -1;
    }

    for (++argv; *argv; ++argv){
        std::ifstream i(*argv);
        json j;
        i >> j;

        std::ofstream o(*argv);
        o << j.dump(4) << std::endl;
    }
}
