/******************************************
Copyright (c) 2020, Mate Soos

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
***********************************************/

#include "gtest/gtest.h"

#include "approxmc/approxmc.h"
#include "test_helper.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

using namespace ApproxMC;
#include <vector>
using std::vector;


TEST(normal_interface, start)
{
    AppMC s;
    SolCount c = s.count();
    EXPECT_EQ(c.cellSolCount, 1);
    EXPECT_EQ(c.hashCount, 0);
}

TEST(normal_interface, example1)
{
    AppMC s;
    s.new_vars(2);
    s.add_clause(str_to_cl("-1, 2"));
    SolCount c = s.count();
    EXPECT_EQ(0, c.hashCount);
    EXPECT_EQ(3, c.cellSolCount);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
