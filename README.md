# Course 10: OOP Level 1 – ProgrammingAdvices Roadmap

This repository tracks my progress through **Step 10** of the comprehensive ProgrammingAdvices roadmap. The core focus of this stage is transitioning from procedural programming to **Object-Oriented Logic**, prioritizing code reusability and architectural foundations.

## 🎯 Learning Objectives
* **Mental Models**: Shifting from "How to solve it" to "How to represent it" using classes and objects.
* **Logic Foundations**: Building strong, bug-resistant logic through structured class design.
* **Reusability**: Developing modular libraries that can be plugged into any future project on the roadmap.

## 🛠️ Developed Libraries
I am building these tools to be used as my "standard library" for future courses:

* **`clsString.h`**: A robust utility for advanced string manipulation (Split, Trim, Case Inversion, etc.).
* **`MyInputLibrary.h`**: A safe input validation engine to handle user data types (int, float, double) with built-in error guarding.
* **`clsDate.h`**: A versatile and reusable C++ class designed to handle all date-related tasks, from simple formatting to intricate business logic and time-gap analysis, including the following:
  * Smart Math: Automatic month/year rollover with leap year support.
  * Business Ready: Calculate vacation days while automatically skipping weekends.
  * Period Logic: Easily detect if two date ranges overlap or calculate days between them.
  * Flexible Formatting: Convert dates to multiple string formats or custom patterns like yyyy-mm-dd. 
*  **`clsUtility.h`** : A comprehensive, high-performance  C++ Utility Library 🛠️ designed for students and developers. This library provides a collection of static tools for **Math**, **Modern Randomization**, and **Data Security**.
   * **🎲 Modern Randomization**: Uses the `std::mt19937` (Mersenne Twister) engine for high-quality random numbers, characters, and words.
   * **🔐 Data Encryption**: Simple yet effective text encryption and decryption using custom keys.
   * **🔢 Advanced Math**: Custom implementations for `IsPrime`, `IsPerfect`, `MyRound`, `MySqrt`, and more.
   * **🔡 String & Word Generation**: Flexible generators for random strings, passwords, and security keys.
   * **📂 Vector Tools**: Built-in `Shuffle` and `DoesExist` functions for various data types (`int`, `float`, `string`, etc.).



## 🛠️ Tech Stack & Concepts

* **Language**: C++11 or higher
* **Paradigm**: Functional/Procedural, basic OOP (Static Utility Pattern)
* **Library**: `<random>`, `<vector>`, `<string>`, `<limits>`


## 📂 Project Highlights
* **Inheritance & Polymorphism**: Practical examples including `clsSmartDevice`, `clsPerson`, and `clsEmployee` hierarchies.
* **Encapsulation**: Using access specifiers (`public`/`private`) to protect data and logic integrity.
* **Clean Code**: Adhering to professional C++ standards as taught by **Dr. Mohammed Abu-Hadhoud**.

---
**Roadmap Status:** Step 10 - Foundations (OOP Level 1)  
**Instructor:** [ProgrammingAdvices.com](https://programmingadvices.com)
