# qtdialogclass

A simple Qt-based calculator application with basic arithmetic operations and number base conversion.

## Features

- Basic arithmetic operations: Addition (+), Subtraction (-), Multiplication (*), Division (/)
- Number input: 0-9
- Display modes: Decimal (10進制) and Hexadecimal (16進制)
- Clear function (C) to reset the calculator
- Equals (=) to calculate the result

## Calculator Layout

```
Display: [0                    ]

Buttons:
┌────┬────┬────┬────────┐
│ +  │ -  │ *  │   /    │
├────┼────┼────┼────────┤
│ 7  │ 8  │ 9  │ 16進制 │
├────┼────┼────┼────────┤
│ 4  │ 5  │ 6  │ 10進制 │
├────┼────┼────┼────────┤
│ 1  │ 2  │ 3  │   =    │
├────┴────┼────┴────────┤
│    0    │      C      │
└─────────┴─────────────┘
```

## How to Use

1. Enter numbers by clicking the number buttons (0-9)
2. Click an operation button (+, -, *, /)
3. Enter the second number
4. Click equals (=) to see the result
5. Click "16進制" to display numbers in hexadecimal
6. Click "10進制" to display numbers in decimal
7. Click "C" to clear and start over

## Building

This is a Qt application. Build using qmake:

```bash
qmake
make
```

Or open the .pro file in Qt Creator.