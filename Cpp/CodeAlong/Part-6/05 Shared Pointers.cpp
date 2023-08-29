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
//  <b>Shared Pointers</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 05 Shared Pointers.cpp -->
// <!-- slides/module_160_raii/topic_140_shared_ptr.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Shared Pointers können *gemeinsam* Eigentümer eines Objekts sein
// - Sie verwenden Reference-Counting

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>
#include <memory>

#include "lifetime_observer.hpp"
#include "print_info.hpp"

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
std::shared_ptr<Obs> obs{};

// %% tags=["keep"]
print_bool(obs);

// %%

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
{
    std::shared_ptr<Obs> obs{std::make_shared<Obs>(1)};
    print_bool("obs", obs);
    print_use_count("obs", obs);
    std::shared_ptr<Obs> obs2{obs};
    print_use_count("obs", obs);
    print_use_count("obs2", obs2);
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
{
    std::shared_ptr<Obs> obs{std::make_shared<Obs>(2)};
    std::shared_ptr<Obs> obs2{};
    print_use_count("obs  (outer block)", obs);
    print_use_count("obs2 (outer block)", obs2);
    {
        std::shared_ptr<Obs> obs3{obs};
        obs2 = obs3;
        print_use_count("obs  (inner block)", obs);
        print_use_count("obs2 (inner block)", obs2);
        print_use_count("obs3 (inner block)", obs3);
    }
    print_use_count("obs  (outer block, again)", obs);
    print_use_count("obs2 (outer block, again)", obs2);
    obs.reset();
    print_use_count("obs  (outer block, after reset)", obs);
    print_use_count("obs2 (outer block, after reset)", obs2);
}


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Shared Pointers und Funktionsaufrufe

// %% tags=["keep"]
void describe(const Obs& obs)
{
    std::cout << "describe(Obs&): " << obs << "\n";
}

// %% tags=["keep"]
void describe(const Obs* obs)
{
    std::cout << "describe(Obs*): " << obs << "\n";
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
auto obs{std::make_shared<Obs>()};

// %% tags=["keep"]
describe(*obs);

// %% tags=["keep"]
describe(obs.get());

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Shared und Unique Pointers
//
// - Ein Unique Pointer kann in einen Shared Pointer umgewandelt werden:

// %% tags=["keep"]
std::unique_ptr<Obs> obs_up{std::make_unique<Obs>()};
std::shared_ptr<Obs> obs_sp{std::move(obs_up)};

// %% tags=["keep"]
std::cout << obs_up.get() << "\n";
std::cout << obs_sp.get() << "\n";

// %% tags=["keep"]
std::cout << *obs_sp;

// %% tags=["keep"]
obs_sp.use_count()

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Vorsicht bei Zyklen!
//
// - Shared Pointer können Zyklen bilden
// - Diese Zyklen werden nicht automatisch aufgelöst

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
struct Cycle
{
    ~Cycle() { std::cout << "Cycle::~Cycle()\n"; }
    std::shared_ptr<Cycle> other;
};

// %% tags=["keep"]
{
    std::shared_ptr<Cycle> c1{std::make_shared<Cycle>()};
    std::shared_ptr<Cycle> c2{std::make_shared<Cycle>()};
    std::shared_ptr<Cycle> c3{std::make_shared<Cycle>()};
    c1->other = c2;
    c2->other = c1;
    print_use_count("c1", c1);
    print_use_count("c2", c2);
    print_use_count("c3", c3);
}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Zum Auflösen von Zyklen kann man Weak Pointers einsetzen
