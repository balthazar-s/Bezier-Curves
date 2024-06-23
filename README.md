# Modeling n-sized Bézier Curves


### Description:
After stumbling across the concept recently, I decided to try my hand at modeling Bézier curves by myself without the use of a graphics library to create the curve.

This project, programmed in C++, uses SFML (Simple and Fast Multimedia Library) to handle the graphics end of the creation of the window, drawing of shapes, etc., but does not calculate the Bézier curves through any built in function.

First of all, the Bézier curve was invented in 1960 by Pierre Bézier to aid in designing cars, but today it is widely used within the context of computer graphics. It is a "parametric curve" that relies on control points that define its path. The first and last points are also sometimes referred to as anchor points because it is from these points that the curve begins and ends.

Several formulas exist for Bézier curves of different sizes, for example with 3, 4, or 5 control points. However, in an effort to challenge myself, this project is scalable with as many control points as needed. To do so, I used the explicit definition of any n-sized Bézier curve which is available on [Wikipedia](https://en.wikipedia.org/wiki/B%C3%A9zier_curve).

The project is composed of 3 .cpp files as well as 2 .hpp headers. The two headers, curve.hpp and point.hpp, define classes _Curve_ and _Point_ respectively, which have their own values and functions. Additionally, within main.cpp, a struct called _MenuButton_ is also defined to aid in the creation of the menu on the top of the screen.


Within main.cpp, the process is generally as follows:
1. Initialize SFML window & relevant settings
2. Load font "arial.ttf" into project
3. Create four menu buttons and initialize mode "move" to the one selected
4. Create a vector of objects of type *Point* and then create and initialize the 4 default points
5. Create a vector containing purely the locations of the previous points
6. Create an object of type *Curve* with the locations mentioned above
7. Begin window loop
8. Check for window exit event
9. Check for a menu selection (and change selection)
10. Using a switch statement, handle point movement based on the selection mode
    - **Move** will only allow for the movement of existing points
    - **Create** will allow for the creation of new points and the movement of existing ones
    - **Delete** will delete any point clicked
    - **Hidden** will hide all points, only display the curves, and not allow for any point movement
11. Update a point if it is moved
12. Update the curve with new point positions
13. Draw the curve to the window
14. Draw the points to the window unless mode "Hidden" is selected
15. Draw menu boxes and text


Within the _Curve_ and _Point_ classes, there are generally the following types of functions:
- Initialize the object with any needed values
- Draw the object to the window
- Update / Move object with new information


The _Curve_ class is more complicated:
- Within curve.cpp, a simple function called "fact" is used to recursively calculated factorial numbers
- The function "draw_line" draws a simple line between two input points of a defined width. As SFML possesses no straight line drawing implementation, these lines are simply rotated rectangles.
- The update function for a _Curve_ object does two things:
    1. It updates the objects own "points" vector to contain only the positions of the points passed in from main.cpp
    2. It creates a vector of point positions which represent the curve. The number of points created is specified by the value "resolution" and the x and y coordinates of these points are calculated with the aforementioned explicit definition of any n-sized Bézier curve.



### Sources and Generative AI
- SFML, https://www.sfml-dev.org/
- Bézier curve, https://en.wikipedia.org/wiki/B%C3%A9zier_curve
- Understanding Bézier Curves, https://mmrndev.medium.com/understanding-b%C3%A9zier-curves-f6eaa0fa6c7d
- On rare occasions ChatGPT was used to help with the programming, notably with the creation of the "draw_line" function. It was also used to sparingly (and mostly unsuccessfully) troubleshoot code and compilation.



### Extra Notes
As I was not successful in compiling this project with static linking, the .exe found within the .build folder will not work without SFML installed. I installed it through Mysys2 and compiled my code with MinGW.
