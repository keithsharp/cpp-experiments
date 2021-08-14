#include <iostream>
#include <random>

#include <boost/program_options.hpp>

namespace po = boost::program_options;

int main(int argc, char** argv) {
    int seed;

    po::options_description desc("Allowed options");
    desc.add_options()
        ("help", "show help message")
        ("seed,s", po::value<int>(&seed), "set seed value")
    ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << std::endl;
        return 1;
    }

    if (vm.count("seed")) {
        std::cout << "Seed value: " << seed << std::endl;
    } else {
        std::cout << "No seed value specified." << std::endl;
        return 2;
    }

    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(seed) };
    std::uniform_int_distribution number{ 1, 10 };
    for (int i = 0; i <= 10; i++) {
        std::cout << number(mersenne) << std::endl;
    }

    std::uniform_real_distribution<float> real_number{ -10, 10 };
    for (int i = 0; i <= 10; i++) {
        std::cout << real_number(mersenne) << std::endl;
    }

    return 0;
}