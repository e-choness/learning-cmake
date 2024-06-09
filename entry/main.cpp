#include "hello.hpp"
#include "log.hpp"
#include "BoxManipulator.hpp"
#include "Stairs.hpp"
#include "ArrayHandler.hpp"
#include "HtmlProvider.hpp"
#include "BattleField.hpp"
#include "HELLOConfig.h"

int main(int argc, char **argv){
    ArrayHandler::show();

    Stairs::show();
    BattleField::fight();

    BoxManipulator boxManipulator;
    boxManipulator.show();

    HtmlProvider::showResults();

    auto hello = Hello();
    hello.showEntries();

    hello.setGreetings("Hello, CMake from library in subdirectory!\n");
    Log::logData(hello.getGreetings(), LogType::MESSAGE);
    std::cout << "The say-hello library is version: " << SAY_HELLO_VERSION << "\n";

    std::cout << argv[0] << "hello_library version: " << HelloLibrary_VERSION_MAJOR << "." << HelloLibrary_VERSION_MINOR << "\n";

    // Get command mLine arguments from main entry args.
    if(argc > 1){
        const double inputValue = std::stod(argv[1]);
        std::cout << "The first command mLine argument: " << inputValue << "\n";
    }
}