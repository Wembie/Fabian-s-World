# Fabian-s-World

Onichan Yamete Kudasai
EXONERADOS (emoticon_de_carita_facherita)

Videojuego de aventura y combate en 2D desarrollado en **C++** con la librería gráfica **Allegro**, como proyecto universitario.

---

## 📖 Descripción

Fabian's World es un videojuego de exploración y batallas por turnos en 2D. El jugador recorre niveles, encuentra enemigos y combate contra ellos usando armas y pociones. El proyecto implementa principios de **Programación Orientada a Objetos** con herencia, polimorfismo y manejo de inventario.

---

## 🗂️ Estructura del repositorio

```
Fabian-s-World/
├── PROYECTO 2/              # Código fuente y recursos del juego
│   ├── main.cpp             # Punto de entrada
│   ├── View.cpp / View.h    # Capa de vista (renderizado con Allegro)
│   ├── Controller.cpp/.h    # Lógica de control del juego
│   ├── personaje.cpp/.h     # Clase base Personaje
│   ├── jugador.cpp/.h       # Clase Jugador (hereda de Personaje)
│   ├── enemigo.cpp/.h       # Clase Enemigo (hereda de Personaje)
│   ├── arma.cpp/.h          # Clase Arma
│   ├── pocion.cpp/.h        # Clase Poción
│   ├── item.cpp/.h          # Clase Item (inventario)
│   ├── *.bmp                # Sprites y fondos del juego
│   ├── musicaFondo.mid      # Música de fondo
│   └── Proyecto 2.exe       # Ejecutable compilado (Windows)
├── Diagrama Clases.drawio   # Diagrama de clases UML
├── Diagrama Clases.png      # Diagrama de clases (imagen)
├── Historia videojuego.pdf  # Historia y narrativa del juego
├── Manual Tecnico.pdf       # Manual técnico del proyecto
└── Trabajo escrito *.pdf    # Documentos escritos del proyecto
```

---

## 🎮 Características del juego

- **2 niveles** de exploración con mapa de desplazamiento
- **Sistema de batallas** al encontrar enemigos en el mapa
- **Inventario** de ítems (pociones y armas)
- **Pociones**: vida, maná, ataque, resistencia y daño
- **Armas**: espada, arco y lanza
- **Música de fondo** durante el juego

---

## 🧱 Arquitectura del código

El proyecto sigue el patrón **MVC (Modelo–Vista–Controlador)**:

| Componente    | Descripción |
|---------------|-------------|
| `View`        | Renderiza pantallas, ciclo principal y bucle de batalla |
| `Controller`  | Contiene la lógica del juego |
| `Personaje`   | Clase base con vida, ataque y resistencia |
| `Jugador`     | Extiende `Personaje`, añade maná e inventario |
| `Enemigo`     | Extiende `Personaje`, con posicionamiento en mapa |
| `Arma`        | Representa armas del jugador |
| `Pocion`      | Ítems consumibles con efectos sobre estadísticas |

---

## 🛠️ Tecnologías utilizadas

- **Lenguaje**: C++
- **Librería gráfica**: [Allegro 4.2](https://liballeg.org/)
- **IDE**: Dev-C++ (Orwell)
- **Plataforma objetivo**: Windows

---

## ▶️ Compilación y ejecución

### Requisitos
- Dev-C++ con Allegro 4.2 instalado, **o**
- MinGW/GCC con la librería Allegro 4.2 (`alleg42.dll` incluida en el proyecto)

### Pasos
1. Abre `PROYECTO 2/Proyecto 2.dev` con Dev-C++.
2. Compila el proyecto (`F9` o *Ejecutar → Compilar y Ejecutar*).
3. También puedes ejecutar directamente `PROYECTO 2/Proyecto 2.exe` en Windows.

> **Nota:** `alleg42.dll` debe encontrarse en la misma carpeta que el ejecutable.

---

## 📄 Documentación

- [`Diagrama Clases.png`](Diagrama%20Clases.png) — Diagrama UML de clases
- [`Historia videojuego.pdf`](Historia%20videojuego.pdf) — Historia y lore del juego
- [`Manual Tecnico.pdf`](Manual%20Tecnico.pdf) — Manual técnico completo

---

## 👥 Autores

Proyecto desarrollado como trabajo universitario por el equipo **FELL / JEAL / MDMVD**.
