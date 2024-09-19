//
// Created by twostone on 19.02.24.
//

#ifndef BATTLESHIPS_OBSERVER_H
#define BATTLESHIPS_OBSERVER_H

#include <vector>
#include <memory>

namespace BattleShipsGameUtilities {

    class Message {

    };

    class Observer {
    public:
        virtual void update(const Message& message, std::unique_ptr<Message> sender) = 0;
    };

    class Subject {
    protected:
        std::vector<std::unique_ptr<Observer>> observers;
    public:
        virtual void addObserver(std::unique_ptr<Observer> observer) = 0;
        virtual void removeObserver(std::unique_ptr<Observer> observer) = 0;
        virtual void notifyObservers(const Message& message, std::unique_ptr<Observer> observer) = 0;
    };

} // BattleShipsGameUtilities

#endif //BATTLESHIPS_OBSERVER_H
