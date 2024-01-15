## Levenshtein

Implementation of the Levenshtein algorithm in the `C++` programming language.
The library can be easily integrated into your project using the `Bazel` build
system. The relevant instructions are given below.

## Quick Start

```C++
#include <cstdlib>
#include <iostream>
#include <string>

#include <levenshtein/levenshtein.hpp>

int main(void)
{
    std::string lhs = "syubogdanov";
    std::string rhs = "levenshtein";

    std::size_t distance = levenshtein::levenshtein(lhs, rhs);
    std::cout << distance << std::endl;

    return EXIT_SUCCESS;
}
```

## Installation

Add the following lines to your `WORKSPACE`:

```python
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "levenshtein",
    sha256 = "13d0ce68ce00788708b716991ac38ebb7509a713b3b2e51eda8e6a14b047206b",
    strip_prefix = "levenshtein-1.0",
    url = "https://github.com/syubogdanov/levenshtein/archive/refs/tags/v1.0.zip",
)
```

Now you can use the library for your needs:

```python
cc_library(
    name = "...",
    srcs = ["..."],
    hdrs = ["..."],
    deps = ["@levenshtein"],
)
```

## License

MIT License, Copyright (c) 2024 Sergei Bogdanov. See [LICENSE](LICENSE) file.
