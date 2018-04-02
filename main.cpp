#include "ahalaimahalai.h"
#include <gtest/gtest.h>

TEST(testIfValuesArePrecalculated, staticAssert) {
    static_assert(AhalaiMahalai<5, 5, 0>::who == 2, "The program gives an incorrect answer.");
    static_assert(AhalaiMahalai<5, 5, 0>::whence == 0, "The program gives an incorrect answer.");
    static_assert(AhalaiMahalai<5, 5, 0>::how == 0, "The program gives an incorrect answer.");
    static_assert(AhalaiMahalai<0, 0, 100>::who == 1, "The program gives an incorrect answer.");
    static_assert(AhalaiMahalai<0, 0, 100>::whence == 3, "The program gives an incorrect answer.");
    static_assert(AhalaiMahalai<0, 0, 100>::how == 100, "The program gives an incorrect answer.");
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}