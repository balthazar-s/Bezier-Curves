# **Boids in C++**

This project is a simple simulation of boids written in C++ using SFML.
Compiled with MYSYS2 and MinGW.

For more information about boids refer to [*Flocks, Herds, and Schools: A Distributed Behavioral Model*](https://www.cs.toronto.edu/~dt/siggraph97-course/cwr87/) by Craig W. Reynolds and [*Boids algorithm - augmented for distributed consensus*](https://vanhunteradams.com/Pico/Animal_Movement/Boids-algorithm.html) by V. Hunter Adams.

This project uses a simple boids algorithm built on the three following rules:
<ul>
  <li>Each boid attempts to avoid others</li>
  <li>Each boid attempts to align itself with the average heading of its neighbors</li>
  <li>Each boid attempts to steer towards the center of mass of its neighbors</li>
</ul>

This code in action looks like this:

<img src="readme_assets/boids_example.gif" width="250" height="250" />
