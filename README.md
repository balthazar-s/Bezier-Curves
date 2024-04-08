# **Boids in C++**

This project is a simple simulation of boids written in C++ using SFML.
Compiled with MYSYS2 and MinGW.

For more information about boids refer to [*Flocks, Herds, and Schools: A Distributed Behavioral Model*](https://www.cs.toronto.edu/~dt/siggraph97-course/cwr87/) by Craig W. Reynolds and [*Boids algorithm - augmented for distributed consensus*](https://vanhunteradams.com/Pico/Animal_Movement/Boids-algorithm.html) by V. Hunter Adams.

This project uses a simple boids algorithm built on the three following rules:
<ul>
  <li>Each boid attempts to avoid others <i>(separation)</i></li>
  <li>Each boid attempts to align itself with the average heading of its neighbors <i>(alignment)</i></li>
  <li>Each boid attempts to steer towards the center of mass of its neighbors <i>(cohesion)</i></li>
</ul>

This code in action looks like this:

<img src="readme_assets/boids_example.gif" width="700" height="700" />

Additionally, a gradient was included based on the concentration of boids within a certain area. Blue is the least dense, then yellow is medium density, with red only appearing in cases of extreme density, 

**Disclaimer: may be significantly laggy on some systems due to cpu limitations.**


<picture>
  <source srcset="readme_assets/boids_example.jpg">
</picture>