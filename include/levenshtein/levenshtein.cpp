/// MIT License
///
/// Copyright (c) 2024 Sergei Bogdanov
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included in all
/// copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
/// SOFTWARE.

#include "include/levenshtein/levenshtein.hpp"

#include <algorithm>
#include <limits>
#include <stdexcept>
#include <vector>

std::size_t levenshtein::levenshtein(const std::string& lhs, const std::string& rhs)
{
    if (lhs.length() > rhs.length())
    {
        return levenshtein::levenshtein(rhs, lhs);
    }

    if (lhs.length() == 0)
    {
        return rhs.length();
    }

    if (rhs.length() == 0)
    {
        return lhs.length();
    }

    if (lhs.length() == std::numeric_limits<std::size_t>::max())
    {
        throw std::overflow_error("the strings are too long");
    }

    std::vector<std::size_t> previous_row(lhs.length() + 1, 0);
    std::vector<std::size_t> current_row(lhs.length() + 1, 0);

    for (std::size_t index = 1; index <= lhs.length(); ++index)
    {
        previous_row[index] = index;
    }

    for (std::size_t rhs_index = 0; rhs_index < rhs.length(); ++rhs_index)
    {
        current_row[0] = rhs_index + 1;
        for (std::size_t lhs_index = 0; lhs_index < lhs.length(); ++lhs_index)
        {
            std::size_t deletion = previous_row[lhs_index + 1] + 1;
            std::size_t insertion = current_row[lhs_index] + 1;

            bool equal_symbols = (lhs[lhs_index] == rhs[rhs_index]);
            std::size_t substitution = previous_row[lhs_index] + ((equal_symbols) ? 0 : 1);

            current_row[lhs_index + 1] = std::min({
                deletion,
                insertion,
                substitution,
            });
        }
        std::swap(previous_row, current_row);
    }

    return previous_row[lhs.length()];
}
