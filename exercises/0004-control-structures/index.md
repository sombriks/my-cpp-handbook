# Control flow

Blocks, conditionals and loops.

In C++, the most basic structure is the block. A block is defined by a `{}` and
anything between them belongs to the block. This is true for several languages.

The `main` function, the [application entry point][entrypoint], owns a block.
Conditional and repetition structures can own a block.

Code inside a block is read from left to right, top to bottom. Loops, like `for`
and `while`, and conditionals, like `if` and `switch` can subvert this a little.

<<< control-flow.cc{cpp}

## How to build

```bash
g++ -Wall control-flow.cc -o control-flow
```

## How to run

```bash
./control-flow
```

## Noteworthy

-

[entrypoint]: https://en.wikipedia.org/wiki/Entry_point
