#include <iostream>

/**
 * Each distinct product of a product family should have a base interface. All
 * variants of the product must implement this interface.
 */
class BlackAnimals {
 public:
  virtual ~BlackAnimals(){};
  virtual std::string Speak() const = 0;
};

/**
 * Concrete Products are created by corresponding Concrete Factories.
 */
class BlackCat : public BlackAnimals {
 public:
  std::string Speak() const override {
    return "Meow.";
  }
};

class BlackDog : public BlackAnimals {
 public:
  std::string Speak() const override {
    return "Woof.";
  }
};

/**
 * Here's the the base interface of another product. All products can interact
 * with each other, but proper interaction is possible only between products of
 * the same concrete variant.
 */
class WhiteAnimals {
  /**
   * Product B is able to do its own thing...
   */
 public:
  virtual ~WhiteAnimals(){};
  virtual std::string Speak() const = 0;
  /**
   * ...but it also can collaborate with the ProductA.
   *
   * The Abstract Factory makes sure that all products it creates are of the
   * same variant and thus, compatible.
  */
  virtual std::string Move(const BlackAnimals &collaborator) const = 0;
};

/**
 * Concrete Products are created by corresponding Concrete Factories.
 */
class WhiteCat : public WhiteAnimals {
 public:
  std::string Speak() const override {
    return "White Meow.";
  }
  /**
   * The variant, Product B1, is only able to work correctly with the variant,
   * Product A1. Nevertheless, it accepts any instance of AbstractProductA as an
   * argument.
  */
  std::string Move(const BlackAnimals &collaborator) const override {
    const std::string result = collaborator.Speak();
    return "The black animals come here and speak ( " + result + " )";
  }
};

class WhiteDog : public WhiteAnimals {
 public:
  std::string Speak() const override {
    return "White Woof.";
  }
  /**
   * The variant, Product B2, is only able to work correctly with the variant,
   * Product A2. Nevertheless, it accepts any instance of AbstractProductA as an
   * argument.
  */
  std::string Move(const BlackAnimals &collaborator) const override {
    const std::string result = collaborator.Speak();
    return "the black animals come here and speak ( " + result + " )";
  }
};

/**
 * The Abstract Factory interface declares a set of methods that return
 * different abstract products. These products are called a family and are
 * related by a high-level theme or concept. Products of one family are usually
 * able to collaborate among themselves. A family of products may have several
 * variants, but the products of one variant are incompatible with products of
 * another.
 */
class AnimalsFactory {
 public:
  virtual BlackAnimals *CreateBlackAnimals() const = 0;
  virtual WhiteAnimals *CreateWhiteAnimals() const = 0;
};

/**
 * Concrete Factories produce a family of products that belong to a single
 * variant. The factory guarantees that resulting products are compatible. Note
 * that signatures of the Concrete Factory's methods return an abstract product,
 * while inside the method a concrete product is instantiated.
 */
class CatFactory : public AnimalsFactory {
 public:
  BlackAnimals *CreateBlackAnimals() const override {
    return new BlackCat();
  }
  WhiteAnimals *CreateWhiteAnimals() const override {
    return new WhiteCat();
  }
};

/**
 * Each Concrete Factory has a corresponding product variant.
 */
class DogFactory : public AnimalsFactory {
 public:
  BlackAnimals *CreateBlackAnimals() const override {
    return new BlackDog();
  }
  WhiteAnimals *CreateWhiteAnimals() const override {
    return new WhiteDog();
  }
};

/**
 * The client code works with factories and products only through abstract
 * types: AbstractFactory and AbstractProduct. This lets you pass any factory or
 * product subclass to the client code without breaking it.
 */

void ClientCode(const AnimalsFactory &factory) {
  const BlackAnimals *black_animals = factory.CreateBlackAnimals();
  const WhiteAnimals *white_animals = factory.CreateWhiteAnimals();
  std::cout << black_animals->Speak() << "\n";
  std::cout << white_animals->Speak() << "\n";
  std::cout << white_animals->Move(*black_animals) << "\n";
  delete black_animals;
  delete white_animals;
}

int main() {
  std::cout << "Client: Testing client code with the first factory type:\n";
  CatFactory *f1 = new CatFactory();
  ClientCode(*f1);
  delete f1;
  std::cout << std::endl;
  std::cout << "Client: Testing the same client code with the second factory type:\n";
  DogFactory *f2 = new DogFactory();
  ClientCode(*f2);
  delete f2;
  return 0;
}