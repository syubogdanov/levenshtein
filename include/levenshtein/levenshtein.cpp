#include "levenshtein.hpp"

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
