//
// Created by YaTeb on 12/28/2020.
//
#include <iostream>
#include "document.hpp"

int main() {
    TDocument<int> doc;
    std::string s;
    while (std::cin >> s) {
        if (s == "new") {
            doc.CreateNew();
            std::cout << "Created new document" << std::endl;
        } else if (s == "open") {
            std::cin >> s;
            FILE* in = fopen(s.c_str(), "rb");
            if (in == NULL) {
                std::cout << "No such file on directory" << std::endl;
            } else {
                doc.LoadFromFile(in);
                std::cout << "Loaded document from " << s << std::endl;
                fclose(in);
            }
        } else if (s == "save") {
            std::cin >> s;
            FILE* out = fopen(s.c_str(), "wb");
            if (out == NULL) {
                std::cout << "No such file on directory" << std::endl;
            } else {
                doc.SaveToFile(out);
                std::cout << "Saved document to " << s << std::endl;
                fclose(out);
            }
        } else if (s == "add") {
            size_t pos;
            unsigned short type;
            std::cin >> pos >> type;
            doc.Add(pos, type);
        } else if (s == "rem") {
            size_t pos;
            std::cin >> pos;
            doc.Delete(pos);
        } else if (s == "print") {
            std::cout << "Printing document:" << std::endl;
            std::cout << doc;
        } else if (s == "undo") {
            doc.Undo();
        } else if (s == "help") {
            std::cout << "\'new\' - create new document" << std::endl;
            std::cout << "\'open\' - open document" << std::endl;
            std::cout << "\'save\' - save document" << std::endl;
            std::cout << "\'add\' - add a figure" << std::endl;
            std::cout << "\'rem\' - remove a figure" << std::endl;
            std::cout << "\'print\' - print document" << std::endl;
            std::cout << "\'undo\' - undo changes" << std::endl;
            std::cout << "\'help\' - show this message" << std::endl;
        } else {
            std::cout << "Unknown command. Type \'help\' to show help" << std::endl;
        }
    }
    return 0;
}