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
//  <b>Quick-Start: Variablen</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 03 Quick-Start Variablen.cpp -->
// <!-- slides/module_120_basics/topic_130_variables.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// # Objekte und Variablen
//
// - Ein *Objekt* in C++
//     - ist ein Speicherbereich
//     - mit einem bestimmten Typ
// - Eine *Variable*
//     - ist ein benanntes Objekt

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Variablendefinition
//
// - Die **Definition** einer Variablen
//     - reserviert den Speicherplatz für die Variable und
//     - führt den Namen ins Programm ein.
// - Eine Variablendefinition *kann* die Variable initialisieren.

// %%
int i{1};
int j{i};
int k;

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Eine initialisierte Variable hat einen definierten Wert.
// - Uninitialisierte Variablen können beliebige Werte enthalten.
// - Das Lesen einer uninitialisierten Variable ist undefiniertes Verhalten und
//   kann zu Absturz des Programms führen.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Variablendefinition:
//   - Typ
//   - Name
//   - `int i;`
//   - Optionale Initialisierung
//   - `int i{1};`
// - Falls keine explizite Initialisierung erfolgt, hängt es vom Typ der Variablen
//   und der Stelle im Programm ab, ob die Variable initialisiert ist oder nicht.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Core-Guidelines zur Initialisierung
//
// - [Core Guidelines: ES.20: Always initialize an
//   object](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es20-always-initialize-an-object)
// - [Core Guidelines: ES.22: Don’t declare a variable until you have a value to
//   initialize it
//   with](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es22-dont-declare-a-variable-until-you-have-a-value-to-initialize-it-with)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// Es gibt mehrere Varianten für die Initialisierung von Variablen:

// %%
int i1 = 10;
int i2(20);
int i3{30};
int i4 = {40};

// %%
i1

// %%
i2

// %%
i3

// %%
i4

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Unterschiede bei der Initialisierung
//
// - Manche Formen der Initialisierung führen verlustbehaftete Konversionen
//   durch.
// - Die Initialisierung mit Klammern `int i(1)` kann manchmal vom Compiler als
//   Funktionsdeklaration interpretiert werden ("most vexing parse")

// %% lang="de"
double value{10.5};
int i1 = value;
int i2(value);
// int i3{value};    // Fehler: verlustbehaftete Konversion
// int i4 = {value}; // Fehler: verlustbehaftete Konversion

// %%
i1

// %%
i2

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Im Allgemeinen ist die `{}`-Syntax die bevorzugte Variante.
// - [Core Guidelines ES.23: Prefer the `{}`-initializer
//   Syntax](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-list)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Value-Initialisierung
//
// - Wenn ein Objekt mit leerem Initialisierer erzeugt wird, spricht man von
//   [*Value-Initialisierung*](https://en.cppreference.com/w/cpp/language/value_initialization).
// - Damit kann man sicherstellen, dass ein Objekt mit einem Standardwert
//   initialisiert wird ohne ihn explizit angeben zu müssen.

// %% lang="de"
// Value-Initialisierung; i ist immer initialisiert
int i{};

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### `{}`-Syntax der Variablendefinition
//
// - Die `{}`-Syntax der Variablendefinition ist:
//
// ```cpp
// T var{};
// T var{arg};
// T var{arg1, arg2, ...};
// ```

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Gleichzeitige Definition mehrerer Variablen
//
// - Wir können mehrere Variablen gleichzeitig definieren.
// - Die Variablen können mit allen gezeigten Initialisierungsformen
//   initialisiert werden oder uninitialisiert bleiben.
// - Das kann leicht unübersichtlich werden, vor allem wenn wir Modifikatoren
//   verwenden.

// %%
int i1{1}, i2{2}, i3{3};

// %%
i1

// %%
i2

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: Variablen
//
// Welche der folgenden Initialisierungen sind gültig?
//
// Versuchen Sie sich zu überlegen, welches Ergebnis Sie erwarten
// und überprüfen Sie es dann indem Sie die Zelle evaluieren.

// %% tags=["keep"]
// int i1 = 1;

// %% tags=["keep"]
// signed short i2(65535u);

// %% tags=["keep"]
// i2

// %% tags=["keep"]
// long i3{3};

// %% tags=["keep"]
// int i4 = {4.0};

// %% tags=["keep"]
// int i5 = 4.0;

// %% tags=["keep"]
// int i6 = 4.5;
