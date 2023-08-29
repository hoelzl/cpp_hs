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
//  <b>Kopieren und Verschieben</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 11 Kopieren und Verschieben.cpp -->
// <!-- slides/module_150_classes/topic_190_copy_control.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// ## Kopieren und Verschieben
//
// - `MyVector`-Objekte werden korrekt zerstört, aber nicht korrekt kopiert.
// - Wir können das Kopieren und Verschieben von Objekten selbst implementieren.
// - Dafür gibt es vier spezielle Member-Funktionen:
//   - Kopierkonstruktor (Copy Constructor)
//   - Kopierzuweisungsoperator (Copy Assignment Operator)
//   - Move-Konstruktor (Move Constructor)
//   - Move-Zuweisungsoperator (Move Assignment Operator)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Copy Constructor und Copy Assignment Operator
//
// - Haben als Parameter eine (`const`)-Referenz auf ein Objekt der eigenen
//   Klasse.
// - Werden (oft) automatisch generiert, wenn sie nicht explizit implementiert
//   werden.
//   - Default: Member werden kopiert.
// - Können explizit mit `= default` deklariert werden.
// - Die Default-Implementierung kann mit `= delete` verhindert werden.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Copy Constructor
//
// - Wird aufgerufen, wenn ein Objekt mit einem anderen Objekt vom gleichen Typ
//   initialisiert wird.
//
// ### Copy Assignment Operator
//
// - Wird aufgerufen, wenn ein Objekt an ein anderes Objekt zugewiesen wird.
// - Definition mit `operator=()`.
// - Gibt eine Referenz auf `*this` zurück.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

struct Copyable {
    static int next_index() {
        static int result{0};
        return ++result;
    }

    int i;

    Copyable() : i{next_index()}
    {
        std::cout << "Copyable(" << i << ")\n";
    };

    Copyable(const Copyable& other) : i{next_index()}
    {
        std::cout << "Copyable(" << i << "): copy constructor called. (Other = " << other.i << ")\n";
    };

    Copyable& operator=(const Copyable& other)
    {
        i = next_index();
        std::cout << "Copyable(" << i << "): copy assignment operator called. (Other = " << other.i << ")\n";
        return *this;
    };
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
Copyable c1{};

// %% tags=["keep"]
Copyable c2{};

// %% tags=["keep"]
c1 = c2;

// %% tags=["keep"]
c1.i

// %% tags=["keep"]
c2.i

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
const Copyable c3{};

// %% tags=["keep"]
Copyable c4{c3};

// %% tags=["keep"]
c4.i

// %% tags=["keep"]
c4.i = 44;

// %% tags=["keep"]
c4.i


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Verschieben von Objekten
//
// - Viele Objekte werden als Handles realisiert:
//   - Kleine Struktur mit Zeiger auf großen Datenbereich.
//   - Kopieren der Struktur ist billig, Kopieren der Daten teuer.
// - In manchen Fällen kann man statt zu kopieren die Daten der Quelle "stehlen".
//   - Das geht, wenn die Quelle nicht mehr benötigt wird.
//   - Man muss die Quelle dabei in einem Zustand lassen, in dem der Destruktor
//     aufgerufen werden kann.
// - Diesen Vorgang nennt man "Verschieben" (move).

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Move-Konstruktor und Move-Zuweisungsoperator
//
// - Haben als Parameter eine Rvalue-Referenz (`T&&`) auf ein Objekt der eigenen
//   Klasse.
// - Erlauben effizientes Verschieben von Objekten.
// - Werden nicht implementiert, wenn Copy-Konstruktor oder
//   Copy-Zuweisungsoperator explizit implementiert werden.
// - Können explizit mit `= default` deklariert werden.
// - Die Default-Implementierung kann mit `= delete` verhindert werden.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Move-Konstruktor
//
// - Wird aufgerufen, wenn ein Objekt mit einem Rvalue initialisiert wird.
// - Rvalues sind grob gesagt Objekte, die nach ihrer Verwendung nicht mehr
//   benötigt werden.
//
// ### Move-Zuweisungsoperator
//
// - Wird aufgerufen, wenn ein Rvalue an ein Objekt zugewiesen wird.
// - Definition mit `operator=()`.
// - Gibt eine Referenz auf das eigene Objekt zurück.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %% tags=["keep"]
struct Movable {
    static int next_index() {
        static int result{0};
        return ++result;
    }

    int i;

    Movable() : i{next_index()}
    {
        std::cout << "Movable(" << i << ") constructed\n";
    };

    Movable(const Movable& other) : i{next_index()}
    {
        std::cout << "Movable(" << i << "): copy constructor called. (Other = " << other.i << ")\n";
    };

    Movable(Movable&& other) : i{next_index()}
    {
        std::cout << "Movable(" << i << "): move constructor called. (Other = " << other.i << ")\n";
    };

    Movable& operator=(const Movable& other)
    {
        i = next_index();
        std::cout << "Movable(" << i << "): copy assignment operator called. (Other = " << other.i << ")\n";
        return *this;
    };

    Movable& operator=(Movable&& other)
    {
        i = next_index();
        std::cout << "Movable(" << i << "): move assignment operator called. (Other = " << other.i << ")\n";
        return *this;
    };
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
Movable make_movable()
{
    Movable m1{};
    Movable m2{};
    if (m1.i % 1234 == 0) {
        return m1;
    } else {
        return m2;
    }
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
Movable m1{};

// %% tags=["keep"]
Movable m2{m1};

// %% tags=["keep"]
m1 = m2;

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
Movable m3{make_movable()};

// %% tags=["keep"]
m3 = make_movable();

// %% tags=["keep"]
Movable m4{static_cast<Movable&&>(m3)};

// %% tags=["keep"]
Movable m5{std::move(m4)};

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: Explizite Konstruktoren
//
// Gegeben die folgenden Structs:

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

struct B;

struct A {
    A()                  { std::cout << "A()\n"; }
    A(const A&)          { std::cout << "A(const A&)\n"; }
    A(A&&)               { std::cout << "A(A&&)\n"; }
    A(int)               { std::cout << "A(int)\n"; }
    A(const B&)          { std::cout << "A(const B&)\n"; }
};

struct B {
    B(const B&)          { std::cout << "B(const B&)\n"; }
    B(B&&)               { std::cout << "B(B&&)\n"; }

    explicit B(int)      { std::cout << "B(int)\n"; }
    explicit B(const A&) { std::cout << "B(const A&)\n"; }
};

struct C {
    C(const A&)          { std::cout << "C(const A&)\n"; }
    C(const B&)          { std::cout << "C(const B&)\n"; }
    // implicit conversion to B
    operator B() const   { std::cout << "operator C::B()\n"; return B{1}; }
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
A f(A a) { std::cout << "f(A)\n"; return a; }

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
B f(B b) { std::cout << "f(B)\n"; return b; }

// %%
C f(C c) { std::cout << "f(C)\n"; return c; }

// %% tags=["keep"]
A ga(A a) { std::cout << "ga(A)\n"; return a; }

// %% tags=["keep"]
B gb(B b) { std::cout << "gb(B)\n"; return b; }

// %%
C gc(C c) { std::cout << "gc(C)\n"; return c; }

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// Welche der folgenden Zeilen kompilieren? Was ist die Ausgabe?

// %% tags=["keep"]
// A a0;

// %% tags=["keep"]
// B b0;

// %% tags=["keep"]
// A a1 = 5;

// %% tags=["keep"]
// B b1 = 5;

// %% tags=["keep"]
// A a2 = A{2};

// %% tags=["keep"]
// B b2 = B{2};

// %% tags=["keep"]
// A a3 = A{B{3}};

// %% tags=["keep"]
// B b3 = C{B{A{}}};

// %% tags=["keep"]
// A a4 = f(5);

// %% tags=["keep"]
// B b4 = f(5);

// %%
// C c4 = f(5);

// %% tags=["keep"]
// A a5 = f(A{});

// %% tags=["keep"]
// B b5 = f(B{1});

// %% tags=["keep"]
// A a6 = ga(5);

// %% tags=["keep"]
// B b6 = gb(5);

// %%
// C c6 = gc(6);

// %% tags=["keep"]
// A a7 = ga(B{7});

// %% tags=["keep"]
// B b7 = gb(C{7});

// %% tags=["keep"]
// A a8 = ga(C{8});

// %% tags=["keep"]
// A a9 = f(ga(5));

// %% tags=["keep"]
// B b9 = f(gb(C{5}));

// %%
// C c9 = f(gb(C{5}));

// %% tags=["keep"]
// A a10 = ga(f(5));

// %% tags=["keep"]
// B b10 = gb(f(5));

// %%
