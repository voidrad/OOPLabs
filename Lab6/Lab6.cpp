//
// Created by YaTeb on 12/27/2020.
//

#include "square.hpp"
#include "list.hpp"
#include "allocator.hpp"
#include <algorithm>

void print_help() {
    std::cout
            << "+---------------------------------+-------------------------------------------+\n"
            << "| add [idx] [vertex_1] [vertex_2] |              Add Figure                   |\n"
            << "+---------------------------------+-------------------------------------------+\n"
            << "|           del [index]           |         Del figure for idx                |\n"
            << "+---------------------------------+-------------------------------------------+\n"
            << "|              print              |        Print figures                      |\n"
            << "+---------------------------------+-------------------------------------------+\n"
            << "|          less [value]           |    Number of figures with area  < value   |\n"
            << "+---------------------------------+-------------------------------------------+\n"
            << "|              help               |              help                         |\n"
            << "+---------------------------------+-------------------------------------------+\n"
            << "|         <end of line>           |           end                             |\n"
            << "+---------------------------------+-------------------------------------------+\n"
            << std::endl;
}

auto interactive_loop() -> void {
    std::string cmd;
    int idx;

    List< Square<int>, allocators::stack_allocator<Square<int>> > list;

    while (std::cin >> cmd) {
        if (cmd == "add") {
            std::cin >> idx;
            auto iter = list.begin();
            for (int i = 0; i < idx; ++i) {
                ++iter;
            }

            try {
                Square<int> input_rec;
                std::cin >> input_rec;
                list.insert(iter, std::move(input_rec));
            } catch (std::exception& exp) {
                std::cerr << "ERROR: " <<exp.what() << std::endl;
                continue;
            }
        } else if (cmd == "del") {
            std::cin >> idx;
            auto iter = list.begin();
            for (int i = 0; i < idx; ++i) {
                ++iter;
            }

            try {
                list.erase(iter);
            } catch (std::exception& exp) {
                std::cerr << "ERROR: " <<exp.what() << std::endl;
                continue;
            }
        } else if (cmd == "print") {
            if (list.size() == 0) {
                std::cout << "List is empty" << std::endl;
            }
            else {
                std::for_each(list.begin(), list.end(), [](const Square<int>& rec) { std::cout << rec << std::endl; });
            }
        } else if (cmd == "less") {
            double max_area;
            std::cin >> max_area;
            int res = std::count_if(list.begin(), list.end(), [&max_area](const Square<int>& rec){ return rec.area() < max_area; });
            std::cout << "Total amount = " << res << std::endl;
        } else if (cmd == "help") {
            print_help();
        } else {
            std::cerr << "ERROR: Invalid command" << std::endl;
        }
    }
}

int main(){
    try {
        print_help();
        interactive_loop();
    } catch (std::exception& exp) {
        std::cerr << "ERROR: " <<exp.what() << std::endl;
    }
    return 0;
}