#include <iostream>
#include <memory>

// Product
class animals {
public:
    virtual ~animals() {}
    virtual std::string speak() const = 0;
};

// Concrete Products
class dog : public animals {
public:
    std::string speak() const override {
        return "{wof}";
    }
};

class cat : public animals {
public:
    std::string speak() const override {
        return "{meow}";
    }
};

// Creator
class Creator {
public:
    virtual ~Creator(){};
    virtual std::unique_ptr<animals> CreateLife() const = 0;

    std::string LifeAction() const {
        std::unique_ptr<animals> life = this->CreateLife();
        std::string result = "Creator: let's life do some action: " + life->speak();
        return result;
    }
};

// Concrete Creators
class dogCreator : public Creator {
public:
    std::unique_ptr<animals> CreateLife() const override {
        return std::make_unique<dog>();
    }
};

class catCreator : public Creator {
public:
    std::unique_ptr<animals> CreateLife() const override {
        return std::make_unique<cat>();
    }
};

// Client code
void ClientCode(const Creator& creator) {
    std::cout << "Client: I'm not aware of the creator's class, but different animals created.\n"
              << creator.LifeAction() << std::endl;
}

int main() {
    std::cout << "App: Launched with the dogCreator.\n";
    dogCreator dogCreator;
    ClientCode(dogCreator);
    std::cout << std::endl;
    std::cout << "App: Launched with the catCreator.\n";
    catCreator catCreator;
    ClientCode(catCreator);
    return 0;
}
