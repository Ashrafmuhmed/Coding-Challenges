# WC (Word Count) Program

A C++ implementation of the Unix `wc` command line utility that counts bytes, characters, words, and lines in a text file.

## Features

The program supports the following counting options:
- `-c`: Count bytes
- `-m`: Count characters
- `-w`: Count words
- `-l`: Count lines
- No flag: Display all counts (bytes, characters, words, lines)

## Usage

```bash
> ccwc -c filename    # Count bytes
> ccwc -m filename    # Count characters
> ccwc -w filename    # Count words
> ccwc -l filename    # Count lines
> ccwc filename       # Display all counts
```

## Example

```bash
> ccwc test.txt
7145  6070  1023  84  test.txt
```
Output format: `[bytes] [characters] [words] [lines] [filename]`

## Implementation Details

- Uses C++ file streams for efficient file handling
- Handles binary and text files
- Supports Unicode characters
- Processes files line by line for memory efficiency
- Resets file position between different counting operations

## Build and Run

Compile with a C++ compiler that supports C++11 or later:

```bash
g++ main.cpp -o ccwc
```

## Note
- Word counting considers any sequence of characters separated by whitespace as a word
- Character count may differ from byte count for files with Unicode characters
- Line counting is based on newline characters
