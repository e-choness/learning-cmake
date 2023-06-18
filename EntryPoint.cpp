#include "src/TypeErasure/Animal.h"
#include "src/TypeErasure/Cow.h"
#include "src/TypeErasure/Dog.h"
#include "src/SolidPrinciples/BetterFilter.h"
#include "src/LiskovSubstitution/Rectangle.h"
#include "src/LiskovSubstitution/MechineFunctions.h"
void TestTypeErasure();
void TestSingleResponsibility();
void TestLiskov();

int main(int argc, char **argv){
    TestLiskov();

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

void TestLiskov(){
    auto rect = std::vector<Rectangle>{
        Rectangle(5,6),
        Rectangle(2,9)
    };

    for(auto& r:rect){
        std::cout << r.area() << std::endl;
    }

    auto documents = std::vector<Document*>();
    documents.push_back(new Document("file 1", "This is file 1 m_Content."));
    documents.push_back(new Document("file 2", "This is file 2 m_Content."));
    class Machine: public IMachine{};

    auto machine = Machine();
    machine.print(documents);
    machine.scan(documents);
}