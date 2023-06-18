#include "src/TypeErasure/Animal.h"
#include "src/TypeErasure/Cow.h"
#include "src/TypeErasure/Dog.h"
#include "src/SolidPrinciples/BetterFilter.h"

void TestTypeErasure();
void TestSingleResponsibility();

int main(int argc, char **argv){
    TestSingleResponsibility();

    return 0;
}

void TestTypeErasure(){
    Dog* dog = new Dog();
    Cow* cow = new Cow();

    SeeAndSay(cow);
    SeeAndSay(dog);
}

void TestSingleResponsibility(){
    auto apple = Product{ "Apple", Color::GREEN, Size::SMALL};
    auto tree = Product{"Tree", Color::GREEN, Size::LARGE};
    auto house = Product{"House", Color::BLUE, Size::SMALL};

    std::vector<Product*> all{&apple, &tree, &house};

    BetterFilter betterFilter;
    auto blueAndSmall = ColorSpecification(Color::BLUE) && SizeSpecification(Size::SMALL);

    auto blueSmallThings = betterFilter.filter(all, blueAndSmall);
    for(auto& x: blueSmallThings)
        std::cout<<x->name<<" is blue and small." <<std::endl;
}