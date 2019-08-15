<a id="markdown-c" name="c"></a>
# C++

<!-- TOC -->

1. [C++](#c)
  1. [Description](#description)
  2. [TODO](#todo)
    1. [C++ stuff](#c-stuff)
2. [Things to learn](#things-to-learn)
  1. [rvalue/lvalue](#rvaluelvalue)
  2. [Const correctness](#const-correctness)
    1. [Rules](#rules)
  3. [Templates](#templates)
  4. [Namespace](#namespace)
  5. [Range-based algorithms](#range-based-algorithms)
  6. [Type-Traits](#type-traits)
  7. [The rule of three/five/zero](#the-rule-of-threefivezero)
  8. [Dynamic programming](#dynamic-programming)

<!-- /TOC -->


<a id="markdown-description" name="description"></a>
## Description

A C++ dojo.

<a id="markdown-todo" name="todo"></a>
## TODO

<a id="markdown-c-stuff" name="c-stuff"></a>
### C++ stuff

- [ ] Add address sanitizer and just all sanitizer to project and CMake .

Extensions for VS code:

- [ ] Header & source file syncer
- [ ] Jump to end of line to add ";"

----------------------------

<a id="markdown-things-to-learn" name="things-to-learn"></a>
# Things to learn

<a id="markdown-rvaluelvalue" name="rvaluelvalue"></a>
## rvalue/lvalue

<a id="markdown-const-correctness" name="const-correctness"></a>
## Const correctness

Const correctness is the use of const in classes and functions in a manner that makes it obvious to the compiler and user of the class what the mutability intentions is for the given member functions and/or parameters.

**Const functions:**

A member function that is const promises to never change the inner logical state of the object it is called on/in.

**Const parameters:**

A const parameter tels the user about a functions mutability intent and make you will not inadvertently change a parameter passed by reference as it will get catched at compile time.

<a id="markdown-rules" name="rules"></a>
### Rules

- Never omit const if it can make sense to put it in!

<a id="markdown-templates" name="templates"></a>
## Templates

Templates are little like macros just more powerful?

dono?

<a id="markdown-namespace" name="namespace"></a>
## Namespace

Something bigger than classes.

dono?

<a id="markdown-range-based-algorithms" name="range-based-algorithms"></a>
## Range-based algorithms

dono?

<a id="markdown-type-traits" name="type-traits"></a>
## Type-Traits

dono?

<a id="markdown-the-rule-of-threefivezero" name="the-rule-of-threefivezero"></a>
## The rule of three/five/zero

dono?

<a id="markdown-dynamic-programming" name="dynamic-programming"></a>
## Dynamic programming

dono?
