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
//  <b>Main</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 07 Main.cpp -->
// <!-- slides/module_120_basics/topic_240_main.cpp -->

// %% [markdown] lang="de" tags=["slide"] slideshow={"slide_type": "slide"}
//
// # Die `main` Funktion
//
// - Die Ausführung eines Programms beginnt immer mit der `main` Funktion.
// - Sie muss eines der folgenden Formate haben:
//   ```cpp
//   int main()
//   {
//       // ...
//   }
//   ```
//   oder
//   ```cpp
//   int main(int argc, char* argv[])
//   {
//       // ...
//   }
//   ```
// - Die `main` Funktion muss `int` zurückgeben.
// - Der Rückgabewert wird (potentiell) vom Betriebssystem verwendet, um zu
//   bestimmen, ob das Programm erfolgreich ausgeführt wurde oder nicht.


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## `argc` und `argv`
//
// - `argc` ist die Anzahl der Kommandozeilenargumente.
// - `argv` ist ein Array von Strings, die die Kommandozeilenargumente
//   repräsentieren.
// - `argv[0]` ist der Name des Programms.
// - `argv[1]` ist das erste Kommandozeilenargument.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Rückgabewert
//
// - Der Rückgabewert der `main` Funktion wird vom Betriebssystem verwendet, um
//   zu bestimmen, ob das Programm erfolgreich ausgeführt wurde oder nicht.
// - Der Rückgabewert `0` bedeutet, dass das Programm erfolgreich ausgeführt
//   wurde.
// - Alle anderen Rückgabewerte bedeuten, dass das Programm nicht erfolgreich
//   ausgeführt wurde.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Quellcode von C++ Programmen
//
// - C++ Programme bestehen aus einer oder mehreren Quelldateien.
// - Jede Quelldatei wird kompiliert und in eine Objektdatei übersetzt.
// - Die Objektdateien werden dann zu einer ausführbaren Datei verlinkt.


// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Cpp-Dateien
//
// - C++ Quelldateien haben typischerweise die Dateiendung `.cpp`.
// - Sie enthalten den Quellcode von Funktionen, Klassen, Variablen,
//   Konstanten, etc.
// - Größere Projekte haben typischerweise mehrere Quelldateien.
// - Diese Dateien können unabhängig voneinander kompiliert werden.
// - Problem: Wie kann eine Funktion `f()` in einer Quelldatei `a.cpp` die
//   Funktion `g()` in einer anderen Quelldatei `b.cpp` aufrufen?
// - Lösung: Vorwärtsdeklarationen

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Vorwärtsdeklaration
//
// - Eine Funktion `g()`, die die Funktion `f()` aufruft, kann kompiliert werden,
//   ohne dass die *Definition* von `f()` bekannt ist.
// - Aber eine *Deklaration* von Funktion `f()` muss vorhanden sein.
// - Eine **Deklaration** einer Funktion besteht aus dem Funktionskopf und einem
//   Semikolon.
// - Die Deklaration einer Funktion teilt dem Compiler mit, dass es diese
//   Funktion gibt und wie sie aufgerufen werden kann.
// - Typischerweise werden Funktionen in Headerdateien deklariert.
// - Zur Laufzeit muss natürlich die Funktion `f()` definiert sein.
// - Siehe `code/completed/simple_examples`.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Headerdateien
//
// - Headerdateien enthalten Deklarationen von Funktionen, Klassen, Variablen,
//   Konstanten, etc.
// - Die Dateiendung ist typischerweise `.h` oder `.hpp`.
// - Sie werden mit der Präprozessordirektive `#include` eingebunden.
// - Damit wird der Quellcode des Headers in den Quellcode des Programms
//   eingefügt.
// - Jeder Header darf nur einmal eingebunden werden.
//   - Typischerweise wird dies durch `#pragma once` oder  Include Guards erreicht.
// - Siehe `code/completed/simple_examples`.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ### Include Guards
//
// - Ein Include Guard ist ein Präprozessor-Makro, das verhindert, dass ein
//   Header mehrfach eingebunden wird.
// - Ein Include Guard besteht aus einem Makronamen und einem `#define`.
// - Der Makroname ist typischerweise der Dateiname in Großbuchstaben und
//   durch Unterstriche ersetzt.
// - Der Makroname wird mit `#ifndef` geprüft.
// - Wenn der Makroname nicht definiert ist, wird der Header eingebunden.
// - Nach dem Einbinden wird der Makroname mit `#define` definiert.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Was gehört in Headerdateien?
//
// Da Header Dateien potentiell von mehreren Quelldateien eingebunden werden,
// sollten sie keine Definitionen enthalten.
//
// See `code/completed/simple_examples`.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// Headerdateien sollten *nur* die folgenden Elemente enthalten:
//
// - Funktions-Deklarationen
// - Klassen- und Struct-Deklarationen
// - Variablendeklarationen
// - Konstanten und Enumerationen
// - Typ Aliase und Using-Deklarationen
// - Template-Deklarationen und -Definitionen

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// Headerdateien sollten *nicht* die folgenden Elemente enthalten:
//
// - Funktionsdefinitionen (außer `inline` und `constexpr`)
// - Aggregat-Definitionen
// - Variablendefinitionen (außer `const` und `constexpr`)
// - anonyme Namespaces
// - `using`-Direktiven

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// # Beispiel: Einfacher Taschenrechner
//
// In diesem Beispiel schreiben wir ein Programm, das einfache arithmetische
// Operationen wie Addition, Subtraktion, Multiplikation und Division
// durchführt. Das Programm nimmt Eingaben vom Benutzer für zwei Zahlen und die
// Operation, die sie durchführen möchten.
//
// 1. Fordern Sie den Benutzer auf, die erste Zahl einzugeben.
// 2. Fordern Sie den Benutzer auf, die zweite Zahl einzugeben.
// 3. Fordern Sie den Benutzer auf, die Operation einzugeben, die er ausführen
//    möchte (+, -, *, /).
// 4. Basierend auf der Operation führen Sie die Berechnung durch und geben Sie
//    das Ergebnis aus.

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Mini-Workshop: BMI-Rechner
//
// In diesem Workshop erstellen Sie ein Programm, das den Body Mass Index
// (BMI) einer Person berechnet. Der BMI ist ein nützlicher Indikator für die
// Gesundheit einer Person und wird mit der folgenden Formel berechnet:
//
// $BMI = Gewicht (kg) / Größe (m)^2$
//
// Ihr Programm nimmt das Gewicht des Benutzers in Kilogramm und die Größe in
// Metern als Eingabe und berechnet dann den BMI und zeigt ihn dem Benutzer an.
//
// 1. Fordern Sie den Benutzer auf, sein Gewicht in Kilogramm einzugeben.
// 2. Fordern Sie den Benutzer auf, seine Größe in Metern einzugeben.
// 3. Berechnen Sie den BMI mit der angegebenen Formel.
// 4. Geben Sie dem Benutzer den berechneten BMI-Wert aus.
//
// Vergessen Sie nicht, geeignete Datentypen für das Speichern der Gewichts- und
// Größenwerte sowie des berechneten BMI zu verwenden.
//
// Sie können das `bmi_sk` Starter Kit verwenden, um zu beginnen.
