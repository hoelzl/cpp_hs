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
//  <b>Templates und Delegation</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 03 Templates und Delegation.cpp -->
// <!-- slides/module_400_templates/topic_180_templates_and_strategy.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// - Das Strategy Pattern wird häufig eingesetzt um Flexibilität in unsere
//   Designs zu bringen.
// - Die Idee dabei ist, dass wir eine Klasse definieren, die eine bestimmte
//   Funktionalität implementiert, aber dabei an bestimmten Stellen die
//   Implementierung an eine andere Klasse delegiert.

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

// %% tags=["keep"]
class DynamicContext;

// %% tags=["keep"]
class Strategy
{
public:
    virtual ~Strategy() = default;
    virtual void algorithm() = 0;
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
class DynamicContext
{
public:
    DynamicContext(std::unique_ptr<Strategy> strategy)
        : strategy_(std::move(strategy))
    {}

    void algorithm()
    {
        std::cout << "DynamicContext::algorithm()" << std::endl;
        strategy_->algorithm();
    }

    void set_strategy(std::unique_ptr<Strategy> strategy)
    {
        strategy_ = std::move(strategy);
    }

private:
    std::unique_ptr<Strategy> strategy_;
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
class ConcreteStrategy1 : public Strategy
{
public:
    void algorithm() override
    {
        std::cout << "ConcreteStrategy1::algorithm()" << std::endl;
    }
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
class ConcreteStrategy2 : public Strategy
{
public:
    void algorithm() override
    {
        std::cout << "ConcreteStrategy2::algorithm()" << std::endl;
    }
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
DynamicContext c{std::make_unique<ConcreteStrategy1>()};
c.algorithm();

// %% tags=["keep"]
c.set_strategy(std::make_unique<ConcreteStrategy2>());
c.algorithm();

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Wir können eine Variante des Strategy Patterns mit Templates
//   implementieren:

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
template <typename T>
class StaticContext
{
public:
    void algorithm()
    {
        std::cout << "Context::algorithm()" << std::endl;
        T::algorithm();
    }
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
class StaticStrategy1
{
public:
    static void algorithm()
    {
        std::cout << "StaticStrategy1::algorithm()" << std::endl;
    }
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
class StaticStrategy2
{
public:
    static void algorithm()
    {
        std::cout << "StaticStrategy2::algorithm()" << std::endl;
    }
};

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
StaticContext<StaticStrategy1> c1;
c1.algorithm();

// %% tags=["keep"]
StaticContext<StaticStrategy2> c2;
c2.algorithm();

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Im Gegensatz zum Strategy Pattern können wir hier nicht zur Laufzeit
//   zwischen verschiedenen Strategien wechseln
// - Dafür müssen wir die Strategien nicht per Zeiger übergeben
// - Dadurch sparen wir die Indirektion und den dynamischen Dispatch
