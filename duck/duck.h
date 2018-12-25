/**
 * Head First Pattern Design SimUDuck.
 * 原则1: 可变和不可变分离.
 * 原则2: 针对接口编程.
 *
 * 对于鸭子来说,其行为例如fly,quack是可变的,我们应该将其分离.
 * 接下来的问题是如何表征这些行为,一种合适的方式是将其作为可
 * 拔插的接口.
 */

#ifndef DUCK_H
#define DUCK_H

#include <iostream>

/**
 * 实现fly接口.
 */
class FlyBehavior {
public:
    virtual void fly() = 0;
    virtual ~FlyBehavior() {}
};

class FlyWithWings : public FlyBehavior {
public:
    virtual void fly() {
        std::cout << "Fly with wings" << std::endl;
    }

    virtual ~FlyWithWings() {}
};

class FlyNoWay : public FlyBehavior {
public:
    virtual void fly() {
        std::cout << "Fly no way" << std::endl;
    }

    virtual ~FlyNoWay() {}
};


/**
 * 定义quack行为.
 */
class QuackBehavior {
public:
    virtual void quack() = 0;
    virtual ~QuackBehavior() {}
};

class Quack : public QuackBehavior {
public:
    virtual void quack() {
        std::cout << "Quack" << std::endl;
    }

    virtual ~Quack() {}
};

class Squeak : public QuackBehavior {
public:
    virtual void quack() {
        std::cout << "Squeak" << std::endl;
    }

    virtual ~Squeak() {}
};

class MuteQuack : public QuackBehavior {
public:
    virtual void quack() {
        std::cout << "MuteQuack" << std::endl;
    }

    virtual ~MuteQuack() {}
};

/**
 * 有了以上行为基础,接下来定义duck类型.
 */
class Duck {
protected:
    FlyBehavior* fly_behavior_;
    QuackBehavior* quack_behavior_;
public:
    Duck() {}

    virtual void performFly() = 0;
    virtual void performQuack() = 0;
    virtual void swim() {}
    virtual void display() {}

    virtual ~Duck() {}
};

class MallarDuck : public Duck {
public:
    MallarDuck() {
        fly_behavior_ = new FlyWithWings();
        quack_behavior_ = new Squeak();
    }

    virtual void performFly() { fly_behavior_->fly(); }
    virtual void performQuack() { quack_behavior_->quack(); }

    virtual ~MallarDuck() {
        delete fly_behavior_;
        delete quack_behavior_;
    }
};

#endif /* DUCK_H */
