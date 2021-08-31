//
// Created by YaTeb on 12/28/2020.
//

#ifndef LAB8_METHOD_HPP
#define LAB8_METHOD_HPP
#include <mutex>
#include <queue>

template<class T>
class TPubSubMQ {
private:
    std::queue<T> MessageQueue;
    std::mutex MQMutex;
public:
    explicit TPubSubMQ() noexcept : MessageQueue(), MQMutex() {}
    ~TPubSubMQ() {}

    bool Empty() {
        MQMutex.lock();
        bool res = MessageQueue.empty();
        MQMutex.unlock();
        return res;
    }

    T Front() {
        MQMutex.lock();
        T elem = MessageQueue.front();
        MQMutex.unlock();
        return elem;
    }

    void Pop() {
        MQMutex.lock();
        MessageQueue.pop();
        MQMutex.unlock();
    }

    void Push(const T & message) {
        MQMutex.lock();
        MessageQueue.push(message);
        MQMutex.unlock();
    }
};

#endif //LAB8_METHOD_HPP
