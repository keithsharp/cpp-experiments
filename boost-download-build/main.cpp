#include <iostream>

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

    return 0;
}