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
//  <b>Beispiel: Pfadkosten</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 09 Beispiel Pfadkosten.cpp -->
// <!-- slides/module_120_basics/topic_900_path_example.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// In einer früheren Lektion hatten wir einen Typ `Point3d` definiert, der einen
// Punkt im dreidimensionalen Raum repräsentiert:

// %% tags=["keep"]
struct Point3d
{
    double x;
    double y;
    double z;
};


// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
#include <iostream>

void print(Point3d p)
{
    std::cout << "Point3d{" << p.x << ", " << p.y << ", " << p.z << "}";
}

// %% tags=["subslide", "keep"] slideshow={"slide_type": "subslide"}
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

// %% tags=["keep"]
print(p1);

// %% tags=["keep"]
distance(p1, p2)

// %% tags=["keep"]
distance(p2, p1)

// %% tags=["keep"]
distance(p1, p4)

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Kontrollfluss
//
// - Wir wollen eine Funktion `path_cost(Point3d p1, Point3d p2)` definieren,
//   die die Kosten berechnet um von `p1` nach `p2` zu kommen.
// - Die Kosten sind folgendermaßen definiert:
//     - Wenn `p1` höher ist als `p2`, dann sind die Kosten 1.5 mal der Abstand
//       von `p1` und `p2`.
//     - Wenn `p1` niedriger ist als `p2`, dann sind die Kosten 0.8 mal der
//       Abstand von `p1` und `p2`.
//     - Wenn `p1` und `p2` gleich hoch sind, dann sind die Kosten der Abstand
//       von `p1` und `p2`.
//     - Die Höhe wird durch das `z`-Attribut angegeben.

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
double path_cost(Point3d p1, Point3d p2)
{
    if (p1.z > p2.z) {
        return 1.5 * distance(p1, p2);
    }
    else if (p1.z < p2.z) {
        return 0.8 * distance(p1, p2);
    }
    else {
        return distance(p1, p2);
    }
}

// %% tags=["subslide"] slideshow={"slide_type": "subslide"}
path_cost(p1, p2)

// %%
path_cost(p2, p1)

// %% tags=["keep"]
path_cost(p1, p3)

// %% tags=["keep"]
path_cost(p3, p1)

// %% tags=["keep"]
path_cost(p1, p4)

// %% tags=["keep"]
path_cost(p4, p1)


// %% tags=["keep"]
#include <vector>

// %%
double path_cost(const std::vector<Point3d>& points)
{
    if (points.size() == 0) {
        return 0.0;
    }
    double result{0.0};
    Point3d prev{points[0]};
    for (const Point3d& p : points) {
        result += path_cost(prev, p);
        prev = p;
    }
    return result;
}

// %%
std::vector<Point3d> path{};

// %%
path_cost(path)

// %%
path.push_back(Point3d{1.0, 2.0, 0.0});
path_cost(path)

// %%
path.push_back(Point3d{2.0, 1.0, 0.0});
path_cost(path)

// %%
path.push_back(Point3d{2.0, 3.0, 1.0});
path_cost(path)

// %%
