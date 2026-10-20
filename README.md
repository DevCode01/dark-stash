# Dark Stash

**C** · **v0.1.0**

_Caesar cipher in C with file or stdin input_

---

## Features

- Encrypts with any shift, decodes with negative
- Reads text from arguments or stdin
- Compiled with strict warnings

## Installation

```bash
git clone https://github.com/DevCode01/dark-stash.git
cd dark-stash
```

## Usage

```bash
make && echo 'Hello' | ./dark-stash 3
```

## How it works

Caesar cipher in C: shifts each letter by a key (0-25, normalized), leaving non-letters untouched. Text can be passed as arguments or piped to stdin.

## Options

- `shift` - shift amount (negative allowed)
- `text ...` - text to transform (reads stdin if omitted)

## Example

```bash
$ make && echo 'Hello' | ./dark-stash 3
Khoor
```

## Testing

```bash
bash tests/run.sh
```

Includes a functional check against real captured output, plus the build/syntax check.

## License

MIT
