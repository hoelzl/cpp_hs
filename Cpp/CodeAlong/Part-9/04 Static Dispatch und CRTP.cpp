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
//  <b>Static Dispatch und CRTP</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 04 Static Dispatch und CRTP.cpp -->
// <!-- slides/module_400_templates/topic_190_static_dispatch.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Mit Vererbung können wir Arbeit zwischen Ober- und Unterklasse verteilen:
//   - Oberklasse implementiert "Gerüst" der Funktionalität
//   - Virtuelle Methoden erlauben die Anpassung des Verhaltens durch
//     Unterklassen:

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %% tags=["keep"]
class DynamicBase
{
public:
    virtual ~DynamicBase() = default;

    void do_something()
    {
        std::cout << "DynamicBase::do_something()\n";
        customization_point();
    }

protected:
    virtual void customization_point() = 0;
    int x{1};
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
class DynamicDerived : public DynamicBase
{
protected:
    void customization_point() override
    {
        std::cout << "DynamicDerived::customization_point(): x = " << x << "\n";
    }
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <memory>

// %% tags=["keep"]
std::unique_ptr<DynamicBase> base{std::make_unique<DynamicDerived>()};

// %% tags=["keep"]
base->do_something();

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Die Implementierung der Methode `customization_point()` wird zur
//   Laufzeit ausgewählt
// - Das ist nicht immer erwünscht
// - Mit Templates können wir eine statische Auswahl erreichen
// - Allerdings müssen wir dabei einen Trick anwenden
//   - Das Curiously Recurring Template Pattern (CRTP)

// %% tags=["start", "subslide"] slideshow={"slide_type": "subslide"}
class StaticBaseStart
{
public:
    void do_something()
    {
        std::cout << "StaticBase::do_something()\n";
        this->customization_point();
    }

    // - Should actually be abstract
    // - Don't want to dispatch dynamically here
    void customization_point()
    {
        std::cout << "StaticBase::customization_point(): x = " << x << "\n";
    }

protected:
    int x{1};
};

// %% tags=["start"]
class StaticDerivedStart : public StaticBaseStart
{
public:
    void customization_point()
    {
        std::cout << "StaticDerived::customization_point(): x = " << x << "\n";
    }
};

// %% tags=["start"]
StaticDerivedStart sds;

// %% tags=["start"]
sds.do_something();


// %%
