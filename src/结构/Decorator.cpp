/**
 * *****************************************************************************
 * @file        Decorator.cpp
 * @brief
 * @author      Yusen Han (hanyusen@aistar.info)
 * @date        2024-03-20
 * @copyright Copyright (c) 2024
 * *****************************************************************************
 */

/*----------------------------------include-----------------------------------*/
#include <iostream>
#include <string>
/*----------------------------------typedef-----------------------------------*/

/*----------------------------------function----------------------------------*/

/**
 * @brief 我理解的装饰器就是创建新的对象，对具体的接口进行装饰，可以动态地装饰，无需修改原来对象的代码
 *
 */


// 给类添加新功能

// 组件接口
class Component {
public:
    virtual ~Component() {}
    virtual std::string Operation() const = 0;
};

// 具体组件
class ConcreteComponent : public Component {
public:
    std::string Operation() const override {
        return "ConcreteComponent";
    }
};

// 装饰基类
class Decorator : public Component {
protected:
    Component* component;
public:
    Decorator(Component* component) : component(component) {}
    std::string Operation() const override {
        return component->Operation();
    }
};

// 具体装饰
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* component) : Decorator(component) {}
    std::string Operation() const override {
        return "ConcreteDecoratorA(" + Decorator::Operation() + ")";
    }
};

class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* component) : Decorator(component) {}
    std::string Operation() const override {
        return "ConcreteDecoratorB(" + Decorator::Operation() + ")";
    }
};

int main() {
    Component* simple = new ConcreteComponent();
    std::cout << "Client: I've got a simple component:\n";
    std::cout << "RESULT: " << simple->Operation();
    std::cout << "\n\n";

    Component* decorator1 = new ConcreteDecoratorA(simple);
    Component* decorator2 = new ConcreteDecoratorB(decorator1);
    std::cout << "Client: Now I've got a decorated component:\n";
    std::cout << "RESULT: " << decorator1->Operation() << std::endl;
    std::cout << "RESULT: " << decorator2->Operation();
    std::cout << "\n";

    delete simple;
    delete decorator1;
    delete decorator2;

    return 0;
}
