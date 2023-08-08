//
// Created by echo_ on 2023-08-08.
//

#pragma once
#include <string>

class UndefinedBehavior {
public:
    static void RunPointerAndAddress();
    static void RunTemplateLessThan();
    static void RunVSignedIntegerOverflow();
    static void RunContainerInvalidateIterators();
    static void RunConstCast();
private:
    template<typename T1, typename T2>
    static void doLessThanLessThan(T1 &t1, T2 &t2);
    static int volume(int length);
    static void DoThing8(const std::string &input);
};
