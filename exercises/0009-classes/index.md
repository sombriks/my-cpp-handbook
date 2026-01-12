# Custom types and classes

One of the greatest powers of C++ is the level of abstraction it allows the
programmer use when creating code.

Abstractions are important to make huge programs easier to understand, evolve
and fix possible issues.

Classes are the foundational idiom for that, let's understand why.

## A matter of state and messages

Dealing only with structured paradigm, you have functions, primitive types,
arrays and structs to express the program.

While types can express **state**, functions can perform operations on that
state. Often functions can also call other functions, reusing operations and
combining them to produce more complex transformations.

That part, the graph of function calls in a program, is the **message passing**.

The following example shows those concepts in action in a simple todo list
application:

<<< 01-todo-list-no-class/main.cc{cpp}

Some common patterns emerge when doing it properly:

### One specific function to create state

The struct defines a *shape* for the state, but it's up to the functions define
how the data must be initialized.

### Distinct messages will manipulate distinct aspects of the state

The function to mark the todo item as complete only needs to know how to flip
the flag, but all the struct is exposed to it. On large scale projects this is
not desirable.

### Message implement behavior

One function creates a todo item, another function prints the todo list and so
on. Those messages perform transformations over the state, either changing it or
creating some side effect. This is *behavior*.

### Discipline when programming

All of this is accomplished with bare, simple structures and a lot of discipline
from the programmer.

All kinds of abstractions can be achieved by simply 'coding right'.

But it demands **experience**.

Another approach is to create foundational language structures to *enforce* code
quality. Ths is where the fun begins.

## Basic class declaration and class usage

You can think of classes as a **specification** of states and messages that are
supposed to be deeply related:

<<< 02-todo-list-with-class/basic-example.cpp

### Visibility qualifiers

Unlike bare, naked structs, the attributes declared on it aren't accessible
directly. This is called **encapsulation**.

In the class declaration, anything you want to be available for external usage
must be declared in the **public** section:

```cpp
class MyClass {
  int myPrivateState;
public:
  int myPublicMessage();
};
```

## Constructor and destructors

Classes allow special functions for the sole purpose of set the initial state.
Also, it's possible to set a special function just for resources cleanup. Those
are the **Constructor** and **Destructor** functions:

<<< 02-todo-list-with-class/constructor-destructor.cpp

How exactly it works?

<<< 03-todo-list-constructor/main.cc{cpp}

By the way, distinct values of the same class are called **objects** or
**class instances**.

## Function and Operator overloading

## Inheritance

## Polymorphism

## Further reading
