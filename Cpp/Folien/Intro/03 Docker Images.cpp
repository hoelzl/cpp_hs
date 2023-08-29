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
//  <b>Docker Images</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 03 Docker Images.cpp -->
// <!-- slides/module_110_introduction/topic_140_docker_images.cpp -->

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Docker
//
// - Docker ist eine Container-Laufzeitumgebung
// - Download: [Docker Website](https://www.docker.com/products/docker-desktop/)
// - Test: `docker run hello-world`

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// ## Docker Images für Notebooks
//
// ```bash
//  docker run --init\
//             -p 8888:8888\
//             --mount type=bind,source=/path/to/slides,target=/root/course\
//             mhoelzl/cam-cpp-notebook:latest
// ```
//
// - `/path/to/slides` ist der absolute Pfad zu dem Ordner, der die Folien enthält
// - Unter Windows fängt dieser Pfad typischerweise mit `C:\Users\...` an

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// - Um auf die Notebooks zuzugreifen:
//   - URL: [http://localhost:8888]
//   - Passwort: `CAM`

// %% [markdown] lang="de" tags=["subslide"] slideshow={"slide_type": "subslide"}
//
// # Docker Images mit der Entwicklungsumgebung
//
// - Am Einfachsten ist es, diese Images als "Dev Container" in VS Code (oder
//   Visual Studio) zu verwenden
// - Installieren Sie die folgenden Erweiterungen in VS Code:
//   - Dev Containers (`ms-vscode-remote.remote-containers`)
//   - C/C++ (`ms-vscode.cpptools`)
//   - C/C++ Extension Pack (`ms-vscode.cpptools-extension-pack`)
//   - CMake Tools (`ms-vscode.cmake-tools`)
// - Öffnen Sie einfach den Ordner `code` in VS Code und wählen Sie "Reopen in
//   Container"
