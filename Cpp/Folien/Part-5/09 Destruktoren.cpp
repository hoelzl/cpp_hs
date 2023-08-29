// -*- coding: utf-8 -*-
// ---
// jupyter:
//   jupytext:
//     text_representation:
//       extension: .cpp
//       format_name: percent
//       format_version: '1.3'
//       jupytext_version: 1.15.0
//   kernelspec:
//     display_name: C++17
//     language: C++17
//     name: xcpp17
// ---

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// <div style="text-align:center; font-size:200%;">
//  <b>Destruktoren</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 09 Destruktoren.cpp -->
// <!-- slides/module_150_classes/topic_170_destructors.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// ## Destruktoren
//
// - Destruktoren sind spezielle Member-Funktionen, die aufgerufen werden, wenn
//   ein Objekt zerstört wird.
// - Destruktoren haben keinen Rückgabetyp und keinen Parameter.
// - Destruktoren können nicht überladen werden.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %% tags=["keep"]
struct MyStruct {
    int i;

    MyStruct(int i = 1) : i{i} {
        std::cout << "MyStruct(" << i << ")\n";
    }

    ~MyStruct() {
        std::cout << "~MyStruct(" << i << ")\n";
    }
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
{
    MyStruct my_struct{};
}

// %% tags=["keep"]
{
    MyStruct my_struct{};
    MyStruct my_struct2{2};
}

// %% tags=["keep"]
MyStruct* my_struct_ptr = new MyStruct{};

// %% tags=["keep"]
delete my_struct_ptr;

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// Damit können wir ein Problem mit Ressourcen-Leaks in unserer
// `MyVector`-Implementierung lösen.
