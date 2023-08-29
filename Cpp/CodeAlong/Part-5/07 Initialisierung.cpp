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
//  <b>Initialisierung</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 07 Initialisierung.cpp -->
// <!-- slides/module_150_classes/topic_162_initialization.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// ## Arten der Initialisierung
//
// - Default-Initialisierung
// - Direkte Initialisierung
// - Kopierinitialisierung

// %% tags=["keep"] lang="de"
int i1;       // Default-Initialisierung
int i3(5);    // Direkte Initialisierung
int i2{5};    // Direkte Initialisierung
int i4 = 5;   // Kopierinitialisierung
int i5 = {5}; // Kopierinitialisierung

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

struct Vec {
    int size_;

    Vec() : size_{0} {
        std::cout << "Vec()\n";
    }

    Vec(int size) : size_{size} {
        std::cout << "Vec(" << size << ")\n";
    }

    Vec(const Vec& other) : size_{other.size_} {
        std::cout << "Vec(const Vec&)\n";
    }

    Vec& operator=(const Vec& other) {
        size_ = other.size_;
        std::cout << "operator=(const Vec&)\n";
        return *this;
    }
}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Default-Initialisierung
//
// - Bei Klassen wird Default-Konstruktor aufgerufen
// - Bei Arrays wird jedes Element Default-initialisiert
// - Sonst wird nichts getan

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Direkte Initialisierung
//
// Wird verwendet bei:
//
// - Initialisierung mit `()` oder `{}`
// - Aufruf von Konstruktoren (function-style cast, `{}`)
// - Static Cast
// - New mit nicht-leerem Initializer
// - Konstruktor-Initialisierungslisten
// - Lambda-Captures "by value"

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Direkte Initialisierung
//
// - Der beste Konstruktor wird verwendet.
// - Möglicherweise wird Aggregat-Initialisierung durchgeführt.
// - Möglicherweise werden Konversionen durchgeführt.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
Vec v(5);            // initialization with ()

// %%

// %% tags=["keep"]
Vec v{5};            // direct-list-initialization

// %% tags=["keep"]
Vec(5);              // function-style cast

// %% tags=["keep"]
Vec{5};              // direct-list-initialized temporary

// %% tags=["keep"]
static_cast<Vec>(5); // static cast

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
new Vec(1)           // new with non-empty initializer

// %% tags=["keep"]
struct A {
    Vec v_;
    A(int i) : v_{i} {}      // constructor initialization list
    //         ^^^^^
};

// %% tags=["keep"]
A{5};

// %% tags=["keep"]
{
    Vec v;
    [v](){};       // lambda capture by value
//  ^^^            // default initialization using copy constructor
}

// %% [markdown] lang="de"
//
// ([Hier](https://cppinsights.io/s/777b0ff7) ist der erzeugte Code.)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Kopierinitialisierung
//
// Wird verwendet bei:
//
// - Initialisierung mit `=`
// - Übergabe von Argumenten "by value"
// - Rückgabewert von Funktionen "by value"
// - Werfen von Ausnahmen "by value"
// - Bei Aggregat-Initialisierung für Elemente mit Initializer

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Kopierinitialisierung
//
// - Der beste *nicht-explizite* Konstruktor wird verwendet.
// - Möglicherweise werden Konversionen durchgeführt.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
Vec v = Vec{5};           // Initialization with `=`

// %% tags=["keep"]
void f(Vec) { /* ... */ }
f(v);                     // Argument passed by value

// %% tags=["keep"]
Vec f() { return v; }
f()                       // Value returned by value

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
try {
    throw v;              // Throw by value
}
catch (Vec) {             // Catch by value
    // ...
}
