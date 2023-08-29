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
//  <b>Smart Pointers</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 03 Smart Pointers.cpp -->
// <!-- slides/module_160_raii/topic_120_smart_pointers.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Die Verwendung von `new` und `delete` ist fehleranfällig
// - Wir können in vielen Fällen Pointer mit RAII verwalten
// - Smart Pointer sind Objekte, die sich wie Pointer verhalten, aber
//   automatisch den Speicher freigeben, wenn sie nicht mehr benötigt werden

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Eigentum (Ownership)
//
// - Der Eigentümer (Owner) eines Objekts ist für das Löschen des Objekts
//   verantwortlich
// - Der Eigentümer eines Objekts kann das Eigentum an ein anderes Objekt
//   übertragen
// - Die korrekte Verwaltung des Eigentums ist ein wesentlicher Bestandteil
//   von robustem und wartbarem C++-Code

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Smart Pointer sind in der Header-Datei `<memory>` definiert.
// - Es gibt verschiedene Arten von Smart Pointern:
//   - `std::unique_ptr`: alleiniges Eigentum
//   - `std::shared_ptr`: gemeinsames Eigentum
//   - `std::weak_ptr`: kein Eigentum, hält ein Objekt nicht am Leben
