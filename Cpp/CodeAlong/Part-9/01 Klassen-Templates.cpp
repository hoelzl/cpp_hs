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
//  <b>Klassen-Templates</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 01 Klassen-Templates.cpp -->
// <!-- slides/module_400_templates/topic_130_class_templates.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Templates erlauben es, Klassen zu definieren, die von einem Typ abhängen
// - Beispiel: `std::vector<T>`
//   - `T` ist der Typ der Elemente im Vektor
//   - `std::vector<int>` ist ein Vektor von `int`s
// - Für jeden Typ, den wir für `T` einsetzen, wird eine neue Vektor-Klasse
//   erzeugt
// - Wir können solche Klassen selbst definieren
// - Dazu verwenden wir das Schlüsselwort `template`, gefolgt von einer
//   Template-Parameter-Liste

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Template-Parameter
//
// - `T` ist ein Template-Parameter (genauer: Typ-Template-Parameter)
// - `T` kann in der Klasse wie ein Typ verwendet werden
// - Beim Instanziieren der Klasse wird `T` durch einen konkreten Typ ersetzt

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %%

// %%

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
BufferV1<std::string> sb;

// %% tags=["keep"]
sb[0] = "Hello";

// %% tags=["keep"]
sb[0]

// %% tags=["keep"]
sb.add(" World");

// %% tags=["keep"]
sb[0]

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Das Instanziieren einer Template-Klasse funktioniert nur, wenn die aufgerufenen
//   Methoden für den konkreten Typ `T` definiert sind:

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <vector>

// %% tags=["keep"]
BufferV1<std::vector<int>> bvi;

// %% tags=["keep"]
bvi[0] = {1, 2, 3};

// %% tags=["keep"]
bvi[0]

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Template-Spezialisierung
//
// - Wir können eine Template-Klasse für bestimmte Typen spezialisieren


// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
template <typename T>
struct BufferV2
{
    T data[10];

    T& operator[](std::size_t index) { return data[index]; }

    void add(T value)
    {
        for (T& v : data) {
            v += value;
        }
    }
};

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}


// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
BufferV2<std::vector<int>> bvi2;

// %% tags=["keep"]
bvi2[0] = {1, 2, 3};

// %% tags=["keep"]
bvi2[0]

// %% tags=["keep"]
bvi2.add({4, 5, 6});

// %% tags=["keep"]
bvi2[0]

// %% tags=["keep"]
bvi2[1]


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Partielle Spezialisierung
//
// - Wir haben `BufferV2` für `std::vector<int>` spezialisiert
// - Oft wäre es besser, wenn wir die Spezialisierung für `std::vector<T>`
//   durchführen könnten
// - Das ist mit partieller Spezialisierung möglich:

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
template <typename T>
struct BufferV3
{
    T data[10];

    T& operator[](std::size_t index) { return data[index]; }

    void add(T value)
    {
        for (T& v : data) {
            v += value;
        }
    }
};


// %% tags=["subslide", "start"] slideshow={"slide_type": "subslide"}
template <>
struct BufferV3<std::vector<int>>
{
    std::vector<int> data[10];

    std::vector<int>& operator[](std::size_t index) { return data[index]; }

    void add(std::vector<int> value)
    {
        for (std::vector<int>& v : data) {
            v.insert(v.end(), value.begin(), value.end());
        }
    }

};


// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
BufferV3<std::vector<std::string>> bvs;

// %% tags=["keep"]
bvs[0] = {"a", "b", "c"};

// %% tags=["keep"]
bvs[0]

// %% tags=["keep"]
bvs.add({"d", "e", "f"});

// %% tags=["keep"]
bvs[0]

// %% tags=["keep"]
bvs[1]

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Template-Parameter können auch Werte sein
// - Sie können dann wie Konstanten verwendet werden
// - Beispiel: `std::array<T, N>`
//   - `T` ist der Typ der Elemente im Array
//   - `N` ist die Anzahl der Elemente im Array
// - Für jeden Typ, den wir für `T` und jede Zahl, die wir für `N` einsetzen,
//   wird eine neue Array-Klasse erzeugt

// %% tags=["subslide", "start"] slideshow={"slide_type": "subslide"}
template <typename T>
struct BufferV4Start
{
    T data[10];

    T& operator[](std::size_t index) { return data[index]; }

    void add(T value)
    {
        for (T& v : data) {
            v += value;
        }
    }

    int size() const { return 10; }
};

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}

// %%

// %%

// %%

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wir können die Werte von Template-Parametern auch berechnen
// - Die Berechnung muss zur Compile-Zeit erfolgen
// - Dazu verwenden wir `constexpr`-Funktionen

// %% tags=["subslide", "start"] slideshow={"slide_type": "subslide"}
int square(int x)
{
    return x * x;
}

// %%

// %%
