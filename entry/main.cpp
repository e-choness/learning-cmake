//
// Created by echo_ on 2023-07-25.
//


//#include "LibCore.hpp"
//#include <memory>
#include "VulkanEngine.hpp"

int main(){
//    std::unique_ptr<LibCore> libCore = std::make_unique<LibCore>();
//    libCore->RunOperatorOverrideExamples();
//    libCore->RunUndefinedBehaviorExamples();
        engine::VulkanEngine engine;
        engine.init();
        engine.run();
        engine.cleanup();
        return 0;
}