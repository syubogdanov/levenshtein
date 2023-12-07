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
    sha256 = "...",
    strip_prefix = "...",
    url = "...",
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

MIT License, Copyright (c) 2023 Sergei Bogdanov. See [LICENSE](LICENSE) file.
