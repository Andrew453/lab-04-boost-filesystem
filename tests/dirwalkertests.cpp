// Copyright 2021 Prokushev Andrew <senior.prockuschev2017@yandex.ru>

#include <stdexcept>

#include <gtest/gtest.h>

#include <dirwalker.hpp>

TEST(Example, EmptyTest) {
    EXPECT_THROW(example(), std::runtime_error);
}
