//
// Created by YaTeb on 12/28/2020.
//
#include <ctime>
#include <functional>
#include <thread>
#include <vector>

#include "factory.hpp"
#include "method.hpp"

TPubSubMQ< std::vector< std::shared_ptr<IFigure> > > mq;
const std::string FOLDER = "C:\\Users\\YaTeb\\CLionProjects\\OOPLabs\\Lab8";
FILE* file = NULL;

std::string genFileName(size_t n) {
    std::string res;
    for (size_t i = 0; i < n; ++i) {
        res.push_back('a' + std::rand() % 26);
    }
    return res;
}

void ThreadFunc() {
    using functionType = std::function<void(std::shared_ptr<IFigure> fig)>;
    functionType PrintToStdout = [](std::shared_ptr<IFigure> fig) {
        fig->Print();
    };
    functionType WriteToFile = [](std::shared_ptr<IFigure> fig) {
        fig->Write(file);
    };
    std::vector<functionType> funcs({PrintToStdout, WriteToFile});
    bool awake = true;
    while (awake) {
        if (!mq.Empty()) {
            std::vector< std::shared_ptr< IFigure > > message = mq.Front();
            if (message.empty()) {
                awake = false;
                break;
            }
            file = fopen((FOLDER + genFileName(16)).c_str(), "wb");
            while (!message.empty()) {
                std::shared_ptr< IFigure > figPtr = message.back();
                message.pop_back();
                for (auto func : funcs) {
                    func(figPtr);
                }
            }
            fclose(file);
            mq.Pop();
        }
    }
}

using SCALAR_TYPE = int;

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Missing argument!" << std::endl;
        return -1;
    }
    std::cout << "Input figures like in Lab 7" << std::endl;
    size_t bufferSize;
    try {
        bufferSize = std::stoi(std::string(argv[1]));
    } catch (std::exception & ex) {
        std::cout << ex.what() << std::endl;
        return -1;
    }
    std::srand(time(NULL));
    std::thread myThread(ThreadFunc);
    std::vector< std::shared_ptr<IFigure> > figures;
    unsigned int type;
    while (std::cin >> type) {
        if (type == SQUARE_TYPE_ID) {
            std::cout << "Input square as follows: x y a" << std::endl;
            std::cout << "x, y is a left bottom corner cords" << std::endl;
            std::cout << "a is square side" << std::endl;
            figures.push_back(TFactory<SCALAR_TYPE, TSquare<SCALAR_TYPE> >::CreateFigure());
            std::cout << "Nice" << std::endl;
        } else if (type == RECTANGLE_TYPE_ID) {
            std::cout << "Input rectangle as follows: x y a b" << std::endl;
            std::cout << "x, y is a left bottom corner cords" << std::endl;
            std::cout << "a and b are width and heigth" << std::endl;
            figures.push_back(TFactory<SCALAR_TYPE, TRectangle<SCALAR_TYPE> >::CreateFigure());
            std::cout << "Nice" << std::endl;
        } else if (type == TRAPEZE_TYPE_ID) {
            std::cout << "Input trapeze as follows: x y a b c" << std::endl;
            std::cout << "x, y is a left bottom corner cords" << std::endl;
            std::cout << "a, b and c are larger, smaller base and height" << std::endl;
            figures.push_back(TFactory<SCALAR_TYPE, TTrapeze<SCALAR_TYPE> >::CreateFigure());
            std::cout << "Nice" << std::endl;
        }
        if (figures.size() == bufferSize) {
            mq.Push(figures);
            bool threadWorkDone = false;
            while (!threadWorkDone) {
                if (mq.Empty()) {
                    threadWorkDone = true;
                }
            }
            figures.clear();
        }
    }
    mq.Push(figures);
    figures.clear();
    mq.Push(figures);
    myThread.join();
}