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
//  <b>Switch</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 06 Switch.cpp -->
// <!-- slides/module_120_basics/topic_224_switch.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Switch
//
// - Die `switch`-Anweisung ist eine Alternative zur `if`-Anweisung.
// - Sie überprüft einen integralen Wert oder eine Enumeration.
// - Die Fälle werden mit `case` angegeben.
// - Der `default`-Fall wird ausgeführt, wenn kein anderer Fall zutrifft.
// - Jedes `case` muss mit einem `break` oder `return` beendet werden, sonst
//   fällt der Programmfluss zur folgenden `case`-Anweisungen durch.


// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

switch (1)
{
    case 1:
        std::cout << "1\n";
        break;
    case 2:
        std::cout << "2\n";
        break;
    case 3:
        std::cout << "3\n";
        break;
}

// %% tags=["keep", "subslide"] slideshow={"slide_type": "subslide"}
#include <iostream>

switch (1)
{
    case 1:
        std::cout << "1\n";
    case 2:
        std::cout << "2\n";
    case 3:
        std::cout << "3\n";
}

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// Zurück zu unserem laufenden Beispiel mit den Pfadkosten:
//
// - Nachdem für die Berechnung der Kosten nur drei Fälle unterschieden werden
//   müssen, können wir eine Enumeration verwenden die möglichen Fälle zu
//   erfassen.
// - Danach können wir mit einem `switch` die Kosten berechnen.
// - Hier sind wieder die Definitionen der benötigten Typen und Funktionen.

// %% tags=["keep"]
struct Point3d
{
    double x;
    double y;
    double z;
};


// %% tags=["keep"]
#include <iostream>

void print(Point3d p)
{
    std::cout << "Point3d{" << p.x << ", " << p.y << ", " << p.z << "}";
}

// %% tags=["keep"]
double distance(Point3d p1, Point3d p2)
{
    double dx{p2.x - p1.x};
    double dy{p2.y - p1.y};
    double dz{p2.z - p1.z};
    return sqrt(dx * dx + dy * dy + dz * dz);
}

// %% tags=["keep"]
Point3d p1{1.0, 2.0, 3.0};
Point3d p2{3.0, 2.0, 1.0};
Point3d p3{3.0, 2.0, 3.0};
Point3d p4{3.0, 2.0, 5.0};

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
enum class TargetHeight {
    Higher,
    Lower,
    Same
};

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
TargetHeight target_height(Point3d p1, Point3d p2)
{
    if (p1.z > p2.z) {
        return TargetHeight::Higher;
    } else if (p1.z < p2.z) {
        return TargetHeight::Lower;
    } else {
        return TargetHeight::Same;
    }
}

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
double path_cost_2(Point3d p1, Point3d p2)
{
    switch (target_height(p1, p2))
    {
    case TargetHeight::Higher:
        return 1.5 * distance(p1, p2);
    case TargetHeight::Lower:
        return 0.8 * distance(p1, p2);
    default:
        return distance(p1, p2);
    }
}

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
path_cost_2(p1, p2)

// %%
path_cost_2(p2, p1)

// %%
path_cost_2(p1, p3)
