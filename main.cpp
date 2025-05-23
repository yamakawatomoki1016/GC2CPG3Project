#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

int main() {
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    animal1->sound();  // イヌ鳴き声：ワン
    animal2->sound();  // ネコ鳴き声:ニャー

    delete animal1;
    delete animal2;

    return 0;
}
