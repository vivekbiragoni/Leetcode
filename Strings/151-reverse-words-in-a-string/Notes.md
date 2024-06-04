<h2>reverse-words-in-a-string Notes</h2><hr>[ Time taken: 19 m 58 s ]


### `std::stringstream`:

- `std::stringstream` is a stream class that operates on strings. It allows you to treat strings as streams, similar to `std::cin` and `std::cout`.
- You can use `std::stringstream` to perform input and output operations on strings as if they were streams.
- It provides similar functionality to `std::cin` and `std::cout` but with strings instead of the console.

### `<<` and `>>` Operators:

- The `<<` and `>>` operators are stream insertion and extraction operators, respectively.
- When used with `std::stringstream`, `<<` inserts data into the stream, and `>>` extracts data from the stream.
- For example:
  - `ss << "Hello";` inserts the string "Hello" into the `std::stringstream` object `ss`.
  - `ss >> word;` extracts a word from the `std::stringstream` object `ss` and stores it in the variable `word`.

### Usage in Code:

In the provided code, we use `std::stringstream` to split the trimmed string into words:

```cpp
std::stringstream ss(trimmed);
std::string word;
while (ss >> word) {
    words.push_back(word);
}
```

Here's what each line does:

1. `std::stringstream ss(trimmed);`: Creates a `std::stringstream` object `ss` initialized with the trimmed string `trimmed`.
2. `std::string word;`: Declares a string variable `word` to store each word extracted from the stream.
3. `while (ss >> word) { ... }`: Reads each word from the `std::stringstream` object `ss` using the `>>` operator and stores it in the variable `word`. The loop continues until there are no more words in the stream.

This process effectively splits the string into words based on whitespace (spaces, tabs, etc.).
