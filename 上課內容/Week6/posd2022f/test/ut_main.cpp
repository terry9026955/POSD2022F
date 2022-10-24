#include <gtest/gtest.h>

#include "ut_hello.h"
#include "ut_circle.h"
#include "ut_sort.h"
#include "ut_square.h"
#include "ut_shape.h"
#include "ut_null_iterator.h"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}